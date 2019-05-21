#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image
{
    double quality;
    double freshness;
    double rating;
};

struct Params
{
    double a;
    double b;
    double c;
};

class FunctionPart
{
public:
    FunctionPart(char new_op, double new_val)
    {
        m_operation = new_op;
        m_value = new_val;
    }
    double Apply(double src_val) const
    {
        switch (m_operation)
        {
        case '+':
            return src_val + m_value;
        case '-':
            return src_val - m_value;
        }
    }
    void Invert()
    {
        switch (m_operation)
        {
        case '+':
            m_operation = '-';
            break;
        case '-':
            m_operation = '+';
            break;
        }
    }
private:
    char m_operation;
    double m_value;
};

class Function
{
public:
    void AddPart(char op, double value)
    {
        m_parts.push_back({op, value});
    }
    double Apply(double value) const
    {
        for (const auto& op : m_parts)
        {
            value = op.Apply(value);
        }
        return value;
    }
    void Invert()
    {
        for (auto& op : m_parts)
        {
            op.Invert();
        }
        reverse(begin(m_parts), end(m_parts));
    }
private:
    vector<FunctionPart> m_parts;
};

Function make_weight_function(const Params& params, const Image& image)
{
    Function func;
    func.AddPart('-', image.freshness * params.a + params.b);
    func.AddPart('+', image.rating * params.c);
    return func;
}

double compute_image_weight(const Params& params, const Image& image)
{
    Function func = make_weight_function(params, image);
    return func.Apply(image.quality);
}

double compute_quality_by_weight(const Params& params, const Image& image, double weight)
{
    Function func = make_weight_function(params, image);
    func.Invert();
    return func.Apply(weight);
}

int main()
{
    Image img = {10, 2, 6};
    Params prms = {4, 2, 6};
    //10 - 2 * 4 - 2 + 6 * 6 = 36
    cout << compute_image_weight(prms, img) << endl;
    cout << compute_quality_by_weight(prms, img, 46) << endl;
    return 0;
}
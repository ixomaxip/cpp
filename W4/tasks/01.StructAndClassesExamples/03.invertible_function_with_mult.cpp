#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
        case '*':
            return src_val * m_value;
        case '/':
            return src_val / m_value;
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
        case '*':
            m_operation = '/';
            break;
        case '/':
            m_operation = '*';
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


// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

// Function MakeWeightFunction(const Params& params,
//                             const Image& image) {
//   Function function;
//   function.AddPart('*', params.a);
//   function.AddPart('-', image.freshness * params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params,
//                               const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   cout << ComputeImageWeight(params, image) << endl;
//   cout << ComputeQualityByWeight(params, image, 52) << endl;
//   return 0;
// }

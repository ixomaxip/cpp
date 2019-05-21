#include <iostream>
#include <vector>

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

};

class Function
{
public:
    void AddPart(char op, double value);
    double Apply(double value) const;
    void Invert();
private:
    vector<FunctionPart> parts;
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

    // double weight = image.quality;
    // weight -= image.freshness * params.a + params.b;
    // weight += image.rating * params.c;
    // return weight;
}

double compute_quality_by_weight(const Params& params, const Image& image, double weight)
{
    Function func = make_weight_function(params, image);
    func.Invert();
    return func.Apply(weight);

    // double quality = weight;
    // quality -= image.rating * params.c;
    // quality += image.freshness * params.a + params.b;
    // return quality;
}

int main()
{
    return 0;
}
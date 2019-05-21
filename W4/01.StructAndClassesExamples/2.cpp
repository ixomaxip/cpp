#include <iostream>

using namespace std;

struct Image
{
    double quality;
    double freshness;
};

struct Params
{
    double a;
    double b;
};

double cmpute_image_weight(const Params& params, const Image& image)
{
    double weight = image.quality;
    weight -= image.freshness * params.a + params.b;
    return weight;
}


int main()
{
    return 0;
}
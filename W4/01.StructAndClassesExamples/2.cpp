#include <iostream>

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

double compute_image_weight(const Params& params, const Image& image)
{
    double weight = image.quality;
    weight -= image.freshness * params.a + params.b;
    weight += image.rating * params.c;
    return weight;
}

double compute_qaul_by_weight(const Params& params, const Image& image, double weight)
{
    double quality = weight;
    quality += image.freshness * params.a + params.b;
    return quality;
}

int main()
{
    return 0;
}
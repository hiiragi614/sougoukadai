#include <stdio.h>
#include <math.h>

int main()
{
    double a = 1, b = 1e+15, c = 1e+14;
    double x;
    x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    printf("%f\n", x);
    x = (2 * c) / (-b - sqrt(b * b - 4 * a * c));
    printf("%f\n", x);
    return 0;
}
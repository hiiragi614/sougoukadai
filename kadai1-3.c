#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    double b;
    double c;
    double answer1;
    double answer2;

    printf("Type a real number for a: ");
    scanf("%lf", &a);
    printf("Type a real number for b: ");
    scanf("%lf", &b);
    printf("Type a real number for c: ");
    scanf("%lf", &c);
    answer1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    answer2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    printf("%lf, %lf\n", answer1, answer2);
    return 0;
}
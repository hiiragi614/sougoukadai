#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    double b;
    double c;
    double answer1;
    double answer2;
    double imagin;

    printf("Type a real number for a: ");
    scanf("%lf", &a);
    printf("Type a real number for b: ");
    scanf("%lf", &b);
    printf("Type a real number for c: ");
    scanf("%lf", &c);
    if (b * b - 4 * a * c >= 0)
    {
        answer1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        answer2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("%lf, %lf\n", answer1, answer2);
    }
    else
    {
        answer1 = -b / (2 * a);
        imagin = sqrt(-b * b + 4 * a * c) / (2 * a);

        printf("%lf+i%lf, %lf-i%lf\n", answer1, imagin, answer1, imagin);
    }


    return 0;
}
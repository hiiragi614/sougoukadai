#include <stdio.h>
int main()
{
    float a1 = 1, b1 = 1;
    double a2 = 1, b2 = 1;
    long double a3 = 1, b3 = 1;
    for (int i = 1; i < 1e+8;i++){
        a1 += 1e-8;
        a2 += 1e-8;
        a3 += 1e-8;
    }
    b1 += 1e-8 * 1e+8;
    b2 += 1e-8 * 1e+8;
    b3 += 1e-8 * 1e+8;
    printf("a1=%.20f\na2=%.20f\na3=%.20Lf\n", a1, a2, a3);
    printf("b1=%.20f\nb2=%.20f\nb3=%.20Lf\n", b1, b2, b3);
    return 0;
}
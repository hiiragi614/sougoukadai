#include "nn.h"

void print(int m, int n, const float *x)
{
    for (int i = 0; i < m * n; i++)
    {
        if (i % n == 0)
        {
            printf("\n");
        }
        printf("%f ", *(x + i));
    }
}

int main()
{
    float x[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    print(2, 3, x);
    return 0;
}
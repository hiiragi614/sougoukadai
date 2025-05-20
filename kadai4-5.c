#include <stdio.h>

int input()
{
    int input = -1, error_scan;
    do
    {
        printf("n = ");
        error_scan = scanf("%d", &input);
        if (error_scan != 1)
        {
            scanf("%*s");
            printf("Invalid input\n");
        }
        else if (input < 0)
        {
            printf("Invalid input\n");
        }
    } while (input < 0);
    return input;
}

int fact(int input)
{
    int fact = 1;
    for (int i = 1; i < input + 1; i++)
    {
        fact *= i;
    }
    return fact;
}

int perm(int n, int r)
{
    int numerator = fact(n);
    int denominator = fact(n - r);
    return numerator / denominator;
}

int main()
{
    int n = input(), output;
    for (int i = 0; i < n + 1; i++)
    {
        output = perm(n, i);
        printf("perm(%d,%d) = %d\n", n, i, output);
    }

    return 0;
}
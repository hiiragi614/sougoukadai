#include <stdio.h>

int input()
{
    int input, error_scan;
    do
    {
        printf("n = ");
        error_scan = scanf("%d", &input);
        if (error_scan != 1)
        {
            scanf("%*s");
            printf("Invalid input\n");
        }

    } while (error_scan != 1);
    return input;
}

void binary(int n)
{
    printf("%d(10) = ", n);
    for (int i = 32; i > 0; i--)
    {
        printf("%d", (n >> (i - 1)) & 1);
    }
    printf("(2)\n");
}

int main()
{
    int n = input();

    binary(n);
    return 0;
}
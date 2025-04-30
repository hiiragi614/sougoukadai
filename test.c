#include <stdio.h>
int main()
{
    int x;
    x = 10;
    if (x > 0)
    {
        printf("x is positive\n");
    }
    else
    {
        printf("x is negative\n");
        x = -x;
    }
    printf("|x| is %d\n", x);
    return 0;
}
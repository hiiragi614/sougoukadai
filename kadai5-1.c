#include <stdio.h>
int fact(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else if (r == 1)
    {
        return n;
    }
    else
    {
        return fact(n - 1, r - 1) + fact(n - 1, r);
    }
}
int main(void)
{
    int n, r;
    printf("n=");
    scanf("%d", &n);
    printf("r=");
    scanf("%d", &r);
    printf("%d\n", fact(n, r));
    return 0;
}

#include <stdio.h>
int main()
{
    int n = 0;
    int n_fact = 1;

    while (n <= 0)
    {
        printf("自然数を入力してください\n");
        printf("n=");
        scanf("%d", &n);
    }

    while(n>1){
        n_fact *= n;
        n--;
    }
    printf("n!=%d\n", n_fact);
    return 0;
}
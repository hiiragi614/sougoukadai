#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 関数histを自分で作成 */
void hist(int times)
{
    float random_calc[10];
    int x;
    int vmin = 0;
    int vmax = 9;
    double vrange = vmax - vmin + 1;

    for (int i = 0; i < 10; i++)
    {
        random_calc[i] = 0;
    }

    for (int i = 0; i < times; i++)
    {
        srand(time(NULL));
        x = vmin + (int)(rand() * vrange / (1.0 + RAND_MAX));
        random_calc[x]++;
    }

    printf("n=%7d:", times);

    for (int i = 0; i < 10; i++)
    {
        printf("%6.1f", random_calc[i] * 100 / times);
    }
    printf("\n");
}

int main()
{
    hist(100);
    hist(1000);
    hist(10000);
    hist(100000);
    hist(1000000);
    return 0;
}
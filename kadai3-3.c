#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int input;
    int comp;
    srand(time(NULL));

    while (1)
    {
        while (1)
        {
            printf("Your input (0,2,5):");
            scanf("%d", &input);
            if (input != 0 && input != 2 && input != 5)
            {
                printf("Invalid input => Input again.\n");
            }
            else
            {
                break;
            }
        }

        comp = (rand() % 3);
        printf("%d\n", comp);

        if (comp == 1)
            comp = 5;

        printf("Comp:%d vs You:%d", comp, input);
        if (comp == input)
        {
            printf(" => Try again.\n");
            continue;
        }
        else if (input == comp - 2 || input == comp - 3 || input == comp + 5)
        {
            printf(" => You win.\n");
            break;
        }
        else
        {
            printf(" => You lose.\n");
            break;
        }
    }

    return 0;
}
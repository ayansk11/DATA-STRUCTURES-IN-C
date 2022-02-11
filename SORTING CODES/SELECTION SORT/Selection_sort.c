#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[100];
    int s, min, temp;

    printf("ENTER THE SIZE OF THE ARRAY: \n");
    scanf("%d", &s);

    printf("ENTER ELEMENTS IN THE ARRAY: \n");
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("THE ELEMENTS IN THE ARRAY ARE: \n");
    for (int i = 0; i < s; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < s - 1; i++)
    {
        min = i;

        for (int j = i+1; j < s; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    printf("PRINTING THE SORTED ARRAY: \n");
    for (int i = 0; i < s; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
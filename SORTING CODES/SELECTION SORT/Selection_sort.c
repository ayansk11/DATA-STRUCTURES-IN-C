#include <stdio.h>

int arr[100];

void selection_sort(int arr[], int s);

int main(int argc, char const *argv[])
{
    int s;

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

    printf("PERFORMING SELECTION SORT ON THE ARRAY........\n");
    selection_sort(arr, s);

    printf("PRINTING THE SORTED ARRAY: \n");
    for (int i = 0; i < s; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}


void selection_sort(int arr[], int s)
{
    int min, temp;

    for (int i = 0; i < s - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < s; j++)
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
}

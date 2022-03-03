#include <stdio.h>

int arr[100];

void insertion_sort(int arr[], int s);

int main(int argc, char const *argv[])
{
    int currindex = 0, s;

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

    printf("PERFORMING INSERTION SORT ON THE ARRAY....... \n");

    insertion_sort(arr, s);

    printf("PRINTING THE SORTED ARRAY: \n");
    for (int i = 0; i < s; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}


void insertion_sort(int arr[], int s)
{
    int temp, currindex;

    for (int i = 1; i < s; i++)
    {
        currindex = i;

        while (currindex > 0 && arr[currindex] < arr[currindex - 1])
        {
            temp = arr[currindex];
            arr[currindex] = arr[currindex - 1];
            arr[currindex - 1] = temp;

            currindex = currindex - 1;
        }
    }
}

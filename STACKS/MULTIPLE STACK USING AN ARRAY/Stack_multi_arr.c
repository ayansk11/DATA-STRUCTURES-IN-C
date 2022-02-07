#include <stdio.h>
#include <stdlib.h>
# define MAX 10

int st[MAX], topA = -1, topB = MAX;

// THERE ARE TWO STACKS, STACK A AND STACK B IN ARRAY st[MAX]

void pushA(int st[]);
void displayA(int st[]);
int popA(int st[]);

void pushB(int st[]);
void displayB(int st[]);
int popB(int st[]);


int main(int argc, char const *argv[])
{
    int option;

    do
    {
        printf("SELECT AN OPTION FROM THE FOLLOWING:\n");
        printf("1.PUSH IN STACK A\t2.PUSH IN STACK B\n3.POP FROM STACK A\t4.POP FROM STACK B\n5.DISPLAY STACK A\t6.DISPLAY STACK B\n7.EXIT\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            pushA(st);
            break;
        case 2:
            pushB(st);
            break;
        case 3:
            popA(st);
            break;
        case 4:
            popB(st);
            break;
        case 5:
            displayA(st);
            break;
        case 6:
            displayB(st);
            break;
        case 7:
            printf("PROGRAM EXITED SUCCESSFULLY\n");
            break;
        default:
            printf("INVALID OPTION!\nPLEASE SELECT A VALID OPTION\n");
            break;
        }
    } while (option != 7);   

    return 0;
}



void pushA(int st[])
{
    int val;

    if (topA == topB - 1) 
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        printf("ENTER THE ELEMENT YOU WANT TO PUSH INTO STACK A\n");
        scanf("%d", &val);
        
        topA++;
        st[topA] = val;
        printf("ELEMENT %d ADDED SUCCESSFULLY TO STACK A\n", st[topA]);
    }
}



void displayA(int st[])
{
    if (topA == -1)
    {
        printf("STACK A IS EMPTY\n");
    }
    else
    {
        printf("STACK A: ");
        for (int i = topA; i >= 0 ; i--)
        {
            printf("%d\t", st[i]);
        }
        printf("\n");
    }
}



int popA(int st[])
{
    int val;

    if (topA == -1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        val = st[topA];
        topA--;
        printf("ELEMENT %d IS SUCCESSFULLY DELETED FROM STACK A\n", val);
    }  
    return st[topA]; 
}




void pushB(int st[])
{
    int val;

    if (topB - 1 == topA) 
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        printf("ENTER THE ELEMENT YOU WANT TO PUSH STACK B\n");
        scanf("%d", &val);
        
        topB--;
        st[topB] = val;
        printf("ELEMENT %d ADDED SUCCESSFULLY TO STACK B\n", st[topB]);
    }
}



void displayB(int st[])
{
    if (topB == MAX)
    {
        printf("STACK B IS EMPTY\n");
    }
    else
    {
        printf("STACK B: ");
        for (int i = topB; i < MAX ; i++)
        {
            printf("%d\t", st[i]);
        }
        printf("\n");
    }
}



int popB(int st[])
{
    int val;

    if (topB == MAX)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        val = st[topB];
        topB++;
        printf("ELEMENT %d IS SUCCESSFULLY DELETED FROM STACK B\n", val);
    }  
    return st[topB]; 
}
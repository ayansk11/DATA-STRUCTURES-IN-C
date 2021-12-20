#include <stdio.h>
#define max 5

int st[max], top = -1;

void push(int st[]);
void display(int st[]);
int peek(int st[]);
int pop(int st[]);

int main(int argc, char const *argv[])
{
    int option;

    do
    {
        printf("SELECT AN OPTION FROM THE FOLLOWING\n");
        printf("1.PUSH\t2.POP\n3.PEEK\t4.DISPLAY\n5.EXIT\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            push(st);
            break;
        case 2:
            pop(st);
            break;
        case 3:
            peek(st);
            break;
        case 4:
            display(st);
            break;
        case 5:
            printf("PROGRAM EXITED SUCCESSFULLY\n");
            break;
        default:
            printf("SELECT A VALID OPTION\n");
            break;
    }
    } while (option != 5);
    
    return 0;
}

void push(int st[])
{
    int val;

    if (top == max - 1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        printf("ENTER THE ELEMENT YOU WANT TO PUSH INTO THE STACK\n");
        scanf("%d", &val);
        
        top++;
        st[top] = val;
        printf("ELEMENT %d ADDED SUCCESSFULLY TO THE STACK\n", st[top]);
    }
}

void display(int st[])
{
    if (top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        for (int i = top; i >= 0 ; i--)
        {
            printf("%d\t", st[i]);
        }
        printf("\n");
    }
}

int peek()
{
    if (top == -1)
    {
        printf("STACK IS EMPTY\n");
        return -1;
    }
    else
    {
        printf("ELEMENT %d IS THE TOP MOST ELEMENT IN THE STACK\n", st[top]);
        return st[top];
    }
}

int pop()
{
    int val;

    if (top == -1)
    {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        printf("ELEMENT %d IS SUCCESSFULLY DELETED FROM THE STACK\n", val);
        return st[top];
    }   
}
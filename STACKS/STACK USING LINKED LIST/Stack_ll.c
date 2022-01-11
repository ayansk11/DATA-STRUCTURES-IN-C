// STACK USING LINKED LIST

#include <stdlib.h>
#include <stdio.h>

struct stack
{
    struct stack *next;
    int data;
};

struct stack *top = NULL;

struct stack *push(struct stack *top);
struct stack *display(struct stack *top);
struct stack *pop(struct stack *top);
struct stack *peek(struct stack *top);

int main(int argc, char const *argv[])
{
    int option;

    do
    {
        printf("SELECT AN OPTION FROM THE FOLLOWING:\n");
        printf("1.PUSH\t2.POP\n3.PEEK\t4.DISPLAY\n5.EXIT\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            top = push(top);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            top = peek(top);
            break;

        case 4:
            top = display(top);
            break;

        case 5:
            printf("PROGRAM EXITED SUCCESSFULLY\n");
            break;

        default:
            printf("INVALID OPTION!\nPLEASE SELECT A VALID OPTION\n");
            break;
        }
    } while (option != 5);
    
    return 0;
}

struct stack *push(struct stack *top)
{
    struct stack *ptr, *newNode;
    int val;

    printf("ENTER THE DATA YOU WANT PUSH INTO THE STACK: \n");
    scanf("%d", &val);

    newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = val;
   
   if (top == NULL)
   {
       top = newNode;
       newNode->next = NULL;
   }
   else
   {
       newNode->next = top;
       top = newNode;
   }
    printf("%d SUCCESSFULLY PUSHED INTO THE STACK\n", top->data); /* or val or newNode->data*/

    return top;
}



struct stack *display(struct stack *top)
{
    struct stack *ptr;

    if (top == NULL)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        ptr = top;

        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return top;
}



struct stack *pop(struct stack *top)
{
    struct stack *ptr;

    if (top == NULL)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        ptr = top;
        top = ptr->next;
        printf("%d SUCCESSFULLY POPPED OUT OF THE STACK\n", ptr->data);
        free(ptr);
    }
    return top;
}



struct stack *peek(struct stack *top)
{
    if (top == NULL)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        printf("%d IS THE TOP MOST ELEMENT IN THE STACK\n", top->data);
    }
    return top;
}

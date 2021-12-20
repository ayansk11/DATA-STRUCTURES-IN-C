#include <stdio.h>
#define max 5

int queue[max], front = -1, rear = -1;

void insert(int queue[]);
void display(int queue[]);
int peek(int queue[]);
int delete(int queue[]);

int main(int argc, char const *argv[])
{
    int option;

    do
    {
        printf("SELECT AN OPTION FROM THE FOLLOWING\n");
        printf("1.INSERT\t2.DELETE\n3.PEEK\t4.DISPLAY\n5.EXIT\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert(queue);
            break;
        case 2:
            delete(queue);
            break;
        case 3:
            peek(queue);
            break;
        case 4:
            display(queue);
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

void insert(int queue[])
{
    int val;

    printf("ENTER THE ELEMENT YOU WANT TO INSERT IN THE QUEUE\n");
    scanf("%d", &val);

    if (front == max - 1)
    {
        printf("QUEUE OVERFLOW\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
        printf("ELEMENT %d ADDED SUCCESSFULLY ADDED TO THE QUEUE\n", queue[rear]);
    }
    else
    {
        rear++;
        queue[rear] = val;
        printf("ELEMENT %d ADDED SUCCESSFULLY ADDED TO THE QUEUE\n", queue[rear]);
    }
}

void display(int queue[])
{
    if (rear == -1 || front>rear)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int peek(int queue[])
{
    if (rear == -1 || front > rear)
    {
        printf("QUEUE IS EMPTY\n");
        return -1;
    }
    else
    {
        printf("ELEMENT %d IS AT THE BEGINNING OF THE QUEUE\n", queue[front]);
        return queue[front];
    }   
}

int delete(int queue[])
{
    int val;

    if (rear == -1 || front > rear)
    {
        printf("QUEUE UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        printf("ELEMENT %d HAS BEEN SUCCESSFULLY DELETED FROM THE QUEUE\n", val);
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
        return queue[front];
    }
}

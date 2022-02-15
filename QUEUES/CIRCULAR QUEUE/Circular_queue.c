#include <stdio.h>
#define max 10

int queue[max], front = -1, rear = -1;

void insert(int queue[]);
int delete(int queue[]);
int peek(int queue[]);
void display(int queue[]);


int main(int argc, char const *argv[])
{
    int option;

    do
    {
        printf("SELECT AN OPTION FROM THE FOLLOWING\n");
        printf("1.INSERT\t2.DELETE\n3.PEEK\t\t4.DISPLAY\n5.EXIT\n");
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
            printf("INVALID OPTION!\nPLEASE SELECT A VALID OPTION\n");
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

    if (rear = max - 1 && front == 0)
    {
        printf("QUEUE OVERFLOW\n")
    }
    else if (rear == -1 && front == -1)
    {
        rear == front == 0;
        queue[rear] = val;
    }
    else
    {
        if (rear == max -1 && front != 0)
        {
            rear = 0;
            queue[rear] = val;
        }
        else
        {
            rear++;
            queue[rear] = val;
        }
    }
    printf("ELEMENT %d ADDED SUCCESSFULLY ADDED TO THE QUEUE\n", queue[rear]);
}



int delete(int queue[])
{
    int val;

    if(front == -1 && rear == -1)
    {
        printf("QUEUE UNDERFLOW\n");
    }

    val = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == max - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    printf("ELEMENT %d HAS BEEN SUCCESSFULLY DELETED FROM THE QUEUE\n", val);
    
    return queue[front];
}



int peek(int queue[])
{
    if(front == -1 && rear == -1)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("ELEMENT %d IS AT THE BEGINNING OF THE QUEUE\n", queue[front]);
        return queue[front];
    }
}



void display(int queue[])
{
    if (front == -1 && rear == -1)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        if (front > rear)
        {
            for(int i = front; i < max; i++)
            {
                printf("%d\t", queue[i])
            }
            for(int i = 0; i <= rear; i++)
            {
                printf("%d\t", queue[i])
            }
            printf("\n");
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
}




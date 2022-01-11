// QUEUE USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

struct queue *q;

struct queue *create_queue(struct queue *q);
struct queue *insert_queue(struct queue *q);
struct queue *display_queue(struct queue *q);
struct queue *delete_queue(struct queue *q);
struct queue *peek(struct queue *q);


int main(int argc, char const *argv[])
{
    int option;

    q = create_queue(q);

    do
    {
        printf("SELECT AN OPTION FROM THE FOLLOWING:\n");
        printf("1.INSERT\t2.DELETE\n3.PEEK\t\t4.DISPLAY\n5.EXIT\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            q = insert_queue(q);
            break;
        case 2:
            q = delete_queue(q);
            break;
        case 3:
            q = peek(q);
            break;
        case 4:
            q = display_queue(q);
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



struct queue *create_queue(struct queue *q)
{
    q = (struct queue* )malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}


struct queue *insert_queue(struct queue *q)
{
    struct node *ptr;
    int val;

    printf("ENTER THE DATA YOU WANT TO INSERT INTO THE QUEUE: \n");
    scanf("%d", &val);

    ptr = (struct node* )malloc(sizeof(struct node));
    ptr->data = val;

    if (q->front == NULL) 
    {
        ptr->next = NULL;
        q->front = q->rear = ptr;
    }
    else
    {
        ptr->next = NULL;
        q->rear->next = ptr;
        q->rear = ptr;
    }

    printf("%d SUCCESSFULLY INSERTED IN THE QUEUE\n", q->rear->data);  /* or ptr->data */

    return q;
}



struct queue *display_queue(struct queue *q)
{
    struct node *ptr;

    ptr = q->front;

    if (q->front == NULL)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
       while (ptr != NULL)
       {
           printf("%d\t", ptr->data);
           ptr = ptr->next;
       }
       printf("\n");
    }
    return q;
}



struct queue *delete_queue(struct queue *q)
{
    struct node *ptr;

    ptr = q->front;

    if (q->front == NULL)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    {
        q->front = q->front->next;

        printf("%d SUCCESSFULLY DELETED FROM THE QUEUE\n", ptr->data);

        free(ptr);
    }
    return q;
}



struct queue *peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else
    {
        printf("%d IS AT THE BEGINNING OF THE QUEUE\n", q->front->data);
    }
    return q;
}



    /*q = peek(q);
    q = delete_queue(q);
    q = display_queue(q);
    q = insert_queue(q);
    q = insert_queue(q);
    q = insert_queue(q);
    q = insert_queue(q);
    q = peek(q);
    q = display_queue(q);
    q = delete_queue(q);
    q = delete_queue(q);
    q = delete_queue(q);
    q = peek(q);
    q = delete_queue(q);
    q = display_queue(q);
    q = delete_queue(q);
    q = peek(q);*/




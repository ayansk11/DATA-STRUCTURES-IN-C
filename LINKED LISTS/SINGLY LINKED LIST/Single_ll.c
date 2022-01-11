// LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create_ll(struct node *start);
struct node *display(struct node *start);

struct node *insert_beg(struct node *start);
struct node *insert_end(struct node *start);
struct node *insert_before(struct node *start);
struct node *insert_after(struct node *start);

struct node *delete_beg(struct node *start);
struct node *delete_end(struct node *start);
struct node *delete_node(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_list(struct node *start);

struct node *sort_list(struct node *start);


int main(int argc, char const *argv[])
{
    int option;

    do
    {
        printf("1.CREATE LINKED LIST\t2.DISPLAY\n\n3.INSERT BEGINNING\t4.INSERT ENDING\n5.INSERT BEFORE\t\t6.INSERT AFTER\n\n7.DELETE BEGINNING\t8.DELETE ENDING\n9.DELETE NODE\t\t10.DELETE AFTER\n\n11.DELETE LINKED LIST\t12.SORT LIST\n13.EXIT\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            start = create_ll(start);
            break;

        case 2:
            start = display(start);
            break;

        case 3:
            start = insert_beg(start);
            break;

        case 4:
            start = insert_end(start);
            break;

        case 5:
            start = insert_before(start);
            break;

        case 6:
            start = insert_after(start);
            break;

        case 7:
            start = delete_beg(start);
            break;

        case 8:
            start = delete_end(start);
            break;

        case 9:
            start = delete_node(start);
            break;

        case 10:
            start = delete_after(start);
            break;

        case 11:
            start = delete_list(start);
            break;

        case 12:
            start = sort_list(start);
            break;

        case 13:
            printf("PROGRAM EXITED SUCCESSFULLY\n");
            break;

        default:
            printf("INVALID OPTION!\nPLEASE SELECT A VALID OPTION\n");
            break;
        }

    } while (option != 13);
    
    return 0;
}



struct node *create_ll(struct node *start)
{
    struct node *ptr, *newNode;
    int val;

    printf("ENTER DATA TO CREATE A LINKED LIST OR ENTER -1 TO EXIT:\n");
    scanf("%d", &val);

    while (val != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->next = NULL;

        if (start == NULL)
        {
            start = newNode;
        }
        else
        {
            ptr = start;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = newNode;
        }

        printf("ENTER DATA OR ENTER -1 TO EXIT:\n");
        scanf("%d", &val);
    }
    return start;
}



struct node *display(struct node *start)
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        ptr = start;

        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);

            ptr = ptr->next;
        }
        
        printf("\n");
    }
    
    return start;
}



/* struct node *insert_beg(struct node *start)
{
    struct node *ptr, *newNode;
    int val;

    printf("ENTER THE DATA YOU WANT TO ADD AT THE BEGINNING OF THE LIST:\n");
    scanf("%d", &val);

    newNode = (struct node* )malloc(sizeof(struct node));
    newNode->data = val;
    
    ptr = start;
    start = newNode;
    newNode->next = ptr;

    printf("%d SUCCESSFULLY ADDED AT THE BEGINNING OF THE LIST\n", val);      //or  newNode->data

    return start;
}                                    OR   */



struct node *insert_beg(struct node *start)
{
    struct node *newNode; 
    int val;

    printf("ENTER THE DATA YOU WANT TO INSERT AT THE BEGINNING OF THE LIST:\n");
    scanf("%d", &val);

    newNode = (struct node* )malloc(sizeof(struct node));
    newNode->data = val;

    newNode->next = start;
    start = newNode;

    printf("%d SUCCESSFULLY INSERTED AT THE BEGINNING OF THE LIST\n", val);   /*or we can use start->data  or  newNode->data  to print*/

    return start;
}



struct node *insert_end(struct node *start)
{
    struct node *ptr, *newNode;
    int val;

    printf("ENTER THE DATA YOU WANT TO INSERT AT THE END OF THE LIST:\n");
    scanf("%d", &val);

    newNode = (struct node* )malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;

    printf("%d SUCCESSFULLY INSERTED AT THE END OF THE LIST\n", val);    /*or  newNode->data  to print*/

    return start;
}



struct node *insert_before(struct node *start)
{
    struct node *ptr, *preptr, *newNode;
    int val, num;

    printf("ENTER THE NUMBER BEFORE WHICH YOU WANT TO INSERT THE DATA:\n");
    scanf("%d", &num);
    printf("ENTER THE DATA YOU WANT TO INSERT IN THE LIST:\n");
    scanf("%d", &val);

    newNode = (struct node* )malloc(sizeof(struct node));
    newNode->data = val;
    
    ptr = start;
    
    while (ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    preptr->next = newNode;
    newNode->next = ptr;

    printf("%d SUCCESSFULLY INSERTED AT THE END OF THE LIST\n", val);    /*or  newNode->data  to print*/

    return start;
}



struct node *insert_after(struct node *start)
{
    struct node *ptr, *preptr, *newNode;
    int val, num;

    printf("ENTER THE NUMBER AFTER WHICH YOU WANT TO INSERT THE DATA:\n");
    scanf("%d", &num);
    printf("ENTER THE DATA YOU WANT TO INSERT IN THE LIST:\n");
    scanf("%d", &val);

    newNode = (struct node* )malloc(sizeof(struct node));
    newNode->data = val;
    
    ptr = start;
    
    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    
    preptr->next = newNode;
    newNode->next = ptr;

    printf("%d SUCCESSFULLY INSERTED AT THE END OF THE LIST\n", val);    /*or  newNode->data  to print*/

    return start;
}



struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    ptr = start;
    start = ptr->next;   /*  or start = start->next */

    printf("%d SUCCESSFULLY DELETED FROM FROM THE LIST\n", ptr->data);

    free(ptr);

    return start;
}



struct node *delete_end(struct node *start)
{
    struct node *preptr, *ptr;

    ptr = start;
    
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;

    printf("%d SUCCESSFULLY DELETED FROM FROM THE LIST\n", ptr->data);

    free(ptr);

    return start;
}



struct node *delete_node(struct node *start)
{
    struct node *preptr, *ptr;
    int num;

    ptr = start;

    printf("ENTER THE NUMBER WHICH YOU WANT TO DELETE FROM THE LIST:\n");
    scanf("%d", &num);
    
    while (ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    
    printf("%d SUCCESSFULLY DELETED FROM FROM THE LIST\n", ptr->data);

    free(ptr);
    
    return start;
}



struct node *delete_after(struct node *start)    // USING THIS FUCTION INSTEAD TO AVOID SEGMENTATION FAULT 
{
    struct node *preptr, *ptr;
    int num;

    ptr = start;
    preptr = ptr;

    printf("ENTER THE NUMBER AFTER WHICH THE NODE HAS TO BE DELETED FROM THE LIST:\n");
    scanf("%d", &num);

    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("ERROR!!!\n PLEASE SELECT THE DELETE END OPTION TO EXECUTE THIS TASK\n");
    }
    else
    {
        preptr->next = ptr->next;

        printf("%d SUCCESSFULLY DELETED FROM FROM THE LIST\n", ptr->data);

        free(ptr);
    }

    return start;
}



/*struct node *delete_after(struct node *start)
{
    struct node *preptr, *ptr;
    int num;

    ptr = start;
    preptr = ptr;

    printf("ENTER THE NUMBER AFTER WHICH THE NODE HAS TO BE DELETED FROM THE LIST:\n");
    scanf("%d", &num);

    start = display(start);

    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;

    printf("%d SUCCESSFULLY DELETED FROM FROM THE LIST\n", ptr->data);

    free(ptr);

    return start;
}*/



struct node *delete_list(struct node *start)
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("THERE IS NO EXISTING LIST TO DELETE\n");
    }
    else
    {
        ptr = start;

        while (ptr != NULL)
        {
            start = delete_beg(start);
        }
        printf("LIST SUCCESSFULLY DELETED\n");
    }
    return start;
} 



struct node *sort_list(struct node *start)
{
    struct node *preptr, *ptr;
    int temp;

    preptr = start;
    
    while (preptr != NULL)
    {
        ptr = preptr->next;

        while (ptr != NULL)
        {
            if (preptr->data > ptr->data)
            {
                temp = preptr->data;
                preptr->data = ptr->data;
                ptr->data = temp;
            }
            ptr = ptr->next;
        }
        preptr = preptr->next;
    }
    return start;
}

    //start = create_ll(start);
    //start = display(start);
    //start = insert_beg(start);           //for TESTING purpose
    //start = display(start);
    //start = insert_end(start);
    //start = display(start);
    //start = insert_before(start);
    //start = display(start);
    //start = insert_after(start);
    //start = display(start);
    //start = delete_beg(start);
    //start = display(start);
    //start = delete_end(start);
    //start = display(start);
    //start = delete_node(start);
    //start = display(start);
    //start = delete_after(start);
    //start = sort_list(start);
    //start = display(start);
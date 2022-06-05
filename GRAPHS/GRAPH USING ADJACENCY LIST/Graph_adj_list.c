#include <stdio.h>
#include <stdlib.h>

struct node
{
    char vertex;
    struct node *next;
};

void create_graph(struct node *adj[], int no_of_nodes);
void display_graph(struct node *adj[], int no_of_nodes);

int main(int argc, char const *argv[])
{
    struct node *adj[10];
    int no_of_nodes;
    
    printf("\nENTER THE NUMBER OF NODES: ");
    scanf("%d", &no_of_nodes);

    for (int i = 0; i < no_of_nodes; i++)
    {
        adj[i] = NULL;
    }

    create_graph(adj, no_of_nodes);
    display_graph(adj, no_of_nodes);

    return 0;
}


void create_graph(struct node *adj[], int no_of_nodes)
{
    struct node *newNode, *lastNode;
    int no_of_neighbours, val;

    for (int i = 0; i < no_of_nodes; i++)
    {
        lastNode = NULL;

        printf("\nENTER THE NUMBER OF NUMBER OF NEIGHBOURS OF %d: ", i);
        scanf("%d", &no_of_neighbours);

        for (int j = 1; j <= no_of_neighbours; j++)
        {
            printf("\nENTER THE NEIGHBOUR %d of %d: ", j, i);
            scanf("%d", &val);

            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->vertex = val;
            newNode->next = NULL;

            if (adj[i] == NULL)
            {
                adj[i] = newNode;
            }
            else
            {
                lastNode->next = newNode;
            }

            lastNode = newNode;
        }
    }  
}


void display_graph(struct node *adj[], int no_of_nodes)
{
    struct node *ptr;

    for (int i = 0; i < no_of_nodes; i++)
    {
        ptr = adj[i];

        printf("THE NEIGHBOURS OF NODE %d ARE: ", i);

        while (ptr != NULL)
        {
            printf("%d\t", ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
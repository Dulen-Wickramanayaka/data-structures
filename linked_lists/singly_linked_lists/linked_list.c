#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} 
node;

node *make_list(int head); // adding the first node of the list
node *insert_node(int value, node *list); // inserting nodes to the beginning of the list
void print_list(node *list);
void free_list(node *list);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("USAGE ./linked_list ..Space_seperated_numbers");
    }

    node *list = NULL; // initailizing list
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        if (list == NULL) // if list isn't exisitng
        {
            list = make_list(number); // make this node the first 
        }
        else
        {
            list = insert_node(number, list); // making a new head
        }
    }

    print_list(list);
    free_list(list);
}

node *make_list(int head)
{
    node *n = malloc(sizeof(node)); // dynamically allocating memory for current node

    n->value = head;
    n->next = NULL;
    return n;
}

node *insert_node(int value, node *list)
{
    node *n = malloc(sizeof(node));

    n->value = value;
    n->next = list; // adding node beore the current head;

    return n;
}

void print_list(node *list)
{
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void free_list(node *list)
{
    if (list == NULL) return;
    free_list(list->next);
    free(list);
}
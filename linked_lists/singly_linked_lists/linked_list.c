#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} 
node;

node *prepend_node(node *n, node *head); // prepending nodes
node *append_node(node *n, node *head); // appending nodes
node *append_sorted(node *n, node *head);
void print_list(node *head); // printing the list
void free_list(node *head); // free the list

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("USAGE ./linked_list ..Space_seperated_numbers");
        return(1);
    }

    node *list = NULL; // initailizing list
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        // creating the current node
        node *n = malloc(sizeof(node)); // dynamically allocating memory for current node
        if (n == NULL)
        {
            printf("memory allocation failed!");
            return 1;
        }
        n->value = number;
        n->next = NULL;

        list = (list == NULL) ? n : append_sorted(n, list); // if list is empty add node at beginning else add node to the list keeping sorted order
    }

    print_list(list);
    free_list(list);
}

node *prepend_node(node *n, node *head)
{
    if (head != NULL) n->next = head; // adding node beore the current head;

    return n;
}

node *append_node(node *n, node *head)
{
    if (head == NULL)
    {
        return prepend_node(n, head);
    }
    node *ptr = head;
    while(ptr != NULL)
    {
        if(ptr->next == NULL)
        {
            ptr->next = n;
            break;
        }
        ptr = ptr->next;
    }
    return head;
}

node *append_sorted(node *n, node *head)
{
    if (head == NULL || head->value > n->value)
    {
        head = prepend_node(n, head); // if list is empty or curren node is smaller than first adding it to the beginning
    }
    else 
    {
        node *ptr = head;
        while(ptr != NULL) // looping through the list
        {
            if(ptr->next == NULL) // if at end add node here
            {
                ptr->next = n;
                break;
            }
            else if(ptr->next->value > n->value) // if next value is smaller than current add node here
            {
                n->next = ptr->next;
                ptr->next = n;
                break;
            }
            ptr = ptr->next; // incrementing the traversal ppointer
        }
    }
    return head;
}

void print_list(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%i ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void free_list(node *head)
{
    if (head == NULL) return;
    free_list(head->next);
    free(head);
}
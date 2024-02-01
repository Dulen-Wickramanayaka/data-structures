#include <stdio.h>
#include <stdlib.h>

typedef struct node // node for the doubly linked list
{
    int value;
    struct node *prev;
    struct node *next;
}
node;

// return value of these functions are the new head of the list
node *prepend_node (node *head, node *n);
node *append_node(node *head, node *n);
node *append_sorted(node *head, node *n);

void print_list(node *head);
void free_list(node *head);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("USAGE ./linked_list ..Space_seperated_numbers\n");
        return(1);
    }

    node *list = NULL; // initailizing list(pointer to the head)
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
        n->prev = NULL;
        n->next = NULL;

        list = append_sorted(list, n); // if list is empty add node at beginning else add node to the list keeping sorted order
    }

    print_list(list);

    free_list(list);
}

node *prepend_node (node *head, node *n) 
{
    if (head == NULL) return n;
    n->next = head;
    head->prev = n; // fixing the prev pointer of the old head
    head = n; // make new node the new head
    return head;
}

node *append_node (node *head, node *n)
{
    if (head == NULL) return n;
    node *ptr = head; // declaration of traversal pointer
    while (ptr != NULL)
    {
        if (ptr->next == NULL) 
        {
            ptr->next = n; // making new node the last node
            n->prev = ptr; // fixing the new node's prev to point to previous last node
            break;
        }
        ptr = ptr->next;
    }
    return head;
}

node *append_sorted(node *head, node *n)
{
    if (head == NULL || head->value > n->value) 
    {
        return prepend_node(head, n);
    }

    node *ptr = head;
    while (ptr != NULL)
    {
        // Check if we reached the end of the list or found the position to insert.
        if (ptr->next == NULL || ptr->next->value > n->value)
        {
            // Inserting at the end or in the middle of the list.
            n->next = ptr->next; // This might be NULL if it's the end of the list.
            if (ptr->next != NULL) 
            {
                ptr->next->prev = n; // Fixing the next node's prev pointer if not inserting at the end.
            }
            ptr->next = n; // Linking current node to new node.
            n->prev = ptr; // Linking new node back to current node.
            return head; // The head doesn't change in this operation.
        }
        ptr = ptr->next;
    }

    // This return statement should not be reached due to the logic covering all cases above.
    return head;
}


void print_list(node *head)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        printf("%i ",ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void free_list(node *head)
{
    node *ptr = head;
    while(ptr != NULL)
    {
        node *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}

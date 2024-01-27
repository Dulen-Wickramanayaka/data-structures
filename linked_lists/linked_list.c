/*
Topic : Linked list in C
Author: DUlen Wickramanayaka
Date: 1/26/2024
Description: simple algorithm to make a linked list in c
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
typedef struct node {
    int number;         // Value of the node
    struct node *next;  // Pointer to the next node
} node;

// Function prototypes
void print_list(node *list);
void free_list(node *list);

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        printf("USAGE: ./linked_list <space-separated numbers>\n");
        return 1;
    }

    node *list = NULL; // Pointer to the first element in the list

    // Iterate over command line arguments
    for (int i = 1; i < argc; i++) 
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node)); // Allocate memory for new node
        if (n == NULL) 
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        n->number = number; // Set node's value
        n->next = NULL; // Initialize next pointer to NULL

        if (list == NULL) 
        {
            // If list is empty, set new node as the first node
            list = n;
        }
        else if (list->number > number) // if number is smaller than the first element adding the current node to beginning
        {
            n->next = list;
            list = n;
        }
        else
        {
            node *ptr = list;
            while(ptr != NULL)
            {
                // if at the end add node to end
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
                // if next nord's number is smaller add node before it
                if (ptr->next->number > number) // if next nodes number is bigger than number
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }

    print_list(list);
    free_list(list);
    return 0;
}

// Print all elements in the linked list
void print_list(node *list) 
{
    for (node *ptr = list; ptr != NULL; ptr = ptr->next) 
    {
        printf("%i  ", ptr->number);
    }
    printf("\n");
}

// Free the memory allocated for the linked list
void free_list(node *list) 
{
    while (list != NULL) 
    {
        node *temp = list->next;
        free(list);
        list = temp;
    }
}

/*
Topic : Linked list in C
Author: DUlen Wickramanayaka
Date: 1/26/2024
Description: simple algorithm to make a linked list in c
*/

#include <stdio.h>
#include <stdlib.h>

// idea of the linked list is that it is made of an structure called node and each node points to the next node in the list like they are waved together
// not like array(in arrays each elemets are stored back to back to back) these node are not stored contiguesly(they are at random memmory locations) that's why pointer to the next node is needed
//advantage of linked list is that no matter howmany elements are in the array while there are more memmory you can insert to anlinked list with constatnt number of steps which is scientifically O{n}

// defining node
// node has two fields as number(wich is the value) and the next(which is the pointer to the next node)
typedef struct node 
{
    int number;
    struct node *next;
}
node;

void print_list(node *list);
void free_list(node *list);

int main(int argc, char *argv[])
{
    if (argc < 2) 
    {
        printf("USAGE : ./linked_list ....space separeted array\n");
        return 1;
    }
    node *list = NULL; //pointer to the first element in the list
    for (int i = 1; i < argc; i++)
    {
        node *n = malloc(sizeof(node)); // current node
        //error handling
        if (n == NULL)
        {
            printf("memory allocation failed");
            return 1;
        }

        n->number = atoi(argv[i]); // making the number field in current node equal to the number in the current position of array
        //as argv is an array of strings we have to convert that string to int for that atoi(ascii to interger) function is used

        n->next = list; // setting the next field to points to previous node which is previously the first elemet(list is the pointer to the first element)

        list = n; // making the pointer list to point to the current node as it is the first element now
    }
    print_list(list);
    free_list(list);
}

// printing the number field of each node
void print_list(node *list)
{
    // idea here is the while pointer is not NULL(pointer becomes null when at the end of the array las elemets next field is null) print the number field of the node pointed by pointer
    node *ptr = list;
    while(ptr != NULL)
    {
        printf("%i  ",ptr->number);
        ptr = ptr->next;
    }
    printf("\n");

}

//freeing the allocated memory for each node
void free_list(node *list)
{
    node *ptr = list;
    while (ptr != NULL)
    {
        node *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}
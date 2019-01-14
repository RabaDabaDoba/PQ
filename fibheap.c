#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* parent;
    struct node* child;
    struct node* left;
    struct node* right;
    int data;
    int priority;
} node;

// Creating min pointer as "mini"
struct node* mini = NULL;

// Declare an integer for number of nodes in the heap
int no_of_nodes = 0;

// Function to insert a node in heap
void insertion(int val)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->priority = val;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if (mini != NULL) {
        (mini->left)->right = new_node;
        new_node->right = mini;
        new_node->left = mini->left;
        mini->left = new_node;
        if (new_node->priority < mini->priority)
            mini = new_node;
    }
    else {
        mini = new_node;
    }
}

// Function to display the heap
void display(struct node* mini)
{
    node* ptr = mini;
    if (ptr == NULL)
        printf("The Heap is Empty\n");

    else {
        printf("The root nodes of Heap are: \n");
        do {
            printf("%d", ptr->priority);
            //cout << ptr->key;
            ptr = ptr->right;
            if (ptr != mini) {
                printf("-->");
            }
        } while (ptr != mini && ptr->right != NULL);
        printf("\n");
              printf("The heap has %d nodes\n", no_of_nodes);
    }
}
// Function to find min node in the heap
void find_min(struct node* mini)
{
    printf("min of heap is %d\n", mini->priority);
}


// Driver code
int main()
{

    no_of_nodes = 10;
    insertion(4);
    insertion(3);
    insertion(7);
    insertion(5);
    insertion(2);
    insertion(1);
    insertion(10);
    insertion(5);
    insertion(2);
    insertion(1);
    display(mini);

    find_min(mini);

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* parent;
    struct node* child;
    struct node* left;
    struct node* right;
    int key;
} node;

// Creating min pointer as "mini"
struct node* mini = NULL;

// Declare an integer for number of nodes in the heap
int no_of_nodes = 0;

// Function to insert a node in heap
void insertion(int val)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = val;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if (mini != NULL) {
        (mini->left)->right = new_node;
        new_node->right = mini;
        new_node->left = mini->left;
        mini->left = new_node;
        if (new_node->key < mini->key)
            mini = new_node;
    }
    else {
        mini = new_node;
    }
}

// Function to display the heap
void display(struct node* mini)
{
    node* ptr = mini;
    if (ptr == NULL)
        printf("The Heap is Empty\n");

    else {
        printf("The root nodes of Heap are: \n");
        do {
            printf("%d", ptr->key);
            //cout << ptr->key;
            ptr = ptr->right;
            if (ptr != mini) {
                printf("-->");
            }
        } while (ptr != mini && ptr->right != NULL);
        printf("\n");
              printf("The heap has %d nodes\n", no_of_nodes);
    }
}
// Function to find min node in the heap
void find_min(struct node* mini)
{
    printf("min of heap is %d\n", mini->key);
}


// Driver code
int main()
{

    no_of_nodes = 7;
    insertion(4);
    insertion(3);
    insertion(7);
    insertion(5);
    insertion(2);
    insertion(1);
    insertion(10);

    display(mini);

    find_min(mini);

    return 0;
}
*/

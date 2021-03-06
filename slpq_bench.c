#include <stdio.h>
#include <stdlib.h>
#include "random.c"
#include <sys/time.h>



typedef struct node {
    int data;
    int priority;
    struct node* next;
} Node;


// Function to Create A New Node
Node *createNode(int data, int priority)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

// Return the value at head
int peek(Node** head)
{
    return (*head)->data;
}

// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}


// Function to push according to priority
void push(Node** head, int d, int p)
{
    Node* start = (*head);

    // Create new Node
    Node* temp = createNode(d, p);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > p) {

        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->priority < p) {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check is list is empty
int isEmpty(Node** head)
{
    return (*head) == NULL;
}

int main(int itterations, int max_data, int max_priority)
{
  Node* pq = createNode(randint(10), randint(10));

  for (size_t i = 0; i < 10000; i++) {

      push(&pq, randint(10), randint(10));

  }

  clock_t start = clock();
  while (!isEmpty(&pq)) {

      pop(&pq);
  }
  clock_t end = clock();
  printf("ticks it took: %ld\n", end-start);
  return 0;
}

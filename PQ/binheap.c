#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int priority;
} Node;

//Node heap =


Node *createNode(int data, int priority)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->priority = priority;
    return node;
}

void push(Node** head, int d, int p)
{
    Node* start = (*head);

    // Create new Node
    Node* temp = createNode(d, p);

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



int main(int argc, char **argv) {
	Node* pq = createNode(4, 1);
}

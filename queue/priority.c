#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;

    int priority;

    struct node* next;

} Node;

Node* newNode(int d, int p)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

int peek(Node** head)
{
    return (*head)->data;
}

void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node** head, int d, int p)
{
    Node* start = (*head);

    Node* temp = newNode(d, p);

    if ((*head)->priority > p) {

        temp->next = *head;
        (*head) = temp;
    }
    else {

        while (start->next != NULL &&
            start->next->priority < p) {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(Node** head)
{
    return (*head) == NULL;
}

int main()
{
    // Create a Priority Queue
    // 70->40->50->60
    Node* pq = newNode(40, 3);
    push(&pq, 50, 1);
    push(&pq, 60, 1);
    push(&pq, 70, 2);

    while (!isEmpty(&pq)) {
        printf("%d ", peek(&pq));
        pop(&pq);
    }

    return 0;
}
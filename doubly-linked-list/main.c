/*
    * Author: Matheus de Sousa Almeida
    * Let's Study the essential Doubly Linked List Functions Together! *

    1) Traversal:
        i) Traversal;
        ii) Searching;
        iii) Length.
    2) Insertion:
        i) Insert at the beginning;
        ii) Insert at the end;
        iii) Insert at the end with tail;
        iv) Insert at a specific position;
        v) Insert in Order.
    3) Deletion:
        i) Delete from the beginning;
        ii) Delete from the end;
        iii) Delete a specific node.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {;
    int data;
    struct node * prev;
    struct node * next;
} Node;

void transversal_dl(Node ** head);
Node * search_dl(Node ** head, int data);
int lenght_dl(Node ** head);

Node * insert_beginning_dl(Node ** head, Node ** tail, int data);
Node * insert_end_dl(Node **head, Node **tail, int data);
Node * tail_insert_end_dl(Node **head, Node ** tail, int data);
Node * insert_specific_position_dl(Node ** head, Node ** tail, int data, int position);

int main() {
    Node * head = NULL;
    Node * tail = NULL;

    insert_beginning_dl(&head, &tail, 13);
    insert_beginning_dl(&head, &tail, 23);
    //insert_end_dl(&head, &tail, 15);
    //tail_insert_end_dl(&head, &tail, 300);
    insert_specific_position_dl(&head, &tail, 100, 2);

    transversal_dl(&head);

    printf("Node founded data = %d\n", search_dl(&head, 13)->data);
    printf("Doubly Linked List Lenght = %d", lenght_dl(&head));

    return 0;
}

void transversal_dl(Node ** head) {
    Node * headSupport = *head;

    int counter = 1;
    while (headSupport != NULL) {
        printf("Node (%d) = %d\n", counter, headSupport->data);

        headSupport = headSupport->next;
        counter++;
    }
}

Node * search_dl(Node ** head, int data) {
    Node * headSupport = *head;

    while (headSupport->data != data && headSupport != NULL) {
        headSupport = headSupport->next;
    }

    return  headSupport ;
}

int lenght_dl(Node ** head) {
    if (*head == NULL) {
        return 0;
    }

    Node * headSupport = *head;
    int counter = 0;

    while (headSupport  != NULL) {
        headSupport = headSupport->next;

        counter++;
    }

    return  counter;
}

Node * insert_beginning_dl(Node ** head, Node ** tail, int data) {
    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->data = data;

    if(*head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;

        return newNode;
    }

    (*head)->prev = newNode;
    newNode->next = *head;
    newNode->prev = NULL;

    *tail = *head;
    *head = newNode;

    return newNode;
}

Node * insert_end_dl(Node **head, Node **tail, int data) {
    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->data = data;

    if(*head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;

        return newNode;
    }

    Node *headTemporary = *head;
    while(headTemporary->next != NULL) {
        headTemporary = headTemporary->next;
    }

    headTemporary->next = newNode;
    newNode->prev = headTemporary;
    newNode->next = NULL;

    *tail = newNode;

    return newNode;
}

Node * tail_insert_end_dl(Node **head, Node ** tail, int data) {
    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->data = data;

    if(*head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        *head = newNode;
        *tail = newNode;

        return newNode;
    }

    Node * lastTail = *tail;
    *tail = newNode;
    lastTail->next = *tail;
    (*tail)->prev = lastTail;
    (*tail)->next = NULL;


    return newNode;
}

Node * insert_specific_position_dl(Node ** head, Node ** tail, int data, int position) {
    if(position < 1 ) {
        return NULL;
    }

    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->data = data;

    if(position == 1 && *head != NULL) {
        newNode->prev = NULL;
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;

        return newNode;
    }

    if(position == 1) {
        newNode->prev = NULL;
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        *tail = newNode;

        return newNode;
    }

    Node *headTemporary = *head;
    int positionCounter = 1;
    while(positionCounter < position - 1 && headTemporary != NULL) {
        headTemporary = headTemporary->next;

        positionCounter++;
    }

    if(headTemporary == NULL) {
        return NULL;
    }

    newNode->next = headTemporary->next;
    headTemporary->next = newNode;
    newNode->prev = headTemporary;

    if (newNode->next != NULL) {
        newNode->next->prev= newNode;
    }

    return newNode;
}
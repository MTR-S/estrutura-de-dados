/*
    * Author: Matheus de Sousa Almeida
    * Let's Study the essential Singly Linked List Functions Together! *

    1) Traversal:
        i) Traversal;
        ii) Searching;
        iii) Length.
    2) Insertion:
        i) Insert at the beginning;
        ii) Insert at the end;
        iii) Insert at a specific position;
        iv) Insert in Order.
    3) Deletion:
        i) Delete from the beginning;
        ii) Delete from the end;
        iii) Delete a specific node.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * nextNode;
}Node;

Node * insert_beginning(Node ** head, int value);
Node * insert_end(Node ** head, int value);
Node * insert_specific_position(Node ** head, int value, int position);
Node * insert_in_order(Node ** head, int value);

int main() {
    Node * head = NULL;

    insert_beginning(&head, 1);
    insert_beginning(&head, 2);


    printf("Valor = %d", (insert_end(&head, 0))->value);

    insert_specific_position(&head, 3, 5);

    insert_in_order(&head, -1);
}

Node * insert_beginning(Node ** head, int value) {
    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->nextNode = *head;
    newNode->value = value;

    *head = newNode;

    return newNode;
}

Node * insert_end(Node ** head, int value) {
    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->value = value;

    if(*head == NULL) {
        newNode->nextNode = *head;

        *head = newNode;
    }

    Node * headTemporary = *head;

    while(headTemporary->nextNode != NULL) {
        headTemporary = headTemporary->nextNode;
    }

    headTemporary->nextNode = newNode;
    newNode->nextNode = NULL;

    return newNode;
}

Node * insert_specific_position(Node ** head, int value, int position) {
    if(position < 1) {
        return NULL;
    }

    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->value = value;

    if(position == 1) {
        newNode->nextNode = *head;
        *head = newNode;

        return newNode;
    }

    Node * headTemporary = *head;
    int positionCounter = 1;
    while(positionCounter < position - 1 && headTemporary != NULL) {
        headTemporary = headTemporary->nextNode;

        positionCounter++;
    }

    if(headTemporary == NULL) {
        return NULL;
    }

    newNode->nextNode = headTemporary->nextNode;
    headTemporary->nextNode = newNode;

    return newNode;
}

Node * insert_in_order(Node ** head, int value) {
    Node * newNode = (Node *) malloc(sizeof(typeof(Node)));

    if(newNode == NULL) {
        return NULL;
    }

    newNode->value = value;

    if(*head == NULL || (*head)->value < value) {
        newNode->nextNode = *head;
        *head = newNode;

        return newNode;
    }

    Node * headTemporary = *head;
    while(headTemporary->nextNode != NULL && headTemporary->nextNode->value > value) {
        headTemporary = headTemporary->nextNode;
    }

    Node * headAssistant = headTemporary->nextNode;
    headTemporary->nextNode = newNode;
    newNode->nextNode = headAssistant;

    return newNode;
}

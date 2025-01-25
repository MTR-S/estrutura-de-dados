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

#include "singly-linked-list.h"

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

int traversal(Node ** head) {
    Node * headTemporary = *head;

    int nodePosition = 1;
    while(headTemporary != NULL) {
        printf("(%d) Node value = %d\n", nodePosition, headTemporary->value);

        headTemporary = headTemporary->nextNode;
        nodePosition++;
    }

    return nodePosition;
}

Node * searching(Node ** head, int value) {
    Node * headTemporary = *head;

    while(headTemporary != NULL && headTemporary->value != value) {
        headTemporary = headTemporary->nextNode;
    }

    return headTemporary;
}

int lenght(Node **head) {
    int lenghtCounter = 0;
    Node * headTemporary = *head;

    while(headTemporary != NULL) {
        headTemporary = headTemporary->nextNode;

        lenghtCounter++;
    }

    return lenghtCounter;
}

Node * delete_beginning(Node ** head) {
    if(*head == NULL) {
        return NULL;
    }

    Node * headTemporary = *head;
    *head = (*head)->nextNode;

    free(headTemporary);

    return *head;
}

Node * delete_end(Node ** head) {
    if(*head == NULL) {
        return NULL;
    }

    if((*head)->nextNode == NULL) {
        free(*head);
        *head = NULL;

        return NULL;
    }

    Node * headTemporary = *head;
    while(headTemporary->nextNode->nextNode != NULL) {
        headTemporary = headTemporary->nextNode;
    }

    free(headTemporary->nextNode);
    headTemporary->nextNode = NULL;

    return *head;
}

Node * delete_specific_node(Node ** head, int value) {
    if(*head == NULL) {
        return NULL;
    }

    if((*head)->value == value) {
        free(*head);
        *head = NULL;

        return *head;
    }

    Node * headTemporary = *head;
    while(headTemporary->nextNode->value != value && headTemporary->nextNode->nextNode != NULL) {
        headTemporary = headTemporary->nextNode;
    }

    if(headTemporary->nextNode->nextNode == NULL) {
        return NULL;
    }

    Node * storeDeletedNode = headTemporary->nextNode;
    headTemporary->nextNode = headTemporary->nextNode->nextNode;

    free(storeDeletedNode);

    return *head;
}
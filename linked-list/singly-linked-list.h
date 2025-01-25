/*
    * Created by Casa on 25/01/2025.
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

#ifndef ESTRUTURA_DE_DADOS_SINGLY_LINKED_LIST_H

#define ESTRUTURA_DE_DADOS_SINGLY_LINKED_LIST_H

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

int traversal(Node ** head);
Node * searching(Node ** head, int value);
int lenght(Node **head);

Node * delete_beginning(Node ** head);
Node * delete_end(Node ** head);
Node * delete_specific_node(Node ** head, int value);

#endif

//ESTRUTURA_DE_DADOS_SINGLY_LINKED_LIST_H
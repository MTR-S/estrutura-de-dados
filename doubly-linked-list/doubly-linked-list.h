//
// Created by Casa on 05/02/2025.
//

#ifndef ESTRUTURA_DE_DADOS_DOUBLY_LINKED_LIST_H
#define ESTRUTURA_DE_DADOS_DOUBLY_LINKED_LIST_H

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

Node * delete_beginning_dl(Node **head, Node ** tail);
Node * delete_end_dl(Node **head, Node ** tail);
Node * tail_delete_end_dl(Node **head, Node ** tail);
Node * delete_specific_node_dl(Node **head, Node ** tail, int data);

#endif

//ESTRUTURA_DE_DADOS_DOUBLY_LINKED_LIST_H

//
// Created by Casa on 05/02/2025.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} Node;

Node * create_tree(int root_data);

Node * inorder_traversal(Node * root);
Node * preOrder_traversal(Node * root);
Node * postOrder_traversal(Node * root);

Node * insert_child(Node * root, int data);

Node * search_child(Node * root, int data);

Node * delete_child(Node * root, int data);



int main() {
    Node * root = create_tree(70);
    root = insert_child(root, 50);
    root = insert_child(root, 50);
    root = insert_child(root, 76);
    root = insert_child(root, 83);
    root = insert_child(root, 81);
    root = insert_child(root, 84);



    printf("Tree Inorder: ");
    inorder_traversal(root);

    printf("\nTree Pre-order: ");
    preOrder_traversal(root);

    printf("\nTree Pos-order: ");
    postOrder_traversal(root);

    int dataToSearch = 76;
    Node * nodeToFound = search_child(root, dataToSearch);
    if(nodeToFound != NULL) {
        printf("\nNode founded: %d", nodeToFound->data);
    } else {
        printf("\nNode not founded");
    }

    delete_child(root, 80);
    printf("\nTree Inorder: ");
    inorder_traversal(root);

    return 0;
}

Node * create_tree(int root_data) {
    Node * root = (Node *) malloc(sizeof(typeof(Node)));

    root->data = root_data;
    root->right = NULL;
    root->left= NULL;

    return root;
}

Node * inorder_traversal(Node * root) {
    if(root == NULL) {
        return NULL;
    }

    inorder_traversal(root->left);

    printf("%d ", root->data);

    inorder_traversal(root->right);

    return root;
}

Node * preOrder_traversal(Node * root) {
    if(root == NULL) {
        return NULL;
    }

    printf("%d ", root->data);

    preOrder_traversal(root->left);
    preOrder_traversal(root->right);

    return root;
}

Node * postOrder_traversal(Node * root) {
    if(root == NULL) {
        return NULL;
    }

    preOrder_traversal(root->left);
    preOrder_traversal(root->right);

    printf("%d ", root->data);

    return root;
}

Node * insert_child(Node * root, int data) {
    if(root == NULL) {
        Node * newChild = (Node *) malloc(sizeof(typeof(Node)));
        if(newChild == NULL) {
            return NULL;
        }

        newChild->data = data;
        newChild->right = NULL;
        newChild->left = NULL;

        return newChild;
    }

    if(data < root->data) {
        root->left = insert_child(root->left, data);
    }

    if(data > root->data) {
        root->right = insert_child(root->right, data);
    }

    return root;
}

Node * search_child(Node * root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }

    if(data < root->data) {
        return search_child(root->left, data);
    }

    if(data > root->data) {
        return search_child(root->right, data);
    }

    return root;
}

Node * delete_child(Node * root, int data) {
    if(root == NULL) {
        return NULL;
    }

    if(data < root->data) {
        root->left = delete_child(root->left, data);
    }
    else if(data > root->data) {
        root->right = delete_child(root->right, data);
    }

    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL ) {
            Node * nodeTemporary = root->right;
            free(root);
            return nodeTemporary;
        }
        else if(root->right == NULL) {
            Node * nodeTemporary = root->left;
            free(root);
            return nodeTemporary;
        }
        else {
            Node * nodeTemporary = root->right;
            while(nodeTemporary->left != NULL) {
                nodeTemporary = nodeTemporary->left;
            }

            root->data = nodeTemporary->data;
            root->right = delete_child(root->right, nodeTemporary->data);
        }
    }

    return root;
}
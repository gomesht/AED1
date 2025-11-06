#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *new_node(int value);
Node *insert(Node *root, int value);
void printPre(Node *root);
void printIn(Node *root);
void printPos(Node *root);
void delete_tree(Node *root);

int main() {
    int C, cases, N, i, number;
   
    if (scanf("%d", &C) != 1) return 1;

    for (cases = 1; cases <= C; cases++) {
      
        if (scanf("%d", &N) != 1) return 1;

        Node *root = NULL;

        for (i = 0; i < N; i++) {
            if (scanf("%d", &number) != 1) {
                delete_tree(root);
                return 1;
            }
            root = insert(root, number);
        }

        printf("Case %d:\n", cases);

        printf("Pre.:");
        printPre(root);
        printf("\n");
       
        printf("In.:");
        printIn(root);
        printf("\n");

        printf("Post.:");
        printPos(root);
        printf("\n");

        delete_tree(root);
    }

    return 0;
}
Node *new_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        exit(1);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insert(Node *root, int value) {
    if (root == NULL) {
        return new_node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    }
  
    else { 
        root->right = insert(root->right, value);
    }
    return root;
}

void delete_tree(Node *root) {
    if (root == NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

void printPre(Node *root) {
    if (root != NULL) {
        printf(" %d", root->value);
        printPre(root->left);
        printPre(root->right);
    }
}

void printIn(Node *root) {
    if (root != NULL) {
        printIn(root->left);
        printf(" %d", root->value);
        printIn(root->right);
    }
}

void printPos(Node *root) {
    if (root != NULL) {
        printPos(root->left);
        printPos(root->right);
        printf(" %d", root->value);
    }
}
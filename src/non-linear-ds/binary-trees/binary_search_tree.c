#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LIST_EMPTY INT_MIN

typedef struct BST {
    struct Node {
        int data;
        struct Node *left, *right;
    } * root;
    int size, height;
} * bst;

typedef struct Node* node;

node node_constructor(int data) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bst bst_constructor() {
    bst newBST = (bst)malloc(sizeof(struct BST));
    newBST->size = newBST->height = 0;
    newBST->root = NULL;
    return newBST;
}

bool is_empty(bst tree) {
    return tree->size == 0;
}

int get_size(bst tree) {
    return tree->size;
}

int get_height(bst tree) {
    return tree->height;
}

int get_root(bst tree) {
    return tree->root->data;
}

node add(node root, int elem) {
    if (root == NULL) {
        root = node_constructor(elem);
    } else if (elem < root->data) {
        root->left = add(root->left, elem);
    } else if (elem > root->data) {
        root->right = add(root->right, elem);
    }
    return root;
}

void in_order_traversal(node root) {
    if (root != NULL) {
        in_order_traversal(root->left);
        printf("%d ", root->data);
        in_order_traversal(root->right);
    }
}

void pre_order_traversal(node root) {
    if (root != NULL) {
        printf("%d ", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void post_order_traversal(node root) {
    if (root != NULL) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ", root->data);
    }
}

int main(int argc, char const* argv[]) {
    bst tree = bst_constructor();
    tree->root = add(tree->root, 5);
    tree->root = add(tree->root, 1);
    tree->root = add(tree->root, 8);
    tree->root = add(tree->root, 6);
    tree->root = add(tree->root, 3);
    pre_order_traversal(tree->root);
    return 0;
}

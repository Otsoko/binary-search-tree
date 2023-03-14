#include "binary_search_tree.h"
#include <stdio.h>

#define DISTANCE 8

typedef struct data {
    int  number;
    char character;
} data_t;

void inorderTraversal(node_t *node);
void preorderTraversal(node_t *node);
void postorderTraversal(node_t *node);

void bstPrintTraversal(node_t *node, int space);
void bstPrint(node_t *root);

int main(int argc, char const *argv[]) {
    binary_search_tree_t bst;
    data_t               data;
    node_t              *node;

    return 0;
}

void inorderTraversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    data_t *data = node->data;
    printf("[%d, %c] ", data->number, data->character);
    inorderTraversal(node->right);
}

void preorderTraversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    data_t *data = node->data;
    printf("[%d, %c] ", data->number, data->character);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    data_t *data = node->data;
    printf("[%d, %c] ", data->number, data->character);
}

void bstPrintTraversal(node_t *node, int space) {
    data_t *data = NULL;

    if (node == NULL)
        return;

    space += DISTANCE;

    bstPrintTraversal(node->right, space);

    printf("\n");
    for (int i = DISTANCE; i < space; i++) {
        printf(" ");
    }
    data = node->data;
    printf("[%d, %c] ", data->number, data->character);

    bstPrintTraversal(node->left, space);
}

void bstPrint(node_t *root) {
    bstPrintTraversal(root, 0);
}
#include "binary_search_tree.h"
#include <stdio.h>
#include <time.h>

#define DISTANCE 8
#define MIN_RAND 0
#define MAX_RAND 100
#define MIN_ASCII 65
#define MAX_ASCII 123

typedef struct data {
    int  number;
    char character;
} data_t;

void inorderTraversal(node_t *node);
void preorderTraversal(node_t *node);
void postorderTraversal(node_t *node);

void bstPrintTraversal(node_t *node, int space);
void bstPrint(node_t *root);

int comparator(const void *a, const void *b);

int main(int argc, char const *argv[]) {
    binary_search_tree_t bst;
    data_t               data;

    bst_init(&bst, sizeof(data_t));

    data.character = 'a';

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        data.number    = (rand() % (MAX_RAND - MIN_RAND)) + MIN_RAND;
        data.character = (rand() % (MAX_ASCII - MIN_ASCII)) + MIN_ASCII;
        bst_insert(&bst, &data, comparator);
    }

    data.number    = 33;
    data.character = 'X';
    bst_insert(&bst, &data, comparator);

    for (int i = 0; i < 5; i++) {
        data.number    = (rand() % (MAX_RAND - MIN_RAND)) + MIN_RAND;
        data.character = (rand() % (MAX_ASCII - MIN_ASCII)) + MIN_ASCII;
        bst_insert(&bst, &data, comparator);
    }

    printf("Length: %ld\n", bst.length);
    printf("Tree view\n");
    bstPrint(bst.root);
    printf("\n");

    printf("Inorder\n");
    inorderTraversal(bst.root);
    printf("\n\nPreorder\n");
    preorderTraversal(bst.root);
    printf("\n\nPostorder\n");
    postorderTraversal(bst.root);
    printf("\n");

    data.number    = 33;
    data.character = 'X';
    bst_delete(&bst, &data, comparator);

    printf("Length: %ld\n", bst.length);
    printf("Tree view\n");
    bstPrint(bst.root);
    printf("\n");

    printf("Inorder\n");
    inorderTraversal(bst.root);
    printf("\n\nPreorder\n");
    preorderTraversal(bst.root);
    printf("\n\nPostorder\n");
    postorderTraversal(bst.root);
    printf("\n");

    bst_destroy(&bst);
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

int comparator(const void *a, const void *b) {
    const data_t *da = a;
    const data_t *db = b;
    return da->number - db->number;
}
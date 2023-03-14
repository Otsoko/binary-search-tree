#include "binary_search_tree.h"
#include <string.h>

int (*bst_cmp_fptr)(const void *, const void *) = NULL;

void bst_init(binary_search_tree_t *tree, size_t element_size) {
    tree->root         = NULL;
    tree->length       = 0;
    tree->element_size = element_size;
}

void bst_destroy(binary_search_tree_t *tree) {
    bst_destroy_traversal(tree->root);
    tree->root         = NULL;
    tree->length       = 0;
    tree->element_size = 0;
}

void bst_destroy_traversal(node_t *node) {
    if (node == NULL) {
        return;
    }
    bst_destroy_traversal(node->left);
    bst_destroy_traversal(node->right);
    free(node->data);
    free(node);
}

node_t *bst_create_node(binary_search_tree_t *tree, void *data) {
    node_t *new = malloc(sizeof(node_t));

    if (!new) {
        return NULL;
    }

    new->data = malloc(tree->element_size);

    if (!new->data) {
        free(new);
        return NULL;
    }

    memcpy(new->data, data, tree->element_size);
    new->left  = NULL;
    new->right = NULL;

    return new;
}

node_t *bst_insert(binary_search_tree_t *tree, void *data) {
    return bst_insert_traversal(tree, tree->root, data);
}

node_t *bst_insert_traversal(binary_search_tree_t *tree, node_t *node, void *data) {
    if (node == NULL) {
        return bst_create_node(tree, data);
    }

    if (bst_cmp_fptr(data, node->data) < 0) {
        node->left = bst_insert_traversal(tree, node->left, data);
    } else {
        node->right = bst_insert_traversal(tree, node->right, data);
    }

    return node;
}
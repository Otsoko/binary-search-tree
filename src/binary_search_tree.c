#include "binary_search_tree.h"
#include <string.h>

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

node_t *bst_insert(binary_search_tree_t *tree, void *data, int (*bst_cmp_fptr)(const void *a, const void *b)) {
    return bst_insert_traversal(tree, &(tree->root), data, bst_cmp_fptr);
}

node_t *bst_insert_traversal(binary_search_tree_t *tree, node_t **node, void *data, int (*bst_cmp_fptr)(const void *a, const void *b)) {
    if (*node == NULL) {
        *node = bst_create_node(tree, data);
        tree->length++;
        return *node;
    }

    if (bst_cmp_fptr(data, (*node)->data) < 0) {
        (*node)->left = bst_insert_traversal(tree, &(*node)->left, data, bst_cmp_fptr);
    } else if (bst_cmp_fptr(data, (*node)->data) > 0) {
        (*node)->right = bst_insert_traversal(tree, &(*node)->right, data, bst_cmp_fptr);
    } else {
        // Element already exists
    }

    return *node;
}

node_t *bst_inorder_successor(node_t *node) {
    node_t *current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

node_t *bst_delete(binary_search_tree_t *tree, void *data, int (*bst_cmp_fptr)(const void *a, const void *b)) {
    return bst_delete_traversal(tree, tree->root, data, bst_cmp_fptr);
}

node_t *bst_delete_traversal(binary_search_tree_t *tree, node_t *node, void *data, int (*bst_cmp_fptr)(const void *a, const void *b)) {
    if (node == NULL) {
        return node;
    }

    if (bst_cmp_fptr(data, node->data) < 0) {
        node->left = bst_delete_traversal(tree, node->left, data, bst_cmp_fptr);
    } else if (bst_cmp_fptr(data, node->data) > 0) {
        node->right = bst_delete_traversal(tree, node->right, data, bst_cmp_fptr);
    } else {
        tree->length--;
        if (node->left == NULL) {
            node_t *temp = node->right;
            free(node->data);
            free(node);
            return temp;
        } else if (node->right == NULL) {
            node_t *temp = node->left;
            free(node->data);
            free(node);
            return temp;
        }

        node_t *temp = bst_inorder_successor(node->right);
        memcpy(node->data, temp->data, sizeof(data));
        node->right = bst_delete_traversal(tree, node->right, temp->data, bst_cmp_fptr);
    }

    return node;
}
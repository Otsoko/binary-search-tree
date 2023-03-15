#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <stdlib.h>

typedef struct node {
    void        *data;
    struct node *left;
    struct node *right;
} node_t;

typedef struct {
    node_t *root;
    size_t  length;
    size_t  element_size;
} binary_search_tree_t;

void    bst_init(binary_search_tree_t *tree, size_t element_size);
void    bst_destroy(binary_search_tree_t *tree);
void    bst_destroy_traversal(node_t *node);
node_t *bst_create_node(binary_search_tree_t *tree, void *data);
node_t *bst_insert(binary_search_tree_t *tree, void *data, int (*bst_cmp_fptr)(const void *a, const void *b));
node_t *bst_insert_traversal(binary_search_tree_t *tree, node_t **node, void *data, int (*bst_cmp_fptr)(const void *a, const void *b));

#endif // __BINARY_SEARCH_TREE_H__
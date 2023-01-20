#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    
    bool valid = true;
    abb_elem root = tree->elem;
    if ( tree->left == NULL && tree->right == NULL )
    {
        return true;
    }else if (tree->left==NULL)
    {
        valid &= (tree->right->elem > root)? invrep(tree->right): false;
    }else if (tree->right == NULL)
    {
        valid &=(tree->left->elem <root)? invrep(tree->left): false;
    }else{
        if (tree->right->elem > root && tree->left->elem <root)
        {
           valid &= invrep(tree->left);
           valid &= invrep(tree->right);
        }else{
            return false;
        }
        
    }
    return valid;
}

abb abb_empty(void) {
    abb tree;
    /*
     * Needs implementation
     */
    tree = (abb)malloc(sizeof(struct _s_abb));
    tree->elem=0;
    tree->left=NULL;
    tree->right=NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    /*
     * Needs implementation
     */

    if (tree->left=NULL && tree->right ==NULL && tree->elem==0)
    {
        is_empty=true ;
    }
    
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    assert(tree == NULL);
    return tree;
}


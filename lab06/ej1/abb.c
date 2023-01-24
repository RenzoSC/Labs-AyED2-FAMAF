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
    if (tree ==NULL)
    {
        return true;
    }
    abb_elem root = tree->elem;
    if ( (tree->left == NULL && tree->right == NULL))
    {
        return true;
    }else if (tree->left==NULL)
    {
        valid &= (tree->right->elem >= root)? invrep(tree->right): false;
    }else if (tree->right == NULL)
    {
        valid &=(tree->left->elem <root)? invrep(tree->left): false;
    }else{
        if (tree->right->elem >= root && tree->left->elem <root)
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
    abb tree = (abb)malloc(sizeof(struct _s_abb));
    tree->elem=0;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb nodo = (abb)malloc(sizeof(struct _s_abb));
    nodo->elem = e;
    nodo->left= NULL;
    nodo->right=NULL;
    /*
     * Needs implementation
     */
    bool nonstop =true;
    if (abb_is_empty(tree))
    {
        return nodo;
    }else{
        abb p = tree;
        while (nonstop)
        {
            if (elem_less(e,p->elem) && p->left!=NULL)
            {
                p= p->left;
            }
            else if (elem_less(p->elem,e) && p->right!=NULL)
            {
                p=p->right;
            }
            else
            {
                nonstop=false;
            }
            
        }
        if (elem_less(e, p->elem))
        {
            p->left = nodo;
        }else if(elem_less(p->elem, e) || elem_eq(e, p->elem)){
            p->right = nodo;
        }
        
        
    }
    assert(invrep(tree) && abb_exists(tree, e));                  //should work, except to the first condition...
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    if (tree->elem==0 && tree->left==NULL && tree->right==NULL)
    {
        return true;
    }
    
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    /*
    * Needs implementation
    */
    if (tree->elem < e && tree->right !=NULL)
    {
        exists = abb_exists(tree->right, e);
    }else if(tree->elem >e && tree->left !=NULL){
        exists = abb_exists(tree->left, e);
    }else if (tree->elem == e)
    {
        return true;
    }
    

    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    if (tree->left !=NULL)
    {
        length += 1+ abb_length(tree->left);
    }
    if (tree->right !=NULL)
    {
        length += 1+ abb_length(tree->right); 
    }

    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    /*
     * Needs implementation
     */
    if(abb_exists(tree, e)){
        bool no_stop = true;
        abb p = tree;
        while (no_stop)
        {
            if (elem_less(e, p->elem))
            {
                p = p->left;
            }else if(elem_less(p->elem, e)){
                p = p->right;
            }else{
                no_stop = false;
            }
        }
        if (p->left ==NULL && p->right == NULL)
        {
            p=NULL;
        }
        if (p->left!=NULL)
        {
            p->elem = abb_max(p->left);
            p->left = abb_remove(p->left,p->elem);
        }else{
            p->elem = abb_min(p->right);
            p->right = abb_remove(p->right,p->elem);
        }

    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    root = tree->elem;

    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    abb flag = tree;
    while (flag->right != NULL)
    {

        max_e = flag->right;
        flag = flag->right;
    }
    
    assert(invrep(tree) && abb_exists(tree, max_e->elem));
    return max_e->elem;
}

abb_elem abb_min(abb tree) {
    abb min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    abb flag = tree;
    while (flag->left != NULL)
    {

        min_e = flag->left;
        flag = flag->left;
    }
    assert(invrep(tree) && abb_exists(tree, min_e->elem));
    return min_e->elem;
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
    free(tree);
    tree->right = NULL;
    tree->left = NULL;
    tree->elem = 0;
    tree = NULL;
    assert(tree == NULL);
    return tree;
}


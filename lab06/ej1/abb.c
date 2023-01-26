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
    return NULL;
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
    if (tree==NULL)
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
    if (tree==NULL)
    {
        return false;
    } else if(tree->elem < e && tree->right !=NULL)
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
    if (tree->left == NULL && tree->right ==NULL)
    {
        return 1;
    }
    
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
    abb p= tree;
    abb parent = NULL;
    while (no_stop)
    {
        if (elem_less(e, p->elem))
        {
            parent = p;
            p = p->left;
        }else if(elem_less(p->elem, e)){
            parent = p;
            p = p->right;
        }else{
            no_stop = false;
        }
    } //busca el elemento a eliminar

    if (p->left ==NULL && p->right == NULL) //caso en el que es una hoja
    {
        if(parent != NULL){
            if(parent->left == p) parent->left = NULL;
            else parent->right = NULL;
        }
        p=abb_destroy(p);
        return tree;    
    }else if(p->left==NULL){ 
        p->elem = p->right->elem;
            p->left = p->right->left;
            p->right = p->right->right;
            abb_destroy(p->right);
            return tree;  
    }else if(p->right ==NULL){                        //caso en el que solo tiene hoja izquierda
        p->elem = p->left->elem;
            p->right = p->left->right;
            p->left = p->left->left;
            abb_destroy(p->left);
            return tree; 
    }else{                                            //caso en el que tiene dos hojas
        p->elem = abb_max(p->left);
        p->left = abb_remove(p->left,p->left->elem);
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
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    abb flag = tree;
    if(flag->right ==NULL){
        return flag->elem;
    }else{
        while (flag->right != NULL)
        {

            flag = flag->right;
        }
    }
    
    assert(invrep(tree) && abb_exists(tree, flag->elem));
    return flag->elem;
}

abb_elem abb_min(abb tree) {
    assert(invrep(tree) && !abb_is_empty(tree));
    /*
     * Needs implementation
     */
    abb flag = tree;
    if (flag->left ==NULL)
    {
        return flag->elem;
    }else{
        while (flag->left != NULL)
        {

            flag = flag->left;
        }
    }
    
    assert(invrep(tree) && abb_exists(tree, flag->elem));
    return flag->elem;
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
    if (tree == NULL) {
        return NULL;
    }
    tree->left=abb_destroy(tree->left);
    tree->right= abb_destroy(tree->right);
    free(tree);
    tree=NULL;
    
    return tree;
}


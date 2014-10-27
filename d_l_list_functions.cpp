#include <stdio.h>
#include <stdlib.h>

#include "d_l_list_functions.h"

int list_ctor (List* L) {

    L->first = (element*) calloc (1, sizeof(element*));
    L->last = (element*) calloc (1, sizeof(element*));

    if ((L->first == 0) || (L->last == 0)) {
        free(L->first);
        free(L->last);
        return ERR_MEM;
    }

    L->first->nxt = L->last;
    L->first->prvs = 0;


    L->last->prvs = L->first;
    L->last->nxt = 0;

    L->ptr = L->first;

    return OK;
}
//============================================================================

//============================================================================
int inp_prvs (List* L, data_t value) {

    if (L->ptr == 0)
        return SPOILT;

    if (L->ptr->prvs == 0)
        return ERR_ACCESS;

    element* buf = L->ptr->prvs;
    L->ptr->prvs = (element*) calloc (1, sizeof(element*));

    if (L->ptr->prvs == 0) {
        free(L->ptr->prvs);
        return ERR_MEM;
    }

    L->ptr->prvs->prvs = buf;
    L->ptr->prvs->nxt = L->ptr;
    buf->nxt = L->ptr->prvs;

    //Assign value
    L->ptr->prvs->data = value;

    return OK;
}
//============================================================================

//============================================================================
int inp_nxt (List* L, data_t value) {

    if (L->ptr == 0)
        return SPOILT;

    if (L->ptr->nxt == 0)
        return ERR_ACCESS;

    element* buf = L->ptr->nxt;
    L->ptr->nxt = (element*) calloc (1, sizeof(element*));

    if (L->ptr->nxt == 0) {
        free(L->ptr->nxt);
        return ERR_MEM;
    }

    L->ptr->nxt->nxt = buf;
    L->ptr->nxt->prvs = L->ptr;
    buf->prvs = L->ptr->nxt;
    //Assign value
    L->ptr->nxt->data = value;
    return OK;
}
//============================================================================

//============================================================================
int extract (List* L, data_t* value) {

    if (L->ptr == 0)
        return SPOILT;

    if ((L->ptr == L->first) || (L->ptr == L->last))
        return ERR_ACCESS;

    if (L->ptr->prvs == 0)
        return SPOILT;

    *value = L->ptr->data;
    L->ptr->nxt->prvs = L->ptr->prvs;
    L->ptr->prvs->nxt = L->ptr->nxt;

    L->ptr = L->ptr->prvs;

    return OK;

}
//============================================================================

//============================================================================
int shft_ptr_nxt (List* L) {

    if (L->ptr->nxt == 0)
        return EMPTY_LINK;
    if (L->ptr == 0)
        return SPOILT;

    L->ptr = L->ptr->nxt;
    return OK;
}
//============================================================================

//============================================================================
int shft_ptr_prvs (List* L) {

    if (L->ptr->prvs == 0)
        return EMPTY_LINK;
    if (L->ptr == 0)
        return SPOILT;

    L->ptr = L->ptr->prvs;
    return OK;
}
//============================================================================

//============================================================================
int shft_to_first (List* L) {

    if (L->first == 0)
        return SPOILT;

    L->ptr = L->first;
    return OK;
}
//============================================================================

//============================================================================
int shft_to_last (List* L) {

    if (L->last == 0)
        return SPOILT;

    L->ptr = L->last;
    return OK;
}
//============================================================================

//============================================================================
int check_empty (List* L) {

    if (L->first->nxt == L->last)
        return EMPTY;

        return NOT_EMPTY;
}
//============================================================================

//============================================================================
void list_dtor (List* L) {
    L->ptr = L->first;

    while ((L->ptr->nxt != L->last) && (L->ptr->nxt != 0)) {
        shft_ptr_nxt(L);
        if (L->ptr->prvs != L->first)
            free(L->ptr->prvs);
    }

    L->first = 0;
    L->last = 0;
    return;
}
//=============================================================================



#include <stdio.h>
#include <stdlib.h>

#include "d_l_list_functions.h"

int main() {
    List L;
    list_ctor(&L);
    double res = 0;

    printf("%ld - CURRENT\n", L.ptr);
    printf("%ld - FIRST\n", L.first);
    printf("%ld - LAST\n", L.last);

    inp_prvs(&L, 13.2);
    my_perror(list_errno);

    inp_nxt(&L, 13.2);
    printf("%ld - NEW\n", L.ptr);
    printf("%ld - NEW\n", L.ptr->nxt);
    shft_ptr_nxt(&L);
    printf("%ld - NEW\n", L.ptr);

    extract(&L, &res);
    printf("%ld - NEW\n", L.ptr);
    printf("%lg\n", res);
    my_perror(list_errno);//ok

    extract(&L, &res);
    printf("%ld - FIRST\n", L.ptr);
    printf("%lg\n", res);
    my_perror(list_errno);

    shft_to_last(&L);

    extract(&L, &res);
    printf("%ld - LAST\n", L.ptr);
    printf("%lg\n", res);
    my_perror(list_errno);

    list_dtor(&L);

    return 0;
}

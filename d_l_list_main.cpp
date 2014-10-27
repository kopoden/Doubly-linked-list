#include <stdio.h>
#include <stdlib.h>

#include "d_l_list_functions.h"

int main() {
    List L;
    list_ctor(&L);

    printf("%ld - CURRENT\n", L.ptr);
    printf("%ld - FIRST\n", L.first);
    printf("%ld - LAST\n", L.last);

    inp_nxt(&L, 13.2);
    printf("%lg\n", L.ptr->nxt->data);

    for (long int i = 0; i < 1024*1024*1024/24; i++) { //1GB
        if (inp_nxt(&L, 13.2) != OK) {
            printf("ERR_MEM\n");
            break;
        }
    }
    printf("FIRST END\n");

    for (long int i = 0; i < 1024*1024*1024/24; i++) { //2GB
        if (inp_nxt(&L, 13.2) != OK) {
            printf("ERR_MEM\n");
            break;
        }
    }
    printf("SECOND END\n");

    list_dtor(&L);

    return 0;
}

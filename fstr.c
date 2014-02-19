#include "fstr.h"
#include <stdlib.h>
#include <string.h>

struct fStr {
    unsigned int    len;
    unsigned int    size;
    char*           data;
};

unsigned int next_p2(unsigned int num) {
    unsigned int n = 2;
    for ( ; n<num ; ) {
        n <<= 1;
    }
    return n;
}

unsigned int get_alloced_size(unsigned int size) {
    if ( size > 1024*1024 ) {
        return (size/(1024*1024)+1)*(1024*1024);
    }else {
        return next_p2(size);
    }
}

struct fStr* fstr_create(char* cstr, unsigned int len) {
    struct fStr* fstr = (struct fStr*)malloc(sizeof(struct fStr));
    fstr->len   = len;
    fstr->size  = get_alloced_size(len+1);
    fstr->data  = (char*)malloc(sizeof(char)*fstr->size);
    memcpy(fstr->data, cstr, fstr->len);
    fstr->data[fstr->len] = 0;
    return fstr;
}


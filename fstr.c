#include "fstr.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct fStr {
    unsigned int    len;
    unsigned int    size;
    char*           data;
};

static unsigned int next_p2_(unsigned int num) {
    unsigned int n = 2;
    for ( ; n<num ; ) {
        n <<= 1;
    }
    return n;
}

static unsigned int get_alloced_size_(unsigned int size) {
    if ( size > 1024*1024 ) {
        return (size/(1024*1024)+1)*(1024*1024);
    }else {
        return next_p2_(size);
    }
}

struct fStr* fstr_create(char* cstr, unsigned int len) {
    struct fStr* fstr = (struct fStr*)malloc(sizeof(struct fStr));
    assert(fstr);
    if ( cstr ) {
        fstr->len   = len;
        fstr->size  = get_alloced_size_(len+1);
        fstr->data  = (char*)malloc(sizeof(char)*fstr->size);
        assert(fstr->data);
        memcpy(fstr->data, cstr, fstr->len);
    }else {
        fstr->len   = 0;
        fstr->size  = get_alloced_size_(len);
        fstr->data  = (char*)malloc(sizeof(char)*fstr->size);
        assert(fstr->data);
    }
    fstr->data[fstr->len] = 0;
    return fstr;
}

void fstr_release(struct fStr* fstr) {
    free(fstr->data);
    free(fstr);
}

struct fStr* fstr_copy(struct fStr* fstr) {
    struct fStr* new_fstr = (struct fStr*)malloc(sizeof(struct fStr));
    assert(new_fstr);
    new_fstr->len   = fstr->len;
    new_fstr->size  = get_alloced_size_(fstr->len+1);
    new_fstr->data  = (char*)malloc(sizeof(char)*new_fstr->size);
    assert(new_fstr->data);
    memcpy(new_fstr->data, fstr->data, fstr->len);
    new_fstr->data[new_fstr->len] = 0;
    return new_fstr;
}

struct fStr* fstr_resize(struct fStr* fstr, unsigned int new_size) {
    if ( fstr->size > new_size ) {
        fstr->len = new_size;
        fstr->data[fstr->len] = 0;
    }else {
        fstr->size = get_alloced_size_(new_size);
        char* new_data = (char*)realloc(fstr->data, sizeof(char)*fstr->size);
        assert(new_data);
        fstr->data = new_data;
        fstr->data[fstr->len] = 0;
    }
    return fstr;
}

unsigned int fstr_len(struct fStr* fstr) {
    return fstr->len;
}

struct fStr* fstr_append(struct fStr* fstr, char* cstr, unsigned int len) {
    if ( fstr->len+len+1 > fstr->size ) {
        fstr_resize(fstr, fstr->len+len+1);
    }
    memcpy(&fstr->data[fstr->len], cstr, len);
    fstr->len += len;
    fstr->data[fstr->len] = 0;
    return fstr;
}

char* fstr_to_cstr(struct fStr* fstr) {
    return fstr->data;
}


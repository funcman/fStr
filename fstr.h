#ifndef FSTR_H
#define FSTR_H

struct fStr;

struct fStr*    fstr_create(char* cstr, unsigned int len);
void            fstr_release(struct fStr* fstr);
struct fStr*    fstr_copy(struct fStr* fstr);
unsigned int    fstr_len(struct fStr* fstr);
struct fStr*    fstr_append(struct fStr* fstr, char* cstr, unsigned int len);
char*           fstr_to_cstr(struct fStr* fstr);

#endif//FSTR_H


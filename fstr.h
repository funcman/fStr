#ifndef FSTR_H
#define FSTR_H

#ifdef __cplusplus
extern "C" {
#endif

struct fStr;

struct fStr*    fstr_create(char* cstr, unsigned int len);
void            fstr_release(struct fStr* fstr);
struct fStr*    fstr_copy(struct fStr* fstr);
struct fStr*    fstr_resize(struct fStr* fstr, unsigned int new_size);
unsigned int    fstr_len(struct fStr* fstr);
struct fStr*    fstr_append(struct fStr* fstr, char* cstr, unsigned int len);
char*           fstr_to_cstr(struct fStr* fstr);

#ifdef __cplusplus
}
#endif

#endif//FSTR_H


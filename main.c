#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
    char *array;
    size_t len;
    size_t cap;
} string;

string *new() {
    string *s = (string *) malloc(sizeof(string));
    if(s == NULL) {
        fprintf(stderr, "malloc err\n");
        return NULL;
    }

    s->array = strdup("");
    if(s->array == NULL) {
        fprintf(stderr, "strdup err\n");
        return NULL;
    }

    s->len = strlen(s->array);
    s->cap = s->len + 1;

    return s;
}

string *from(char *str) {
    if(str == NULL) {
        fprintf(stderr, "str is NULL\n");
        return NULL;
    }

    string *s = (string *) malloc(sizeof(string));
    if(s == NULL) {
        fprintf(stderr, "malloc err\n");
        return NULL;
    }

    s->array = strdup(str);
    if(s->array == NULL) {
        fprintf(stderr, "strdup err\n");
        return NULL;
    }

    s->len = strlen(s->array);
    s->cap = s->len + 1;

    return s;
}

void destroy(string *s) {
    free(s->array);
    free(s);
}

int main() {
    string *s = from("Hello, World!");
    printf("%s\n", s->array);

    destroy(s);

    return 0;
}

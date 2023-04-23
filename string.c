#include "string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для создания новой пустой строки
string *new() {
    // Выделение памяти под структуру
    string *s = (string *) malloc(sizeof(string));
    if(s == NULL) {
        fprintf(stderr, "malloc err\n");
        return NULL;
    }

    // Копирование пустой строки в массив
    s->array = strdup("");
    if(s->array == NULL) {
        fprintf(stderr, "strdup err\n");
        return NULL;
    }

    // Установка длины и емкости
    s->len = strlen(s->array);
    s->cap = s->len + 1;

    return s;
}

// Функция для создания новой строки из существующей
string *from(char *src) {
    // Проверка на нулевой указатель
    if(src == NULL) {
        fprintf(stderr, "str is NULL\n");
        return NULL;
    }

    // Выделение памяти под структуру
    string *s = (string *) malloc(sizeof(string));
    if(s == NULL) {
        fprintf(stderr, "malloc err\n");
        return NULL;
    }

    // Копирование существующей строки в массив
    s->array = strdup(src);
    if(s->array == NULL) {
        fprintf(stderr, "strdup err\n");
        return NULL;
    }

    // Установка длины и емкости
    s->len = strlen(s->array);
    s->cap = s->len + 1;

    return s;
}

string *cat()

// Функция для освобождения памяти из строки
void destroy(string *src) {
    free(src->array);
    free(src);
}

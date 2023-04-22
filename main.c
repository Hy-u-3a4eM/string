#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определение структуры для представления строки
typedef struct string {
    char *array; // Указатель на массив символов
    size_t len; // Длина строки
    size_t cap; // Емкость массива
} string;

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
string *from(char *str) {
    // Проверка на нулевой указатель
    if(str == NULL) {
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
    s->array = strdup(str);
    if(s->array == NULL) {
        fprintf(stderr, "strdup err\n");
        return NULL;
    }

    // Установка длины и емкости
    s->len = strlen(s->array);
    s->cap = s->len + 1;

    return s;
}

// Функция для освобождения памяти из строки
void destroy(string *s) {
    free(s->array);
    free(s);
}

int main() {
    // Создание строки из литерала
    string *s = from("Hello, World!");

    // Вывод строки на экран
    printf("%s\n", s->array);

    // Освобождение памяти из строки
    destroy(s);

    return 0;
}

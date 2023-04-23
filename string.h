//
// Created by gsult on 23.04.2023.
//

#ifndef STRING_H
#define STRING_H

#include <corecrt.h>

// Определение структуры для представления строки
typedef struct string {
    char *array; // Указатель на массив символов
    size_t len; // Длина строки
    size_t cap; // Емкость массива
} string;

string *new();
string *from(char *src);
string *cat();
void destroy(string *src);

#endif //STRING_H

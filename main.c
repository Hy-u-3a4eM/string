#include <stdio.h>
#include "string.h"

int main() {
    // Создание строки из литерала
    string *s = from("Hello, World!");

    // Вывод строки на экран
    printf("%s\n", s->array);

    // Освобождение памяти из строки
    destroy(s);

    return 0;
}

#include <stdio.h>

#define STLEN 81

int main(void)
{
    char words[STLEN];

    puts("Введите строку: ");
    gets(words);

    printf("Ваша строка, выведенная дважды:\n");

    puts(words);
    printf("%s", words);
    puts("Готово!");

    return 0;
}
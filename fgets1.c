#include <stdio.h>

#define STLEN 15

int main(void)
{
    char words[STLEN];

    puts("Введите строку:");
    fgets(words, STLEN, stdin);
    printf("Ваша строка, выведенная дважды (1 - puts(), 2 - fputs()):\n");
    puts(words);
    fputs(words, stdout);

    puts("Введите еще одну строку");
    fgets(words, STLEN, stdin);
    printf("Ваша строка, выведенная дважды (1 - puts(), 2 - fputs()):\n");
    puts(words);
    fputs(words, stdout);
    printf("Готово.");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX];
    char name[MAX];
    char *ptr;

    puts("Введите название для файла, в котором вы можете хранить слова");
    puts("(если вы уже создали такой файл, введите его название):");
    fgets(name, MAX, stdin);

    ptr = strchr(name, '\n');
    if (ptr != 0)
    {
        *ptr = '\0';
    }

    if ((fp = fopen(name, "a+")) == NULL)
    {
        fprintf(stderr, " Не удается открыть файл \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }

    printf("Введите слова для добавления в файл %s.\n", name);
    puts("Для завершения введите символ \"#\" в начале строки.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
    {
        fprintf(fp, "%s\n", words);
    }

    printf("Содержимое файла %s:\n", name);
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
    {
        puts(words);
    }

    puts("Готово!");
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Ошибка при закрытии файла wordy\n");
    }

    return 0;
}
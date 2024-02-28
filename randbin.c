#include <stdio.h>
#include <stdlib.h>

#define ARSIZE 1000

int main(void)
{
    double numbers[ARSIZE];
    double value;
    const char *file = "numsdoub.dat";
    int i;
    long pos;
    FILE *iofile;

    for (i = 0; i < ARSIZE; i++)
    {
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    }
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Не удается открыть файл %s для вывода.\n", file);
        exit(EXIT_FAILURE);
    }

    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);

    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr,
                "Не удается открыть файл %s для произвольного доступа.\n", file);
        exit(EXIT_FAILURE);
    }

    printf("Введите индекс в диапозоне от 0 до %d:\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE - 1)
    {
        pos = (long)i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("По этому индексу находится значение %f.\n", value);
        puts("Введите следующий индекс(или значение за пределами диапазона для завершения):");
    }
    fclose(iofile);
    puts("Программа завершена");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 40;
const char *pcg = "Строковый литерал";

int main(void)
{
    int auto_store = 40;
    char auto_string[] = "Автоматический массив char";
    int *pi;
    char *pcl;

    pi = (int *)malloc(sizeof(int));
    *pi = 35;
    pcl = (char *)malloc(strlen("Динамическая строка") + 1);
    strcpy(pcl, "Динамическая строка");

    printf("   static_store: %d адрес %p\n", static_store, &static_store);
    printf("   auto_store: %d адрес %p\n", auto_store, &auto_store);

    printf("    *pi: %d адрес %p\n", *pi, pi);

    printf("  %s; адрес %p\n", auto_string, auto_string);
    printf("  %s; адрес %p\n", pcl, pcl);
    printf("  %s; адрес %p\n", "Строка", "Строка");

    free(pi);
    free(pcl);
}
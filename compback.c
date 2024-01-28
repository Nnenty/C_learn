#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("strcmp(\"A\", \"A\")В возвращает %d\n",
           strcmp("A", "A"));
    printf("strcmp(\"A\", \"B\") возвращает %d\n",
           strcmp("A", "B"));
    printf("strcmp(\"B\", \"A\") возвращает %d\n",
           strcmp("B", "A"));
    printf("strcmp(\"C\", \"A\") возвращает %d\n",
           strcmp("C", "A"));
    printf("strcmp (\"Z\",\"a\") возвращает %d\n",
           strcmp("Z", "a"));
    printf("strcmp (\"apples\", \"apple\") возвращает %d\n",
           strcmp("apples", "apple"));

    return 0;
}
#include <stdio.h>
#include <string.h>

#define LISTSIZE 6

int main(void)
{
    const char *list[LISTSIZE] =
        {
            "astronomia", "astatism",
            "astrophysics", "ostracism",
            "asterism", "astrolabe"};
    int count = 0;
    int i;

    for (i = 0; i < LISTSIZE; i++)
    {
        if (strncmp(list[i], "astro", 5) == 0)
        {
            printf("Found: %s\n", list[i]);
            count++;
        }
    }
    printf("Words with \"astro\": %d", count);

    return 0;
}
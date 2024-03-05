#include <stdio.h>

#define LEN 100

struct names
{
    char first[LEN];
    char last[LEN];
};
struct guy
{
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2] =
        {
            {.handle = {.first = "Билли", .last = "Бонс"},
             .favfood = "запеченными омарами",
             .job = "персональный тренер",
             .income = 68112.00},
            {.handle = {.first = "Джим", .last = "Хокинс"},
             .favfood = "рыбным фрикасе",
             .job = "редактор таблоида",
             .income = 232400.00}};
    struct guy *him;

    printf("адрес #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("указатель #1: %p #2: %p\n", him, him + 1);
    printf("him -> income равно $%.2f: (*him).income равно $%.2f\n",
           him->income, (*him).income);
    him++;
    printf("him -> favfood равно %s: him -> handle.last равно %s\n",
           him->favfood, him->handle.last);

    return 0;
}
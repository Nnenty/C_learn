#include <stdio.h>

#define MAXTITL 100
#define MAXAUTL 100

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book readfirst;
    int score;

    puts("Введите рейтинг книг до 100:");
    scanf("%d", &score);

    if (score >= 84)
    {
        readfirst = (struct book){
            .author = "Федор Достоевский",
            .title = "Преступление и наказание",
            .value = 11.25};
    }
    else
    {
        readfirst = (struct book){
            .author = "Фред Уинсон",
            .title = "Красивая шляпа мистера Баунси",
            .value = 5.99};
    }
    puts("Назначенные вами рейтинги:");
    printf("\"%s\": %s ($%.2f)\n", readfirst.title, readfirst.author,
           readfirst.value);
}
#include <stdio.h>

#define FUNDLEN 50
struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds *);
int main(void)
{
    struct funds stan =
        {
            .bank = "Tincoffe",
            .bankfund = 4032.27,
            .save = "Otvetch'ayu",
            .savefund = 8543.94};
    printf("Общая сумма на счетах $%.2f.\n", sum(&stan));

    return 0;
}
double sum(const struct funds *money)
{
    return (money->bankfund + (*money).savefund);
}
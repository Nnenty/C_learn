#include <stdio.h>

#define FUNDLEN 50
#define N 2

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds money[], int n);

int main(void)
{
    struct funds jones[N] =
        {
            {.bank = "Tincoffe",
             .bankfund = 4032.27,
             .save = "Otvecha'u",
             .savefund = 8543.94},

            {.bank = "Sberbank",
             .bankfund = 3620.88,
             .save = "Otvecha'u!",
             .savefund = 3802.91}};
    printf("Общая сумма на счету составляет $%.2f.\n",
           sum(jones, N));

    return 0;
}
double sum(const struct funds money[], int n)
{
    double total;
    int i;

    for (i = 0, total = 0; i < n; i++)
    {
        total += money[i].bankfund + money[i].savefund;
    }

    return total;
}
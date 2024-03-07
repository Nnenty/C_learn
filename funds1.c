#include <stdio.h>

#define FUNDLEN 50
struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(double x, double y)
{
    return (x + y);
}
int main(void)
{
    struct funds stan =
        {
            .bank = "Garlic-Melon Bank",
            .bankfund = 4032.27,
            .save = "Lusky's Savings and Loan",
            8543.94};
    printf("Общая сумма на счету $%.2f.\n", sum(stan.bankfund, stan.savefund));

    return 0;
}
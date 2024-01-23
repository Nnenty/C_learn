#include <stdio.h>

#define SLEN 40
#define LIM 5

int main(void)
{
    int i;

    const char *mytalents[LIM] = {
        "Мгновенное складывание чисел", "Точное умножение",
        "Накапливание данных", "Исполнение инструкций с точностью до буквы",
        "Знание языка программирования C"};
    char yourtalents[LIM][SLEN] = {
        "Хождение по прямой", "Здоровый сон",
        "Рассылка писем", "Просмотр телевизора",
        "Чтение статей"};

    puts("\tСравним наши таланты.");
    printf(" %-52s  %-25s\n", "Мои таланты", "Ваши таланты");

    for (i = 0; i < LIM; i++)
    {
        printf("%-52s | %-25s\n", mytalents[i], yourtalents[i]);
    }

    printf("\nРазмер mytalents: %zd;\nРазмер yourtalents: %zd\n",
           sizeof(mytalents), sizeof(yourtalents));

    return 0;
}
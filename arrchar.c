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

    puts("\t     Сравним наши таланты.");
    printf("%-45s %-25s\n", "Ваши таланты", "Мои таланты");

    for (i = 0; i < LIM; i++)
    {
        printf("%-42s %-25s\n", yourtalents[i], mytalents[i]);
    }

    printf("\nРазмер mytalents: %zd;\nРазмер yourtalents: %zd\n",
           sizeof(mytalents), sizeof(yourtalents));

    return 0;
}
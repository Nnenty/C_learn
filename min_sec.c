#include <stdio.h>
#define SEC_PER_MIN 60
void main()
{
    int sec, min, left;

    printf("Перевод секунд в минуты и секунды!\n");
    printf("Введите количество секунд \
    (Введите 0 для выхода):\n");
    scanf("%d", &sec);
    while (sec > 0)
    {
        min = sec / SEC_PER_MIN;
        left = sec % SEC_PER_MIN;
        printf("%d секунд - это %d минут(ы) и %d секунд.\n", sec,
               min, left);
        printf("Введите следующее значение \
        (Введите 0 для выхода)\n");
        scanf("%d", &sec);
    }
    printf("Готово!\n");

    return 0;
}
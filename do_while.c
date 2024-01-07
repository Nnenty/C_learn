#include <stdio.h>
void main()
{
    const int secret_code = 228;
    int code_enterned;
    do
    {
        printf("Чтобы войти в клуб Бравл-старсеров\n");
        printf("пожалуйста, введи секретный код:");
        scanf("%d", &code_enterned);
    } while (code_enterned != secret_code);
    printf("Поздравляем, теперь вы");
    printf(" состоите в клубе Бравл-старсеров!\n");
    return 0;
}
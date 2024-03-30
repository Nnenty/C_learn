#include <stdio.h>
#include <stdbool.h>

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define RED 1   // 001
#define GREEN 2 // 010
#define BLUE 4  // 100

#define BLACK 0                    // 000
#define YELLOW (RED | GREEN)       // 011
#define PURPLE (RED | BLUE)        // 101
#define CYAN (GREEN | BLUE)        // 110
#define WHITE (RED | GREEN | BLUE) // 111

const char *colors[8] = {"черный", "красный", "зеленый", "желтый",
                         "синий", "фиолетовый", "голубой", "белый"};
struct box_props
{
    bool opaque : 1;
    unsigned int fill_color : 3;
    unsigned int : 4;
    bool show_border : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    unsigned int : 2;
};

void show_settings(const struct box_props *pb);

int main(void)
{
    struct box_props box = {true, WHITE, true, BLUE, SOLID};

    puts("Исходные настройки окна:");
    show_settings(&box);

    box.opaque = false;
    box.fill_color = PURPLE;
    box.border_color = CYAN;
    box.border_style = DASHED;
    box.show_border = false;

    puts("\nИзмененные настройки окна:");
    show_settings(&box);

    return 0;
}
void show_settings(const struct box_props *pb)
{
    printf("Окно %s.\n",
           pb->opaque == true ? "непрозрачно" : "прозрачно");
    printf("Цвет фона %s.\n", colors[pb->fill_color]);
    printf("Рамка %s.\n",
           pb->show_border == true ? "отображается" : "не отображается");
    if (pb->show_border == true)
    {
        printf("Цвет рамки %s.\n", colors[pb->border_color]);
        printf("Стиль рамки ");
        switch (pb->border_style)
        {
        case SOLID:
            printf("сплошной.\n");
            break;
        case DOTTED:
            printf("пунктирный.\n");
            break;
        case DASHED:
            printf("штриховой.\n");
            break;
        default:
            puts("неизвестного типа.");
        }
    }
}
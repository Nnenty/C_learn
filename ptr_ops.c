#include <stdio.h>
int main(void)
{
       int urn[5] = {100, 200, 300, 400, 500};
       int *ptr1, *ptr2, *ptr3;
       int i;

       ptr1 = urn;
       ptr2 = &urn[2];

       printf("значения массива urn[5]:\n");
       for (i = 0; i < 5; i++)
       {
              printf("%d ", urn[i]);
       }
       printf("\n\n");

       printf("значение указателя, разыменованный указатель, адрес указателя:\n");
       printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n",
              ptr1, *ptr1, &ptr1);
       ptr3 = ptr1 + 4;
       printf("\nсложение значения int с указателем:\n");
       printf("ptr1 + 4 = %p, *(ptr + 3) = %d, (*ptr + 4) =  %d",
              ptr1 + 4, *(ptr1 + 3), (*ptr1 + 4));
       ptr1++;
       printf("\nзначениия после выполнения операции ptr1++:\n");
       printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p",
              ptr1, *ptr1, &ptr1);
       ptr2--;
       printf("\nзначения после выполнения операции --ptr2:\n");
       printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
              ptr2, *ptr2, &ptr2);
       --ptr1;
       ++ptr2;
       printf("\nвосстановление исходных значений указателей:\n");
       printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
       printf("\nвычитание оджного указателя из другого:\n");
       printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n",
              ptr2, ptr1, ptr2 - ptr1);
       printf("\nвычитание из указателя значения типа int:\n");
       printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);

       return 0;
}
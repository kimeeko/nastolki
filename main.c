#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "nastolki.h"

int main()
{
        char *locale=setlocale(LC_ALL,"Rus");
        list l;
        l.first = NULL;
        l.last = NULL;
        l.n = 0;
        load(&l, "igri1");

        int choice;
        char vid[20];
        int min_price;

        do
        {
                puts("Меню:");
                puts("1. Показать все товары");
                puts("2. Добавить новый товар");
                puts("3. Удалить товар по индексу");
                puts("4. Найти по типу и цене");
                puts("5. Редактировать товар по индексу");
                puts("6. Выход");
                printf("Введите ваш выбор: ");
                scanf("%d", &choice);
                switch (choice)
                {
                        case 1:
                                print(&l);
                                break;
                        case 2:
                                {
                                        char name[20], sloznost[20], vid[20];
                                        int vozrast, chislo_people, price;
                                        printf("Введите Имя, Тип, Минимальный возраст игрока, Сложность, Количество иг>
                                        scanf("%19s %19s %d %19s %d %d", name, vid, &vozrast, sloznost, &chislo_people>
                                        push(&l, name, vid, vozrast, sloznost, chislo_people, price);
                                        save(&l, "igri1");
                                }
                                break;
                        case 3:
                                print(&l);
                                {
                                        int index;
                                        printf("Введите индекс товара для удаления: ");
                                        scanf("%d", &index);
                                        deletes(&l, index);
                                        save(&l, "igri1");
                                }
                                break;
                        case 4:
                                printf("Введите тип и цену товара: ");
                                scanf("%19s %d", vid, &min_price);
                                search(&l, vid, min_price);
                                break;
                        case 5:
                                print(&l);
                                {
                                        int index;
                                        printf("Введите индекс товара для редактирования: ");
                                        scanf("%d", &index);
                                        edit(&l, index);
                                        save(&l, "igri1");
                                }
                                break;
                        case 6:
                                puts("Выход...");
                                break;
                        default:
                                puts("Неверный выбор, введите число от 1 до 6.");
                }
        } while (choice != 6);

        ni *current = l.first;
        while(current)
        {
                ni* temp = current -> next;
                free(current);
                current = temp;
        }
        return 0;
}



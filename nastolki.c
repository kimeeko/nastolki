#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nastolki.h"

void push(list*l, char * name, char * vid, int vozrast, char * sloznost, int chislo_people, int price)
{
        ni * new = (ni*) malloc (sizeof(ni));
        strcpy(new->name, name);
        strcpy(new->vid, vid);
        new -> vozrast = vozrast;
        strcpy(new->sloznost, sloznost);
        new -> chislo_people = chislo_people;
        new -> price = price;
        new->next=NULL;
        if(l->n == 0)
        {
                l->first = new;
        }
        else
        {
                l->last->next = new;
        }
        l->last = new;
        l->n++;
}
void load(list * l, const char * igri1)
{
        FILE *f=fopen(igri1, "r");
        if (!f)
        {
                puts("файл не найден. Создайте новый файл");
                f = fopen(igri1, "w");
                if (!f)
                {
                        puts("Ошибка! Не удалось создать файл.");
                        return;
                }
                fclose(f);
                return;
        }
        char name[20];
        char vid[20];
        int vozrast;
        char sloznost[20];
        int chislo_people;
        int price;
        while (fscanf(f, "%19s %19s %i %19s %i %i", name, vid, &vozrast, sloznost, &chislo_people, &price)==6)
        {
                push(l, name, vid, vozrast, sloznost, chislo_people, price);
        }
        fclose(f);
}
void save(list *l, const char *igri1)
{
        FILE *f = fopen(igri1, "w");
        if (!f)
        {
                puts("Ошибка! Не удалось сохранить файл.");
                return;
        }
        ni *current = l->first;
        while (current)
        {
                fprintf(f, "%s %s %i %s %i %i\n", current->name, current->vid, current->vozrast, current->sloznost, current -> chislo_people, current -> price);
                current = current->next;
        }
        fclose(f);
}
ni * get(list * l, int index)
{
        if(index < 0 || index >= l->n)
        {
                return NULL;
        }
        ni * current = l->first;
        for(int i = 0; i < index; i++)
        {
                current = current -> next;
        }
        return current;
}
void deletes(list*l, int index)
{
        if(l->n == 0 || index < 0 || index >= l -> n)
        {
                puts("Неверный индекс.");
                return;
        }
        if(index == 0)
        {
                ni* temp = l -> first;
                l -> first = temp -> next;
                free(temp);
        }
        else
        {
                ni * prev = get(l, index - 1);
                if(!prev)
                {
                        puts("Товар не найден.");
                return;
                }
                ni * current = prev -> next;
                if(current == l->last)
                {
                        prev -> next = NULL;
                        l -> last = prev;
                }
                else
                {
                        prev -> next = current -> next;
                }
                free(current);
        }
        l -> n--;
}
void print(list*l)
{
        ni * current = l -> first;
        int index = 0;
        while(current)
        {
                printf("Индекс: %d, Имя: %s, Вид: %s, Возраст: %i, Сложность: %s, Количество игроков: %i, Цена: %i\n", index, current -> name, current -> vid, current -> vozrast, current -> sloznost, current -> chislo_people, current -> price);
                current = current -> next;
                index++;
        }
}
void search(list *l, char *vid, int min_price)
{
        ni *current = l->first;
        int found = 0;
        while (current)
        {
                if (strcmp(current->vid, vid) == 0 && current->price == min_price)
                {
                        printf("Найдено: Имя = %s, Цена = %i\n", current->name, current->price);
                        found = 1;
                }
                current = current->next;
        }
        if (!found)
        {
                puts("Товар не найден.");
        }
}
void edit(list *l, int index )
{
        if(l->n == 0 || index < 0 || index >= l -> n)
        {
                puts("Неверный индекс.");
                return;
        }

        ni * current = get(l, index);
        if (!current)
        {
                puts("ERROR!");
                return;
        }
        printf("Введите Новое имя, Новый тип, Новый минимальный возраст игрока, Новую сложность, Новое количество игроков, Новую цену товара: ");
        scanf("%19s %19s %d %19s %d %d", current->name, current->vid, &(current->vozrast), current->sloznost,&(current->chislo_people), &(current->price));
}


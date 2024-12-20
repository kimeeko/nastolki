typedef struct nastolki
{
        char name[20];
        char vid[20];
        int vozrast;
        char sloznost[20];
        int chislo_people;
        int price;
        struct nastolki *next;
}ni;

typedef struct list
{
        ni * first;
        ni * last;
        int n;
}list;

void push(list*l, char * name, char * vid, int vozrast, char * sloznost, int chislo_people, int price);
void load(list * l, const char * igri1);
void save(list *l, const char *igri1);
void deletes(list*l, int index);
void print(list*l);
void search(list *l, char *vid, int min_price);
void edit(list *l, int index );

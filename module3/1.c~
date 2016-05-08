#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct telbook
{
    char name[20];
    char  number[12];
    struct telbook *next; /*указатель на следующую запись*/
    struct telbook *prior;/*указатель на предыдущую запись*/
};
struct telbook *start;/*указатель на первую запись*/
struct telbook *last;/*указатель на последнюю запись*/
struct telbook *find(char *);
void enter(void), search(void), save(void);
void load(void), list(void);
void mldelete(struct telbook **, struct telbook **);
void dls_store(struct telbook *i, struct telbook **start, struct telbook **last);
void inputs(char *, char *, int), display(struct telbook *);
int menu_select(void);
int main(void)
{
    start = last = NULL;
    for(;;) {
        switch(menu_select()) {
            case 1: enter();/*добавление*/
              break;
            case 2: mldelete(&start, &last);/*удаление*/
              break;
            case 3: list();/*вывод всего списка*/
              break;
            case 4: search();/*поиск*/
              break;
            case 5: save();/*запись в файл*/
              break;
            case 6: load();/*чтение из файла*/
              break;
            case 7: exit(0);/*выход*/            
        }
    }
    return 0;
}
int menu_select(void)/*выбор действия*/
{
    char s[80];
    int c;
    printf("1 - ввод контакта\n"); 
    printf("2 - удаление контакта\n");
    printf("3 - отображение всего списка\n");
    printf("4 - поиск\n");
    printf("5 - сохранение в файл\n");
    printf("6 - чтение из файла\n");
    printf("7 - выход\n");
    do {
        printf("\nваш выбор: ");
        fgets(s, sizeof(s), stdin);
        c=atoi(s);
    }while(c<1 || c>7);

    return c;
}
void enter(void)/*ввод контакта*/
{
    struct telbook *info;
    for(;;) {
        info=(struct telbook *)malloc( sizeof(struct telbook));
        if(!info) {
            printf("\nнет свободной памяти");
            return;
        }
        inputs("введите имя: ", info->name, 20);
        if(!info->name[0]) break;
        inputs("введите номер телефона: ", info->number, 12);
        dls_store(info, &start, &last);
    }
}
void inputs(char *prompt, char *s, int count)/*ввод строки с клавиатуры
длиной не больше count*/
{
    char p[255];
    do {
        printf("%s", prompt);
        fgets(p, 254, stdin);
        if(strlen(p)>count) printf("\nслишком длинная строка\n");
    }while(strlen(p)>count);
    p[strlen(p)-1]=0;
    strcpy(s, p);
}
void dls_store(struct telbook *i, struct telbook **start, struct telbook **last)
/*создание упорядоченного списка*/
{
    struct telbook *old, *p;
    if(*last==NULL) {
        i->next=NULL;
        i->prior=NULL;
        *last=i;
        *start=i;
        return;
    }
    p= *start;
    old=NULL;
    while(p) {
        if(strcmp(p->name, i->name)<0) {
            old=p;
            p=p->next;
        }
        else {
            if(p->prior) {
                p->prior->next=i;
                i->next=p;
                i->prior=p->prior;
                p->prior=i;
                return;
            }
            i->next=p;
            i->prior=NULL;
            p->prior=i;
            *start=i;
            return;
        }
    }
    old->next=i;
    i->next=NULL;
    i->prior=old;
    *last=i;
}
void mldelete(struct telbook **start, struct telbook **last)
/*удаление контакта*/
{
    struct telbook *info;
    char s[80];
    inputs("введите имя: ", s, 20);
    info=find(s);
    if(info) {
        if(*start==info) {
            *start=info->next;
            if(*start) (*start)->prior=NULL;
            else *last=NULL;
        }
        else {
            info->prior->next=info->next;
            if(info!=*last)
                info->next->prior=info->prior;
            else
                *last=info->prior;
        }
        free(info);
    }
}
struct telbook *find( char *name)/*функция find выполняет поиск*/
{
    struct telbook *info;
    info=start;
    while(info) {
        if(!strcmp(name, info->name)) return info;
        info=info->next;
    }
    printf("имя не найдено\n");
    return NULL;
}
void list(void)/*отображение всего списка на экране*/
{
    struct telbook *info;
    info=start;
    while(info) {
        display(info);
        info=info->next;
    }
    printf("\n\n");
}
void display(struct telbook *info)/*функция display выполняет вывод на экран*/
{
    printf("%s\n", info->name);
    printf("%s\n", info->number);
    printf("\n\n");
}
void search(void)/*поиск имени в списке*/
{
    char name[20];
    struct telbook *info;
    printf("введите имя: \n");
    scanf("%s", name);
    info=find(name);
    if(!info) printf("не найдено\n");
    else display(info);
}
void save(void)/*сохранение в файле*/
{
    struct telbook *info;
    FILE *fp;
    fp=fopen("telbook.txt", "wb");
    if(!fp) {
        printf("нельзя открыть файл\n");
        exit (1);
    }
    printf("\nсохранение в файле\n");
    info=start;
    while(info) {
        fwrite(info, sizeof(struct telbook), 1, fp);
        info=info->next;
    }
    fclose(fp);
}
void load()/*чтение из файла*/
{
    struct telbook *info;
    FILE *fp;
    fp=fopen("telbook.txt", "rb");
    if(!fp) {
        printf("нельзя открыть файл\n");
        exit (1);
    }
    while(start) {/*освобождение памяти, если в ней уже есть список*/
        info=start->next;
        free(start);
        start=info;
    }
    start=last=NULL;
    printf("\nчтение из файла\n");
    while(!feof(fp)) {
        info =(struct telbook *)malloc( sizeof(struct telbook));
        if (!info) {
            printf("нет свободной памяти\n");
            return;
        }
        if(1 !=fread(info, sizeof(struct telbook), 1, fp)) break;
        dls_store(info, &start, &last);
    }
    fclose(fp);
}

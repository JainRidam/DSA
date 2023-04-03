#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *prev; // 1.iska matlab hai ki humein hai jo similar structure ko point kar sake
                              // 2. humein yeh ek poiner banaya hai jo similar type structure ko point kar sake matlab uske pass power hai node ko point karne ki jise hum us node ka data and link ko acess kar sake
};
struct node *head, *last, *t2;

int a, b, c, d, e, g, f, l;
void new_node();
void create();
void show();
void empty_list_insert();
void empty_list();
void cases_of_insert();
void insert_begin();
void insert_between();
void insert_last();
void cases_of_delete();
void delete_begin();
void delete_between();
void delete_last();
void end();
void main_cases();
int main()
{
    printf("Enter no of nodes\n");
    scanf("%d", &a);
    for (int j = 0; j < a; j++)
    {
        create();
    }
    show();
    main_cases();
}
void main_cases()
{
    printf("now what do you want to do \n1.INSERT\n2.DELETE\n");
    scanf("%d", &b);
    printf("\n");
    switch (b)
    {
    case 1:
        cases_of_insert();
        break;

    case 2:
        cases_of_delete();
        break;
    }
}
void end()
{
    printf("\n1.Continue\n2.End\n");
    scanf("%d", &l);
    switch (l)
    {
    case 1:
        main_cases();
        break;

    case 2:
        break;
    }
}
void create()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // 1.malloc help us to make node
                                                                    // 2.(struct node*) typecasting haimatlab malloc jo memory banaye ga wo iss type ko return karega matlab humare nod eko memory allocate karega
    printf("enter data of node:\n");
    scanf("%d", &temp->data);
    temp->next = temp->prev = NULL;
    if (head == NULL)
    {
        head = last = temp;
        return;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        return;
    }
}
void new_node()
{
    t2 = (struct node *)malloc(sizeof(struct node));
}
void show()
{

    if (head != NULL)
    {

        struct node *t1 = head;
        printf("\nForward movement:\n");
        for (int k = 0; t1 != NULL; k++)
        {

            printf("--->%d", t1->data);
            t1 = t1->next;
        }
        printf("\n backward movement\n");
        t1 = last;
        for (int m = 0; t1 != NULL; m++)
        {
            printf("---->%d", t1->data);
            t1 = t1->prev;
        }
    }
}
void cases_of_insert()
{
    printf("\n Now what do you want to do:\n1.Insert at begin\n2.Insert at between\n3.Insert at last\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        insert_begin();
        show();
        end();
        break;

    case 2:
        insert_between();
        show();
        end();

        break;
    case 3:
        insert_last();
        show();
        end();

        break;
    }
}
void empty_list_insert()
{
    printf("\nList is empty\ndo you want to make first node\n1.Yes\n2.No");
    scanf("%d", &e);
    switch (e)
    {
    case 1:
        create(); // temp naam ka node banega
        break;

    default:
        break;
    }
}
void empty_list()
{
    printf("\nList is empty\n");
}
void insert_begin()
{

    if (head == NULL)
    {
        empty_list_insert();
    }
    else
    {
        printf("\nEnter data you want to insert\n");
        scanf("%d", &d);
        new_node(); // yaha t2 naam ka ek pointer bana hai jek new node ko point kar raha hai
        t2->data = d;
        t2->next = head;
        head->prev = t2;
        t2->prev = NULL;
        head = t2;
        return;
    }
}
void insert_between() // new case d,e var use kar sakte hai since wo free hai
{
    if (head == NULL)
    {
        empty_list_insert();
    }
    else
    {
        new_node(); // t2 naam ka node bangeya hai
        struct node *atemp;
        atemp = head;
        printf("\nAfter which data you want to insert\n");
        scanf("%d", &d);
        printf("\n");
        printf("enter data u want to insert");
        scanf("%d", &f);
        t2->data = f; // new node mein jo data dalna hai
        for (int r = 0; atemp->data != d; r++)
        {
            atemp = atemp->next;
        }
        t2->next = atemp->next;
        atemp->next->prev = t2;
        atemp->next = t2;
        t2->prev = atemp;
    }
}
void insert_last() // d,e,f free var hai
{

    if (head == NULL)
    {
        empty_list_insert();
    }
    else
    {
        new_node(); // new node bana hai jise t2 point kar raha hai
        printf("\nEnter data u want to insert\n");
        scanf("%d", &d);
        t2->data = d;
        last->next = t2;
        t2->prev = last;
        t2->next = NULL;
        last = t2;
    }
}
void cases_of_delete() // c,d,e,.f,g saare var free hai
{
    printf("\n Now what do u wnat to do\n1.Delete at begin\n2.Delte at between\n3.Delete at last\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        delete_begin();
        show();
        end();

        break;

    case 2:
        delete_between();
        show();
        end();

        break;
    case 3:
        delete_last();
        show();
        end();

        break;
    }
}
void delete_begin() // d,e,f,g free var hai
{
    struct node *curr;
    if (head == NULL)
    {
        empty_list();
    }
    else
    {
        curr = head;
        head = head->next;
        head->prev = NULL;
        curr->next = NULL;
        curr->prev = NULL;
        curr->data = e;
        free(curr);
        printf("\nDeleted data is: %d", e);
    }
}
void delete_between() // d,e,f,g free var hai
{
    struct node *atemp, *ptemp;
    atemp = ptemp = head;
    if (head == NULL)
    {
        empty_list();
    }
    else
    {
        printf("\nEnter the data u wnat to delete\n");
        scanf("%d", &d);
        for (int r = 0; atemp->data != d; r++)
        {
            ptemp = atemp;
            atemp = atemp->next;
        }
        ptemp->next = atemp->next;
        atemp->next->prev = ptemp;
        atemp->data = e;
        atemp->next = NULL;
        atemp->prev - NULL;
        free(atemp);
    }
}
void delete_last()
{
    struct node *atemp;
    atemp = last;
    last->prev->next = NULL;
    last->data = e;
    last = atemp->prev;
    atemp->prev = NULL;
    free(atemp);
}
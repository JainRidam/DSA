#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int i, a, b, c, d, e, f, m, j, item = 0, r, q,s;
struct node *head, *last, *ptemp = NULL;
void create(void);
void show(void);
void insert_begin(void);
void insert_last(void);
void insert_between();
void end();
void imp_cases();
void cases();
void del();
void delete_begin(void);
void delete_between(void);
void delete_last(void);
void swap();
void swap_begin();
void swap_between();
void swap_last();
void Reverse();
void doubly();
void singly();
int main()
{

    printf("enter no of nodes \n");
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        create();
    }
    printf("Your list \n");
    show();
    printf("\n");
    imp_cases();

    return 0;
}
void singly()
{
    printf("enter no of nodes \n");
    scanf("%d", &a);
    for (i = 0; i < a; i++)
    {
        create();
    }
    printf("Your list \n");
    show();
    printf("\n");
    imp_cases();
}
void create()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head == NULL)
    {
        head = last = temp;
        return;
    }
    else
    {
        last->next = temp;
        last = temp;
        return;
    }
}
void show()
{
    struct node *t1 = head;
    for (int j = 0; t1 != NULL; j++)
    {
        printf("----->%d", t1->data);
        t1 = t1->next;
    }
}
void imp_cases()
{
    printf("what do you want to do\n");
    printf("1.Delete\n2.Insert\n3.Swap\n4.Reverse\n");
    scanf("%d", &r);
    switch (r)
    {
    case 1:
        del();
        break;

    case 2:
        cases();
        break;
    case 3:
        swap();
        break;
    case 4:
        Reverse();
        break;
    }
}
void insert_begin()
{
    struct node *t2 = (struct node *)malloc(sizeof(struct node));
    t2->data = c; // iska matlab hai t2 ki data value c hai.
    if (head != NULL)
    {
        t2->next = head;
        head = t2;
        return;
    }
    else
    {
        head = last = t2;
        t2->next = NULL;
        return;
    }
}
void insert_last()
{
    struct node *t2 = (struct node *)malloc(sizeof(struct node));
    t2->data = d;
    if (last != NULL)
    {
        last->next = t2;
        t2->next = NULL;
    }
    else
    {
        head = last = t2;
        t2->next = NULL;
    }
}
void insert_between()
{
    struct node *t2 = (struct node *)malloc(sizeof(struct node));
    struct node *atemp, *rtemp;
    t2->data = e;
    rtemp = head;
    atemp = head;
    for (int l = 0; rtemp->data != f; l++)
    {
        atemp = rtemp;
        rtemp = rtemp->next;
    }
    t2->next = rtemp->next;
    rtemp->next = t2;
}
void end()
{
    printf("what do you want to do\n1.Continue\n2.End \n ");
    scanf("%d", &m);
    switch (m)
    {
    case 1:
        imp_cases();
        break;

    case 2:

        break;
    }
}
void cases()
{
    printf("\nwhat do you want to do \n");
    printf("1.Insert at begin \n 2.Insert at last \n 3.Insert at between\n");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        printf("enter data you want to insert at begin \n");
        scanf("%d", &c);
        insert_begin();
        show();
        end();
        break;

    case 2:
        printf("enter data you want to insert\n");
        scanf("%d", &d);
        insert_last();
        show();
        end();
        break;
    case 3:
        printf("Enter data after you want to insert\n");
        scanf("%d", &f);
        printf("enter data you want to insert\n");
        scanf("%d", &e);
        insert_between();
        show();
        end();
        break;
    }
}
void del()
{
    printf("What do you want to do \n1.Deletion at begin\n2.Deletion at between\n3.Deletion at last\n");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        delete_begin();
        break;

    case 2:
        delete_between();
        break;

    case 3:
        delete_last();
        break;
    }
}
void delete_begin()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        ptemp = head;
        head = head->next;
        item = ptemp->data;
        free(ptemp);
    }
    printf("\n");
    show();
    printf("Deleted data is: %d \n", item);
    end();
}
void delete_between()
{
    struct node *rtemp;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        printf("Which data you want to delete\n");
        scanf("%d", &b);
        ptemp = head;
        rtemp = head;
        for (c = 0; rtemp->data != b; c++)
        {
            ptemp = rtemp;
            rtemp = rtemp->next;
        }
        item = rtemp->data;
        ptemp->next = rtemp->next;
        free(rtemp);
        printf("\n");
        show();
        printf("Deleted data is: %d \n", item);
        end();
    }
}
void delete_last()
{
    struct node *rtemp;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        ptemp = head;
        rtemp = head;
        for (d = 0; rtemp->next != NULL; d++)
        {
            ptemp = rtemp;
            rtemp = rtemp->next;
        }
        item = rtemp->data;
        ptemp->next = NULL;
        free(rtemp);
        show();

        printf("Deleted data is: %d \n", item);
        end();
    }
}
void swap()
{

    printf("1.At beginning\n2.At between\n3.At end\n");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        swap_begin();
        break;
    case 2:
        swap_between();
        break;
    case 3:
        swap_last();
        break;
    }
}
void swap_begin()
{
    struct node *rtemp;
    rtemp = head;
    ptemp = rtemp->next;
    head = rtemp->next;
    rtemp->next = ptemp->next;
    head->next = rtemp;
    show();
    printf("\n");
    end();
}
void swap_between()
{
    struct node *rtemp, *atemp;
    printf("Write the value of data u want to swap with its next data\n");
    scanf("%d", &j);
    ptemp = head;
    rtemp = head;
    for (c = 0; rtemp->data != j; c++)
    {
        ptemp = rtemp;
        rtemp = rtemp->next;
    }
    atemp = rtemp->next;
    ptemp->next = atemp;
    rtemp->next = atemp->next;
    atemp->next = rtemp;
    show();
    printf("\n");
    end();
}
void swap_last()
{
    struct node *rtemp;
    rtemp = head;
    ptemp = head;
    for (d = 0; rtemp->next != last; d++)
    {
        ptemp = rtemp;
        rtemp = rtemp->next;
    }
    last->next = rtemp;
    rtemp->next = NULL;
    ptemp->next = last;
    show();
    printf("\n");
    end();
}
void Reverse()
{
    struct node *atemp, *ntemp;
    atemp = head;
    ptemp = head;
    ntemp = last;
    printf("The reverse link list is:-\n");
    for (d = 0; atemp->next != last; d++)
    {
        atemp = atemp->next;
    }

    for (c = 0; head != atemp; c++)
    {

        head = ptemp->next;
        atemp->next = ptemp;
        ptemp->next = ntemp;
        ntemp = ptemp;
        ptemp = head;
    }
    last->next = atemp;
    head = last;
    show();
    end();
}

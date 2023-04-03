
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next; 
};
struct node*head,*last;
void create (int val){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    // head=last=NULL;
    // printf("Enter the data \n");
    temp->data=val;
    temp->next=NULL;
    if(head==NULL){
        head=last=temp;
        return;
    }
    else{
        last->next=temp;
        last=temp;
        return;
    }
}
void show(){
    struct node*t1=head;
    while(t1!=NULL){
        printf("---->%d",t1->data);
        t1=t1->next;
    }
}
void sort(){
    int a=0;
    int b=1;
    struct node *t2=head->next;
    struct node *t4=head;
    struct node *t3=head->next;
    struct node *t5;
    // struct node *t3=head->next;
for(int j=0;t2!=NULL;j++){
    if(t2->data==a){
t5->next=t2->next;
t2->next=t3;    
t4->next=t2;
t4=t4->next;
// t3=t4->next;
t2=t5->next;
    }else{
    t5=t2;
    t2=t2->next;}


}


// for(int k=0;t3!=NULL;k++){
//     if(t3->data==b){
// t4->next=t3;
// t4=t4->next;
//     }
//     t3=t3->next;
// }

}
int main(){
    create(0);
    create(1);
    create(1);
    create(1);
    create(0);
    create(0);
    create(1);
    create(0);
    create(1);
    // printf("%d",head->data);
    create(1);
    create(1);
    create(0);
    create(1);
    create(0);
    create(1);
    show();
    printf("\n");
    sort();
    show();



}


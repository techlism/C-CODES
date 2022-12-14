#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node*  next;
};
typedef struct node node;
node * head = NULL;

struct createStack{
    void(*push)();
    void(*printStack)();
};
typedef struct createStack stack;

void push(int data){
    node* temp=(node*) malloc(sizeof(node));
    temp->data = data;
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void printStack(){
    node * temp=head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){

 stack s;
 s.push=push;
 s.push(&push);
 s.printStack=printStack;
 s.printStack(&printStack);
 s.push(11);
 s.push(12);
 s.push(1);
 s.push(13);
 s.printStack();
    
}
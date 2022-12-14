#include<stdlib.h>
#include<stdio.h>
struct linkedlistNode{
   int data;
   struct linkedlistNode * next;
   struct linkedlistNode * prev;
};
typedef struct linkedlistNode node;
node * curr=NULL;
node * prev=NULL;
node * head=NULL;

void insertFront(int data){
    node * temp=(node*) malloc(sizeof(node));
    if(head==NULL){
        temp->data=data;
        temp->prev=NULL;
        temp->next=NULL;
        head=temp;
    }
    else{
        temp->data=data;
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
}
void insertSpecific(int data,int position){
    node * temp =head;
    node * nodetoInsert= (node *) malloc(sizeof(node));
    nodetoInsert->data=data;
    if(position==1){
        //for front position
        insertFront(data);
    }
    else{
     int count=2;
     while(count<position && temp->next!=NULL){
        temp=temp->next;
        count++;
     }
     if(temp->next==NULL){
       //for last position
       nodetoInsert->prev=temp;
       temp->next=nodetoInsert;
       nodetoInsert->next=NULL;

     }
     else{
        //for any other position
     temp->next->prev = nodetoInsert;
     nodetoInsert->next=temp->next;
     nodetoInsert->prev=temp;
     temp->next=nodetoInsert;
     }    
    }

}
void deleteNode(int position){
    if(position==1){
     //Deleting first Node
      node* temp=head;
      head=head->next;
      head->prev=NULL;
      temp->next=NULL;
      temp->prev=NULL;
      free(temp);
    }
    else{
        int count=2;
        node * temp=head;
        while(count<position && temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        if(temp->next->next==NULL){
            //Last Node
            node * nodetoDelete = temp->next;
            temp->next=NULL;
            nodetoDelete->prev=NULL;
            nodetoDelete->next=NULL;
            free(nodetoDelete);
        }
        else{
            //for any other positions
            node* nodetoDelete=temp->next;
            temp->next=temp->next->next;
            temp->next->prev=temp;
            nodetoDelete->next=NULL;
            nodetoDelete->prev=NULL;
            free(nodetoDelete);
        }
    }
}
void printList(){
    node * temp = head;
    while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
    }
    printf("\n");
}
int main(){
    insertFront(12);
    insertFront(11);
    insertFront(10);
    printList();
    insertSpecific(13,4);
    insertSpecific(14,4);
    printList();
    deleteNode(3);
    printf("After Deleting 3rd Node\n");
    printList();
}
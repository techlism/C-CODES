#include<stdio.h>
#include<stdlib.h>
struct linkedlistNode{
   int data;
   struct linkedlistNode * next;
};
typedef struct linkedlistNode node;
node *head = NULL;

void insertHead(int data){
    node* temp = (node *) malloc (sizeof(node));
    temp->data=data;
    temp->next=head;
    head=temp;
}
void insertSpecific(int data,int position){
    // 0 based Indexing
    if(position==0){
        insertHead(data);
    }
    node * traverse = head;
    node * temp=(node* ) malloc(sizeof(node));
    temp->data=data;
    int count=1;
    while(count<position && traverse->next!=NULL){
      traverse=traverse->next;
      count++;
    }
    temp->next=traverse->next;
    traverse->next=temp;
}
void deleteNode(int position){
    node * temp =head;
    if(position==0){
        head=head->next;
        temp->next=NULL;
        free(temp);
        return;
    }
    int count=1;
    while(count<position && temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    node* nodetoDelete=temp->next;
    temp->next=temp->next->next;
    nodetoDelete->next=NULL;
    free(nodetoDelete);
}

void printList(){
    node* temp = head ;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverseList(){
     node* temp;
     node * r;
     node * s;
     temp=head;
     r=NULL;
    while(temp!=NULL){
        s=r;
        r=temp;
        temp=temp->next;
        r->next=s;
    }
    head=r;
}

int main(){
    insertHead(12);
    insertHead(11);
    insertHead(10);
    insertHead(9);
    insertSpecific(8,1);
    insertSpecific(7,1);
    printList();
    insertSpecific(6,3);
    printList();
    // deleteNode(3);
    printf("List after Deleting one Node\n");
    printList();
    // printf("Reversed List\n");
    // reverseList();
    // printList();
    sortList();
    printf("Trying Sort Algo\n");
    printList();

}

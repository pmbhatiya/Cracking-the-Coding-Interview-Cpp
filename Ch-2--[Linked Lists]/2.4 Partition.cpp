#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
};
void push(node **head,int data){
    node *newNode=new node();
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }else{
        node *ptr=*head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }

}
void display(node *head){
    if(head==NULL){
        cout<<"List empty"<<endl;
    }
    else{
        node *runner=head;
        while(runner!=NULL){
            cout<<runner->data<<" ";
            runner=runner->next;
        }
        cout<<endl;
    }

}
node * partitionList(node *head,int k){
    node *top=head;
    node *tail=head;

    while(head!=NULL){
        node *next=head->next;
        if(head->data<k){
            head->next=top;
            top=head;

        }else{
            tail->next=head;
            tail=head;
        }

        head=next;
    }
    tail->next=NULL;

    return top;
}
int main(){
    node *head=NULL;
    push(&head,4);
    push(&head,2);
    push(&head,1);
    push(&head,5);
    push(&head,12);
    display(head);
    head=partitionList(head,5);
    display(head);

    return 0;
}

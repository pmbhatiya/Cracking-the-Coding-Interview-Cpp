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
        cout<<"Empty List"<<endl;
    }else{
        node *ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;

    }

}
node *findBegning(node *head){
    node *fast=head;
    node *slow=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            break;
        }
    }
    if(fast==NULL || fast->next==NULL){
        return NULL;
    }

    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }

return fast;
}
int main(){
    node *head=NULL,*save=NULL,*prev=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);

    save=head;
    int count=0;
    while(save->next!=NULL){
        count++;
        if(count==3)
            prev=save;
        save=save->next;
    }
    save->next=prev;
//    display(head);
    cout<<findBegning(head)->data<<endl;

    return 0;
}
/* Explenation

n=3 cycle length
m=2 note in cycle
k=1 steps in cycle to meeting point

n is multiple of m+k

m=n-k
2=3-1
2=2


<----m--><-----n--------->
1--->2--->3--->4--->5--->3
         <--k-->

*/

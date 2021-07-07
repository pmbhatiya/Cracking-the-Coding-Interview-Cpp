#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
};
void push(node **head,int value){
    node *newNode=new node();
    newNode->data=value;
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
void displayList(node *head){
    if(head==NULL){
        cout<<"Empty List"<<endl;
    }else{
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
    }
}
void deleteMiddleNode(node *head){
    if(head==NULL){
        cout<<"Empty List"<<endl;
    }else{
            node *p1=head,*p2;
            float len=0;
            while(p1!=NULL){
                len+=1;
                p1=p1->next;
            }
            if(len<=2){
                cout<<"Do Not Delete first and Last Node"<<endl;
            }else{
                    len=ceil(len/2);
                    p1=head;
                    while(len!=1){
                        len-=1;
                        p2=p1;
                        p1=p1->next;
                    }
                    p2->next=p1->next;
                    cout<<endl;
            }
    }
}
int main(){
    node *head=NULL;

    push(&head,78);
    push(&head,98);
    push(&head,100);
     push(&head,718); push(&head,7128);
    push(&head,918);
//    push(&head,1100);
    displayList(head);
    deleteMiddleNode(head);
    displayList(head);
    return 0;
}

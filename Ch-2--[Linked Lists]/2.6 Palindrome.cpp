#include<bits/stdc++.h>
using namespace std;
class node{
public: int data;
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
        cout<<"Empty List";
    }else{
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
}
node *reverseAndClone(node *check){
    node *ptr=NULL;
    while(check!=NULL){
        node *newNode=new node();
        newNode->data=check->data;
        newNode->next=ptr;
        ptr=newNode;
        check=check->next;
    }

return ptr;
}
bool isEqual(node *one,node *two){
    while(one!=NULL && two!=NULL){
        if(one->data!=two->data)
            return false;
        one=one->next;
        two=two->next;
    }


return (one==NULL && two==NULL);
}
bool isPalindrome(node *head){
    node *reversed=reverseAndClone(head);
    return isEqual(head,reversed);

}
bool isPalindromeStack(node *head){
    node *fast=head;
    node *slow=head;

    stack<int> palindromeStack;
     while(fast!=NULL && fast->next!=NULL){
        palindromeStack.push(slow->data);
        slow=slow->next;
        fast=fast->next->next;
     }
    if(fast!=NULL){
        slow=slow->next;
    }

    int top;
    while(slow!=NULL){
        top=palindromeStack.top();
        palindromeStack.pop();
        if(top!=slow->data){
            return false;
        }
        slow=slow->next;
    }

return true;
}
int main(){
    node *head=NULL;

    push(&head,0);
    push(&head,1);
    push(&head,2);
    push(&head,1);
    push(&head,0);

    display(head);
    bool flag;
    //reverse and compare
//    flag=isPalindrome(head);
    flag=isPalindromeStack(head);
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}

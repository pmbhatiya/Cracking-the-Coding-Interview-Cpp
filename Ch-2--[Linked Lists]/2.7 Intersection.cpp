#include<bits/stdc++.h>
using namespace std;
class node{
public:
        int data;
        node *next;
};
class Result{
public:
      node *tail;
      int size;
      Result(node *other,int len){
        tail=other;
        size=len;
      }
};
void push(node **head,int data){

    node *newNode=new node();
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;

}
void push(node **head,node **other,int data){

    node *newNode=new node();
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;
    *other=newNode;

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
Result * getTailandSize(node *head){
    if(head==NULL)
        return NULL;

    int len=1;
    node *current=head;
    while(current->next!=NULL){
        len++;
        current=current->next;
    }
    Result *rs=new Result(current,len);
    return rs;
}
node *getKthNode(node *ptr,int k){
    node *current=ptr;
    while(k>0 && current!=NULL){
        k--;
        current=current->next;
    }
    return current;
}
node *findIntersection(node *l1,node *l2){
    if(l1==NULL || l2==NULL)
        return NULL;
    Result *result1=getTailandSize(l1);
    Result *result2=getTailandSize(l2);

    if(result1->tail!=result2->tail){
        return NULL;
    }

    node *shorter=result1->size<result2->size?l1:l2;
    node *longer=result1->size<result2->size?l2:l1;

    longer=getKthNode(longer,abs(result1->size - result2->size));

    while(shorter!=longer){
        shorter=shorter->next;
        longer=longer->next;
    }
    return longer;
}
int main(){
    node *l1Head=NULL;
    node *l2Head=NULL;


    push(&l1Head,&l2Head,1);
    push(&l1Head,&l2Head,2);
    push(&l1Head,&l2Head,7);
    push(&l1Head,9);
    push(&l1Head,5);
    push(&l1Head,1);
    push(&l1Head,3);

    push(&l2Head,6);
    push(&l2Head,4);

    display(l1Head);
    display(l2Head);

    cout<<findIntersection(l1Head,l2Head)->data<<endl;
    return 0;
}

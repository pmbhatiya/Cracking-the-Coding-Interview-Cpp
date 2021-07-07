#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;
};
class partialSum{
public:node *sum=NULL;
        int carry=0;
};
node *insertBefore(node *li,int data){
    node *newNode=new node();
    newNode->data=data;

    if(li!=NULL)
    newNode->next=li;


return newNode;
}
int length(node *head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}
node *padList(node *ptr,int pedding){
    node *runner=ptr;
     for(int i=0;i<pedding;i++){
        runner=insertBefore(runner,0);
    }
    return runner;
}
void push(node **head,int value){
    node *newNode=new node();
    newNode->data=value;
    newNode->next=*head;
    *head=newNode;
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
partialSum *addHelperLists(node *l1,node *l2){
    if(l1==NULL && l2==NULL){
        partialSum *sum=new partialSum();
        return sum;
    }

    partialSum *sum=addHelperLists(l1->next,l2->next);
    int value=sum->carry+l1->data+l2->data;


    node *full_result=insertBefore(sum->sum,value%10);

    sum->sum=full_result;
    sum->carry=value/10;
    return sum;

}
node *addLists(node *l1,node *l2){
    int len1=length(l1);
    int len2=length(l2);

    if(len1<len2){
        l1=padList(l1,len2-len1);
    }else{
        l2=padList(l2,len1-len2);
    }
    partialSum *sum=addHelperLists(l1,l2);

    if(sum->carry==0){
        return sum->sum;
    }else{
        node *result=insertBefore(sum->sum,sum->carry);
        return result;
    }
}
int main(){
    node *l1Head=NULL;
    node *l2Head=NULL;

    push(&l1Head,2);
    push(&l1Head,3);
    push(&l1Head,7);


    push(&l2Head,8);
    push(&l2Head,9);
    push(&l2Head,5);

    display(l1Head);
    display(l2Head);

    node *sum=NULL;
    sum=addLists(l1Head,l2Head);

    display(sum);
    return 0;
}

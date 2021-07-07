#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
};
void addNode(node **head,int val){
    node *newNode=new node();
    newNode->data=val;
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
        cout<<"No element in the List"<<endl;
    }else{
        node *ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
    //Rucursive soln
//node* kthTolast(int k,node *head,int &i){
//    if(head==NULL){
//       return 0;
//    }
//    node *ind=kthTolast(k,head->next,i);
//    i=i+1;
//    if(i==k){
//        return head;
//    }
//    cout<<i<<endl;
//    return ind;
//}
    //end recursive soln
  node *kthTolast(int k,node *head){

    if(head==NULL){
        cout<<"Empty List";
        return head;
    }
    node *p1=head,*p2=head;
    for(int i=0;i<k;i++){
        if(p1==NULL) return NULL;
        p1=p1->next;
    }
    while(p1!=NULL){
        p1=p1->next;
        p2=p2->next;
    }
    return p2;


  }

int main(){
    node *head=NULL;
    addNode(&head,12);
    addNode(&head,33);
    addNode(&head,78);
    addNode(&head,98);
    displayList(head);
    //for recursive approach
//    int i=0;
//    node *ans=kthTolast(2,head,i);
//    cout<<ans->data<<endl;
      //end for recursive approach
    node *ans;
    ans=kthTolast(2,head);
    cout<<ans->data<<endl;

    displayList(head);

    return 0;
}

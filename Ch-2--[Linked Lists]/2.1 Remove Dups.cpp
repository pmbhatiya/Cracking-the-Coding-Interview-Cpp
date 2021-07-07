#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
            int data;
            Node* next;
};
void addNode(Node **head,int data){
                Node *newNode=new Node();
                newNode->data=data;
                newNode->next=NULL;
                if(*head==NULL){
                    *head=newNode;
                }else{
                    Node *currunt=*head;
                    while(currunt->next!=NULL){
                        currunt=currunt->next;
                    }
                    currunt->next=newNode;
                }

}
void display(Node *ptr){
        if(ptr==NULL){
            cout<<"NO Element In Linked List"<<endl;
        }else{
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
        }

}
//void deleteDups(Node *head){ //complexity 0(N)
//    map<int,int> MyDups;
//    Node *prev=NULL;
////    cout<<(**head).data<<endl;
//    while((head)!=NULL){
//        if(MyDups[head->data]){
//            prev->next=head->next;
//        }else{
//        MyDups[head->data]=head->data;
//        prev=head;
//
//        }
//        head=head->next;
//    }
//}

void deleteDups(Node *head){ //complexity 0(N^2)
    Node *ptr=head;
    while(ptr!=NULL){
        Node *runner=ptr;
        while(runner->next!=NULL){
            if(runner->next->data==ptr->data){
                    runner->next=runner->next->next;
            }else{
                    runner=runner->next;
            }
        }
        ptr=ptr->next;
    }
}

int main(){
    Node* head=NULL;
    addNode(&head,10);
    addNode(&head,20);
    addNode(&head,20);
    addNode(&head,40);
    addNode(&head,40);
    addNode(&head,50);
    display(head);
    cout<<endl;
    deleteDups(head);
    display(head);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class hashTable{
private:
    struct node{
    int val;
    struct node *next;
    };
    node *a[100];


public:
    hashTable(){
                for(int i=0;i<100;i++){
                    a[i]=NULL;
                }
    }
    int hashFunction(int data){
        return (data%100);
    }

    void add(int data){
            node *ptr,*ptr2;
            int index=hashFunction(data);
            ptr=(node *)malloc(sizeof(node));
            ptr->val=data;
            ptr->next=NULL;
            if(a[index]==NULL){
                a[index]=ptr;
            }else{
                ptr2=a[index];
                while(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                }
                ptr2->next=ptr;
            }

    }
    void displayHashTable(){
            node *pass;
            for(int i=0;i<100;i++){
                pass=a[i];
                if(a[i]==NULL)
                    continue;
                while(pass!=NULL){
                    cout<<pass->val<<" ";
                    pass=pass->next;
                }
                cout<<endl;
            }
        cout<<endl;

    }
    void removeData(int data){
        node *ptr,*parent;
        int index=hashFunction(data);
        ptr=a[index];
        parent=NULL;
        if(a[index]==NULL){
            cout<<"Data NOT found"<<endl;
        }else{
                while(ptr->val!=data){
                    if(ptr->next==NULL){
                        break;
                    }
                    parent=ptr;
                    ptr=ptr->next;
                }
                if(ptr->next==NULL && ptr->val==data){
                        if(parent==NULL){
                            a[index]=NULL;
                            delete(ptr);
                        }else{
                            parent->next=NULL;
                            delete(ptr);
                        }

                }else if(ptr->next==NULL){
                        cout<<"Element not found";
                }else{
                    parent->next=ptr->next;
                    delete(ptr);
                }

      }
    }
};
int main(){

    hashTable obj;
    obj.add(39);
    obj.add(88);
    obj.add(90);
    obj.add(58);
    obj.add(77);
    obj.add(66);
    obj.add(43);
    obj.add(56);
    obj.add(166);
    obj.add(87);
    obj.displayHashTable();
    obj.removeData(77);
    obj.removeData(90);
    obj.removeData(43);
    cout<<"Updated Hash Tables"<<endl;
    obj.displayHashTable();

    return 0;
}

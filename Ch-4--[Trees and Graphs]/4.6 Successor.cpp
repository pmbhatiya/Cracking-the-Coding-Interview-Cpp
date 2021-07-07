#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
    node *parent;
};

class Successor{
private:
        int noOFnode=7;
public:
    node* createBST(node *root,int val){
        if(root==NULL){
              node *newNode=new node();
              newNode->data=val;
              newNode->left=NULL;
              newNode->right=NULL;
              newNode->parent=NULL;
              return newNode;
        }else{
             node *temp;
            if(val<root->data){
                temp=createBST(root->left,val);
                root->left=temp;
                temp->parent=root;

            }else{
                temp=createBST(root->right,val);
                root->right=temp;
                temp->parent=root;
            }
            return root;
        }

    }
    void in_order(node *ptr){
        if(ptr!=NULL){
            in_order(ptr->left);
            cout<<ptr->data<<" ";
            in_order(ptr->right);
        }
    }
    node *minValue(node *ptr){
        node *temp=ptr;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    node *in_Successor(node *ptr){
        if(ptr->right!=NULL)
            return minValue(ptr->right);

        node *p=ptr->parent;
        while(p!=NULL && p->left!=ptr){
            ptr=p;
            p=p->parent;
        }
        return p;

    }
};
int main(){

    Successor obj;
    node *root=NULL;
    int arr[]={20,8,22,4,12,21,28,3,6,10,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        root=obj.createBST(root,arr[i]);
    }
    obj.in_order(root);

    node *findNode=NULL;
    findNode=root->left->right->right;
    cout<<"find Node Successor -->"<<findNode->data<<endl;
    cout<<obj.in_Successor(findNode)->data;

    return 0;
}

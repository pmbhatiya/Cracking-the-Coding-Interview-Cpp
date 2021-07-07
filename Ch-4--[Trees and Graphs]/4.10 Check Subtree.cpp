#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
};
class checkSubtree{
public:
    node *createBt(node *root,int arr[],int i,int n){
        if(i<n){
            node *newNode=new node();
            newNode->data=arr[i];
            newNode->left=NULL;
            newNode->right=NULL;
            root=newNode;
            root->left=createBt(root->left,arr,2*i+1,n);
            root->right=createBt(root->right,arr,2*i+2,n);
        }
        return root;
    }
    void In_order(node *ptr){
        if(ptr!=NULL){
            In_order(ptr->left);
            cout<<ptr->data<<" ";
            In_order(ptr->right);
        }
    }

    void getOrderString(node *ptr,string &str){
        if(ptr==NULL){
            str+="X";
            return;
        }
        str+=to_string(ptr->data);
        getOrderString(ptr->left,str);
        getOrderString(ptr->right,str);

    }
    bool containsTree(node *t1,node *t2){
        string s1="",s2="";
        getOrderString(t1,s1);
        getOrderString(t2,s2);
        return(s1.find(s2)!=string::npos);
    }

    //second approch
    bool matchTree(node *r1,node *r2){
        if(r1==NULL && r2==NULL){
            return true;
        }else if(r1==NULL || r2==NULL){
            return false;
        }else if(r1->data!=r2->data){
            return false;
        }else{
            return matchTree(r1->left,r2->left) && matchTree(r1->right,r2->right);
        }

    }
    bool subTree(node *r1,node *r2){
        if(r1==NULL){
            return false;
        }
        else if(r1->data==r2->data && matchTree(r1,r2)){
                return true;
        }
        return subTree(r1->left,r2) || subTree(r1->right,r2);
    }
    bool containTree(node *t1,node *t2){
        if(t2==NULL)
            return true;
        return subTree(t1,t2);
    }
    //end of second approach

};
int main(){
    checkSubtree obj;
    int T1_arr[]={1,2,3,4,5,6,7};
    int T2_arr[]={1,2,3};
    node *t1Root=NULL,*t2Root=NULL;
    int lenT1=sizeof(T1_arr)/sizeof(T1_arr[0]);
    int lenT2=sizeof(T2_arr)/sizeof(T2_arr[0]);

    t1Root=obj.createBt(t1Root,T1_arr,0,lenT1);
    t2Root=obj.createBt(t2Root,T2_arr,0,lenT2);

//    obj.In_order(t2Root);
     if(obj.containTree(t1Root,t2Root)){
        cout<<"Yes"<<endl;
     }else{
        cout<<"No"<<endl;
     }

    return 0;
}

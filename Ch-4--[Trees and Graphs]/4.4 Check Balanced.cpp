#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
};
class checkBalanced{
public:
       node *createBST(node *ptr,int val,int n){
           if(val<n){
           node *newNode=new node();
           newNode->data=val+1;
           ptr=newNode;
           newNode->left=createBST(ptr->left,2*val+1,n);
           newNode->right=createBST(ptr->right,2*val+2,n);
           }
        return ptr;
       }
       void in_order(node *ptr){
        if(ptr!=NULL){
            in_order(ptr->left);
            cout<<ptr->data<<" ";
            in_order(ptr->right);
        }
       }
//       int getHeight(node *ptr){
//        if(ptr==NULL) return -1;
//        return max(getHeight(ptr->left),getHeight(ptr->right))+1;
//       }
//       bool isBalanced(node *root){
//            if(root==NULL) return true;
//            int heightDiff=getHeight(root->left)-getHeight(root->left);
//            if(abs(heightDiff)>1){
//                return false;
//            }else{
//                return (isBalanced(root->left) && isBalanced(root->right));
//            }
//
//       }
       int checkHeight(node *ptr){
           if(ptr==NULL) return -1;

           int leftHeight=checkHeight(ptr->left);
           if(leftHeight==INT_MIN) return INT_MIN;

           int rightHeight=checkHeight(ptr->right);
           if(rightHeight==INT_MIN) return INT_MIN;

           int heightDiff=leftHeight-rightHeight;
           if(abs(heightDiff)>1){
                return INT_MIN;
           }else{
                cout<<leftHeight<<" "<<rightHeight<<endl;
                return(max(leftHeight,rightHeight)+1);
           }
       }
       bool isBalanced(node *root){
            return (checkHeight(root)!=INT_MIN);
       }
};
int main(){
    node *root=NULL;
    checkBalanced obj;
    root=obj.createBST(root,0,7);
    obj.in_order(root);

    bool flag;
    flag=obj.isBalanced(root);
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


    return 0;
}

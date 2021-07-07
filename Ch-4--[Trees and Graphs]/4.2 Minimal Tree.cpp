#include<bits/stdc++.h>
using namespace std;
class node{
    public:
            int data;
            node *left;
            node *right;
};
class CreateBinarySearchTree{
private:
        int noOfNode=0;
public:
       CreateBinarySearchTree(int n){
                noOfNode=n;
       }
       node *createBST(int *arr){
            return createBST(arr,0,noOfNode-1);
       }
       node *createBST(int *arr,int start,int endNode){
           if(endNode<start){
            return NULL;
           }
            int mid=(start+endNode)/2;
            node *n=new node();
            n->data=arr[mid];
            n->left=createBST(arr,start,mid-1);
            n->right=createBST(arr,mid+1,endNode);
            return n;

       }
       void in_Order_Traversal(node *ptr){
        if(ptr!=NULL){
                in_Order_Traversal(ptr->left);
                cout<<ptr->data<<" ";
                in_Order_Traversal(ptr->right);
            }
       }
       void displayBST(node *root){
        cout<<"Display BST....."<<endl;
        in_Order_Traversal(root);
       }



};
int main(){
    int *arr=new int[10];
    for(int i=0;i<10;i++){
        arr[i]=i*i;
    }
    int n=(sizeof(int)*10)/sizeof(int);
//    cout<<n<<endl;
    node *root=NULL;

    CreateBinarySearchTree b(n);

    root=b.createBST(arr);
    b.displayBST(root);


    return 0;
}

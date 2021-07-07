#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
};
class ValidateBST{
private:
            int index=0;


public:
        node *createBST(node *root,int arr[],int i,int n){
            if(i<n){
                node *newNode=new node();
                newNode->data=arr[i];
                root=newNode;
                root->left=createBST(root->left,arr,2*i+1,n);
                root->right=createBST(root->right,arr,2*i+2,n);
            }
            return root;
        }
        void in_order(node *ptr){
            if(ptr!=NULL){
                in_order(ptr->left);
                cout<<ptr->data<<" ";
                in_order(ptr->right);
            }
        }

        void copyBST(node *ptr,int *arr){
                if(ptr==NULL){
                    return;
                }

                copyBST(ptr->left,arr);
                arr[index]=ptr->data;
                index++;
                copyBST(ptr->right,arr);

        }

//        bool checkBST(node *root,int n){
//            int *arr=new int[n];
//            copyBST(root,arr);
//            for(int i=1;i<n;i++){
////                    cout<<arr[i]<<" ";
//                   if(arr[i]<=arr[i-1]){
//                    return false;
//                   }
//            }
//            return true;
//        }
        bool checkBST(node *root){
            if(root==NULL) return true;

            if(!checkBST(root->left)){
                return false;
            }

            if(index!=0 && root->data<=index){
                return false;
            }
            index=root->data;

            if(!checkBST(root->right)){
                return false;
            }
            return true;

        }

            bool checkBST(node *root,int MIN,int MAX){
                if(root==NULL){
                    return true;
                }
               cout<<MIN<<" "<<MAX<<" "<<root->data<<endl;
               if((MIN!=NULL && root->data<=MIN)|| (MAX!=NULL && root->data>MAX)){
                    return false;
               }

               if(!checkBST(root->left,MIN,root->data) || !checkBST(root->right,root->data,MAX)){
                return false;
               }

               return true;
            }



};

int main(){
    node *root=NULL;
    ValidateBST obj;
    int arr[]={20,10,30,5,15,25,38};

    int n=sizeof(arr)/sizeof(arr[0]);
    root=obj.createBST(root,arr,0,n);
    obj.in_order(root);
    cout<<endl;

    //problem solve start
    bool flag;
    flag=obj.checkBST(root,NULL,NULL);
    if(flag){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


return 0;
}

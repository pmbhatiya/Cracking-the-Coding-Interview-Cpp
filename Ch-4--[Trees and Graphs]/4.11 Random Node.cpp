#include<bits/stdc++.h>
using namespace std;

class TreeNode{
private:
    int data;
    int Size=0;
public:
         TreeNode *left;
         TreeNode *right;
         TreeNode(int d){
            data=d;
            Size=1;
            left=NULL;
            right=NULL;

         }
         int size(){
            return Size;
         }
         int Data(){
            return data;
         }
         TreeNode* getRandomNode(){
             int leftSize=left==NULL?0:left->size();
             int index=rand()%Size;
//             cout<<index<<" "<<endl;
             if(index<leftSize){
                return left->getRandomNode();
             }else if(index==leftSize){
                return this;
             }else{
                return right->getRandomNode();
             }
         }
         void insertInOreder(int d){
             if(d<=data){
                if(left==NULL){
                    left=new TreeNode(d);
                }else{
                    left->insertInOreder(d);
                }
             }else{
                if(right==NULL){
                    right=new TreeNode(d);
                }else{
                    right->insertInOreder(d);
                }

             }
             Size++;
         }
         TreeNode *find(int d){
             if(d==data){
                return this;
             }else if(d<=data){
                return left!=NULL?left->find(d):NULL;
             }else if(d>data){
                return right!=NULL?right->find(d):NULL;
             }
             return NULL;
         }
};
int main(){
    TreeNode *obj=new TreeNode(20);
    int arr[]={10,30,35,15,17,5,7,3};
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++){
            obj->insertInOreder(arr[i]);
    }
         cout<<"Answer...."<<endl;

//    obj.inorder(obj);
    cout<<obj->getRandomNode()->Data()<<endl;
    cout<<obj->getRandomNode()->Data()<<endl;
    cout<<obj->getRandomNode()->Data()<<endl;
    cout<<obj->getRandomNode()->Data()<<endl;

//    cout<<obj->find(35)->Data()<<endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
};
class pathsWithSum{
public:
    node *createBT(node *root,int arr[],int i,int n){
        if(i<n){
            node *newNode=new node();
            newNode->data=arr[i];
            newNode->left=NULL;
            newNode->right=NULL;
            root=newNode;
            root->left=createBT(root->left,arr,2*i+1,n);
            root->right=createBT(root->right,arr,2*i+2,n);
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
    void incrementHashTable(map<int,int> &hashTable,int key,int delta){
        int newCount=hashTable[key]+delta;
        if(newCount==0){
            hashTable[key]=0;
        }else{
            hashTable[key]=newCount;
        }
    }
    int countPathsWithSum(node *root,int targetSum,int runningSum,map<int,int> &pathCount){
        if(root==NULL){
                return 0;
        }
        runningSum+=root->data;
        int sum=runningSum-targetSum;
        int totalPaths=pathCount[sum];

        if(runningSum==targetSum){
            totalPaths++;
        }

        incrementHashTable(pathCount,runningSum,1);
        totalPaths+=countPathsWithSum(root->left,targetSum,runningSum,pathCount);
        totalPaths+=countPathsWithSum(root->right,targetSum,runningSum,pathCount);
        incrementHashTable(pathCount,runningSum,-1);

        return totalPaths;
    }
    int countPathsWithSum(node *root,int targetSum){
        map<int,int> pathsCount;
        return countPathsWithSum(root,targetSum,0,pathsCount);
    }

};
int main()
{
    int arr[]={10,5,-3,3,2,0,11,3,-2,0,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    pathsWithSum obj;
    node *root=NULL;
    root=obj.createBT(root,arr,0,len);
    obj.In_order(root);
    cout<<endl;
    cout<<"total paths: "<<obj.countPathsWithSum(root,8);

    return 0;
}

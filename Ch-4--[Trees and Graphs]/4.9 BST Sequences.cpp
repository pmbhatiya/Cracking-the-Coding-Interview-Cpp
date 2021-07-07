#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
};
class BST_sequences{
public:
    node* createBST(node *root,int data){

        if(root==NULL){
                node *newNode=new node();
                newNode->data=data;
                newNode->left=NULL;
                newNode->right=NULL;
                return newNode;
        }else{
            node *tmp;
            if(root->data>data){
                tmp=createBST(root->left,data);
                root->left=tmp;

            }else{
                tmp=createBST(root->right,data);
                root->right=tmp;
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
    void wevedlist(list<int> first,list<int> second,list<list<int>> &results,list<int> prefix){
        if(first.size()==0 || second.size()==0){
            list<int> result;
            result.assign(prefix.begin(),prefix.end());
            list<int>::iterator i=first.begin();
            for(;i!=first.end();i++){
                result.push_back(*i);
            }
            i=second.begin();
             for(;i!=second.end();i++){
                result.push_back(*i);
            }
            results.push_back(result);
            return;
        }

        int headFirst=first.front();
        first.pop_front();
        prefix.push_back(headFirst);
        wevedlist(first,second,results,prefix);
        prefix.pop_back();
        first.push_front(headFirst);

        int headSecond=second.front();
        second.pop_front();
        prefix.push_back(headSecond);
        wevedlist(first,second,results,prefix);
        prefix.pop_back();
        second.push_front(headSecond);


    }
    list<list<int>> allSequences(node *root){
        list<list<int>> results;

        if(root==NULL){
            list<int> q;
            results.push_back(q);
            return results;
        }
        if (root -> left == NULL && root -> right == NULL) {
            list<int> seq;
            seq.push_back(root -> data);
            results.push_back(seq);
            return results;
    }

        list<int> prefix;
        prefix.push_back(root->data);

        list<list<int>> leftSeq=allSequences(root->left);
        list<list<int>> rightSeq=allSequences(root->right);
        list<list<int>>::iterator left=leftSeq.begin();
        list<list<int>>::iterator right=rightSeq.begin();

        for(;left!=leftSeq.end();left++){
            for(;right!=rightSeq.end();right++){
                list<list<int>> weaved;
                wevedlist(*left,*right,weaved,prefix);
//                results.assign(weaved.begin(),weaved.end());
                 list<list<int>>::iterator i=weaved.begin();
                 for(;i!=weaved.end();i++){
                        results.push_back(*i);
                 }
            }
        }
        return results;
    }

};

int main(){
    node *root=NULL;
    BST_sequences obj;
    int arr[]={7,5,9,1,6,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        root=obj.createBST(root,arr[i]);
    }

//    obj.in_order(root);
    list<list<int>> ans;
    ans=obj.allSequences(root);
    cout<<"Main Answer....."<<endl;
    list<list<int>>::iterator i=ans.begin();
    list<int>::iterator j;
    for(;i!=ans.end();i++){
        for(j=(*i).begin();j!=(*i).end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

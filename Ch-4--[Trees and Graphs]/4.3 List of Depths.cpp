#include<bits/stdc++.h>
using namespace std;
class node{
public:
        int data;
        node *left;
        node *right;
};
class createLinkedLevelofBST{
private:
    int noOfNode=7;
public:

        node *BST(node *root,int i,int n){
           if(i<n){
                node *newNode=new node();
                newNode->data=i+1;
                newNode->left=NULL;
                newNode->right=NULL;
                root=newNode;
                root->left=BST(root->left,2*i+1,n);
                root->right=BST(root->right,2*i+2,n);
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
//        vector<list<node*>> createLevelDepth(node *root){
//            vector<list<node*>> result;
//            list<node*> current;
//            if(root!=NULL){
//                current.push_back(root);
//            }
//            while(!current.empty()){
//
//                list<node*> next_depth;
//                for(node *ptr:current){
//
//                        if(ptr->left!=NULL){
//                            next_depth.push_back(ptr->left);
//                        }
//                        if(ptr->right!=NULL){
//                            next_depth.push_back(ptr->right);
//                        }
//
//                }
//                result.push_back(current);
//                current=next_depth;
//            }
//
//            return result;
//
//        }
        void createLevelDepth(node *root,vector<list<node*>> &lists,int level){

            if(root==NULL) return;

            list<node *> li;
            li.push_back(root);
            if(lists.size()==level){
                lists.push_back(li);
            }else{
                lists[level].push_back(root);
            }
            createLevelDepth(root->left,lists,level+1);
            createLevelDepth(root->right,lists,level+1);
        }
        vector<list<node*>> createLevelDepth(node *root){
            vector<list<node*>> result;
            createLevelDepth(root,result,0);

        return result;
        }
};
int main(){

    node *root=NULL;
    createLinkedLevelofBST obj;
    root=obj.BST(root,0,7);
    obj.in_order(root);
    cout<<endl;
    vector<list<node*>> ans;
    ans=obj.createLevelDepth(root);


    int len=ans.size();
    cout<<"printed Level LinkedList"<<endl;

    vector<list<node*> >::iterator iter;
    for(iter = ans.begin(); iter!= ans.end(); iter++){
        list<node*> li = *iter;
        list<node*>::iterator it;
        for(it = li.begin(); it!=li.end(); it++){
            node* ptr = *it;
            cout<<ptr->data<<" ";
        }
        cout<<'\n';
    }
//     int i=0;
//     list<node*>::iterator it;
//     while(i!=len){
//        it=ans[i].begin();
//        for(;it!=ans[i].end();it++){
//            cout<<(*it)->data<<" ";
//        }
//        cout<<endl;
//        i++;
//     }

return 0;
}

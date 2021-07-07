#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *left;
    node *right;
    node *parent;
};
//for second approch
class result{
public:
    node *add;
    bool isAncestor;
    result(node *ptr,bool isAnc){
        isAncestor=isAnc;
        add=ptr;
    }
};
//for second approch

class firstCommonAncestor{
private:
    list<node*> temp;
public:
    node *createBT(node *ptr,int arr[],int n,int i,node *parent){
        if(i<n){
                node *newNode=new node();
                newNode->data=arr[i];
                if(arr[i]==78 || arr[i]==96){
                    temp.push_back(newNode);
                }
                newNode->parent=parent;
                ptr=newNode;
                ptr->left=createBT(ptr->left,arr,n,2*i+1,ptr);
                ptr->right=createBT(ptr->right,arr,n,2*i+2,ptr);

        }
        return ptr;
    }
    void in_order(node *ptr){
        if(ptr!=NULL){
            in_order(ptr->left);
//            cout<<ptr->data<<" "<<ptr->parent->data<<endl;
              cout<<ptr->data<<" "<<endl;
              if(ptr->parent!=NULL){
                cout<<"Parent data : "<<ptr->parent->data<<" "<<endl;
              }
            in_order(ptr->right);
        }

    }
    list<node *> getFindNode(){
        return temp;
    }
    node * getSibling(node *ptr){
        if(ptr==NULL || ptr->parent==NULL){
            return NULL;
        }
        node *parent;
        parent=ptr->parent;
        return (parent->left==ptr?parent->right:parent->left);

    }
    bool covers(node *root,node *temp){
        if(root==NULL){
            return false;
        }
        if(root==temp){
            return true;
        }
        return (covers(root->left,temp)||covers(root->right,temp));

    }


      //second approach
      result *commonAncestorHelper(node *root,node *p,node *q){
          if(root==NULL){
            result *rNull=new result(NULL,false);
            return rNull;
          }
          if(root==p && root==q){
            result *rAns=new result(root,true);
            return rAns;
          }
          result *rx=commonAncestorHelper(root->left,p,q);
          if(rx->isAncestor){
            return rx;
          }

         result *ry=commonAncestorHelper(root->right,p,q);
          if(ry->isAncestor){
            return ry;
          }

          if(rx->add!=NULL && ry->add!=NULL){
            result *rAns=new result(root,true);
            return rAns;
          }else if(root==p || root==q){
            bool isAns=rx->add!=NULL || ry->add!=NULL;
            result *rAns=new result(root,isAns);
            return rAns;
          }else{
            result *rAns=new result(rx->add!=NULL?rx->add:ry->add,false);
            return rAns;
          }

      }
    node *commonAncestor(node *root,node *p,node*q){
        result *r=commonAncestorHelper(root,p,q);
        if(r->isAncestor){
            return (r->add);
        }
        return NULL;

    }
    //second end

};
int main(){
    node *root=NULL;
    firstCommonAncestor obj;
    int arr[]={12,36,54,78,96,31,45};
    int n=sizeof(arr)/sizeof(arr[0]);
    root=obj.createBT(root,arr,n,0,NULL);
//    obj.in_order(root);
    list<node*> nodesPQ;
    nodesPQ=obj.getFindNode();
    node *p,*q;
    p=nodesPQ.front();
    q=nodesPQ.back();
//    cout<<p->data<<" "<<q->data;
    node *ans;
    ans=obj.commonAncestor(root,p,q);
    cout<<ans->data;
    return 0;
}

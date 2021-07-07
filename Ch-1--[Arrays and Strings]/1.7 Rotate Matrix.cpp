#include<bits/stdc++.h>
using namespace std;

bool rotate90(int *mat,int rows,int cols){
    int n=rows;
    for(int layer=0;layer<n/2;layer++){

        int first=layer;
        int last=n-1-layer;
        for(int i=first;i<last;i++){
            int offset=i-first;
            int top=mat[first*n+i]; //save top

            //left->top
            mat[first*n+i]=mat[(last-offset)*n+first];

            //bootom->left
            mat[(last-offset)*n+first]=mat[last*n+(last-offset)];

            //right->bottom
            mat[last*n+(last-offset)]=mat[i*n+last];

            //top->right
            mat[i*n+last]=top;

        }

    }

    for(int x=0;x<rows;x++){
        for(int j=0;j<cols;j++){
            cout<<mat[x*4+j]<<" ";
        }
        cout<<endl;
    }
return true;
}

int main(){

    int mat[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    int n,rows,cols;
    n=sizeof(mat)/sizeof(int);
    rows=sizeof(mat)/sizeof(mat[0]);
    cols=n/rows;
//    cout<<n<<" "<<rows<<" "<<cols<<endl;
   bool flag;
   flag=rotate90(*mat,rows,cols);
   if(!flag){
    cout<<"Not Possible Rotation"<<endl;
   }

    return 0;
}

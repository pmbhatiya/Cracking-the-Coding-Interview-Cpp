#include<bits/stdc++.h>
using namespace std;
void nullifyRow(int *mat,int row,int cols,int n){
    for(int i=0;i<cols;i++){
        mat[row*n+i]=0;
    }

}
void nullifyCol(int *mat,int col,int rows,int n){
    for(int j=0;j<rows;j++){
        mat[n*j+col]=0;
    }

}
void setZeros(int *mat,int rows,int cols){
    bool rowHasZero=false;
    bool colHasZero=false;
    int n=rows;

    for(int i=0;i<cols;i++){
        if(mat[0*n+i]==0){
            rowHasZero=true;
            break;
        }
    }
    for(int j=0;j<rows;j++){
        if(mat[n*j+0]==0){
            colHasZero=true;
            break;
        }
    }
    for(int i=1;i<rows;i++){
        for(int j=1;j<cols;j++){
            if(mat[i*n+j]==0){
                mat[n*i+0]=0;
                mat[0*n+j]=0;
            }
        }
    }
    for(int i=1;i<rows;i++){
        if(mat[n*i+0]==0){
            nullifyRow(mat,i,cols,n);
        }
    }

    for(int j=1;j<cols;j++){
        if(mat[n*0+j]==0){
            nullifyCol(mat,j,rows,n);
        }
    }
    if(rowHasZero) nullifyRow(mat,0,cols,n);
    if(colHasZero) nullifyCol(mat,0,rows,n);


    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<mat[i*rows+j]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    int mat[4][4]={{1,2,3,4},
                   {5,6,7,8},
                   {9,0,11,12},
                   {13,14,15,0}};

   int rows,cols;
   rows=sizeof(mat)/sizeof(mat[0]);
   cols=(sizeof(mat)/sizeof(int))/rows;
   setZeros(&mat[0][0],rows,cols);


    return 0;
}

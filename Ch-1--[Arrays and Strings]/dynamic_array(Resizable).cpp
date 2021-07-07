#include<bits/stdc++.h>
using namespace std;

int* resizeArray(int *arr,int len)
{

    int *newArray=new int[len*2];
    memcpy(newArray,arr,len*sizeof(int));
    len=len*2;

    delete []arr;
    return newArray;
}

int main(){
    int *arr=new int[5];
    for(int i=0;i<5;i++){
        arr[i]=i*i*i;
    }

    arr=resizeArray(arr,5);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}



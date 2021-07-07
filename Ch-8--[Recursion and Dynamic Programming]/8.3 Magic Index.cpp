#include<bits/stdc++.h>
using namespace std;
int magicIndexDistinct(int arr[],int start,int end){
    if(end<start){
        return -1;
    }
    int mid=(start+end)/2;
    if(arr[mid]==mid){
        return mid;
    }else if(arr[mid]>mid){
        return magicIndexDistinct(arr,start,mid-1);
    }else{
        return magicIndexDistinct(arr,mid+1,end);
    }

}
int magicIndexNonDistinct(int arr[],int start,int end){
    if(end<start){
        return -1;
    }

    int mid=(start+end)/2;
    if(arr[mid]==mid){
        return mid;
    }
    int leftIndex=min(mid-1,arr[mid]);
    int left=magicIndexNonDistinct(arr,start,leftIndex);
    if(left>0){
        return left;
    }

    int rightIndex=max(mid+1,arr[mid]);
    int right=magicIndexDistinct(arr,rightIndex,end);

    return right;


}
int main(){

//    int arr[]={-40,-20,-1,1,2,3,5,7,9,12,13};
    int arr[]={-10,-5,2,2,2,3,4,7,9,12,13};
    int len=sizeof(arr)/sizeof(arr[0]);

    cout<<"Magic Index Is : "<<magicIndexDistinct(arr,0,len-1)<<endl;
    cout<<"Magic Index Is : "<<magicIndexNonDistinct(arr,0,len-1);
    return 0;

}

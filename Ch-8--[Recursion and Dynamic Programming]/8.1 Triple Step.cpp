#include<bits/stdc++.h>
using namespace std;
//int countWays(int n){
//    if(n<0){
//        return 0;
//    }else if(n==0){
//        return 1;
//    }else{
//        return countWays(n-1)+countWays(n-2)+countWays(n-3);
//    }
//}
int countWays(int n,int *arr){
    if(n<0){
        return 0;
    }else if(n==0){
        return 1;
    }else if(arr[n]>-1){
        return arr[n];
    }else{
        arr[n]=countWays(n-1,arr)+countWays(n-2,arr)+countWays(n-3,arr);
        return arr[n];
    }
}
int countWays(int n){
    int *arr=new int[n+1];
    fill(arr,arr+n+1,-1);
    return countWays(n,arr);
}

int main(){
    cout<<countWays(5);

    return 0;
}

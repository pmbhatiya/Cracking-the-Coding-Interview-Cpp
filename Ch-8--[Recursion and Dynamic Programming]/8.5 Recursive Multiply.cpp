#include<bits/stdc++.h>
using namespace std;

int minProductHelper(int smaller,int bigger){
    if(smaller==0){
        return 0;
    }else if(smaller==1){
        return bigger;
    }

    int s=smaller>>1;
    int side1=minProductHelper(s,bigger);
    int side2=side1;
    if(smaller%2==1){
        side2=minProductHelper(smaller-s,bigger);
    }
    return side1+side2;
}

//int minProduct(int a,int b){
//    int bigger=a>b?a:b;
//    int smaller=a>b?b:a;
//    return minProductHelper(smaller,bigger);
//}
int minProduct(int smaller,int bigger,int *memo){
    if(smaller==0){
        return 0;
    }else if(smaller==1){
        return bigger;
    }else if(memo[smaller]>0){
        return memo[smaller];
    }
    int s=smaller>>1;
    int side=minProduct(s,bigger,memo);
    int side2=side;
    if(smaller%2==1){

        side2=minProduct(smaller-s,bigger,memo);
    }


    memo[smaller]=side+side2;
    return memo[smaller];
}
int minProduct(int a,int b){
    int smaller=a>b?b:a;
    int bigger=a>b?a:b;
    int *memo=new int[smaller+1];
    fill(memo,memo+smaller+1,0);
    return minProduct(smaller,bigger,memo);

}
int main(){
    int a=9,b=7;
    cout<<minProduct(a,b);
return 0;
}

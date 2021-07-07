#include<bits/stdc++.h>
using namespace std;
int makeChange(int amount,int denoms[],int len,int index,map<string,int> &memo){
    if(amount==0) return 1;
    if(index>=len) return 0;
    string key=to_string(amount+index);
    if(memo[key]>0){
        return memo[key];
    }
    int denomAmount=denoms[index];
    int ways=0;

    for(int i=0;(i*denomAmount)<=amount;i++){
        int remainingAmount=amount-(i*denomAmount);
        ways+=makeChange(remainingAmount,denoms,len,index+1,memo);
    }
    memo[key]=ways;
    return ways;
}
int makeChange(int n){
    int denoms[]={25,10,5,1};
    int len=sizeof(denoms)/sizeof(denoms[0]);
    map<string,int> memo;
    return makeChange(n,denoms,len,0,memo);
}
int main(){
    int n=100;
    cout<<makeChange(n)<<endl;
    return 0;
}

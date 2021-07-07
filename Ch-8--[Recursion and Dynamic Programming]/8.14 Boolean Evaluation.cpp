#include<bits/stdc++.h>
using namespace std;
bool stringToBool(string c){
    if(c[0]=='1'){
        return true;
    }else{
        return false;
    }
}
int countEval(string s,bool result,map<string,int> &memo){
    if(s.size()==0) return 0;
    if(s.size()==1){
        return stringToBool(s)==result?1:0;
    }
    if(memo.find(to_string(result)+s)!=memo.end()){
        return memo[to_string(result)+s];
    }

    int ways=0;

    for(int i=0;i<s.size();i++){
        char c=s[i];

        string left=s.substr(0,i);
        string right=s.substr(i+1,s.size());

        int leftTrue=countEval(left,true,memo);
        int leftFalse=countEval(left,false,memo);
        int rightTrue=countEval(right,true,memo);
        int rightFalse=countEval(right,false,memo);

        int total=(leftTrue+leftFalse)*(rightTrue+rightFalse);

        int totalTrue=0;
        if(c=='^'){
            totalTrue=leftTrue*rightFalse+leftFalse*rightTrue;
        }else if(c=='&'){
            totalTrue=leftTrue*rightTrue;
        }else if(c=='|'){
            totalTrue=leftTrue*rightTrue+leftFalse*rightTrue+leftTrue*rightFalse;
        }

        int subWays=result?totalTrue:total-totalTrue;
        ways+=subWays;

    }
    memo[to_string(result)+s]=ways;
    return ways;
}
int main(){
    string exp="0&0&0&1^1|0";
    map<string,int> memo;
    cout<<countEval(exp,true,memo);
    return 0;
}

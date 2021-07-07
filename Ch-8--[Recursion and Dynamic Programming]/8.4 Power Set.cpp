#include<bits/stdc++.h>
using namespace std;
list<vector<int>> getSubsets(vector<int> &set,int index){
    list<vector<int>> allSubsets;
    if(set.size()==index){
        vector<int> emptySet;
        allSubsets.push_back(emptySet);
    }else{
        allSubsets=getSubsets(set,index+1);
        int item=set[index];
        list<vector<int>> mySubsets;
        for(auto subset:allSubsets){
                vector<int> newSubset;
                newSubset=subset;
                newSubset.push_back(item);
                mySubsets.push_back(newSubset);
        }
        list<vector<int>>::iterator i=mySubsets.begin();
        for(;i!=mySubsets.end();i++){
            allSubsets.push_back(*i);
        }
    }
    return allSubsets;
}
vector<int> convertIntToSet(int x,vector<int> &set){
    vector<int> subset;
    int index=0;
    for(int k=x;k>0;k>>=1){
        if((k&1)==1){
            subset.push_back(set[index]);
        }
        index++;
    }
    return subset;
}
list<vector<int>> getSubsetsSeconSolution(vector<int> &set){
    list<vector<int>> allSubsets;
    int maxValue=1<<set.size();
    for(int k=0;k<maxValue;k++){
        allSubsets.push_back(convertIntToSet(k,set));
    }

    return allSubsets;
}
int main(){
    vector<int> set{1,2,3};
    list<vector<int>> ans;
//    ans=getSubsets(set,0);
    ans=getSubsetsSeconSolution(set);
    list<vector<int>>::iterator i=ans.begin();
    for(;i!=ans.end();i++){
        vector<int>::iterator j=(*i).begin();
        for(;j!=(*i).end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

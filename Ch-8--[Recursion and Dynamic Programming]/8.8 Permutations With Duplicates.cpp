#include<bits/stdc++.h>
using namespace std;
map<char,int> buildFreqTable(string str){
    map<char,int> freq;
    int i=0;
    while(i!=str.size()){
        if(freq.find(str[i])==freq.end()){
            freq[str[i]]=0;
        }
        freq[str[i]]+=1;
        i++;
    }

    return freq;
}
void printPerms(map<char,int> &frequency,string prefix,int remaining,list<string> &result){
    if(remaining==0){
        result.push_back(prefix);
        return;
    }
    map<char,int>::iterator i=frequency.begin();
    for(;i!=frequency.end();i++){
        int count=frequency[i->first];
        if(count>0){
            frequency[i->first]-=1;
            printPerms(frequency,prefix+(i->first),remaining-1,result);
            frequency[i->first]=count;
        }
    }

}
list<string> printPerms(string str){
    list<string> result;
    map<char,int> frequency=buildFreqTable(str);
    printPerms(frequency,"",str.size(),result);
    return result;
}
int main(){
    string str="aabbbbc";
    list<string> ans;
    ans=printPerms(str);
    list<string>::iterator i=ans.begin();
    for(;i!=ans.end();i++){
        cout<<*i<<endl;
    }
    return 0;
}

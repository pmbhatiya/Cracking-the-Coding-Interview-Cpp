#include<bits/stdc++.h>
using namespace std;
string insertCharAt(string word,char c,int i){
    string start=word.substr(0,i);
    string end=word.substr(i);
    return (start+c+end);
}
list<string>  getPerms(string str){
    list<string> permutations;
    if(str.empty()){
        string s="";
        permutations.push_back(s);
        return permutations;
    }

    char first=str[0];
    string reminder=str.substr(1);
    list<string> words=getPerms(reminder);
    list<string>::iterator i=words.begin();
    for(;i!=words.end();i++){
        for(int j=0;j<=(*i).size();j++){
            string s=insertCharAt(*i,first,j);
            permutations.push_back(s);
        }
    }
    return permutations;
}

//second approach
void getParmsSecond(string prefix,string reminder,list<string> &result){
    if(reminder.size()==0){
        result.push_back(prefix);
    }

    int len=reminder.size();
    for(int i=0;i<len;i++){
        string before=reminder.substr(0,i);
        string after=reminder.substr(i+1,len);
        char c=reminder[i];
        getParmsSecond(prefix+c,before+after,result);
    }

}
list<string> getParmsSecond(string str){
    list<string> result;
    getParmsSecond("",str,result);
    return result;
}

//end of second approach
int main(){
    string str="ABCD";
    list<string> ans;
//    ans=getPerms(str);
    ans=getParmsSecond(str);
    list<string>::iterator i=ans.begin();
    for(;i!=ans.end();i++){
        cout<<*i<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool isUniqueChar(string str){
    if(str.length()>128){
        return false;
    }
    bool *charset=new bool[128];
    int val;
    for(int i=0;i<str.length();i++){
        val=int(str[i]);
        if(charset[val]){
            return false;
        }else{
            charset[val]=true;
        }
    }

    return true;
}
int main(){
    string s1="hello";
    string s2="normal";
    string s3="abcdefghijklmno";
    bool flag;
    flag=isUniqueChar(s3);

    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

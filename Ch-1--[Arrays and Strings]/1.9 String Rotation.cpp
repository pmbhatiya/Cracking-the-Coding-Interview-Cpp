#include<bits/stdc++.h>
using namespace std;
bool isSubstring(string source,string check){
     int s1Len=check.length();
     int s2Len=source.length();
     int j=0;
     for(int i=0;i<=s2Len-s1Len;i++){
        for(j=0;j<s1Len;j++){
            if(source[i+j]!=check[j]) break;
        }
        if(j==s1Len) return true;
     }

return false;
}
bool rotation(string source,string check){
    int len=source.length();
    if(len==check.length() && len>0){
        source=source+source;
        return isSubstring(source,check);
    }

    return false;
}
int main(){
    string s1="waterbottle";
    string s2="erbottlewat";
    bool flag=rotation(s1,s2);
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }


    return 0;
}

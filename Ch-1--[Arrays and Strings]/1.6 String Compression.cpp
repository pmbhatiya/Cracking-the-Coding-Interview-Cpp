#include<bits/stdc++.h>
using namespace std;
int compressedLen(string str){
    int len=0;
    int countContinue=0;
    for(int i=0;i<str.length();i++){
        countContinue++;
        if(i+1>=str.length() || str[i]!=str[i+1]){
            len+=to_string(countContinue).length()+1;
            countContinue=0;
        }


    }
return len;
}
string stringComprison(string source){

    int finalLen=compressedLen(source);
    if(finalLen>=source.length()) return source;

    string compress="";
    int conCount=0;

    for(int i=0;i<source.length();i++){
        conCount++;
        if(i+1>=source.length() || source[i]!=source[i+1]){
            compress.append(1,source[i]);
            compress.append(to_string(conCount));
            conCount=0;
        }
    }
return compress;
}
int main(){

    string s1="aaacccwweeer";
    cout<<stringComprison(s1);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
//three type of modification can perform on string
// 1. insert -->>other string have one greter length
// 2. delete -->other string less than one length
// 3. replace (modify) -->both string same length than replace


//bool oneReplace(string source,string check){
//    bool differanceCheck=false;
//    for(int i=0;i<source.length();i++){
//        if(source[i]!=check[i]){
//            if(differanceCheck){
//                return false;
//            }
//            differanceCheck=true;
//        }
//    }
//    return true;
//}
//bool oneInsert(string source,string check){
//    int index=0,index2=0;
//
//    string s1=source.length()<check.length()?source:check;
//    string s2=source.length()<check.length()?check:source;
//    while(index<s1.length() && index2<s2.length()){
//        if(s1[index]!=s2[index2]){
//            if(index!=index2){
//                return false;
//            }
//            index2++;
//
//        }else{
//            index++;
//            index2++;
//
//        }
//    }
//    return true;
//}
//bool oneaway(string source,string check){
//    if(source.length()==check.length()){
//        return oneReplace(source,check);
//    }else if(source.length()-1==check.length()){ //true than it can be one away insert
//        return oneInsert(source,check);
//    }else if(source.length()+1==check.length()){ //true than it can be one away modify(delete)
//        return oneInsert(source,check);
//    }
//
//return false;
//}
bool oneaway(string source,string check){
    int s1Len=source.length(),s2Len=check.length();
    if(abs(s1Len-s2Len)>1){
        return false;
    }
    string s1=s1Len<s2Len?source:check;
    string s2=s1Len<s2Len?check:source;
    s1Len=s1.length();
    s2Len=s2.length();
    int index=0,index2=0;
    bool differance=false;
    bool equalLength=false;
    if(s1Len==s2Len){
        equalLength=true;
    }
    while(index<s1Len && index2<s2Len){
        if(s1[index]!=s2[index2]){

            if(differance) return false;
            differance=true;

            if(equalLength) index++;
        }else{
            index++;
        }
        index2++;
    }
    return true;
}
int main(){

    string s1="pale"; //source
    string s2="pales";//source

    string c1="ple"; //check
    string c2="pale"; //check
    string c3="bale"; //check
    string c4="bae"; //check
    string c5="ale"; //check
    bool flag;
    flag=oneaway(s1,c5);

    if(flag){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}

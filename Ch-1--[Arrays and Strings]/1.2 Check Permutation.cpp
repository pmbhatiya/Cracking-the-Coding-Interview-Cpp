#include<bits/stdc++.h>
using namespace std;
//bool Check_permutation(string source,string destination){
//    if(source.length()!=destination.length()){
//        return false;
//    }
//    sort(source.begin(),source.end());
//    sort(destination.begin(),destination.end());
//    return (source==destination);
//
//}

bool Check_permutation(string source,string destination){
    if(source.length()!=destination.length()){
        return false;
    }
   int *charset=new int[128];
   for(int i=0;i<source.length();i++){
    charset[int(source[i])]++;
   }
   int charData;
   for(int j=0;j<destination.length();j++){
    charData=int(destination[j]);
    charset[charData]--;

    if(charset[charData]<0){
            return false;
    }
   }
    return true;
}
int main(){
    string s1="hello";
    string s2="olleh";
    bool flag;
    flag=Check_permutation(s1,s2);
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}

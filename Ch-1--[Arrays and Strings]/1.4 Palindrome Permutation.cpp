#include<bits/stdc++.h>
using namespace std;

bool permuatationPalindromeCheck(string str){
    int *charset=new int[128];
    int oddNo=0,temp=0;

    memset(charset,0,128*sizeof(int));
    for(int i=0;i<str.length();i++){
        if(str[i]==' ')
            continue;
        temp=int(str[i]);
        charset[temp]++;
        if(charset[temp]%2==1){
            oddNo++;
        }else{
            oddNo--;
        }
    }
    cout<<oddNo<<endl;
return (oddNo<=1);
}
int main(){
    string s1="tact coa";
    bool flag;
    flag=permuatationPalindromeCheck(s1);
    if(flag){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}

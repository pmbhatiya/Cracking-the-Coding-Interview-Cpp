#include<bits/stdc++.h>
using namespace std;
string URLify(string source,int trueLength){
    int spaces=0,index=0,i=0;
    for(i=0;i<trueLength;i++){
        if(source[i]==' '){
            spaces+=1;
        }
    }
    index=trueLength+(spaces*2);
    if(trueLength<source.length()){
        source[trueLength]='\0';
    }
    for(i=trueLength-1;i>=0;i--){
        if(source[i]==' '){
                source[index-1]='0';
                source[index-2]='2';
                source[index-3]='%';
                index=index-3;
        }else{
            source[index-1]=source[i];
            index--;

        }

    }
return source;
}
int main(){
    string s1="Mr John Smith    ";
    int trueLength=13;
    cout<<URLify(s1,trueLength);

    return 0;
}

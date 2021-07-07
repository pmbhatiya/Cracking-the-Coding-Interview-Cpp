#include<bits/stdc++.h>
using namespace std;

string joinWords(string words[],int n){
    string sentence="";
    for(int i=0;i<n;i++){
        sentence=sentence+words[i];
    }
 return sentence;
}
string stringBuilder(string words[],int n){
    string sentence="";
    for(int i=0;i<n;i++){
        sentence.append(words[i]);
    }

    return sentence;
}
string StringStream(string words[],int n){
    stringstream s;
    for(int i=0;i<n;i++){
        s<<words[i];
    }
    return s.str();
}
int main(){
    string s1[]={"Hello1","Hello2","Hello3","Hello4","Hello5","Hello6","Hello7","Hello8","Hello9","Hello10"};
    int n=sizeof(s1)/sizeof(s1[0]);
//    cout<<joinWords(s1,n)<<endl;
//    cout<<stringBuilder(s1,n)<<endl;
      cout<<StringStream(s1,n)<<endl;
    return 0;

}

#include<bits/stdc++.h>
using namespace std;
string insertInside(string str,int leftIndex){
    string left=str.substr(0,leftIndex+1);
    string right=str.substr(leftIndex+1,str.size());
    return left+"()"+right;

}
set<string> generateParens(int remaining){
    set<string> result;

    if(remaining==0){
        result.insert("");
    }else{
        set<string> prev=generateParens(remaining-1);
        set<string>::iterator itr=prev.begin();
        for(;itr!=prev.end();itr++){
            for(int i=0;i<(*itr).size();i++){
                if((*itr)[i]=='('){
                    string s=insertInside((*itr),i);
                    result.insert(s);
                   }
            }
            result.insert("()"+(*itr));
        }

    }
    return result;
}

//second approach
void addParen(list<string> &result,int leftRem,int rightRem,char *str,int count){
    if(leftRem<0 || rightRem<leftRem ) return;

    if(leftRem==0 && rightRem==0){
        int index=0;
        string s;
        while(str[index]!='\0'){
            s+=str[index];
            index++;
        }
        result.push_back(s);
    }else{
        if(leftRem>0){
            str[count]='(';
            addParen(result,leftRem-1,rightRem,str,count+1);
        }
        if(rightRem>leftRem){
            str[count]=')';
            addParen(result,leftRem,rightRem-1,str,count+1);
        }

    }
}
list<string> generateParensSecond(int count){
    char *str=new char[count*2];
//    fill(str,str+(count*2),'0');
    list<string> result;
    addParen(result,count,count,str,0);
    return result;

}

//end of second approach
int main(){
    int n=4;
    set<string> ans;
    ans=generateParens(n);
    set<string>::iterator i=ans.begin();
    for(;i!=ans.end();i++){
        cout<<*i<<endl;
    }

    cout<<"Second approach answer..."<<endl;
    list<string> ansSecond;
    ansSecond=generateParensSecond(n);
    list<string>::iterator j=ansSecond.begin();
    for(;j!=ansSecond.end();j++){
        cout<<*j<<endl;
    }
    return 0;
}

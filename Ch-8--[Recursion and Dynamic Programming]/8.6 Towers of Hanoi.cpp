#include<bits/stdc++.h>
using namespace std;
class Tower{
public:
    stack<int> disks;
    int index;
    Tower(int i){
        index=i;
    }
    int Index(){
        return index;
    }
    void add(int d){
        if(!disks.empty() && disks.top()<=d)
        {
            cout<<"Error Placing Disks : "<<d<<endl;
        }else{
            disks.push(d);
        }
    }
    void moveTopTo(Tower *t){
        int top=disks.top();
//        cout<<disks.top()<<endl;
        disks.pop();
        t->add(top);
    }
    void moveDisks(int n,Tower *destination,Tower *buffer){
        if(n>0){
            moveDisks(n-1,buffer,destination);
            moveTopTo(destination);
            moveDisks(n-1,destination,this);
        }
    }
    void printTower(){
        while(!disks.empty()){
            cout<<disks.top()<<" ";
            disks.pop();
        }
    }

};
int main(){
    int n=3;
    Tower *towers[n];
    for(int i=0;i<n;i++){
        towers[i]=new Tower(i);
    }
    for(int i=n;i>0;i--){
        towers[0]->add(i);
    }
    towers[0]->moveDisks(n,towers[2],towers[1]);
    towers[2]->printTower();

    return 0;
}

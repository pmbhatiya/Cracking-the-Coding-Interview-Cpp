#include<bits/stdc++.h>
using namespace std;
class setOfStack{
        private:
                vector<stack<int>> stacks;
                int capacity;
                int curuntIndex=0;
        public:
                setOfStack(int cap){
                    capacity=cap;
                    stack<int> s;
                    stacks.push_back(s);
                }
                void push(int data){
                       if(stacks[curuntIndex].size()==capacity){
                            stack<int> newStack;
                            curuntIndex++;
                            stacks.push_back(newStack);
                       }
                       if(stacks[curuntIndex].size()<capacity){
                        stacks[curuntIndex].push(data);
                       }
                }

                void pop(){
                    if(!stacks[curuntIndex].empty()){
                        stacks[curuntIndex].pop();
                    }
                    if(stacks[curuntIndex].empty() && stacks.size()>1){
                        stacks.pop_back();
                        curuntIndex--;
                    }

                }
                int mystacksTop(){
                    return stacks[curuntIndex].top();
                }
                int popAt(int index){
                        int popData=0;
                        if(curuntIndex+1<index){
                            cout<<"Not found stack"<<endl;
                            return popData;
                        }else if(curuntIndex+1==index){
                                popData=stacks[curuntIndex].top();
                                pop();
                                return popData;
                        }else{
                                popData=stacks[index-1].top();
                                if(stacks[index-1].size()==1){
                                    index-=1;
                                    curuntIndex--;
                                    stacks.erase(stacks.begin()+index);
                                }else{
                                    stacks[index-1].pop();
                                }
                                return popData;
                        }

                }

};
int main(){

    setOfStack obj(3);

    obj.push(23);
    obj.push(24);
    obj.push(25);

    obj.push(126);
    obj.push(123);
    obj.push(213);

    obj.push(231);
    obj.push(129);

    cout<<obj.popAt(2)<<endl;
    cout<<obj.popAt(2)<<endl;
    cout<<obj.popAt(2)<<endl;


//    obj.pop();
//    obj.pop();
//    obj.pop();
    cout<<obj.mystacksTop();
    return 0;
}

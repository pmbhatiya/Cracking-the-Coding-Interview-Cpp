#include<bits/stdc++.h>
using namespace std;
class MyQueue{
private:
        stack<int> newestStack;
        stack<int> oldestStack;
public:
    void push(int data){
        newestStack.push(data);
    }

    int pop(){
        shiftStacks();
        int popData=oldestStack.top();
        oldestStack.pop();
        return popData;
    }
    void shiftStacks(){
        if(oldestStack.empty()){
            while(!newestStack.empty()){
            oldestStack.push(newestStack.top());
            newestStack.pop();
        }
        }
    }
    int peek(){
        shiftStacks();
        return oldestStack.top();
    }

};
int main(){
    MyQueue obj;
    obj.push(10);
    obj.push(65);
    obj.push(110);
    cout<<obj.pop()<<endl;
    obj.push(615);
    obj.push(120);
    cout<<obj.pop()<<endl;
    obj.push(651);
    cout<<obj.peek()<<endl;
    cout<<obj.pop()<<endl;
    return 0;
}

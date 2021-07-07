#include<bits/stdc++.h>
using namespace std;
class sortStack{
private:
        stack<int> myStack;
public:
        void push(int data){
                myStack.push(data);
        }
        void pop(){
             myStack.pop();
        }
        int peek(){
             return myStack.top();
        }
        bool isEmpty(){
            return (myStack.empty());
        }
        void sorting(){
            stack<int> r;
            int tmp;
            while(!myStack.empty()){
                tmp=myStack.top();
                myStack.pop();
                while(!r.empty() && r.top()>tmp){
                    myStack.push(r.top());
                    r.pop();
                }
                r.push(tmp);
            }
          while(!r.empty()){
                 myStack.push(r.top());
                 r.pop();
          }
        }
        void printStack(){
            stack<int> print=myStack;
            while(!print.empty()){
                cout<<print.top()<<" ";
                print.pop();

            }

        }

};
int main(){
    sortStack obj;
    obj.push(7);
    obj.push(8);
    obj.push(1);
    obj.push(12);
    obj.push(5);

    obj.sorting();
    obj.printStack();



    return 0;
}

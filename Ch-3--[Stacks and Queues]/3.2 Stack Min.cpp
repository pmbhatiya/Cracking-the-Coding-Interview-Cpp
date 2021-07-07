#include<bits/stdc++.h>
using namespace std;
//First approach
//class stackNode{
//public:
//        int data;
//        int minValue;
//};
//class MyStack{
//private:
//        int sizeOfStack=10;
//        int top=-1;
//        stackNode *arr=new stackNode[sizeOfStack];
//public:
//        void push(int val){
//            if(isFull()){
//                cout<<"Stack is Full"<<endl;
//            }else{
//                top++;
//                arr[top].data=val;
//                arr[top].minValue=min(val,myMin());
//            }
//        }
//        int pop(){
//            if(isEmpty()){
//                cout<<"Stack is Empty"<<endl;
//            }else{
//                int value=arr[top].data;
//                arr[top].data=NULL;
//                arr[top].minValue=NULL;
//                top--;
//                return value;
//            }
//            return 0;
//        }
//        int myMin(){
//            if(isEmpty()){
//                return 100000;
//            }else{
//
//                return arr[top-1].minValue;
//            }
//
//        }
//        int peek(){
//            if(isEmpty()){
//
//                cout<<"Stack is empty"<<endl;
//            }else{
//
//                return arr[top].data;
//            }
//        }
//        bool isEmpty(){
//            return top==-1;
//        }
//        bool isFull(){
//            return top==sizeOfStack-1;
//        }
//
//};
//end of first approach
//second approach code
class secondApproach{
private:
     stack<int> super;
     stack<int> minStack;
public:
        void push(int val){
            if(val<=mymin()){
                minStack.push(val);
            }
            super.push(val);
        }
        int pop(){
            int val=super.top();
            super.pop();
            if(val==mymin()){
                minStack.pop();
            }
            return val;
        }
        int mymin(){
            if(minStack.empty()){
                return INT_MAX;
            }else{
                return minStack.top();
            }

        }


};

//end of code second
int main(){
//first approach

//    MyStack obj;
//    obj.push(10);
//    obj.push(20);
//    obj.push(30);
//    obj.push(40);
//    obj.push(50);
//    cout<<obj.pop()<<" ";
//    cout<<obj.pop()<<" ";
//    cout<<obj.pop()<<" ";
//    cout<<endl;
//    cout<<obj.peek();

//first approach it will take more space

//second approach
    secondApproach obj;

    obj.push(10);
    obj.push(50);
    obj.push(110);
    obj.push(150);
    obj.push(1110);
    obj.push(40);

    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;

    cout<<obj.mymin()<<endl;

//end of second approach
    return 0;
}

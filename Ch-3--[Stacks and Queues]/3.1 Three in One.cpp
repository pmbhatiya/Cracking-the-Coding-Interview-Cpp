#include<bits/stdc++.h>
using namespace std;

class FixedMultiStack{
private: int numberOfStack=3;
         int stackCapacity;
         int *values;
         int *sizes;
public:
        FixedMultiStack(int stackSize){
            stackCapacity=stackSize;
            values=new int[stackSize * numberOfStack];
            sizes=new int[numberOfStack+1];

        };
        void push(int stackNum,int data){
            if(isFull(stackNum)){
                cout<<"Stack is Full Completely"<<endl;
            }else{
            sizes[stackNum]++;
            values[indexOfTop(stackNum)]=data;
            }
        }
        int pop(int stackNo){
            if(isEmpty(stackNo)){
                cout<<"Stack is empty"<<endl;
            }else{
                int index=indexOfTop(stackNo);
                int val=values[index];
                values[index]=0;
                sizes[stackNo]--;
                return val;
            }

            return 0;
        }
        int peek(int stackNo)
        {
            if(isEmpty(stackNo)){
                return 0;
            }
            return values[indexOfTop(stackNo)];
        }
        void displayStack(int stackNo){
            int j=stackNo*stackCapacity+sizes[stackNo]-1;
            for(int i=j;i>=stackNo*stackCapacity;i--){
                cout<<values[i]<<" ";
            }
            cout<<endl;
        }
        int indexOfTop(int stackNum){
            int offset=stackNum*stackCapacity;
            int sizeofStack=sizes[stackNum];
            return offset+sizeofStack-1;
        }

        bool isFull(int stackNum){
            return sizes[stackNum]==stackCapacity;
        }
        bool isEmpty(int stackNum){
            return sizes[stackNum]==0;
        }

        ~FixedMultiStack(){
            delete []values;
            delete []sizes;
        }

};

int main(){

    FixedMultiStack obj(10);


    obj.push(1,20);
    obj.push(1,30);
    obj.push(1,40);
    obj.push(1,50);

    obj.push(2,60);
    obj.push(2,70);
    obj.push(2,80);
    obj.push(2,90);

    obj.push(3,160);
    obj.push(3,170);
    obj.push(3,180);
    obj.push(3,190);

    cout<<endl;
    obj.displayStack(1);
    obj.displayStack(2);
    obj.displayStack(3);
    cout<<endl;

    cout<<"delted Node"<<endl;
    cout<<obj.pop(1)<<endl;
    cout<<obj.pop(2)<<endl;
    cout<<obj.pop(3)<<endl;

    cout<<"Display Peek of Each Stack"<<endl;
    cout<<obj.peek(1)<<endl;
    cout<<obj.peek(2)<<endl;
    cout<<obj.peek(3)<<endl;


    cout<<"End of Code";

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Box{
    public:
        int height;
};
int createStack(vector<Box*> &boxes,int bottomIndex,int stackMap[]){
    if(bottomIndex<boxes.size() && stackMap[bottomIndex]>0){
        return stackMap[bottomIndex];
    }
    Box *bottom=boxes[bottomIndex];
    int maxHeight=0;
    for(int i=bottomIndex+1;i<boxes.size();i++){
        if((bottom->height)<(boxes[i]->height)){
            int height=createStack(boxes,i,stackMap);
            maxHeight=max(maxHeight,height);
        }
    }
    maxHeight+=bottom->height;
    stackMap[bottomIndex]=maxHeight;
    return maxHeight;

}
int comapare(Box *x,Box *y){
    return (y->height-x->height);
}
int createStack(vector<Box*> &boxes){
    sort(boxes.begin(),boxes.end(),comapare);
    int stackMap[boxes.size()]={};
    int maxHeight=0;
    for(int i=0;i<boxes.size();i++){
        int height=createStack(boxes,i,stackMap);
        maxHeight=max(maxHeight,height);
    }
    return maxHeight;
}
int main(){
    vector<Box*> boxes;
    for(int j=32;j!=22;j--){
        Box *newBox=new Box();
        newBox->height=j;
        boxes.push_back(newBox);
    }
    cout<<createStack(boxes);

//    list<Box*>::iterator i=boxes.begin();
//    for(;i!=boxes.end();i++){
//        cout<<(*i)->height<<" ";
//    }
    return 0;
}

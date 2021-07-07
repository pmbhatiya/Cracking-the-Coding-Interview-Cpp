#include<bits/stdc++.h>
using namespace std;
int GRID_SIZE=8;
bool checkValid(vector<int> &columns,int row1,int column1){
    for(int row2=0;row2<row1;row2++){
        int column2=columns[row2];

        if(column1==column2)
                return false;

        int columDistance=abs(column2-column1);
        int rowDistance=row1-row2;

        if(columDistance==rowDistance){
            return false;
        }
    }
    return true;
}
void placeQueens(int row,vector<int> columns,list<vector<int>> &results){
    if(row==GRID_SIZE){
        results.push_back(columns);
    }else{

        for(int col=0;col<GRID_SIZE;col++){
            if(checkValid(columns,row,col)){
                columns[row]=col;
                placeQueens(row+1,columns,results);
            }
        }

    }
}
int main(){
    vector<int> columns{-1,-1,-1,-1,-1,-1,-1,-1};
    list<vector<int>> results;
    placeQueens(0,columns,results);
    list<vector<int>>::iterator i=results.begin();
    for(;i!=results.end();i++){
        vector<int>::iterator j=(*i).begin();
        for(;j!=(*i).end();j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }

    return 0;
}

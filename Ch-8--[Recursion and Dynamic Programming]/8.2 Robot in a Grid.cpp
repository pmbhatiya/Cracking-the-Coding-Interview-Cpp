#include<bits/stdc++.h>
using namespace std;
class Point{
    public:
        int row;
        int col;
     Point(int r,int c){
        row=r;
        col=c;
    }
};
int **createMatrix(int rows,int cols){
    int **matrix=new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            matrix[i][j]=1;
        }
    }
    return matrix;
}
bool getPath(int **matrix,int currRow,int currCol,vector<Point*> &path,unordered_set<Point*> &duplicateVisits){
    if(currRow<0 || currCol<0 || matrix[currRow][currCol]==-1){
        return false;
    }

    Point * currPos=new Point(currRow,currCol);

    if(duplicateVisits.find(currPos)!=duplicateVisits.end()){
        return false;
    }

    bool atOrigin=currRow==0 && currCol==0;
    if(atOrigin || getPath(matrix,currRow-1,currCol,path,duplicateVisits) || getPath(matrix,currRow,currCol-1,path,duplicateVisits)){
        path.push_back(currPos);
        return true;
    }
    duplicateVisits.insert(currPos);
    return false;
}
vector<Point *> getPath(int **matrix,int row,int col){
    vector<Point*> path;
    unordered_set<Point *> duplicteVisits;


    if(row!=0 || matrix!=nullptr){
        if(getPath(matrix,row-1,col-1,path,duplicteVisits)){
            return path;
        }
    }

    return path;
}
int main(){
    int **matrix=createMatrix(5,7);
    matrix[1][3] = -1;
    matrix[2][5] = -1;
    matrix[3][2] = -1;
    matrix[0][1] = -1;

    vector<Point *>path=getPath(matrix,5,7);
    if(path.size()==0){
        cout<<"Paths Not Exists"<<endl;
    }else{
            for(int i=0;i<path.size();i++){
                cout<<path[i]->row<<" "<<path[i]->col<<endl;
            }

    }


    return 0;
}

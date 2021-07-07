#include<bits/stdc++.h>
using namespace std;
enum Color{Black,White,Red,Blue,green};
bool PaintFill(Color screen[4][4],int r,int c,Color oColor,Color nColor){
    if(r<0 || r>=4 || c<0 || c>=4){
        return false;
    }
    if(screen[r][c]==oColor){
            screen[r][c]=nColor;
            PaintFill(screen,r-1,c,oColor,nColor);
            PaintFill(screen,r+1,c,oColor,nColor);
            PaintFill(screen,r,c-1,oColor,nColor);
            PaintFill(screen,r,c+1,oColor,nColor);
    }
    return true;
}
bool PaintFill(Color screen[4][4],int r,int c,Color nColor){
    if(screen[r][c]==nColor) return false;
    return PaintFill(screen,r,c,screen[r][c],nColor);
}

int main(){
    Color screen[4][4]={{Black,Black,Red,Blue},{Black,White,Red,Blue},{Black,Black,Red,Blue},{green,White,Red,Blue}};

    if(PaintFill(screen,0,0,Red)){
        cout<<"Yes"<<endl;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<screen[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

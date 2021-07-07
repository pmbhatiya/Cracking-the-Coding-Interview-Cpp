#include<bits/stdc++.h>
using namespace std;
class graph{
private:
        int noOfVertex;
        list<int> *adj;

public:
    graph(int n){
        adj=new list<int>[n];
        noOfVertex=n;
    }

    void addEdge(int v,int e){
        adj[v].push_back(e);
    }

    bool Bfs(int source,int destination){
        if(source==destination) return true;

        bool *visited=new bool[noOfVertex];
        for(int i=0;i<noOfVertex;i++){
            visited[i]=false;
        }

        queue<int> q;
        q.push(source);
        visited[source]=true;
        list<int>::iterator i;
        int curruntNode;
        while(!q.empty()){
                curruntNode=q.front();
//                cout<<curruntNode<<" ";
                for(i=adj[curruntNode].begin();i!=adj[curruntNode].end();i++){
                    if(!visited[*i]){
                        if(*i==destination){
                            return true;
                        }
                        else{
                            visited[*i]=true;
                            q.push(*i);
                        }
                    }
                }
            q.pop();
        }
        return false;
    }

};
int main(){

    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    bool flag;
    flag=g.Bfs(2,3);
    if(flag){
        cout<<"Found Path -->Yes"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}

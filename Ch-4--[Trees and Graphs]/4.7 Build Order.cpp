#include<bits/stdc++.h>
using namespace std;
class Project{
private:
    list<Project*> children;
    map<char,Project*> hashMap;
    char name;
    int state=0;
public:
    void setName(char name){
        this->name=name;
    }
    char getName(){
        return name;
    }
    void setState(int val){
        state=val;
    }
    int getState(){
        return state;
    }
    void addNeighbor(Project *node){
        if(hashMap.find(node->getName())==hashMap.end()){
            children.push_back(node);
            hashMap[node->getName()]=node;
        }
    }

    list<Project*> getChildren(){
        return children;
    }
};
class Graph{
private:
    list<Project*> nodes;
    map<char,Project*> hashMap;
public:
    void createNode(char name){
        if(hashMap.find(name)==hashMap.end()){
            Project *node=new Project();
            node->setName(name);
            nodes.push_back(node);
            hashMap[name]=node;
        }
    }
    Project* getNode(char name){
        return hashMap[name];
    }

    void addEdge(char startName,char endName){
        Project *start=getNode(startName);
        Project *End=getNode(endName);
        start->addNeighbor(End);
    }
    list<Project*> getNodes(){
        return nodes;
    }

} ;

class findBuildOrder{
public:
    Graph buildGraph(char *proj,char dependency[][2],int dependency_len){
        Graph g;
        int i=0,len=strlen(proj);
        while(i!=len){
            g.createNode(proj[i]);
            i++;
        }

        for(int j=0;j<dependency_len;j++){
            char first=dependency[j][0];
            char second=dependency[j][1];
            g.addEdge(first,second);
       }
        return g;

    }
    bool DFS(Project *project,stack<Project*> &Stack){
        if(project->getState()==1){
            return false;
        }
        if(project->getState()==0){
            project->setState(1);
            list<Project*> children=project->getChildren();
            list<Project*>::iterator m=children.begin();
            for(;m!=children.end();m++){
                if(!DFS(*m,Stack)){
                    return false;
                }
            }
            project->setState(2);
            Stack.push(project);
        }

        return true;
    }
    stack<Project*> orderProjects(list<Project*> projects){
        stack<Project*> Stack;
        list<Project*>::iterator i=projects.begin();

        while(i!=projects.end()){
            if((*i)->getState()==0){
                if(!DFS(*i,Stack)){
                    return Stack;
                }
            }
            i++;
        }
        return Stack;

    }
};
int main(){
    char projects[]={'a','b','c','d','e','f','p','\0'};
    char dependency[][2]={{'a','d'},{'f','b'},{'b','d'},{'f','a'},{'d','c'},{'b','p'}};
    findBuildOrder obj;
    int len=sizeof(dependency)/sizeof(dependency[0]);
    Graph g;
    g=obj.buildGraph(projects,dependency,len);
    stack<Project*> Stack=obj.orderProjects(g.getNodes());
    cout<<"Stack final Answer"<<endl;
    while(!Stack.empty()){
        cout<<(Stack.top())->getName()<<" ";
        Stack.pop();
    }
    return 0;
}
//ans: f,e,b,p,a,d,c

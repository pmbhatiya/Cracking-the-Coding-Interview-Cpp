#include<bits/stdc++.h>
using namespace std;
class Animal{
public:
     string name;
     string type;
     int time;
};
class Dog:public Animal{
public:
    Dog(string name){
        this->name=name;
        type="dog";
    }

};
class Cat:public Animal{
public:
        Cat(string name){
            this->name=name;
            type="cat";
        }
};
class shelter{
private:
        int Time=0;
        queue<Dog> dogs;
        queue<Cat> cats;
public:
        void enqueue(Dog d){
            d.time=Time++;
            dogs.push(d);
        }
        void enqueue(Cat c){
            c.time=Time++;
            cats.push(c);
        }
        Animal dequeueAny(){
            if(dogs.size() && cats.size()){
                    Dog d=dogs.front();
                    Cat c=cats.front();
                    Animal ans=d.time<=c.time?(Animal)dequeueDogs():(Animal)dequeueCats();
                    return ans;

            }
            else if(dogs.size()==0){
                return (Animal)dequeueCats();
            }
            else if(cats.size()==0){
                return (Animal)dequeueDogs();
            }
            Animal obj;
            return obj;

        }
        Dog dequeueDogs(){
            if(dogs.size()==0){
                cout<<"Empty Dogs"<<endl;
                Dog o("NULL");
                return o;
            }
            Dog d=dogs.front();
            dogs.pop();
            return d;
        }
        Cat dequeueCats(){
            if(cats.size()==0){
                cout<<"Empty Cats"<<endl;
                Cat c("NULL");
                return c;
            }
            Cat c=cats.front();
            cats.pop();
            return c;
        }
};
int main(){
    shelter s;
    Dog d1("Montu"),d2("Chintu"),d3("Pinku");
    Cat c1("Rani"),c2("Emma"),c3("Jully");
    s.enqueue(d1);
    s.enqueue(c1);
    s.enqueue(d2);
    s.enqueue(d3);
    s.enqueue(c2);
    s.enqueue(c3);
    cout<<s.dequeueDogs().name<<endl;
    cout<<s.dequeueCats().name<<endl;
    cout<<s.dequeueAny().name<<endl;
    cout<<s.dequeueCats().name<<endl;
    cout<<s.dequeueCats().name<<endl;
return 0;
}

#include<iostream>
using namespace std;

class Queue{
private:
    int * arr;
    int maxSize, CurSize, Front, Rear;
public:
    Queue (int s){
        maxSize=s;
        arr=new int[maxSize];
        CurSize=0;
        Front=0;
        Rear=maxSize-1;
    }
    void Push(int d){
        if (CurSize==maxSize) return;
        Rear=(Rear+1)%maxSize;
        arr[Rear]=d;
        CurSize++;
    }
    int first(){
        if (CurSize==0) return -1; else return arr[Front];
    }
    void pop(){
        if (CurSize==0) return;
        Front=(Front+1)%maxSize;
    bool isEmpty(){
        if (CurSize==0) return true; else return false;
    }
};

int main(){
    Queue q(5);
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.pop();
    q.Push(5);
    q.Push(6);

    while (!q.isEmpty()){
        cout<<q.first()<<" ";
        q.pop();
    }
}

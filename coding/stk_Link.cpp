#include<iostream>
#include<vector>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node (int d){
        data=d;
        next=NULL;
    }
    friend class LinkedList;
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head=NULL;
    }
    void InsertAtStart(int d){
        Node* newNode=new Node(d);
        newNode->next=head;
        head=newNode;
    }




    void DeleteAtEnd(){
        if (head==NULL) return;
        if (head->next==NULL){
            //DeleteAtStart();
            head = NULL;
            return;
        }
        Node* t=head;
        while (t->next->next!=NULL) t=t->next;
        delete t->next;
        t->next=NULL;
    }



};


class Stack {
private :
    LinkedList ll;
    int CurSize;


public :

    Stack()
    {
        CurSize =0;
    }

    void Push(int data)
    {
        ll.InsertAtStart(data);
        CurSize ++;
    }

    void Pop()
    {
        if(CurSize == 0) return ;
        ll.DeleteAtEnd();
        CurSize--;
    }

    int First()
    {
        if(ll.head == NULL) return -1;
        return (ll.head)->data;
    }

    bool isEmpty()
    {
        if(ll.head == NULL) return true ;

        return false;

    }



};







int main(){
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6);
    s.Push(7);

    while(!s.isEmpty())
    {
        cout<<s.First()<<"  ";
        s.Pop();
    }

}


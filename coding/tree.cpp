#include<iostream>
#include<queue>
using namespace std;

class Node{
private :
    int data;
    Node **children;
    int childCount;

public :
    Node(int d)
    {
       data = d;
       children = NULL;
       childCount = 0;
    }

    friend class GenericTree;
};

class GenericTree{
private :
    Node *Root;
public :
    genericTree()
    {
        Root = NULL;
    }

    Node * insertPreOrder()
    {
        int c,d;
        cout<<"Enter Data : ";
        cin>>d;
        Node *newNode = new Node(d);
        cout<<"Enter No. of Children : ";
        cin>>c;
        newNode->childCount = c;
        newNode->children = new Node*[c];
        for(int i=0;i<c;i++)
        {
            newNode->children[i]= insertPreOrder();
        }
        return newNode;
    }

    void insertPO()
    {
        Root = insertPreOrder();


    }

    void printPreOrder(Node *rt)
    {
        if(rt == NULL)return ;
        cout<<rt->data<<" ";
        for(int i =0; i<rt->childCount; i++ )
        {
            printPreOrder(rt->children[i]);
        }
    }

    void printPO()
    {
        cout<<"PreOrder : ";
        printPreOrder(Root);
        cout<<endl;
    }

    void printPostOrder(Node *rt)
    {
        if(rt == NULL)return ;

        for(int i =0; i<rt->childCount; i++ )
        {
            printPostOrder(rt->children[i]);
        }
        cout<<rt->data<<" ";
    }

    void printPsO()
    {
        cout<<"PostOrder : ";
        printPostOrder(Root);
        cout<<endl;
    }
    void printLO()
    {
        cout<<"Leve Order : "<<endl;
        if(Root == NULL) return;

        queue<Node *> q;

        q.push(Root);q.push(NULL);

        while(!q.empty())
        {
            Node *f = q.front();
            q.pop();
            if(f==NULL) {

                cout<<endl;
                if(!q.empty()) q.push(NULL);
            }

            else{
                cout<<f->data<< " ";
                for(int i = 0;i<f->childCount;i++)
                {
                    q.push(f->children[i]);


                }
            }
        }



    }

    void insertLO()
    {

    }


    int NodeCount(Node *rt)
    {
        if(rt == NULL) return 0;
        int cnt =0;
        for(int i =0; i<rt->childCount;i++)
        {
            cnt +=NodeCount(rt->children[i]);
        }
        return cnt+1;
    }
    int NodeCount()
    {
        cout<<" No. of Nodes : ";
        return  NodeCount(Root);
    }

    int NodeSum(Node *rt)
    {
        if(rt == NULL) return 0;
        int sum =0;
        for(int i =0; i<rt->childCount;i++)
        {
            sum +=NodeSum(rt->children[i]);
        }
        return sum+(rt->data);
    }
    int NodeSum()
    {

        cout<<" Sum of Nodes : ";
        return  NodeSum(Root);
    }



};


int main()
{
    GenericTree gt;
    gt.insertPO();
    gt.printPO();
    gt.printPsO();
    gt.printLO();
    cout<<gt.NodeCount()<<endl;
    cout<<gt.NodeSum()<<endl;



}

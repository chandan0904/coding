#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<iterator>
#include<stdlib.h>
#include<dos.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,bool> pib;

class Node{


public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;

    }


};
typedef pair<Node*,int> pni;
typedef pair<Node*,pair<int,int> > pnii;

class BinaryTree{
private:
    Node *root;

    void takeInputInO(Node *rt)
    {
        int d;
        cout<<"Enter Left Node Of "<<rt->data<<" (if not -1) : ";
        cin>>d;

        if(d!=-1){
            rt->left = new Node(d);
            takeInputInO(rt->left);
        }

        cout<<"Enter Right Node Of "<<rt->data<<" (if not -1) : ";
        cin>>d;
        if(d!=-1)
        {
            rt->right = new Node(d);
            takeInputInO(rt->right);
        }
    }

    void takeInputLO(Node *rt)
    {
        int d;
        queue<Node*> q;
        q.push(rt);
        Node *temp;

        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            cout<<"Enter left Node of "<<temp->data<<" (if not -1) : ";
            cin>>d;
            if(d != -1)
            {
                temp->left = new Node(d);
                q.push(temp->left);
            }
            cout<<"Enter Right Node of "<<temp->data<<" (if not -1) : ";
            cin>>d;
            if(d != -1)
            {
                temp->right = new Node(d);
                q.push(temp->right);
            }
        }
    }

    void printInO(Node *rt)
    {
        if(rt != NULL)
        {
            printInO(rt->left);
            cout<<rt->data<<" ";
            printInO(rt->right);
        }
    }

    printLO(Node *rt)
    {
        queue<Node*> q;
        q.push(rt);
        Node *temp;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);

        }
    }

    void printTree(Node *rt)
    {
        queue<Node*> q;
        q.push(rt);
        q.push(NULL);
        Node* temp;

        while(!q.empty())
        {
            temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                cout<<endl;
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                cout<<temp->data<<" ";
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);

            }
        }
    }

    void printPstO(Node *rt)
    {
        if(rt != NULL)
        {
            printPstO(rt->left);
            printPstO(rt->right);
            cout<<rt->data<<" ";
        }
    }

     void printPreO(Node *rt)
    {
        if(rt != NULL)
        {
            cout<<rt->data<<" ";
            printPreO(rt->left);
            printPreO(rt->right);

        }
    }

    pii diameter(Node *rt)
    {
        pii temp1,temp2,ans;
        ans.first = temp1.first = temp2.first = -1;
        ans.second = temp1.second = temp2.second = -1;
        if(rt != NULL)
        {
            temp1 = diameter(rt->left);
            temp2 = diameter(rt->right);
            ans.second =max(temp1.second,ans.second);
            ans.first =max(temp1.first,ans.first);

            ans.second = max(temp2.second,ans.second);
            ans.first = max(temp2.first,ans.first);
            int myDiameter = temp1.second+temp2.second+2;
            ans.first = max(myDiameter,ans.first);
            ans.second +=1;
        }
        return ans;
    }

    Node* buildPreoderInorder(int preO[],int inO[],int preS,int preE,int inS,int inE )
    {
        if(preS>preE || inS>inE) return NULL;
        int i=0;
        for(i; i<preE ; i++)
        {
            if(preO[preS] == inO[inS+i])
                break;
        }

        Node *rt = new Node(preO[preS]);
        rt->left = buildPreoderInorder(preO,inO,preS+1,preS+i,inS,inS+i-1);
        rt->right = buildPreoderInorder(preO,inO,preS+i+1,preE,inS+i+1,inE);


        return rt;
    }

    Node* buildPostoderInorder(int posO[],int inO[],int posS,int posE,int inS,int inE )
    {
        if(posS>posE || inS>inE) return NULL;

        int i=0;

        for(i; i<posE; i++)
        {
            if(posO[posE] == inO[inS+i])
                break;
        }

        Node *rt = new Node(posO[posE]);
        if(posS==posE || inS==inE) return rt;

        rt->left = buildPostoderInorder(posO,inO,posS,posS+i-1,inS,inS+i-1);
        rt->right = buildPostoderInorder(posO,inO,posS+i,posE-1,inS+i+1,inE);

        return rt;
    }

    Node* buildPreoderPostorder(int preO[],int postO[],int postS,int postE,int &p )
    {
        if(postS>postE) return NULL;

        int i=0;
        static int j =0;
        if(j==30) exit(0);
        j++;

        for(i; i<postE; i++)
        {
            if(preO[p+1] == postO[postS+i])
                break;
        }

        Node *rt = new Node(preO[p++]);
        if(postS==postE) return rt;

        rt->left = buildPreoderPostorder(preO,postO,postS,postS+i,p);
        rt->right = buildPreoderPostorder(preO,postO,postS+i+1,postE-1,p);
        return rt;
    }

    int hight(Node *rt)
    {
        if(rt==NULL) return 0;

        return max(hight(rt->left),hight(rt->right))+1;


    }

    pnii sumOfSubTree(Node *rt)
    {
         ;

        pnii left,right,ans;
        left.first = right.first = ans.first =NULL;
        left.second.first = right.second.first = ans.second.first =0;
        left.second.second = right.second.second = ans.second.second= 0;
        if(rt == NULL) return ans;
        if(rt->left!= NULL)
            left = sumOfSubTree(rt->left);

        if(rt->right!= NULL)
            right = sumOfSubTree(rt->right);
        if(left.second> right.second)
            ans = left;
        else
            ans = right;
        /*cout<<"node : "<<rt->data<<endl;
        cout<<"left : "<<left.second<<endl;
        cout<<"right : "<<right.second<<endl;*/
        if(left.second.second+right.second.second+rt->data > ans.second.first )
        {
            //cout<<"hello "<<rt->data <<endl;
            ans.first = rt;
            ans.second.first = left.second.second+right.second.second+rt->data ;
        }
        ans.second.second = left.second.second+right.second.second+rt->data;
        return ans;
    }


    void printTreeD(Node *rt)
    {
        int h;
        Node *f,*check;
        check = new Node(-1);
        queue<Node*> q;
        q.push(rt);
        q.push(check);
        h=hight();
        int space=1;
        space =space<<h;
        //for(int i=0;i<=h;i++)
            cout<<" "<<space<<endl;
        while(!q.empty())
        {

            f = q.front();
            q.pop();
            if(f==check)
            {
                space=space>>1;
                cout<<endl;
                cout<<endl;
                if(!q.empty()) q.push(check);
            }
            else{
                for(int i=0;i<=space;i++)
                cout<<" ";
                if(f!=NULL){
                cout<<f->data;
                //if(f->left!=NULL)
                    q.push(f->left);
                //if(f->right!=NULL)
                    q.push(f->right);
                }
                for(int i=0;i<=space;i++)
                cout<<" ";


            }
        }

    }


    void printTree90(Node *rt,int d)
    {
        if(rt==NULL) return ;

        printTree90(rt->right,d+1);
        for(int i=0; i<d; i++ )
            cout<<"\t";
        cout<<rt->data<<endl;
        cout<<endl;
        printTree90(rt->left,d+1);



    }

    bool balancedTree(Node *rt)
    {
        if(rt == NULL) return true;

        int lH,rH;

        lH = hight(rt->left);
        rH = hight(rt->right);
        if(abs(lH-rH)<=1 && balancedTree(rt->left)&&balancedTree(rt->right))
            return true;
        return false;




    }


    list<Node*> *LikedListOfAllLeve(Node *rt)
    {

        list<Node*> * ln;
        queue<Node*> q;
        int i=0;
        q.push(rt);
        q.push(NULL);
        Node* temp;
        ln= new list<Node*>[hight(rt)];


        while(!q.empty())
        {
            temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                i++;
                //cout<<endl;
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                //cout<<temp->data<<" ";
                ln[i].push_back(temp);
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);

            }
        }

        return ln;

    }

    void printLevels(Node *rt, int h){
 		if(rt==NULL) return;
 		if(h==1) cout<<" " << rt->data;
 		else{
 			printLevels(rt->left,h-1);
 			printLevels(rt->right,h-1);
 		}
 	}


 	void nodeHaveNotSibling(Node *rt)
 	{
 	    if(rt==NULL) return;

 	    if(rt->left!=NULL && rt->right == NULL)
            cout<<rt->left->data<<" ";


        else if(rt->left==NULL && rt->right != NULL)
             cout<<rt->right->data<<" ";

        nodeHaveNotSibling(rt->left);
        nodeHaveNotSibling(rt->right);

 	}

 	Node* removeLeaves(Node *rt)
    {
        if(rt==NULL) return NULL;

        if(rt->left == NULL && rt->right == NULL)
        {
            delete(rt);
            return NULL;
        }

        rt->left = removeLeaves(rt->left);
        rt->right = removeLeaves(rt->right);

        return rt;

 	}

 	int countLeafNode(Node* rt)
 	{
 	    if(rt==NULL) return 0;
 	    if(rt->left==NULL && rt->right == NULL)
            return 1;

        return countLeafNode(rt->left) + countLeafNode(rt->right);
 	}

 	void zigZagPrint(Node *rt)
 	{
 	    stack<Node*> stc1,stc2;
 	    bool flag = false;
 	    Node *top;
        //stc1.push(NULL);

        stc1.push(rt);

 	    while(!stc1.empty())
        {
            top = stc1.top();
            stc1.pop();
            cout<<top->data<<" ";

            if(flag)
            {

                if(top->right!=NULL){
                    //cout<< " right "<<top->right->data;

                    stc2.push(top->right);
                }
                if(top->left!=NULL){
                    stc2.push(top->left);
                    //cout<<"  left "<<top->right->data;
                }


            }
            else
            {

                //cout<<top->data<<" ";
                if(top->left!=NULL){
                    stc2.push(top->left);
                    //cout<<"  left "<<top->right->data;
                }
                if(top->right!=NULL){
                    stc2.push(top->right);
                    //cout<<" right "<<top->right->data;
                }

            }
            if(stc1.empty())
            {
                cout<<endl;
                swap(stc1,stc2);
                flag = !flag;
            }

        }

 	}

///******************************************************PUBLIC*************************************************************
public:
    BinaryTree()
    {
        root = NULL;
    }

    takeInputInO()
    {
        int d;
        cout<<"Enter Root Node : ";
        cin>>d;
        root = new Node(d);

        takeInputInO(root);
    }
    takeInputLO()
    {
        int d;
        cout<<"Enter Root Node : ";
        cin>>d;
        root = new Node(d);

        takeInputLO(root);
    }

    void printInO()
    {
        cout<<"Inorder : ";;
        printInO(root);
        cout<<endl;

    }

    void printLO()
    {
        cout<<"LeveOrder : ";
        printLO(root);
        cout<<endl;

    }

    void printPstO()
    {
        cout<<"Postorder : ";
        printPstO(root);
        cout<<endl;

    }
    void printPreO()
    {
        cout<<"PreOrder : ";
        printPreO(root);
        cout<<endl;
    }

    void printTree()
    {
        cout<<"Tree : "<<endl;
        printTree(root);
        cout<<endl;
    }

    void diameter()
    {

        pii p = diameter(root);
        cout<<" Diameter : "<<p.first;
        cout<<endl;
    }

    void buildPreoderInorder()
    {
       int preO[]={1,2,4,7,10,5,8,11,3,6,9,12,13};

       int inO[]={7,10,4,2,5,11,8,1,6,12,9,13,3};

        //{-3,2,3,6,4,-5,1,-2};///{1,2,4, 8, 5, 3, 6, 9, 7};///{1,2,4,5,3,6,7};
        //{6,3,2,4,-3,1,-5,-2};///{8, 4, 2, 5, 1, 9, 6, 3, 7};///{4,2,5,1,6,3,7};
       root = buildPreoderInorder(preO,inO,0,12,0,12);
    }

     void buildPostoderInorder()
    {
       int postO[]={10,7,4,11,8,5,2,12,13,9,6,3,1};

       int inO[]={7,10,4,2,5,11,8,1,6,12,9,13,3};

        //{-3,2,3,6,4,-5,1,-2};///{1,2,4, 8, 5, 3, 6, 9, 7};///{1,2,4,5,3,6,7};
        //{6,3,2,4,-3,1,-5,-2};///{8, 4, 2, 5, 1, 9, 6, 3, 7};///{4,2,5,1,6,3,7};
       root = buildPostoderInorder(postO,inO,0,12,0,12);
    }

    void buildPreoderPostorder()
    {
        int p=0;
        int preO[]={1,-2,-4,7,-10,5,8,-11,3,6,9,12,13};
        int postO[]={-10,7,-4,-11,8,5,-2,12,13,9,6,3,1};
        root = buildPreoderPostorder(preO,postO,0,12,p);
    }

    int hight()
    {
        return hight(root);
    }

    void sumOfSubTree()
    {
        pnii p;
        cout<<"Sum of SubTree Max : ";
        p =sumOfSubTree(root);
        cout<<"Node : "<<p.first->data<<"  sum is "<<p.second.first<<endl;
    }

    void printTreeD()
    {
        cout<<"TREE"<<endl;
        printTreeD(root);
    }


    void printTree90()
    {
        printTree90(root,0);
    }


    bool  balancedTree()
    {
        cout<<"tree Balence : ";
        return balancedTree(root);
    }


    void LikedListOfAllLeve()
    {
        list<Node*> *lNode;
        lNode = LikedListOfAllLeve(root);
        int h =hight();
        for(int i=0; i<h; i++){
            for(auto j = lNode[i].begin();j!=lNode[i].end();j++)
            {
                cout<<"-> "<<(*j)->data<<" ";

            }
            cout<<endl;
        }
    }

    void printLevels()
    {
        int h=hight();
        for(int i=1; i<=h;i++){
            printLevels(root,i);
            cout<<endl;
        }
    }

    void nodeHaveNotSibling()
    {   cout<<"Node Have Not Sibling : ";
        nodeHaveNotSibling(root);
        cout<<endl;
    }

    void removeLeaves()
    {
        root = removeLeaves(root);
    }

    int countLeafNode()
    {
        return countLeafNode(root);
    }

    void zigZagPrint()
    {
        cout<<"Zig Zag Oreder : "<<endl;
        zigZagPrint(root);
        cout<<endl;
    }

};


int main()
{
    BinaryTree bt;

    //bt.takeInputInO();
    //bt.takeInputLO();
    //bt.buildPreoderInorder();
    bt.buildPostoderInorder();
    //bt.buildPreoderPostorder();
    //bt.printInO();
    //bt.printPstO();
    //bt.printPreO();
    //bt.printLO();
    cout<<"Hight"<<bt.hight()<<endl;
    bt.printTree();
    //bt.diameter();

    //bt.sumOfSubTree();
    //bt.printTree90();
    //cout<< bt.balancedTree()<<endl;
    bt.LikedListOfAllLeve();
    bt.printLevels();
    bt.nodeHaveNotSibling();
    //bt.removeLeaves();
    //bt.printTree();
    cout<<"No. Of Leaf Nodes : "<<bt.countLeafNode()<<endl;
    bt.zigZagPrint();





}

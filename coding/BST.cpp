#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> pii;

class TreeNode{
public:
    int data;
    TreeNode* left, *right;

    TreeNode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
typedef pair<int,pair<TreeNode*,int>> pini;

class BST{
private:
    TreeNode * root;
public:
    BST(){root=NULL;}
    void PrintPreOrder(TreeNode* rt){
        if (rt==NULL) return;
        cout<<rt->data<<" ";
        PrintPreOrder(rt->left);
        PrintPreOrder(rt->right);
    }
    void PrintPreOrder(){///public function
        cout<<"PreOrder:";
        PrintPreOrder(root);
        cout<<endl;
    }
    void PrintPostOrder(TreeNode* rt){
        if (rt==NULL) return;
        PrintPostOrder(rt->left);
        PrintPostOrder(rt->right);
        cout<<rt->data<<" ";
    }

   void PrintPostOrder(){///public function
        cout<<"PostOrder:";
        PrintPostOrder(root);
        cout<<endl;
    }

   void PrintInOrder(TreeNode* rt){
        if (rt==NULL) return;
        PrintInOrder(rt->left);
        cout<<rt->data<<" ";
        PrintInOrder(rt->right);
    }

   void PrintInOrder(){///public function
        cout<<"InOrder:";
        PrintInOrder(root);
        cout<<endl;
    }

    void PrintLevelOrder(){
        if (root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if (f==NULL){
                cout<<endl;
                if (!q.empty()) q.push(NULL);
            } else{
                cout<<f->data<<" ";
                if (f->left!=NULL) q.push(f->left);
                if (f->right!=NULL) q.push(f->right);
           }
        }
        cout<<endl;
    }

    TreeNode* BuildPreOrderInOrder(int PreOrder[], int InOrder[], int sPO, int ePO,
                                   int sIO, int eIO){
        if (sPO>ePO||sIO>eIO) return NULL;
        int rtData=PreOrder[sPO];
        TreeNode* rt=new TreeNode(rtData);
        int i;
        for (i=sIO;i<=eIO;i++){
            if (InOrder[i]==rtData) break;
        }
        int cLST=i-sIO;
        rt->left=BuildPreOrderInOrder(PreOrder,InOrder,sPO+1,sPO+cLST,sIO,sIO+cLST-1);
        rt->right=BuildPreOrderInOrder(PreOrder,InOrder,sPO+cLST+1,ePO,sIO+cLST+1,eIO);
        return rt;
    }

    void BuildPreOrderInOrder(){
        int PreOrder[]= {-3,2,3,6,4,-5,1,-2};///{1,2,4, 8, 5, 3, 6, 9, 7};///{1,2,4,5,3,6,7};
        int InOrder[]= {6,3,2,4,-3,1,-5,-2};///{8, 4, 2, 5, 1, 9, 6, 3, 7};///{4,2,5,1,6,3,7};
        root= BuildPreOrderInOrder(PreOrder,InOrder,0,7,0,7);
    }

    TreeNode* InsertData(TreeNode* rt, int d){
        if (rt==NULL) {
            TreeNode *n=new TreeNode(d);
            return n;
        }
        if (d<=rt->data){
            rt->left=InsertData(rt->left,d);
        }
        else rt->right=InsertData(rt->right,d);
        return rt;
    }
    void TakeInput(){
        int d;
        cin>>d;
        while (d!=-1){
            root=InsertData(root,d);
            cin>>d;
        }
    }
    bool Search(TreeNode* rt, int d){
        if (rt==NULL) return false;
        if (rt->data==d) return true;
        if (d<rt->data){
            return Search(rt->left,d);
        } else return Search(rt->right,d);
    }
    bool Search(int d){
        return Search(root,d);
    }
    TreeNode* Remove(TreeNode* rt, int d){
        if (rt==NULL) return rt;
        if (rt->data==d){
            if (rt->left==NULL && rt->right==NULL){
                delete rt;
                return NULL;
            }
            if (rt->right==NULL){
                TreeNode* t=rt->left;
                delete rt;
                return t;
            }
            if (rt->left==NULL){
                TreeNode* t=rt->right;
                delete rt;
                return t;
            }
            TreeNode* t=rt->right;
            while (t->left!=NULL){
                t=t->left;
            }
            swap(rt->data,t->data);
            rt->right=Remove(rt->right, t->data);
            return rt;
        }
        if (d<=rt->data) rt->left=Remove(rt->left,d);
            else rt->right=Remove(rt->right,d);
        return rt;
    }
    void Remove(int d){
        root=Remove(root,d);
    }
    bool isBST(TreeNode* rt, int minVal, int maxVal){
        if (rt==NULL) return true;
        if (rt->data<minVal||rt->data>maxVal) return false;
        return isBST(rt->left,minVal,rt->data)
            && isBST(rt->right,rt->data,maxVal);
    }

    bool isBST(){
        return isBST(root,-10000,10000);
    }
    TreeNode* BuildFromSortedArray(int arr[], int sPos, int ePos){
        if (sPos>ePos) return NULL;
        int mid=(sPos+ePos)/2;
        TreeNode * rt=new TreeNode(arr[mid]);
        rt->left=BuildFromSortedArray(arr,sPos,mid-1);
        rt->right=BuildFromSortedArray(arr,mid+1,ePos);
        return rt;
    }
    void BuildFromSortedArray(){
        int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        int n=15;
        root=BuildFromSortedArray(arr,0,n-1);
    }
};

int main(){
    BST T;
    ///T.BuildPreOrderInOrder();
    ///T.TakeInput();
    T.BuildFromSortedArray();
    T.PrintPreOrder();
    T.PrintInOrder();
    T.PrintPostOrder();
    T.PrintLevelOrder();
    cout<<"Search:"<<T.Search(10)<<" "<<T.Search(20);
    T.Remove(15);///26, 28,9
    T.PrintInOrder();
    cout<<"IsBST:"<<T.isBST();
}


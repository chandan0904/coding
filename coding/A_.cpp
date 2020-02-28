#include<bits/stdc++.h>
#include<cmath>
//#include<stdlib.h>


#define i first
#define j second
using namespace std;

typedef pair<int,int> Blank;
typedef pair<int,int> pii;
class Puzzle
{   
    public:
    bool closeList[3][3];
    Blank blank;
    int puz_mat[3][3];
    int g_n,f_n,h_n;
    public:
    Puzzle()
    {
    	for(int i=0;i<3;i++)
    		{
    			for(int j=0;j<3;j++)
    			{
    				closeList[i][j]=0;
				}
			}
        g_n,f_n,h_n=0;
        blank.i=0;
        blank.j=0;
    }
    void copyObject(Puzzle copy)
    {
    	//this->closeList = copy.closeList;
    	this->g_n=copy.g_n;
    	this->h_n=copy.h_n;
    	this->f_n=copy.f_n;
		this->blank.i=copy.blank.i;
    	this->blank.j=copy.blank.j;	
    	for(int i=0;i<3;i++)
    	{
    		for(int j=0;j<3;j++)
    		{
    			this->puz_mat[i][j]=copy.puz_mat[i][j];
    			this->closeList[i][j] = copy.closeList[i][j];
			}
		}
	}

void checkBlank()
{
	for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
                {
                    if(this->puz_mat[i][j]==0)
                       {
                         	this->blank.i=i;
                         	this->blank.j=j;
                         	return;
				       }
                }
        }
      cout<<"Invalid input!!!! No blank space in the puzzle"<<endl;
}

void heuristic(map<int,pii> goal_state)
{
	int heuristic=0;
	int x;
  	for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
               {
               	
               		if(this->puz_mat[i][j]==0)
               		continue;
               		
               		
               		x=this->puz_mat[i][j];
               		//int y=this->puz_mat[i][j];
                    /*if(i!=goal_state[ x ].i || j!=goal_state[ x ].j )
                        h++;
                    /**/
					int a = goal_state[ x ].i - i;
                    int b = goal_state[ x ].j - j;
                    a = a<0?-a:a;
                    b = b<0?-b:b;                   
                    heuristic += (a+b);
			    }
        }
    this->h_n=heuristic;
}

bool compareMat(map<int,pii> goal_state)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			{	
	  			if(i!=goal_state[(this->puz_mat[i][j]) ].i || j!=goal_state[ (this->puz_mat[i][j]) ].j )
	     			return false;
			}
	}	
  return true;	
}
};
class compare
{
	public:
	bool operator()(Puzzle pz1,Puzzle pz2)
		{
		   return pz1.f_n > pz2.f_n;
		}	
};
//////////////////////////	M	A	I	N		 F	U	N	C	T	I	O	N		//////////////////////////////
int main() 
{
	int i,j;
	int arr[][3]={	{1,2,3},
				   	{0,4,6},
				  	{7,5,8}
				};
	/*int arr[][3]={	{1,2,3},
				   	{0,4,6},
				  	{7,5,8}
				};*/
	map<int,pii> goal_state;
	int a=0;
	for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		goal_state[a++] = make_pair(i,j);
		}
	}
	//goal_state[0] = make_pair(2,2);
	//int goal_state[][3]={{1,2,3},{4,5,6},{7,8,0}};
    Puzzle cur_state;
    
    
    int g_count=0,NOS=0;
    
    for(int i=0;i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cur_state.puz_mat[i][j]=arr[i][j];
		}
	}
    Blank blnk;
    cur_state.checkBlank();
    priority_queue<Puzzle,vector<Puzzle>,compare> pq;
    //Puzzle UP,DOWN,LEFT,RIGHT;
    cur_state.heuristic(goal_state);
    
    cur_state.f_n=cur_state.h_n;
    
    pq.push(cur_state);
    
    while(!pq.empty())
    {
    	
    	
    	//cout<<"check point5"<<endl;
	    cur_state=pq.top();
		pq.pop();
		i=cur_state.blank.i;
    	j=cur_state.blank.j;
    	cur_state.closeList[i][j]=1;
        g_count++;
    	
    	if(cur_state.compareMat(goal_state))
    	{
    		cout<<"result"<<endl;
    		for(int i=0;i<3;i++)
    		{
    			for(int j=0;j<3;j++)
    			{
    				cout<<cur_state.puz_mat[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<"Total "<<NOS<<" to solve the puzzle"<<endl;
			return 0;
		}
		//if(g_count ==17) return 0;
		cout<<"	LOW cost maze  	"<<g_count<<endl;
    	for(int i=0;i<3;i++)
    	{
    		for(int j=0;j<3;j++)
    		{
    			cout<<cur_state.puz_mat[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"heuristic : "<<cur_state.f_n<<" \n\n";
	cout<<"---------------\n"<<endl;
    if(cur_state.blank.i<2 && !cur_state.closeList[i+1][j])//this is for up move///data move
        {     
              cout<<"check point1"<<endl;
              Puzzle UP;
              UP.copyObject(cur_state);
              swap(UP.puz_mat[UP.blank.i][UP.blank.j],UP.puz_mat[(UP.blank.i)+1][UP.blank.j]);
              UP.blank.i=(UP.blank.i) + 1;
              UP.g_n=g_count;
              UP.heuristic(goal_state);
			  UP.f_n=UP.h_n;//+UP.g_n;
			  pq.push(UP);
			  NOS++;
			  //cout<<" "
			  	for(int i=0;i<3;i++)
    		  	{
    				for(int j=0;j<3;j++)
    				{
    					cout<<UP.puz_mat[i][j]<<" ";
					}		
					cout<<endl;
				}
				cout<<"heuristic : "<<UP.f_n<<" \n\n";
        }
    if(cur_state.blank.i>0 && !cur_state.closeList[i-1][j])//this is for down move
        {
        	  cout<<"check point2"<<endl;
        	  Puzzle DOWN;
              DOWN.copyObject(cur_state);
              swap(DOWN.puz_mat[DOWN.blank.i][DOWN.blank.j],DOWN.puz_mat[DOWN.blank.i-1][DOWN.blank.j]);
              DOWN.blank.i=(DOWN.blank.i)-1;
              DOWN.g_n=g_count;
              DOWN.heuristic(goal_state);
		      DOWN.f_n=DOWN.h_n;//+DOWN.g_n;
			  pq.push(DOWN);
			  NOS++;   
			 
				for(int i=0;i<3;i++)
    		  	{
    				for(int j=0;j<3;j++)
    				{
    					cout<<DOWN.puz_mat[i][j]<<" ";
					}		
					cout<<endl;
				}
				cout<<"heuristic : "<<DOWN.f_n<<" \n\n";		  
        }
    if(cur_state.blank.j<2 && !cur_state.closeList[i][j+1])//this is for left move
        {
              cout<<"check point3"<<endl;
              Puzzle LEFT;
			  LEFT.copyObject(cur_state);
              swap(LEFT.puz_mat[LEFT.blank.i][LEFT.blank.j],LEFT.puz_mat[LEFT.blank.i][LEFT.blank.j+1]);
              LEFT.blank.j=(LEFT.blank.j)+ 1;
              LEFT.g_n=g_count;
              LEFT.heuristic(goal_state);
		      LEFT.f_n=LEFT.h_n;//+LEFT.g_n;
			  pq.push(LEFT);
			  NOS++;
			  
			  	for(int i=0;i<3;i++)
    		  	{
    				for(int j=0;j<3;j++)
    				{
    					cout<<LEFT.puz_mat[i][j]<<" ";
					}		
					cout<<endl;
				}
				cout<<"heuristic : "<<LEFT.f_n<<" \n\n";
	    } 
    if(cur_state.blank.j>0 && !cur_state.closeList[i][j-1])//this is for right move
        {
              cout<<"check point4"<<endl;
              Puzzle RIGHT;
			  RIGHT.copyObject(cur_state);
              swap(RIGHT.puz_mat[RIGHT.blank.i][RIGHT.blank.j],RIGHT.puz_mat[RIGHT.blank.i][RIGHT.blank.j-1]);
              RIGHT.blank.j=(RIGHT.blank.j)- 1;
              RIGHT.g_n=g_count;
              RIGHT.heuristic(goal_state);
		      RIGHT.f_n=RIGHT.h_n;///+RIGHT.g_n;
			  pq.push(RIGHT);
			  NOS++;
			  
			  	for(int i=0;i<3;i++)
    		  	{
    				for(int j=0;j<3;j++)
    				{
    					cout<<RIGHT.puz_mat[i][j]<<" ";
					}		
					cout<<endl;
				}
				cout<<"heuristic : "<<RIGHT.f_n<<" \n\n";
	    }
	    
    }//while end
    cout<<"NOT FOUND";
    return 0;
}


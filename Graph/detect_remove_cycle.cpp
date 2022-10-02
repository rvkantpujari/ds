#include<bits/stdc++.h> 
using namespace std; 

#define MAX_SIZE 20

struct linkNode
{
	int data;
	linkNode* next;
};
class mystack
{
public:

	int s[MAX_SIZE];
	int top;

	myqueue()
	{
		top = -1;
	}
	void push(const int v)
	{
		if(top == MAX_SIZE-1)
			cout<<"\n stack is full";
		else
			s[++top] = v;
	}
	int peek()
	{
		if(top == -1)
		{
			//cout<<"\n stack is empty!!";
			return -1;
		}
		else
			return s[top];
	}
	void pop()
	{
		if(top == -1)
			cout<<"\n stack is empty!!";
		else
			--top;
	}
	const bool isEmpty()
	{
		if(top == -1)
			return true;
		else
			return false;
	}
};

//typedef linkNode node;
class linkList
{
	public:struct linkNode* first;
		struct linkNode* last;
		linkList()
		{
			first = NULL;
			last = NULL;
		}

		void insertLast(const int d)
		{
			struct linkNode* newNode = (linkNode*)malloc(sizeof(linkNode));
			newNode->data = d;
			newNode->next = NULL;
			if(last!=NULL)
			{
				last->next = newNode;
				last = newNode;
			}
			else
			{
				first = newNode;
				last = newNode;
			}

		}
		void displayList()
		{
			struct linkNode* current = first;
			current = current->next;
			while(current!=NULL)
			{
				cout<<current->data<<" ";
				current = current->next;
			}
		}
		void displayBFSList(myqueue &q, bool isVisted[],const int size)
		{
			struct linkNode* current = first;
			current = current->next;
			while(current!=NULL)
			{
				if(!isVisted[current->data])
				{
					//cout<<"onc";
					isVisted[current->data]=true;
					q.push(current->data);

					//cout<<" in Dis "<<q.peek()<<current->data<<isVisted[2];
				}
				current = current->next;
			}
		}
		void checkCycle(myqueue &q, bool isVisted[],const int size)
		{
			struct linkNode* current = first;
			current = current->next;
			while(current!=NULL)
			{
				if(!isVisted[current->data])
				{
					//cout<<"onc";
					isVisted[current->data]=true;
					q.push(current->data);

					//cout<<" in Dis "<<q.peek()<<current->data<<isVisted[2];
				}
				else 
					return
				current = current->next;
			}
		}
};
class graph
{
	public:
	linkList list[20];
	int nVert;

	graph()
	{
		nVert = 0;
	}

	void addVertex(int d)
	{
		if(nVert<20)
		{
			list[nVert].insertLast(d);
			++nVert;
		}
		else
			cout<<"\nyou cant add more vertex!!";
	}

	void addEdge(const int s, const int e) 
	{ 
		list[s].insertLast(e);
	}

	// A utility function to print the adjacency list 
	// representation of graph 
	void printGraphBFS(int s) 
	{ 
		bool  *isVisted = new bool[nVert];
		for(int i=0; i<nVert; ++i)
			isVisted[i] = false;

		myqueue q;
		isVisted[s] = true;
		q.push(s);

		while(!q.isEmpty())
		{
			int f = q.peek();
			q.pop();
			cout<<" -> "<<f;

			list[f].checkCycle(q,isVisted,nVert);
			//cout<<q.peek()<<isVisted[q.peek()];
		}
		//cout<<"end "<<isVisted[1]; 	
	}
	bool isCyclic()
	{
		bool  *isVisted = new bool[nVert];
		for(int i=0; i<nVert; ++i)
			isVisted[i] = false;

		myqueue q;
		isVisted[s] = true;
		q.push(s);

		while(!q.isEmpty())
		{
			int f = q.peek();
			q.pop();
			cout<<" -> "<<f;

			list[f].displayBFSList(q,isVisted,nVert);
			//cout<<q.peek()<<isVisted[q.peek()];
		}
	} 
};


int main() 
{ 
	int V = 5; 

	graph g;
	vector<int> adj[V]; 
	for(int i=0;i<4; ++i)
		g.addVertex(i);
	g.addEdge(0, 2); 
	g.addEdge(2, 0); 
	g.addEdge(0, 1); 
	g.addEdge( 1, 2); 
	g.addEdge( 2, 3); 
	g.addEdge( 3, 3); 
	//g.addEdge( 3, 4); 
	//g.addEdge(1,0); 
	//g.list[1].displayList();
	g.printGraphBFS(2); 
	
	if(g.isCyclic())
	{

	}
	else
		cout<<"\ngraph contains NO cycle!";

	return 0; 
} 
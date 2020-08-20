import java.io.*; 
import java.util.*;
class Node
{
	public int data;
	public Node next;
	public Node(int d, Node n)
	{
		data = d;
		next = n;
	}
	public void displayNode()
	{
		System.out.print(data + " ");
	}
}

class Queue
{
	public Node root;
	public int size;
	public Queue()
	{
		root = null;
		size = 0;
	}
	public void enqueue(int d) //means at last
	{
		if(root==null)
			root = new Node(d,null);
		else
		{
			Node newNode = root;
			while(newNode.next!=null)
				newNode = newNode.next;
			newNode.next = new Node(d,null);
		}
		size++;
	}
	public int dequeue()
	{
		int val = this.root.data;
		this.root = this.root.next;
		size--;
		return val;
	}
	public void displayList()
	{
		Node newNode = root;
		while(newNode!=null)
		{
			System.out.print(" -> " + newNode.data);
			newNode = newNode.next;
		}
	}
	public int getNodeCount()
	{
		return size;
	}
}

class Stack
{
	public Node root;
	public int size;
	public Stack()
	{
		root = null;
		size = 0;
	}
	public void push(int d) //means at last
	{
		if(root==null)
			root = new Node(d,null);
		else
		{
			Node newNode = root;
			while(newNode.next!=null)
				newNode = newNode.next;
			newNode.next = new Node(d,null);
		}
		size++;
	}
	public int pop()
	{
		int val = this.root.data;
		this.root = this.root.next;
		size--;
		return val;
	}
	public void displayList()
	{
		Node newNode = root;
		while(newNode!=null)
		{
			System.out.print(" -> " + newNode.data);
			newNode = newNode.next;
		}
	}
	public int getNodeCount()
	{
		return size;
	}
}
class Graph
{
	private int V;
	private Queue list[];
	public Graph(int max_vert)
	{
		V = max_vert;
		list = new Queue[V];
		for(int i=0;i<V;i++)
			list[i] = new Queue();
	}
	public void addEdge(int src, int des)
	{
		list[src].enqueue(des);
	}
	public void addRevEdge(int src, int des)
	{
		list[des].enqueue(src);
	}
	public void TraversalBFS(int s)
	{
		boolean visited[] =  new boolean[V];
		visited[s]=true;
		Queue queue = new Queue();
		queue.enqueue(s);
		int qSize = queue.getNodeCount();
		while(qSize!=0)
		{
			s = queue.dequeue();
			System.out.print(s+ " ");
			Node n = list[s].root;
			while(n!=null)
			{
				if(!visited[n.data])
				{
					visited[n.data]=true;
					queue.enqueue(n.data);
				}
				n = n.next;
			}
			qSize = queue.getNodeCount();
		}
	}
	
	public void printGraph() 
    {
    	System.out.println("\n");
    	for(int i = 0; i < V; i++)
        {
            if(list[i].getNodeCount()>0)
            {
	            System.out.println("Adjacency list of vertex "+ i);
	            System.out.print("head");
            	list[i].displayList();
            	System.out.print("\n");
            }
        }
    }
}

public class GraphTraversal
{
	public static void main(String[] args)
	{
		Graph g = new Graph(5);
		g.addEdge(0, 1);
        g.addEdge(0, 4);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.TraversalBFS(0);
        //g.printGraph();
	}
}
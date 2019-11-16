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

class List
{
	public Node root;
	public int size;
	public List()
	{
		root = null;
		size = 0;
	}
	public void addNode(int d)//means at last
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
	private List list[];
	public Graph(int max_vert)
	{
		V = max_vert;
		list = new List[V];
		for(int i=0;i<V;i++)
			list[i] = new List();
	}
	public void addEdge(int src, int des)
	{
		//System.out.println(src+" "+des);
		list[src].addNode(des);
		// When the graph is undirected.
		//list[des].addNode(src);
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

public class AdjListGraph
{
	public static void main(String[] args)
	{
		Graph g = new Graph(5);
		g.addEdge(0, 1);
        g.addEdge(0, 4);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(4, 1);
        g.addEdge(4, 3);
        g.printGraph();
	}
}
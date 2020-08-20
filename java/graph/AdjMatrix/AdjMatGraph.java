class Graph
{
	private int V;
	private int edge[][];
	public Graph(int max_vert)
	{
		V = max_vert;
		edge = new int[V][V];
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				edge[i][j] = 0;
	}
	public void addEdge(int src, int des)
	{
		this.edge[src][des]=1;
	}
	public void printGraph()
	{
		for(int i=0;i<V;i++)
		{
			System.out.println("\nAdjacency List of Vertex "+i);
			System.out.print("Head");
			for(int j=0;j<V;j++)
			{
				if(this.edge[i][j]==1)
					System.out.print(" -> "+j);
			}
		}
	}
}

public class AdjMatGraph
{
	public static void main(String args[])
	{
		Graph g = new Graph(5);
		g.addEdge(0, 1);
		g.addEdge(0, 4);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.printGraph();
	}
}
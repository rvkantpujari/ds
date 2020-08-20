class Node
{
	public int LinkData;
	public Node nextLink;
	public Node(int d, Node n)
	{
		LinkData = d;
		nextLink = n;
	}
	public void displayCurrNode()
	{
		System.out.print(LinkData+ " ");
	}
}

class StackLL
{
	private Node headNode;
	public StackLL(){
		headNode = null;
	}
	public void push(int d)
	{
		Node newnode = new Node(d,headNode);
		headNode = newnode;
	}
	public void pop()
	{
		Node temp = this.headNode;
		temp = temp.nextLink;
		headNode = temp;
	}
	public void peek(){
		System.out.print(this.headNode.LinkData+"\n");
	}
}

public class StackApp
{
	public static void main(String[] args)
	{
		StackLL stk = new StackLL();
		stk.push(10);
		stk.push(100);
		stk.push(20);
		stk.push(200);
		stk.peek();
		stk.pop();
		stk.peek();
		stk.pop();
		stk.peek();
		stk.pop();
		stk.peek();
		stk.pop();
	}
}
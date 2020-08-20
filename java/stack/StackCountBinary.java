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
	private int size;
	public StackLL(){
		headNode = null;
		size = 0;
	}
	public void push(int d)
	{
		Node newnode = new Node(d,headNode);
		headNode = newnode;
		size++;
	}
	public int pop()
	{
		Node temp = this.headNode;
		int val = temp.LinkData;
		temp = temp.nextLink;
		headNode = temp;
		size--;
		return val;
	}
	public void peek(){
		System.out.print(this.headNode.LinkData+"\n");
	}
	public int getSize()
	{
		return size;
	}
}

public class StackCountBinary
{
	public static void countZerosOnes(String exp)
	{
		StackLL zeroStk = new StackLL();
		StackLL oneStk = new StackLL();
		for(int i=0;i<exp.length();i++)
		{
			char ch = exp.charAt(i);
			if(ch==' ')
				continue;
			else if(ch=='0')
				zeroStk.push(0);
			else if(ch=='1')
				oneStk.push(1);
		}
		System.out.println("");
		if(zeroStk.getSize()>oneStk.getSize())
			System.out.print("0's are more than 1's in " + exp);
		else if(zeroStk.getSize()<oneStk.getSize())
			System.out.print("1's are more than 0's in " + exp);
		else
			System.out.print("Number of 0's and 1's are equal in " + exp);
		System.out.println("");
	}
	public static void main(String[] args)
	{
		countZerosOnes("10110");
	}
}
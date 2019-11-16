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
	public int pop()
	{
		Node temp = this.headNode;
		int val = temp.LinkData;
		temp = temp.nextLink;
		headNode = temp;
		return val;
	}
	public void peek(){
		System.out.print(this.headNode.LinkData+"\n");
	}
}

public class StackPostfixEval
{
	public static int doCal(int n1, int n2, char op)
	{
		int res=0;
		if(op=='+')
			res = n1+n2;
		else if(op=='-')
			res = n1-n2;
		else if(op=='*')
			res = n1*n2;
		else if(op=='/')
			res = n1/n2;
		return res;
	}
	public static void PostFixEval(String exp)
	{
		StackLL numStk = new StackLL();
		for(int i=0;i<exp.length();i++)
		{
			char ch = exp.charAt(i);
			if(ch==' ')
				continue;
			else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
			{
				int n2 = numStk.pop();
				int n1 = numStk.pop();
				numStk.push(doCal(n1,n2,ch));
			}
			else
			{
				int val = Character.getNumericValue(ch);
				if(val>=0 && val<=9)
					numStk.push(val);	
			}
		}
		System.out.print("\t\tPostfix Evaluation \nExpression: "+exp+"\nAnswer: "+numStk.pop());
	}
	public static void main(String[] args)
	{
		StackLL stk = new StackLL();
		PostFixEval("2 3 1 * + 9 -");
	}
}
//import java.Math.*;
class Node
{
	public String data;
	public Node next;
	public Node(String d, Node n)
	{
		data = d;
		next = n;
	}
}

class LinkedList
{
	private Node root,last;
	public LinkedList(){
		root = null;
		last = null;
	}
	public void insert(String d)
	{
		Node newnode = new Node(d,null);
		if(root==null)
			root = last = newnode;
		else
			last = newnode;
	}
	public boolean search(String d)
	{
		Node n = root;
		while(root!=null)
		{
			if(d == root.data)
				return true;
			root = root.next;
		}
		return false;
	}
}

class hashTable
{
	private LinkedList list[];
	private int size;
	public hashTable(int htbSize)
	{
		size = htbSize;
		list = new LinkedList[size];
		for(int i=0;i<size;i++)
			list[i] = new LinkedList();
	}
	public double calHash(String str, int type)
	{
		double sum=0,r=0;
		if(type==0)
		{
			r=2;
			for(int i=0;i<str.length();i++)
			{
				int val = Character.getNumericValue(str.charAt(i));
				sum = (sum + (val * Math.pow(r,i)) % size) % size;
			}	
		}
		else if (type==1)
		{
			r=10;
			for(int i=0;i<str.length();i++)
			{
				int val = Character.getNumericValue(str.charAt(i));
				sum = (sum + (val * Math.pow(r,i)) % size) % size;
			}
		}
		else
		{
			r=128;
			for(int i=0;i<str.length();i++)
			{
				int val = (int)str.charAt(i);
				sum = (sum + (val * Math.pow(r,i)) % size) % size;
			}
		}
		//System.out.println("\n"+sum+"\n");
		return sum;
	}
	public void intHash(String str)
	{
		double index = calHash(str,1);
		list[(int)index].insert(str);
	}
	public void strHash(String str)
	{
		double index = calHash(str,2);
		list[(int)index].insert(str);
	}
	public void searchKey(String str, int type)
	{
		double key = calHash(str,type);
		if(list[(int)key].search(str)==true)
			System.out.print(str+" found.\n");
		else
			System.out.print(str+" not found.\n");
	}
}
public class hashChain
{
	
	public static void main(String[] args)
	{
		hashTable hc = new hashTable(11);
		//hc.intHash("123");
		hc.strHash("123");
		// searchKey(arg,arg,1) here 0 for bitstring, 1 for decimal, 2 for string
		//hc.searchKey("321",2);
		hc.searchKey("123",2);
	}
}
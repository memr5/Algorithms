import java.util.*;
class Node
{
	int data;
	Node left;
	Node right;
	Node(int data)
	{
		this.data=data;
		this.left=null;
		this.right=null;
	}
}
class bst
{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		int i,j,n;
		n=in.nextInt();
		Node node=null;
		for(i=0;i<n;i++)
		{
			int x=in.nextInt();
			if(i==0)
				node=new Node(x);
			else
				insert(node,x);
		}
		inorder(node);
		System.out.println();
	}
	static void insert(Node node,int x)
	{
		if(node.data>=x)
		{
			if(node.left!=null)
				insert(node.left,x);
			else
				node.left=new Node(x);
		}
		else
		{
			if(node.right!=null)
				insert(node.right,x);
			else
				node.right=new Node(x);
		}
	}
	static void inorder(Node node)
	{
		if(node==null)
			return;
		inorder(node.left);
		System.out.print(node.data+" ");
		inorder(node.right);
	}
}
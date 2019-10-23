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
class morrisinorder
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
		morrisInorder(node); //Inorder traversal in O(1) space
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
	static void morrisInorder(Node node)
	{
		Node current=node;
		while(current!=null)
		{
			if(current.left==null)
			{
				System.out.print(current.data+" ");
				current=current.right;
			}
			else
			{
				Node temp=findDescendant(current);
				if(temp.right==null)
				{
					temp.right=current;
					current=current.left;
				}
				else
				{
					System.out.print(temp.right.data+" ");
					current=temp.right;
					temp.right=null;
					current=current.right;
				}
			}
		}
	}
	static Node findDescendant(Node node)
	{
		Node temp=node.left;
		while(true)
		{
			if(temp.right==null)
				break;
			if(temp.right==node)
				break;
			temp=temp.right;
			break;
		}
		return temp;
	}
}
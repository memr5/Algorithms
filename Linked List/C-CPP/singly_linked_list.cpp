#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node* createList(int m)
{
	cout<<"enter the elements:  ";
    node *head, *p, *q;
    for(int i=0;i<m;i++)
    {
        q = new node;
        cin>>q->data;
        q->next = NULL;
        if(i==0)
        {
            head = q;
            p = q;
        }
        else
        {
            p->next = q;
            p = p->next;
        }
    }
    return head;
}

void display(node *head)
{
    node *p = new node;
    p = head;
    while(p!=NULL)
    {
        cout<<p->data<<"  ";
        p = p->next;
    }
    delete p;
}

void insert(node *head,int num, int pos)
{
    node *p, *q, *temp;
    int count = 0;
    pos-=1;
    q = new node;
    q->data = num;
    p = head;
    if(pos == 0)
    {
        q->next = p;
        head = q;
    }
    else
    {
        while(count != pos)
        {
            temp = p;
            p = p->next;
            count++;
        }
        temp->next = q;
        q->next = p;
    }
    
}

void deleteElement(node *head, int num)
{
    node *p, *q;
    p = head;
    if(p->data == num)
    {
        head = p->next;
    }
    else
    {
        q = p->next;
        while(q != NULL)
        {
            if(q->data == num)
            {
                p->next = q->next;
                break;
            }
            p = p->next;
            q = p->next;
        }
    }
    
}

node* makeEmpty(node* head)
{
    head = NULL;
    return head;
}

void find(node *head, int num)
{
    node *p;
    int count=0;
    p = head;
    while(p!=NULL)
    {
        if(p->data == num)
        {
            cout<<"\nFound\n";
            break;
        }
        p=p->next;
        count++;
    }
    if(p==NULL)
    {
    	cout<<"match not found"<<endl;
    }
    else
    {
    	cout<<"position: "<<count+1<<endl;
    }
}

void find_kth(node *head,int position,int num)
{
	node*p;
	p=head;
	if(position<=num)
	{
		for(int i=0;i<(position-1);i++)
		{
			p=p->next;
		}
		cout<<"value: "<<p->data<<endl;
	}
	else
	{
		cout<<"invalid position"<<endl;
	}
}

void SelectionSort(node* head)
{
    node* temp = head;
    while (temp)
    {
       	node* min = temp;
       	node* r = temp->next;
       	while (r)
       	{
        	if (min->data > r->data)
            {
   	            min = r;
   	        }
   	        r = r->next;
       	}
        int data = temp->data;
        temp->data = min->data;
        min->data = data;
        temp = temp->next;
    }
}

int main()
{
    node *head;
    int n,num, pos,number,index;
    char ch;
    cout<<"enter the number of elements to enter:  ";
    cin>>n;
    head = createList(n);
    cout<<"the entered list is:  ";
    display(head);
    cout<<"\n\nEnter the number to delete: ";
    cin>>num;
    deleteElement(head, num);
    display(head);
    cout<<"\n\nEnter a number to insert: ";
    cin>>num;
    cout<<"Enter the position to insert at: ";
    cin>>pos;
    insert(head, num, pos);
    display(head);
    cout<<"\n\nenter the number to check if present or not: ";
    cin>>number;
    find(head,number);
    cout<<"\nEnter the index whose value is to be found: ";
    cin>>index;
    find_kth(head,index,n);
	cout<<"\nsorted list: ";
	SelectionSort(head);
	display(head);
    cout<<"\npress E to empty the list or any other to skip and display:  ";
    cin>>ch;
    if(ch==101)
    {
    	ch-=32;
    }
    switch(ch)
    {
	    case 'E':
    		head = makeEmpty(head);
		    display(head);
		    break;
		default:
			display(head);
	}
	cout<<endl;
    return 0;
}

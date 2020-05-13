 
#include <stdio.h>
#include <stdlib.h>
#define MAX 2147483647
#define en printf("\n")
#define forn(i,n) for (int i = 0; i < (n); ++i)
#define cin(n) scanf("%d",&(n))

int * memory(int node)
{
	return (int*)calloc((node+1)*node*node,sizeof(int));
}


int min(int a,int b)
{
	return a < b ? a : b ;
}

void War_init(int *arr,int n)
{
	for(int i = 0; i <= (n+1)*n*n ; i++)
		if(arr[i] != 1)
			arr[i]=0;
}

void Floyd_init(int *arr, int n)
{
	int i,j;
	forn(i,n)
	{
		forn(j,n)
		{
			if( i == j )
					arr[ i*n + j ] = 0;
				else
					arr[ i*n + j ] = MAX;
		}
	}
	
}

void Display(int *arr, int k, int n)
{
	forn(i,n)
	{
		en;
		forn(j,n)
		{	
			if(arr[k*n*n + i*n + j] == MAX)
				printf("  inf\t" );
			else
				printf("  %d\t",arr[k*n*n + i*n + j]);
		}
	}
}

void Warshall(int *arr, int n )
{
	int k=0;
	for(k=1; k <=n ; k++)
	{
		int d=k-1;
		forn(i,n)
		{
			forn(j,n)
			{
				if(arr[(k-1)*n*n + i*n + j] || (arr[(k-1)*n*n + i*n + d] && arr[(k-1)*n*n + d*n + j]) )
					arr[k*n*n + i*n + j] = 1 ;
			}
		}
		printf("\n \n\t FOR K =  %d \n",k);
		Display(arr,k,n);
	}

} 

void floyd(int *arr,int n)
{
	for(int k = 1; k <= n ; k++)
	{
		int d = k-1;
		forn(i,n)
		{
			forn(j,n)
			{
					if(arr[(k-1)*n*n + i*n + d] != MAX && arr[(k-1)*n*n + d*n + j] != MAX)
						arr[k*n*n+i*n+j] = min(arr[(k-1)*n*n+i*n+j], arr[(k-1)*n*n + i*n + d] + arr[(k-1)*n*n + d*n + j]);
					else
						arr[k*n*n+i*n+j] = arr[(k-1)*n*n+i*n+j];
			}
		}
		printf("\n \n\t FOR K =  %d \n",k);
		Display(arr,k,n);
	}

}

int main()
{
	int choice, index,node,m = 1,src,des,weight;
	int *adj;
	int i,k,j;
	do
	{
		printf("\nPRESS 1 for Warshall Algo\nPRESS 2 for Floyd Algo\nPRESS 3 for exit\nEnter your Choice:  ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n enter nos of vertices :  ");
					cin(node);
					if(node < 2)
						break;

					adj = memory(node);
					while(1)
					{
						printf("\ndo you want to enter edge?:\n1. Yes \n2. No\nEnter your  choice: ");
						cin(m);
						printf("%d",m);
						if(m == 2)
						{
							printf("\n your current graph is ::\n");
							getchar();
							break;
						}
						printf("\nEnter src :  ");
						cin(src);
						printf("\nEnter des:  ");
						cin(des);

						if( src <= 0 || des <= 0 || src > node || des > node)
							printf(" Re-enter \n");
						
						else if(adj[(src-1)*node +  des-1]==1)
							printf(" Already entered!! \n ");
						else 
							adj[(src-1)*node +  des-1]=1;	
					}
					War_init(adj ,node);
					Display(adj, 0 , node);
					Warshall(adj, node);
					free(adj);
					break;

			case 2: printf("\n enter nos of vertices :  ");
					cin(node);
					if(node < 2)
						break;

					adj = memory(node);
					Floyd_init(adj ,node);
					while(1)
					{
						printf("\ndo you want to enter edge?:\n1. Yes \n2. No\nEnteryour  choice: ");
						cin(m);
						printf("%d",m);
						if(m == 2)
						{
							printf("\n your current graph is ::\n");
							getchar();
							break;
						}
						printf("\nEnter src :  ");
						cin(src);
						printf("\nEnter des:  ");
						cin(des);
						if(src <= 0 || des <= 0 || src > node || des > node)
							printf(" Re-enter  \n");

						else
						{
							index = (src-1)*node +  des-1;
						 	if(adj[index] != MAX && adj[index] != 0)
								printf(" Already entered!! \n");
							else 
							{
								printf("\nEnter weight:  ");
								cin(weight);
								if(src != des)
									adj[index]= weight;
							}
						
					   }
					}
					Display(adj, 0 , node);
					floyd(adj, node);
					free(adj);
					break;	

		}
	}while(choice != 3);

	return 0;
}

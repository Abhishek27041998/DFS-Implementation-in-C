#include<stdio.h>
#include<stdlib.h>

#define MAX 25 

int visited[MAX];

int adjMat[MAX][MAX];

int n,e;
 
void init()
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			adjMat[i][j] = 0;
		
			if(i == j )
				adjMat[i][j] = -1;
		}
	}
}

void read_graph()
{
	printf("Enter number of vertices : ");
	scanf("%d",&n);

	int num;

	for(int i = 0; i < n; i++)
	{
		printf("\nEnter number of vertices adjacent to %d : ",i);
		scanf("%d",&num);
		int v;

		printf("\nEnter the Vertices Number adjacent to %d : \n",i);
		for(int j = 0; j < num; j++)
		{
			scanf("%d",&v);

			if(v > -1 && v < n)
				adjMat[i][v] = 1;
			else
			{
				printf("Invalid edge\n");
				j--;
			}
		}

	}
}

void DFS(int i)
{
	int j;
	printf("\n%d",i);

        visited[i]=1;
    
        for(j=0;j<n;j++)
        	if(!visited[j] && adjMat[i][j]==1)
            		DFS(j);
}

int main()
{
	init();

 	read_graph();
 
        DFS(0);
	
        return 0;
}
 


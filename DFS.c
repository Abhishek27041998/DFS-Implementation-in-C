#include<stdio.h>
#include<stdlib.h>

int adjMat[10][10],visited[10];


void DFS(int i)
{
    int j;

    printf("\n%d",i);

    visited[i]=1;
    
    for(j = 1; j <= 10; j++)
       if(!visited[j] && adjMat[i][j]==1)
            DFS(j);
}

int main()
{

	printf("Enter Adjacency Matrix\n");
	
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 10; j++)
		{	
			if(i != j)
			{
				printf("Is %d adjacent to %d (0/1)\n",i,j);
				scanf("%d",&adjMat[i][j]);
			}
		}
	}

	for(int i = 0 ; i < 10; i++)
		visited[i+1] = 0;
	
	DFS(1);
	
	return 0;
}



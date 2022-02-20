#include<stdio.h>
int main()
{
	int i,gr_mat[6][6],ch,deg[6],temp,indegree[6]={0,0,0,0,0,0},outdegree[6]={0,0,0,0,0,0},j;
	
	printf("Enter the type of graph 1-Undirected Graph\t2-Directed Graph : ");
	scanf("%d",&ch);
	printf("\nEnter the adjacency matix for the graph : \n");
	
	
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++) 
			scanf("%d",&gr_mat[i][j]);                        //to get the input of graph adjecency matrix
	}    
	printf("\nThe adjecency matrix for graph is :\n");
	for(i=0;i<6;i++)
	{	printf("\n");
		for(j=0;j<6;j++) 
			printf("%d\t",gr_mat[i][j]);
	}     									 //to print the graph adjecency matrix
	switch(ch)
	{
		case 1: for(i=0;i<6;i++)
			 {
			 
			 	deg[i]=0;
			 	for(j=0;j<6;j++)
			 	{
			 		if(gr_mat[i][j]==1)
			 			deg[i]++;			//to find the degree of each vertex
			 	}
			  }
			  
			  for(i=0;i<6;i++)
			  {
			 	
			 	for(j=i;j<6;j++)				//sorting the degrees in descending oreder						
			 	{
			 		if(deg[j]>deg[i])
			 		{
			 			temp=deg[i];
			 			deg[i]=deg[j];
			 			deg[j]=temp;
			 			
			 		}
			 	}
			 }
			 printf("\nThe degree of the graph is %d\n",deg[0]); //the degree of graph is first element of sorted degrees 
			 break;
			 
		case 2:for(i=0;i<6;i++)
			 {
			 	
			 	for(j=0;j<6;j++)
			 	{
			 		if(gr_mat[i][j]==1)
			 		{	indegree[j]++;
			 			outdegree[i]++;		//to find the indegree and outdegree of each vertex and storing in two seperate matrices 
			 		}
			  	}
			  }
			  for(i=0;i<6;i++)
			  {
			  	printf("\nDegreee of vertex %d is\nindegree:%d\noutdegree:%d\n",i+1,indegree[i],outdegree[i]);  //printing the degree of each vertex 
			  }
			 break ;
	}
	return 0;
		
		
}

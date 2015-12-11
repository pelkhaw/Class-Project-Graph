*Graph.c                 
 * Paul El-khawaja           
 * ECE 223 Fall 2015
 * MP6
 *
 * Propose: A template for Graph.c. 
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>

#include "Graph.h"  
#define TRUE 1
#define FALSE 0
//This function creates the graph given to us in the instructions
// it takes in as its arguments and empty matrix of nodes and 
// then just has the graph hard coded into the matrix
void GraphCreate1(Node **Nodes)
{    
        
        int n=0;
        int Vertices=7;
        for(n=0;n<Vertices;n++)
        {               
                Nodes[n]=(Node *)malloc(sizeof(Node));
                Nodes[n]->key=n;
                Nodes[n]->root=NULL;
         
        }
        Nodes[0]->degree=0;
        Nodes[1]->degree=2;
        Nodes[2]->degree=3;
        Nodes[3]->degree=2;
        Nodes[4]->degree=1;
        Nodes[5]->degree=1;
        Nodes[6]->degree=3;
        Nodes[1]->root=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[1]->root->weight=3;
        Nodes[1]->root->key=2;
        Nodes[1]->root->Next=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[1]->root->Next->weight=5;
        Nodes[1]->root->Next->key=6;
        Nodes[1]->root->Next->Next=NULL;
        Nodes[2]->root=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[2]->root->weight=7;
        Nodes[2]->root->key=3;
        Nodes[2]->root->Next=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[2]->root->Next->weight=3;
        Nodes[2]->root->Next->key=4;
        Nodes[2]->root->Next->Next=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[2]->root->Next->Next->weight=10;
        Nodes[2]->root->Next->Next->key=6;
        Nodes[2]->root->Next->Next->Next=NULL;
        Nodes[3]->root=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[3]->root->weight=5;
        Nodes[3]->root->key=4;
        Nodes[3]->root->Next=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[3]->root->Next->weight=1;
        Nodes[3]->root->Next->key=5;
        Nodes[3]->root->Next->Next=NULL;
        Nodes[4]->root=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[4]->root->weight=6;
        Nodes[4]->root->key=5;
        Nodes[4]->root->Next=NULL;
        Nodes[5]->root=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[5]->root->weight=7;
        Nodes[5]->root->key=6;
        Nodes[5]->root->Next=NULL;
        Nodes[6]->root=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[6]->root->weight=4;
        Nodes[6]->root->key=0;
        Nodes[6]->root->Next=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[6]->root->Next->weight=8;
        Nodes[6]->root->Next->key=3;
        Nodes[6]->root->Next->Next=(NodeLine *)malloc(sizeof(NodeLine));
        Nodes[6]->root->Next->Next->weight=9;
        Nodes[6]->root->Next->Next->key=4;
        Nodes[6]->root->Next->Next->Next=NULL;
        
}
//This function creates the second graph by taking in an empty matrix
// and the number of Vertices in the graph and using the given formulas
// to calculated weight of connections
void GraphCreate2(Node **Nodes,int Vertices)
{    
        
        int n=0;
        int i=0;
        double w;
        NodeLine* rover;
        for(n=0;n<Vertices;n++)
        {               
                Nodes[n]=(Node *)malloc(sizeof(Node));
                Nodes[n]->key=n;
                Nodes[n]->root=NULL;
         
        }

        for(n=0;n<Vertices;n++)
        {
                for(i=0;i<Vertices;i++)
                {
                        if (i!=n)
                        {
                                w=(double )abs(n-i)+pow(((n-i)+2),2)+(3*i);
                                rover=Nodes[n]->root;
                                if(Nodes[n]->root==NULL)
                                {
                                        Nodes[n]->root=(NodeLine *)malloc(sizeof(NodeLine));
                                        rover=Nodes[n]->root;
                                        
                                }
                                else
                                {
                                        while (rover->Next!=NULL)
                                        {
                                                rover=rover->Next;
                                               
                                        }            
                                        rover->Next=(NodeLine *)malloc(sizeof(NodeLine));
                                        rover=rover->Next;
                                }
                                rover->weight=w;
                                rover->key=i;
                                rover->Next=NULL;
                                Nodes[n]->degree++;
                        }
                }
        }
        
        
        
        
}
//This function creates a graph by taking in a an empty matrix for nodes and
// the number of vertices and a variable used to give the number of adjacent 
// nodes and build the graph using the formulas given to us
void GraphCreate3(Node **Nodes,int Vertices, int R)
{
        int n=0;
        int i=0;
        double w;
        double D;
        double M;
        double F;
        double C;
        NodeLine* rover;

        Nodes[0]=(Node *)malloc(sizeof(Node));
        Nodes[0]->x=0;
        Nodes[0]->y=0.5;
        Nodes[0]->key=0;
        Nodes[0]->root=NULL;
       
        Nodes[1]=(Node *)malloc(sizeof(Node));
        Nodes[1]->x=1.0;
        Nodes[1]->y=0.5;
        Nodes[1]->key=1;
        Nodes[1]->root=NULL;
        for(n=2;n<Vertices;n++)
        {               
                Nodes[n]=(Node *)malloc(sizeof(Node));
                Nodes[n]->x=drand48();
                Nodes[n]->y=drand48();
                Nodes[n]->key=n;
                Nodes[n]->root=NULL;
         
        }
        
        for(n=0;n<Vertices;n++)
        {
                for(i=0;i<Vertices;i++)
                {
                        if(i!=n)
                        {
                                D=sqrt(pow((Nodes[n]->x-Nodes[i]->x),2)+pow((Nodes[n]->y-Nodes[i]->y),2));
                                C=sqrt(R/(Vertices*M_PI));
                                M=log10(1+pow((1/C),2));
                                F=log10(1+pow((1/(D+(C/1000))),2));
                        
                                if(D<=C)
                                {
                                        w=M/F;
                                        
                                        rover=Nodes[n]->root;
                                        if(Nodes[n]->root==NULL)
                                        {
                                                Nodes[n]->root=(NodeLine *)malloc(sizeof(NodeLine));
                                                rover=Nodes[n]->root;
                                                
                                        }
                                        else
                                        {
                                                while (rover->Next!=NULL)
                                                {
                                                        rover=rover->Next;
                                                       
                                                }            
                                                rover->Next=(NodeLine *)malloc(sizeof(NodeLine));
                                                rover=rover->Next;
                                        }
                                        rover->weight=w;
                                        rover->key=i;
                                        rover->Next=NULL;
                                        Nodes[n]->degree++;
                                }
                        } 
                }
        }
}
// This function uses dijkstras algorithm to calculate the shortest path between
// two nodes in a graph with weights
// the inputs are
// The Graph
// the source node
// the destination node
// the size of the array 
// and an option to print
// the print option is used when the user asks for the shortest path, but can
// be left out when the function is being called from another function to save time
double Shortpath(Node **Nodes, int source, int V,int length, int opt)
{
        if (source<0||source>=length||V<0||V>=length)
        {
        printf("INPUTED SILLY VALUES TRY AGAIN\n");      
        return 0;     
        }
        NodeLine* rover;
        double ShortestDistance[length];
        int n=0,i=0;
        int W[length];
        int w=source;
        int inverse[length];
        int check=1, whole=0;
        int Predecessor[length];
        int pred=source;
        int stop=V;
        Predecessor[source]=source;
        rover=Nodes[source]->root;
        int Max=0;
        for(n=0;n<length;n++)
        {
                ShortestDistance[n]=INFINITY; 
                W[n]=0;
        }     
        W[source]=1;   
        ShortestDistance[source]=0;
        while(rover!=NULL)
        {
                ShortestDistance[rover->key]=rover->weight;
                Predecessor[rover->key]=pred;
                rover=rover->Next;
                
        }
        
        while(check!=length)
        {
                double MinDistance=INFINITY;
                double Cost;
                
                for(n=0;n<length;n++)
                {
                                
                        if (ShortestDistance[n]<=MinDistance&&W[n]!=1)
                        {
                                MinDistance=ShortestDistance[n];             
                                w=n;
                        }
                }
                
                if(W[w]==0)
                {
                        W[w]=1;
                        check++;           
                        pred=w;
                }
                rover=Nodes[w]->root;
                while(rover!=NULL)
                {
                        Cost=ShortestDistance[w]+rover->weight;
                        if(Cost<ShortestDistance[rover->key])
                        {
                                ShortestDistance[rover->key]=Cost;
                                Predecessor[rover->key]=pred;
                        }
                        rover=rover->Next;
                }
        }

//These options are to create different outputs and returns depending on what the
//need of the function call Dijkstra algorithm is
        if (opt==0||opt==2||opt==1)
        {
                n=0;
                if (opt==2)
                {
                        for(n=1;n<length;n++)
                        {
                                if (ShortestDistance[n]>ShortestDistance[Max]&&ShortestDistance[n]!=INFINITY)
                                        Max=n;
                                if(ShortestDistance[n]==INFINITY)
                                        whole=1;
                        }
                        printf("The Diameter is %.4lf, from %i to %i",ShortestDistance[Max],source,Max);

                        if(whole==1)
                                printf(", and the Graph is not connected");
                        printf("\n");
                V=Max;
                }
                 if(ShortestDistance[V]!=INFINITY&&opt==1)
                {

                        printf("the cost of the path is %.2lf\n",ShortestDistance[V]);  
                        inverse[n]=V;
                        do
                        {
                                n++;
                                V=Predecessor[V]; 
                                inverse[n]=V;                                                
                        }while(source!=V);
                        for(i=n;i>=0;i--)
                        {
                                printf("%i--",inverse[i]);
                        }
                        printf("\n");
                }      
                else if(opt==1)
                        printf("Path Does not exist\n");         

        }
        else if(opt==0)
        {
                for(n=1;n<length;n++)
                {
                        if (ShortestDistance[n]>ShortestDistance[Max]&&ShortestDistance[n]!=INFINITY)
                                Max=n;
                }
        }
        else if(opt==3)
        {
                n=0;
                 if(ShortestDistance[V]!=INFINITY)
                 {
                  printf("the cost of the path is %.2lf\n",ShortestDistance[V]);   
                        inverse[n]=V;
                        do
                        {
                                n++;
                                V=Predecessor[V]; 
                                inverse[n]=V;                                                
                        }while(source!=V);
                        if(source!=stop)
                        {
                                for(i=n;i>=0;i--)
                                {
                                        printf("%i--",inverse[i]);
                                }
                        
                        printf("\n");
                        }
                        if(source!=stop)
                                clearpath(Nodes,inverse,n,source,stop,length);
                        else 
                        printf("\nNo paths exist\n");  
                 }      
                else
                        printf("\nNo paths exist\n");           
        }
        if (ShortestDistance[Max]==INFINITY)
                return 0;
        return ShortestDistance[Max]; 
}
// This function takes an input of string of nodes, the number in that string
// The list containing the nodes, the size of the list
// and the start and stop values to the Node string
void clearpath(Node** Nodes,int * path,int n,int start,int stop,int length)
{
        int i=0;
        NodeLine *rover,*prev;

        for(i=n;i>0;i--)
        {
                rover=Nodes[path[i]]->root;
                if (rover->key==path[i-1])
                {
                        rover=Nodes[path[i]]->root;
                        Nodes[path[i]]->root=rover->Next;
                }
                else
                {
                        prev=rover;
                        rover=rover->Next;
                        while(rover->key!=path[i-1])
                        {
                                prev=rover;
                                rover=rover->Next;
                        }
                        prev->Next=rover->Next;
                }
             free(rover);
             Nodes[path[i]]->degree--;
        }
        Shortpath(Nodes, start, stop,length, 3);
}
// This function has an input of the Nodes in the matrix and
// the size of the graph in number of nodes
// the function  calls dijkstras algorithsm for every node in
// the graph and uses the max distance that's not infinity to 
// find the diameter of the graph
void diameter(Node **Nodes,int V)
{
int i;
double D[V];
int Max=0;
  
for(i=0;i<V;i++)
{
               D[i]=Shortpath(Nodes, i, 0,V,0);
               //printf("%.4lf--",D[i]);
}
for(i=1;i<V;i++)
{
        if(D[i]>D[Max])
                Max=i;
}
Shortpath(Nodes, Max, 0,V,2);
        
}
// This function deletes the graph and frees the memory taken from the system
// The input is the graph and the number of Vertices in the graph
void CleanUp(Node **Nodes,int Vertices)
{
        int n=0;  
        NodeLine* rover;
        NodeLine* prev;
        for(n=0;n<Vertices;n++)
        {
                rover=Nodes[n]->root;
                
                while(rover!=NULL)
                {
                        prev=rover;
                        rover=rover->Next;
                        prev->Next=NULL;
                        free(prev);
                }
                free(Nodes[n]);
                Nodes[n]=NULL;
                
        }
}
// This function takes the graph and prints a quick and easy to read list to 
// understand how the graph is set-up
// The input is the graph and the number of Vertices in the graph
void dirty_print(Node **Nodes,int Vertices)
{
        NodeLine* rover;
        int n;
        for(n=0;n<Vertices;n++)
        {
                printf("NODE:%d D%d ",Nodes[n]->key,Nodes[n]->degree);
                rover=Nodes[n]->root;
                while(rover!=NULL)
                {
                        
                        printf("--%d(%.3lf)",rover->key,rover->weight);
                        rover=rover->Next;
                }
                printf("\n");
        }
        
}

/* lab6.c 
 * Lab6: Graphs
 * ECE 223, Fall 2015
 *

 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>
#include <float.h>

#include "Graph.h"

/* constants used with Global variables */

#define TRUE 1
#define FALSE 0

/* Global variables for command line parameters */
int GraphType=2;
int Vertices=7;  
int Adjacent=10;
int GraphOperation=0;
int DestVertex=1;
int Operation=0;
int Source=0;
int Seed = 911645379;
int Verbose = FALSE;

/* prototypes for functions in this file only */
void getCommandLine(int argc, char **argv);
//Main Function Takes input args
// and calls the complementary function from Graph.c
// to complete the task
int main(int argc, char **argv)
{
        clock_t start, end;
        getCommandLine(argc, argv);
        assert((Vertices>0));
        assert((GraphType>0));
        assert((GraphType<4));
        
        printf("Seed: %d\n", Seed);
        srand48(Seed);
        
        if (GraphType==1)
                Vertices=7;
        Node* NodeList[Vertices]; 

        if (GraphType==1)               
                GraphCreate1(NodeList);    
        else if (GraphType==2)   
                GraphCreate2(NodeList,Vertices);
        else if (GraphType==3)
                GraphCreate3(NodeList,Vertices,Adjacent );
        if (Verbose==TRUE)
                dirty_print(NodeList,Vertices);
        if (GraphOperation==1)
        {
                start = clock();
                Shortpath(NodeList,Source,DestVertex,Vertices,1);
                end= clock();
                printf("After Dijkstras algorithm exercise, time=%g\n",
                1000*((double)(end-start))/CLOCKS_PER_SEC);
                
        }
        else if (GraphOperation==2)
        {
                start = clock();
                diameter(NodeList,Vertices);
                end= clock();
                printf("After Diameter algorithm exercise, time=%g\n",
                1000*((double)(end-start))/CLOCKS_PER_SEC);       
        }
        else if (GraphOperation==3)
                Shortpath(NodeList, Source,DestVertex,Vertices,3);
        if (Verbose==TRUE)
                dirty_print(NodeList,Vertices);
        CleanUp(NodeList,Vertices);
        return 0;

}



/* read in command line arguments and store in global variables for easy
 * access by other functions.
 */
void getCommandLine(int argc, char **argv)
{
    /* optopt--if an unknown option character is found
     * optind--index of Next element in argv 
     * optarg--argument for option that requires argument 
     * "x:" colon after x means argument required
     */
    int c;
    int index;

    while ((c = getopt(argc, argv, "n:a:h:s:d:r:g:v")) != -1)
        switch(c) {
            case 'n': Vertices = atoi(optarg);          break;
            case 'a': Adjacent = atoi(optarg);          break;
            case 'v': Verbose = TRUE;                   break;
            case 'h': GraphOperation = atoi(optarg);    break;
            case 's': Source = atoi(optarg);            break;
            case 'd': DestVertex = atoi(optarg);        break;
            case 'r': Seed = atoi(optarg);              break;
            case 'g': GraphType = atoi(optarg);         break;
            case '?':
                if (isprint(optopt))
                    fprintf(stderr, "Unknown option %c.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
            default:
                
                exit(1);
        }
        
    for (index = optind; index < argc; index++)
        printf("Non-option argument %s\n", argv[index]);
}



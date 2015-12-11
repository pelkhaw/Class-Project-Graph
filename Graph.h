/* Graph.h 
 *
 * Public functions for Graph
 *
 */
//This struct holds values that show what node each
//node is connected to and with what weight
typedef struct graph_NodeLine_tag {
    int key;
    double weight;
    struct graph_NodeLine_tag *Next;
} NodeLine;
//This struct represents a node 
typedef struct Node_tag {
    NodeLine *root;
    int key;
    double x;
    double y;
    int degree;
}Node;
//Prototyping functions Used in Graph.c
void GraphCreate2(Node**,int);
void GraphCreate1(Node**);
void GraphCreate3(Node**,int,int);
void dirty_print(Node**,int);
void CleanUp(Node**, int);
double Shortpath(Node**,int,int,int,int);
void diameter(Node**,int);
void clearpath(Node**,int *,int,int,int,int);


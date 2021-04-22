
#include "gluethread/glthread.h"

//Max size of the routing device could be of 16 bytes
#define NODE_NAME_SIZE 16
#define IF_NAME_SIZE   16

//Max number of empty slots per node is defined as 10
#define MAX_INTF_PER_NODE 10


/*FORWARD DECLARATION*/
typedef struct node_ node_t;
typedef struct link_ link_t;



//Data Structure that defines the interface
typedef struct interface_{

char if_name[IF_NAME_SIZE];

//Every interface has a pointer to the node which it is a part of
struct node_ *att_node;  

//Nodes are connected to the links
struct link_ *link;   

} interface_t;


//Data Structure defining the links
struct link_{

//interface connected to the empty slots
interface_t intf1;
interface_t intf2;
unsigned int cost;

};

//Data Structure Defining the Node in the graph
struct node_{

//Node name
char node_name[NODE_NAME_SIZE];

//member of array holds address to the Interface DS
interface_t *intf[MAX_INTF_PER_NODE];

//This adds node to the linked List of the Graph
glthread_t graph_glue;

};


//Data Structure defining the graph
typeof struct graph_{

char topology_name[32];
glthread_t node_list;    //glthread is nothing but Linked List itself

};


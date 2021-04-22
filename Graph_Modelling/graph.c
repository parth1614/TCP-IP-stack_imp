
#include "graph.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void
insert_link_between_two_nodes(node_t *node1,
                          
                            char *from_if_name,
                            char *to_if_name,
                            unsigned int cost){


link_t *link = calloc(1, sizeof(link_t));

/*SET INTERFACE PROPERTIES*/
strncpy(link->intf1.if_name, from_if_name, IF_NAME_SIZE);
link->intf1.if_name[IF_NAME_SIZE] = '\0';

//Setting up the link 2
strncpy(link->intf2.if_name, to_if_name, IF_NAME_SIZE);
link->intf2.if_name[IF_NAME_SIZE] = '\0';

//set the back pointer to link
link->intf1.link = link;

link->intf2.link = link;

//Attaching links to the nodes

link->intf1.att_node = node1;
link->intf2.att_node = node2;
link->cost = cost;

//Attaching the interfaces to the empty slots

int empty_intf_slot;

}


graph_t *

//The API creates a new graph
create_new_graph(char *topology_name){

//Storage for the newly formed graph
graph_t *graph = calloc(1,sizeof(graph_t));

strncpy(graph->topology_name, topology_name,32);
graph->topology_name[32] = '\0';

init_glthread(&graph->node_list);
return graph;

}

node_t *

create_graph_node(graph_t *graph, char *node_name){

node_t *node = calloc(1, sizeof(node_t));

strncpy(node->node_name, node_name, NODE_NAME_SIZE);
node->node_name[NODE_NAME_SIZE] = '\0';

init_glthread(&node->graph_glue);
glthread_add_next(&graph->node_list, &node->graph_glue);
return node;

}





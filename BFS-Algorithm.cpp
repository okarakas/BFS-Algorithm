#include<iostream>
using namespace std; 

class Node { //Class structure that holds the connection between nodes
    public:
        char from; //The variable where the first node is held
        char to; //The variable that will hold the node's connections
};


void BFS(char start);//BFS function definition
int edge_num;//Variable that holds the total number of connections
Node * nodes;//Define nodes object connected to Node class

int main() 
{
    //The nodes of the graph and the nodes it is connected to
    //It will be read from the edges.txt file.
    FILE *edges;
    edges=fopen("edges.txt","r");
    fscanf(edges, "%d", &edge_num); //The first line of the file contains the number of links.

    nodes = new Node [edge_num];//The array is created by containing the variables that depend on the Node class.
    
    //Node links read from the file are assigned to the "from" and "to" variables, respectively.
    //Connections "from" are defined as the first node and "to" as its child child nodes.
    for(int i=0; i<edge_num; i++){
        fscanf(edges, "\n %c %c", &nodes[i].from, &nodes[i].to);
    }
    
    BFS('S'); //The BFS function is called by specifying the starting node in parentheses.
    //Since nodes are defined as char type in the program, they are specified using ' in parentheses.
}


void BFS(char start) {
    char visited[edge_num]; //Array to keep visited nodes
    int visit{0};//Variable used to control visited nodes
    char queue[edge_num];//Since the nodes must visit their connections step by step, the queue sequence in which we will keep the connection of each node
    int que{0};//Variable used to control the queue sequence
  
    //Each element of the arrays is entered first as a ' ' (space) to make it easier to control the visited and queue arrays.
    for(int i=0; i<edge_num; i++){
        visited[i] = ' ';
        queue[i] = ' ';
    }
    
    cout << "Result when using Breadth-First search (start node: " << start << "):";
    visited[visit] = start;//Assigning the starting node to the visited array. 
    //The first node is saved as visited and printed to the screen.
    cout  << " " << visited[visit];
    
    //BFS algorithm, starting from the starting node determined in the graph, visits the nodes it is connected to, step by step.
    
    //Defined a loop that scans by continuing from the last digit each time
    for(visit=0;visit<edge_num; visit++){
        
        //In this loop, the nodes that are connected to whichever node in the transaction is listed.
        for(int i=0; i<edge_num; i++){
            if(visited[visit] == nodes[i].from){//visited[visit] = last visited node. nodes[i].from = The master node defined within the Node class, retrieved from edges.txt.
            //The equality is checked and when the two nodes match, the nodes that the node is linked to by index number are added to the Queue array.
                queue[que] = nodes[i].to;//Connected nodes are stored in Queue array sequentially. nodes[i].to = Linked node defined within the Node class, retrieved from edges.txt.
                que++;//Incrementing the control variable of the queue array by 1.
            }
        } 
        //This loop checks respectively whether the nodes in the Queue array have been visited.
        for(int i=0; i<que; i++){
            for(int j=0; j<edge_num; j++){
                if(visited[j] != ' ' && visited[j] == queue[i]){
                    break;//If the node in the queue array exists in the visited array and the corresponding element of the visited array is not empty,
					//the loop is exited and the control of the next node is passed.
                }
                else if(visited[j] == ' '){//If the above equality cannot be achieved and the relevant element of the visited array is empty;
                    visited[j] = queue[i];//In the queue array, the next node is added to the visited array.
                    cout  << " " << visited[j];//The visited node is printed to the screen.
                    break;//The loop exits and moves to the next node held in the Queue array.
                }
            }
        } 
        //This loop is used to empty the Queue array, when each node in the Queue array is added to the visited array,
		//to add the links to the nodes to be visited when moving to the next step of the graph.
        for(int i=0; i<edge_num; i++){
            queue[i] = ' ';
        }
        que=0;//We reset the control variable of the queue array.
    }
    cout << endl;
}
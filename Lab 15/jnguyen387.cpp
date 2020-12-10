#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <climits>                                                  //added climits to get access to INT_MAX  

struct Graph {
    std::list<std::string> vertices;
    std::map<std::pair<std::string,std::string>,int> edges;
    void PrintOut(void);
    void AddEdge(std::string,std::string,int);
    void AddVertex(std::string);
    bool FindVertex(std::string);
    int FindEdgeCost(std::string vert1, std::string vert2);
    int IsReachable(std::string vert1, std::string vert2);
};

void Graph::PrintOut(void) {
    std::list<std::string>::iterator it;
    std::map<std::pair<std::string,std::string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        std::cout << *it << std::endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        std::cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << std::endl;
    }
}

void Graph::AddVertex(std::string vert){
    vertices.push_back(vert);
}

void Graph::AddEdge(std::string vert1,std::string vert2,int weight) {
    std::pair<std::string,std::string> p(vert1,vert2);
    edges[p] = weight;
}

bool Graph::FindVertex(std::string vert1) {                          //just reused code from printout, but instead of printing out *it, im just checking to see if vert1 is in the Graph
    std::list<std::string>::iterator it;
    for(it = vertices.begin(); it!=vertices.end();it++){
        if(*it == vert1){                                            //if it is, return true, else return false
            return true;
        }        
    }
    return false;
}

int Graph::FindEdgeCost(std::string vert1, std::string vert2) {
    std::pair<std::string,std::string> p(vert1,vert2);
    if(edges.find(p) != edges.end()){
        return edges[p];
    }
    return -1;
}

int Graph::IsReachable(std::string vert1, std::string vert2) {       //used the algorithm pseudocode in the textbook on pg.595
    std::map<std::string,std::string> color;
    std::map<std::string,std::string> predecessor;
    std::map<std::string, int> distance;
    std::queue<std::string> Q;
    std::string u;
    std::string adjacencyVertex;

    std::list<std::string>::iterator it;
    std::map<std::pair<std::string,std::string>,int>::iterator eit;
    for(it = vertices.begin(); it!=vertices.end();it++){             //initializing all the vertices besides source vertex with color White, distance Infinity, and precessdor NIL
        color[*it] = "WHITE";                                        //to indicate we haven't traveled to that vertex yet
        distance[*it] = INT_MAX;
        predecessor[*it] = "NIL";
    }
    color[vert1] == "GRAY";                                          //we reach the vertex and edit its property to Gray, 0, and NIL
    distance[vert1] = 0;
    predecessor[vert1] = "NIL";    

    Q.push(vert1);                                                   //add the vertex into the Queue

    while(Q.size() != 0){
        u = Q.front();
        Q.pop();
        for(eit = edges.begin(); eit != edges.end(); eit++){         //this allows us to go through the edges, but it doesnt know what is the adjacency vertex 
            if(((*eit).first).first == u){                           //so we find the vertex and then create a variable storing its adjacency vertex
                adjacencyVertex = ((*eit).first).second;
            }
            if(color[adjacencyVertex] == "WHITE"){                   //now that we found the adjacency vertex, can start to edit its properties to Gray, u.d + 1, and u
                color[adjacencyVertex] = "GRAY";
                distance[adjacencyVertex] = distance[u] + 1;
                predecessor[adjacencyVertex] = u;
                Q.push(adjacencyVertex); 
            }
        }
        color[u] = "BLACK";                                          //color the u vertex black to indicate we finish this vertex
    }

    if(distance[vert2] < INT_MAX){                                   //added this code to check to see if there is a distance from vertex 1 to vertex 2
        return distance[vert2];                                      //if there is return distance[vert2] else return -1
    }
    return -1;
}

int main() {
    Graph G;

    std::string inputFirstName;  
    
    std::cin >> inputFirstName;
 
    while(inputFirstName != "END"){                                  //loop until we type in END, otherwise input all the names into the Graph Vertex
        G.AddVertex(inputFirstName); 
        std::cin>>inputFirstName;
    }

    std::string inputSecondName;
    int weight = 0;
    std::cin>>inputFirstName;

    while(inputFirstName != "END"){                                 //loop until we type in END, otherwise input all the names and weight into the Graph Edge
        std::cin>>inputSecondName;
        std::cin>>weight;
        G.AddEdge(inputFirstName,inputSecondName,weight);
        std::cin>>inputFirstName;
    }

    G.PrintOut();

    int inputParameter = 0;

    std::cin>>inputParameter;
  
    while(inputParameter != 0){                                     //loop until we type in 0, otherwise if 1, search for vertex and return result    
        if(inputParameter == 1){                                    //if 2, search for edge and return cost
            std::cin>>inputFirstName;                               //if 3, search if the 2 vertices are reachable and return distance
            bool located = G.FindVertex(inputFirstName);
            if(located){
                std::cout<< 1 <<std::endl;
            } else{
                std::cout<< 0 <<std::endl;
            }
        } else if(inputParameter == 2){
            std::cin>>inputFirstName;
            std::cin>>inputSecondName;
            int edgeCost = G.FindEdgeCost(inputFirstName,inputSecondName);
            std::cout<<edgeCost<<std::endl;            
        } else if(inputParameter == 3){
            std::cin>>inputFirstName;
            std::cin>>inputSecondName;
            int numEdges = G.IsReachable(inputFirstName,inputSecondName);
            std::cout<<numEdges<<std::endl;
        }
        std::cin>>inputParameter;
    }
    return 0;
}

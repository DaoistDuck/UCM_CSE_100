#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

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

bool Graph::FindVertex(std::string vert1) {
    //search vert1 inside list<string> vertices 
    // if find it linear search, return true, else return false
    //need some for loop
}

int Graph::FindEdgeCost(std::string vert1, std::string vert2) {
    std::pair<std::string,std::string> p(vert1,vert2);
    if(edges.find(p) != edges.end()){
        return edges[p];
    }
    return -1;

}

int Graph::IsReachable(std::string vert1, std::string vert2) {
}

int main() {
    Graph G;

    return 0;
}

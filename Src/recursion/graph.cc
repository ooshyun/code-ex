#include <iostream>
#include <queue>            // queue in BFS
#include <unordered_map>    // unordered_map
#include <algorithm>        // find
#include "stdio.h"

struct GraphNode{
    int id;
    std::vector<int> adjacent;
    friend bool operator==(const GraphNode& g1, const GraphNode& g2){
        return g1.id == g2.id;
    }
    GraphNode(int id=-1){
        this->id = id;
    };
    ~GraphNode(){
    };
};

class Graph{
private:
    bool hasPathDFS(GraphNode* source, GraphNode* destination, std::vector<int> visited)
    {        
        visited.push_back(source->id);         

        std::cout << "Visited " << source->id << std::endl;
        for (std::vector<int>::iterator it = visited.begin() ; it != visited.end(); ++it)
            std::cout << " " << *it << " ";
        std::cout << std::endl;

        if(source == destination)
            return true;
        
        std::vector<int>::iterator bufadj = source->adjacent.begin();

        // std::cout << "Adjacent " << source->id << std::endl;
        // for (std::vector<int>::iterator it = source->adjacent.begin() ; it != source->adjacent.end(); ++it)
        //     std::cout << " " << *it << " ";
        // std::cout << std::endl;

        GraphNode* bufnode;
        while(bufadj != source->adjacent.end())
        {
            bufnode = &hashmap[*bufadj];

            auto is_find = std::find(visited.begin(), visited.end(), bufnode->id);
            if(is_find != visited.end()) 
            {
                bufadj++;
                continue;
            }

            if(hasPathDFS(bufnode, destination, visited)){
                return true;
            };
            bufadj++;
        }
        return false;
    }
    bool hasPathBFS(GraphNode* source, GraphNode* destination)
    {
        std::vector<int> visited;
        visited.push_back(source->id);
        std::queue<int> visit_nodes_next;

        for (std::vector<int>::iterator it = source->adjacent.begin() ; it != source->adjacent.end(); ++it)
            visit_nodes_next.push(*it);

        GraphNode* bufnode;
        int idbuf;
        while (!visit_nodes_next.empty())
        {
            idbuf = visit_nodes_next.front();
            visit_nodes_next.pop();

            visited.push_back(idbuf);
            bufnode = &hashmap[idbuf];
            
            std::cout << "Visited " << idbuf << std::endl;
            for (std::vector<int>::iterator it = visited.begin() ; it != visited.end(); ++it)
                std::cout << " " << *it << " ";
            std::cout << std::endl;

            if(bufnode == destination)
                return true;

            for (std::vector<int>::iterator it = bufnode->adjacent.begin() ; it != bufnode->adjacent.end(); ++it)
                visit_nodes_next.push(*it);
        }
        
        return false;
    }
public:
    std::unordered_map<int, GraphNode> hashmap;
    GraphNode* getNode(int id){
        return &hashmap[id];
    }
    void addNode(int id);
    void addEdge(int source, int destination){
        GraphNode* s = getNode(source);
        GraphNode* d = getNode(destination);
        s->adjacent.push_back(d->id);
        d->adjacent.push_back(s->id);
    }

    bool hasPathDFS(int source, int destination){
        std::cout << "Find DFS " << source << " - " << destination << std::endl;

        GraphNode* s = getNode(source);
        GraphNode* d = getNode(destination);

        // std::cout << "Node " << s->id << std::endl;
        // for (std::vector<int>::iterator it = s->adjacent.begin() ; it != s->adjacent.end(); ++it)
        //     std::cout << " " << *it+1 << " ";
        // std::cout << std::endl;

        // std::cout << "Node " << d->id << std::endl;
        // for (std::vector<int>::iterator it = d->adjacent.begin() ; it != d->adjacent.end(); ++it)
        //     std::cout << " " << *it+1 << " "; 
        // std::cout << std::endl;
                   
        std::vector<int> visited;
        return hasPathDFS(s, d, visited);
    }
    bool hasPathBFS(int source, int destination){
        GraphNode* s = getNode(source);
        GraphNode* d = getNode(destination);
        return hasPathBFS(s, d);
    }

};

size_t num_node = 8;
const size_t num_edge = 10;

void testGraph(){
    int edge[num_edge][2] = {{1, 2}, {1, 4}, {1, 3}, {1, 6}, {2, 3}, {3, 6}, {4, 6}, {5, 6}, {6, 8}, {7, 8}};

    Graph solution = Graph();
    GraphNode* bufGraphNode;
    uint8_t i = 0;
    for(i=0; i<num_node; i++)
    {
        solution.hashmap[i] = GraphNode(i);
    }

    for(i=0; i<num_edge; i++)
    {
        solution.addEdge(edge[i][0]-1, edge[i][1]-1);
    }

    std::cout << "Check Node and Edge" << std::endl;
    // std::vector<int>::iterator it, uint8_t j;
    
    for(i=0; i<num_node; i++)
    {
        bufGraphNode = solution.getNode(i);
        std::cout << " Node " << bufGraphNode->id << std::endl;
        std::cout << "Adjacent \n";

        for (std::vector<int>::iterator it = bufGraphNode->adjacent.begin() ; it != bufGraphNode->adjacent.end(); ++it)
            std::cout << " " << *it << " ";

        // it = bufGraphNode->adjacent.begin();
        // for(j=0; j<bufGraphNode->adjacent.size(); ++j)
        // {
        //     std::cout << " " << *it << " ";
        //     it++;
        // }

        std::cout << "\n";
    }

    int source = 1;
    int destination = 8;

    std::cout << "DFS PATH? " << solution.hasPathDFS(source-1, destination-1) << std::endl << "--------------\n";
    std::cout << "BFS PATH? " << solution.hasPathBFS(source-1, destination-1) << std::endl;
  
}
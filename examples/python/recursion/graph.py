class GraphNode(object):
    def __init__(self, node) -> None:
        self.node = node
        self.adjecent = []


class Solution(object):
    def __init__(self):
        self.hashmap = {}


    def add_edge(self, source, destination):
        print("Add edge from {} to {}".format(source, destination))
        source_node : GraphNode = self.hashmap[source]
        destination_node : GraphNode = self.hashmap[destination]
        source_node.adjecent.append(destination_node)
        destination_node.adjecent.append(source_node)

    def _has_path_DFS(self, source_node: GraphNode, destination_node: GraphNode, visited: set):
        if source_node.node in visited: # ???
            return False, visited

        visited.add(source_node.node)
        print(visited, source_node.node, destination_node.node, len(source_node.adjecent), source_node.adjecent[0].node)
        
        if source_node.node == destination_node.node:
            return True, visited

        limit = len(source_node.adjecent)
        idadj = 0
        while (idadj < limit):
            if source_node.adjecent[idadj].node in visited:
                idadj += 1
                continue
            
            result, visited = self._has_path_DFS(source_node.adjecent[idadj], destination_node, visited)
            if result: 
                return True, visited
            idadj += 1
            
        visited.pop()
        return False, visited
        
    def has_path_DFS(self, source, destination):
        src_node = self.hashmap[source]
        dest_node = self.hashmap[destination]
        visited = set()
        return self._has_path_DFS(src_node, dest_node, visited)        


    def _has_path_BFS(self, source_node: GraphNode, destination_node: GraphNode): # TODO
        visited = set()
        next_to_visit = []

        next_to_visit.append(source_node)

        level = 0
        prev_level_node = source_node
        while(len(next_to_visit) > 0):
            node: GraphNode = next_to_visit.pop(0)

            if node.node == destination_node.node:
                visited.add(node.node)
                return True, visited

            if node.node in visited:
                continue

            visited.add(node.node)
            next_to_visit.extend(node.adjecent) 
            if node == prev_level_node:
                prev_level_node = node.adjecent[-1]
                level += 1
                print(f"Level {level} {prev_level_node.node}")
                
        return False, visited


    def has_path_BFS(self, source, destination):
        return self._has_path_BFS(self.hashmap[source], self.hashmap[destination])
    

    def shortest_path_BFS(self, source_node, destination_node): # TODO How to get shortest path, consider weight and if negative path exists
        visited = set()
        next_to_visit = []

        next_to_visit.append(source_node)

        while(len(next_to_visit) > 0):
            node: GraphNode = next_to_visit.pop(0)

            for next_node in node.adjecent:
                if next_node.node not in visited:                    
                    next_to_visit.extend(next_node) 
                    visited.add(next_node.node)
                
        return visited




def test_graph():
    edge = ((1, 2), (1, 4), (1, 3), (1, 6), (2, 3), (3, 6), (4, 6), (5, 6), (6, 8), (7, 8))
    sol = Solution()

    for i in range(1, 9):
        sol.hashmap[i] = GraphNode(i)

    for i in range(10):
        sol.add_edge(edge[i][0], edge[i][1]);

    for node in sol.hashmap.values():
        print(node.node, [_node.node for _node in node.adjecent])

    print("-"*10)

    source = 1;
    destination = 8;
    # 1 2 3 6 8 # TODO DFS Choose this, but it is not the shortest path
    # 1 3 6 8
    print(f"DFS PATH? {sol.has_path_DFS(source, destination)}")
    print(f"BFS PATH? {sol.has_path_BFS(source, destination)}") # TODO BFS has error

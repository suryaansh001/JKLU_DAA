#bellman ford algo 

def bellman_ford(graph, source):
    dist={node: float('inf') for node in graph}
    dist[source]=0

    for _ in range(len(graph) - 1):#v-1 baar chalane k lite coz the number of edge  is len(graph} 
        for node in graph:
            for neighbor in graph[node]:

                if dist[node]+graph[node][neighbor] < dist[neighbor]:
                    if _ == len(graph) - 1:
                        print("Negative cycle detected")
                        return None
                    else:
                        dist[neighbor]=dist[node]+graph[node][neighbor]


    
    return dist

graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'C': 3, 'D': 2},
    'C': {'D': 5},
    'D': {}
}
print(bellman_ford(graph, 'A'))
# print(len(graph))
# for node in graph:
#     print(node)
#     for neighbor in graph[node]:
#         print("the neighbor of",node,"is",neighbor)
#         print("the weight of",neighbor,"is",graph[node][neighbor])
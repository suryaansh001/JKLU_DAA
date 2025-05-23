import heapq

def find(parent, vertex):
    if parent[vertex] != vertex:
        parent[vertex] = find(parent, parent[vertex])
    return parent[vertex]

def union(parent, rank, vertex1, vertex2):
    root1 = find(parent, vertex1)
    root2 = find(parent, vertex2)

    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
        elif rank[root1] < rank[root2]:
            parent[root1] = root2
        else:
            parent[root2] = root1
            rank[root1] += 1

def kruskal_algorithm(graph):
    edges = []
    for vertex in graph:
        for neighbor, weight in graph[vertex].items():
            heapq.heappush(edges, (weight, vertex, neighbor))

    parent = {v: v for v in graph}
    rank = {v: 0 for v in graph}
    mst = []

    while edges:
        weight, vertex1, vertex2 = heapq.heappop(edges)
        if find(parent, vertex1) != find(parent, vertex2):
            union(parent, rank, vertex1, vertex2)
            mst.append((vertex1, vertex2, weight))

    return mst

# Example usage:
graph = {
    'A': {'B': 1, 'C': 3},
    'B': {'A': 1, 'C': 1, 'D': 6},
    'C': {'A': 3, 'B': 1, 'D': 5},
    'D': {'B': 6, 'C': 5}
}

mst = kruskal_algorithm(graph)
print("Minimum Spanning Tree:", mst)
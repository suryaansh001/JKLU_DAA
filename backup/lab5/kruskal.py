import heapq

def prims_algorithm(graph, strt):
    mst = []
    visited = set()
    min_heap = [(0, strt, None)]  

    while min_heap:
        weight, current_vertex, parent = heapq.heappop(min_heap)
        if current_vertex not in visited:
            visited.add(current_vertex)
            if parent is not None:
                mst.append((parent, current_vertex, weight))

            for neighbor, edge_weight in graph[current_vertex].items():
                if neighbor not in visited:
                    heapq.heappush(min_heap, (edge_weight, neighbor, current_vertex))

    return mst

graph=[[]]
mst = prims_algorithm(graph,'A')
print("Min span tree:", mst)
























# import networkx as nx

# def kruskal_mst_networkx(edges, num_nodes):
  

#     graph = nx.Graph()

#     graph.add_nodes_from(range(num_nodes))

#     graph.add_weighted_edges_from(edges)
#     mst = nx.minimum_spanning_tree(graph, algorithm="kruskal")  


#     mst_edges = []
#     for u, v, data in mst.edges(data=True):
#         weight = data['weight']
#         mst_edges.append((u, v, weight))

#     return mst_edges


# num_nodes = 4 
# edges = [
#     (0, 1, 10),
#     (0, 2, 6),
#     (0, 3, 5),
#     (1, 3, 15),
#     (2, 3, 4)
# ]

# mst = kruskal_mst_networkx(edges, num_nodes)
# # #plot the tree
# # G = nx.Graph()
# # G.add_weighted_edges_from(edges)
# # pos = nx.spring_layout(G)
# # nx.draw(G, pos, with_labels=True)
# # labels = nx.get_edge_attributes(G,'weight')
# # nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
# # nx.draw_networkx_edges(G, pos, edgelist=mst, edge_color='r', width=2)
# # nx.show()


# print("Minimum Spanning Tree:")
# for u, v, weight in mst:
#     print(f"Edge: {u} - {v}, Weight: {weight}")

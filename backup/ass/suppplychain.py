import heapq
import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

# Supply Chain Logistics Optimization with Multi-Criteria and Capacity Constraints

def dijkstra(graph, start):
    queue = [(0, start)]
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    
    while queue:
        current_distance, current_node = heapq.heappop(queue)
        
        for neighbor, (weight, capacity) in graph[current_node].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    
    return distances

# Graph with distances and capacity constraints (Weight, Capacity)
graph = {
    'Delhi': {'Mumbai': (10, 50), 'Kolkata': (15, 40)},
    'Mumbai': {'Delhi': (10, 50), 'Chennai': (12, 60), 'Bangalore': (15, 55)},
    'Kolkata': {'Delhi': (15, 40), 'Hyderabad': (10, 45)},
    'Chennai': {'Mumbai': (12, 60), 'Bangalore': (2, 70), 'Pune': (8, 50)},
    'Bangalore': {'Mumbai': (15, 55), 'Chennai': (2, 70), 'Ahmedabad': (5, 65)},
    'Hyderabad': {'Kolkata': (10, 45), 'Ahmedabad': (10, 50)},
    'Pune': {'Chennai': (8, 50), 'Ahmedabad': (6, 55)},
    'Ahmedabad': {'Bangalore': (5, 65), 'Hyderabad': (10, 50), 'Pune': (6, 55)}
}

distances_from_Delhi = dijkstra(graph, 'Delhi')
print("Optimal Supply Chain Routes:", distances_from_Delhi)

def plot_graph(graph):
    G = nx.DiGraph()
    
    for node in graph:
        for neighbor, (weight, _) in graph[node].items():
            G.add_edge(node, neighbor, weight=weight)
    
    pos = nx.spring_layout(G)
    labels = nx.get_edge_attributes(G, 'weight')
    
    plt.figure(figsize=(10, 6))
    nx.draw(G, pos, with_labels=True, node_color='lightblue', edge_color='gray', node_size=3000, font_size=10)
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)
    plt.title("Supply Chain Network")
    plt.show()
    plt.savefig('supply_chain_network.png')

plot_graph(graph)
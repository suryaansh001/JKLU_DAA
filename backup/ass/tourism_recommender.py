import heapq
import networkx as nx
import numpy as np

# Supply Chain Logistics Optimization

def dijkstra(graph, start):
    queue = [(0, start)]
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    
    while queue:
        current_distance, current_node = heapq.heappop(queue)
        
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    
    return distances

graph = {
    'Delhi': {'Mumbai': 10, 'Kolkata': 15},
    'Mumbai': {'Delhi': 10, 'Chennai': 12, 'Bangalore': 15},
    'Kolkata': {'Delhi': 15, 'Hyderabad': 10},
    'Chennai': {'Mumbai': 12, 'Bangalore': 2, 'Pune': 8},
    'Bangalore': {'Mumbai': 15, 'Chennai': 2, 'Ahmedabad': 5},
    'Hyderabad': {'Kolkata': 10, 'Ahmedabad': 10},
    'Pune': {'Chennai': 8, 'Ahmedabad': 6},
    'Ahmedabad': {'Bangalore': 5, 'Hyderabad': 10, 'Pune': 6}
}

distances_from_Delhi = dijkstra(graph, 'Delhi')
print("Optimal Supply Chain Routes:", distances_from_Delhi)

# Tourism Recommendation System

def personalized_recommendation(graph, start):
    scores = {}
    for node in graph:
        if node != start:
            score = sum(graph[node].values()) / len(graph[node])
            scores[node] = score
    
    return sorted(scores.items(), key=lambda x: x[1], reverse=True)

tourism_graph = {
    'Jaipur': {'Delhi': 5, 'Agra': 7},
    'Delhi': {'Jaipur': 5, 'Varanasi': 6},
    'Agra': {'Jaipur': 7, 'Mumbai': 8},
    'Varanasi': {'Delhi': 6, 'Lucknow': 9},
    'Mumbai': {'Agra': 8, 'Goa': 10},
    'Lucknow': {'Varanasi': 9, 'Kolkata': 4},
    'Kolkata': {'Lucknow': 4, 'Bangalore': 5},
    'Bangalore': {'Kolkata': 5, 'Goa': 7},
    'Goa': {'Mumbai': 10, 'Bangalore': 7}
}

recommendations = personalized_recommendation(tourism_graph, 'Jaipur')
print("Top Recommended Tourist Destinations:", recommendations)

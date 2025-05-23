
def Floyd_Warshall(G,V):

    dist= [row[:] for row in graph]

    for i in range(V):
        for j in range(V):
            for k in range(V):
                if dist[i][k]+ dist[k][j]< dist[i][j]:
                    dist[i][j]= dist[i][k] +dist[k][j]
    
    for i in range(V):
        for j in range(V):A
            if dist[i][j]==float('inf'):
                print("INF",end="\t")
            else:
                print(dist[i][j],end= "\t")
        print()

G= [(1,2,3),
    (1,3,8),
    (1,5,-4),
    (2,5,7),
    (2,4,1),
    (3,2,4),
    (4,1,2),
    (4,3,-5),
    (5,4,6)]


INF = float('inf')
graph = [
    [0,    7,   10],
    [INF,  0,    3],
    [4,  INF,   0]
]

V= 3
Floyd_Warshall(graph,V)
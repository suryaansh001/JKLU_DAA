#code for quick find
def quickfind():
    n = int(input("Enter the number of elements: "))
    elements = list(map(int, input("Enter the elements: ").split()))
    parent = list(range(n))
    rank = [0] * n

    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]

    def union(x, y):
        x_root = find(x)
        y_root = find(y)
        if x_root == y_root:
            return
        if rank[x_root] > rank[y_root]:
            parent[y_root] = x_root
        elif rank[x_root] < rank[y_root]:
            parent[x_root] = y_root
        else:    
            parent[y_root] = x_root
            rank[x_root] += 1

    for i in range(n):
        for j in range(i + 1, n):
            if elements[i] == elements[j]:
                union(i, j)

    clusters = []
    for i in range(n):
        clusters.append(find(i))

    return clusters

clusters = quickfind()
print("Clusters:", clusters)
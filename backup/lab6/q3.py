def Guards(arr):
    arr.sort()
    g = []
    i = 0
    while i < len(arr):
        g.append(arr[i] + 1)
        area_covered = (arr[i], arr[i] + 2)
        while i < len(arr) and arr[i] <= area_covered[1]:
            i += 1
    return g

arr = [12,7,4,11]
print(Guards(arr))
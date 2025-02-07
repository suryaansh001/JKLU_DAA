def optimalmerge(files):
    files.sort()
    merge=0
    while len(files)>1:
        merge=files[0] + files[1]
        files[0]=merge
        files.pop(1)
        files.sort()
    return merge
files = list(map(int,input("enter the space separated numbers for list of file content").split()))
min_cost = optimalmerge(files)
print("Minimum cost of merging is:", min_cost, "Comparisons")
 

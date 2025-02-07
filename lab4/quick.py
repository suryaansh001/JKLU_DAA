# import numpy as np 

# arr = [[1,2],[3,4],[1,3],[2,4],[1,4],[2,3],[7,8]]

# arr.sort(key=lambda x:x[0])
# print(arr)

# conn=[]
# for i in range(len(arr)):
#     if not conn:
#         conn.append(set(arr[i]))
#     else:
#         for j in range(len(conn)):
#             if not conn[j].isdisjoint(set(arr[i])):
#                 conn[j] = conn[j].union(set(arr[i]))
#                 break
#         else:
#             conn.append(set(arr[i]))

# print(conn)


import numpy as np 

arr = [[1,2],[3,4],[1,3],[2,4],[1,4],[2,3],[7,8]]

arr.sort(key=lambda x:x[0])
print(arr)

conn=[]
for i in range(len(arr)):
    if not conn:
        conn.append(set(arr[i]))
    else:
        for j in range(len(conn)):
            if not conn[j].isdisjoint(set(arr[i])):
                conn[j] = conn[j].union(set(arr[i]))
                break
        else:
            conn.append(set(arr[i]))

print(conn)

def check_connection(a, b):
    for s in conn:
        if a in s and b in s:
            return "Yes"
    return "No"


a, b = map(int, input("enter two numbers ").split())
print(f"{a} and {b} connected?  {check_connection(a, b)}")
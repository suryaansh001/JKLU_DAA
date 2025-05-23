max_wt=int(input("enter max weight"))
w=w=[3,2,2] 
v =[5,1,1]
n=len(w)
dp=[[0 for i in range(max_wt+1)] for j in range(n+1)]
for i in range(1,1+n):
    for j in range(1,max_wt+1):
        if w[i-1]<=j:
            dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]])
        else:
            dp[i][j]=dp[i-1][j]
print(dp[n][max_wt])


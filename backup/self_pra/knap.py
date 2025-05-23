max_wt=int(input("enter knapsack wt "))
arr=[(4,5),(5,2),(10,9),(5,5)] # [(p,w)]
def knapscak(arr,max_wt):
    n=len(arr)
    dp=[[0 for _ in range(max_wt + 1)] for _ in range(n + 1)]
#dp arr 
    for i in range(1,len(arr)+1):
        pr,wt=arr[i-1]
        for  w in range(1,max_wt):
            if wt <= w :
                dp[i][w]=max(dp[i-1][w],dp[i-1][w-wt] + pr)
            else:
                dp[i][w]=dp[i-1][w]
    print(max(max(dp)))
knapscak(arr,max_wt

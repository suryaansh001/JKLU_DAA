def weighted_interval_scheduling(intervals):
    intervals.sort(key=lambda x: x[1])
    
    def binary_search(intervals,index):
        low,high=0,index - 1
        while low <= high:
            mid=(low + high) // 2
            if intervals[mid][1] <= intervals[index][0]:
                if intervals[mid + 1][1] <= intervals[index][0]:
                    low=mid + 1
                else:
                    return mid
            else:
                high=mid - 1
        return -1

    n=len(intervals)
    dp=[0] * n
    dp[0]=intervals[0][2]
    
    for i in range(1,n):
        incl_profit=intervals[i][2]
        l=binary_search(intervals,i)
        if l != -1:
            incl_profit += dp[l]
        dp[i]=max(dp[i - 1],incl_profit)

    return dp[-1]

intervals=[(1,3,50),(2,5,20),(4,6,70),(6,7,60)]
print(weighted_interval_scheduling(intervals))

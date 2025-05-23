def maxx(arr,low,high):
    if low == high :
        return arr[low]
    midd=(low+high)//2
    maxx1=maxx(arr,low,midd)
    maxx2=maxx(arr,midd+1,high)
    return max(maxx1,maxx2)
def minn(arr,low,high):
    if low == high :
        return arr[low]
    midd=(low+high)//2
    maxx1=maxx(arr,low,midd)
    maxx2=maxx(arr,midd+1,high)
    return max(maxx1,maxx2)

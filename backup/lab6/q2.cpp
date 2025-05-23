#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

pair<int, int> divide_conquer(vector<int> points) {
    int n = points.size();
    
    if (n == 1) {
        return {points[0], points[0]};
    }
    if (n == 2) {
        return {min(points[0], points[1]), max(points[0], points[1])};
    }
    
    int mid = n / 2;
    vector<int> left_side(points.begin(), points.begin() + mid);
    vector<int> right_side(points.begin() + mid, points.end());
    
    pair<int, int> left_result = divide_conquer(left_side);
    pair<int, int> right_result = divide_conquer(right_side);
    
    int overall_min = min(left_result.first, right_result.first);
    int overall_max = max(left_result.second, right_result.second);
    
    return {overall_min, overall_max};
}

int main() {
    int n;
    printf("enter the number of elements in the array\n");
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        printf("enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    pair<int, int> result = divide_conquer(arr);
    int max_distance = result.second - result.first;
    printf("max distance: %d\n", max_distance);
    
  
    return 0;
}
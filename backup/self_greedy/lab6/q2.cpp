#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm> // Include algorithm for max and min functions

using namespace std;

pair<int, int> divide_and_sort(vector<int> &v, int low, int high) {
    if (low == high) {
        return make_pair(v[low], v[low]);
    }
    int mid = (low + high) / 2;
    pair<int, int> left = divide_and_sort(v, low, mid);
    pair<int, int> right = divide_and_sort(v, mid + 1, high);

    int maxx = max(left.first, right.first);
    int minn = min(left.second, right.second);
    return make_pair(maxx, minn);
}

int main() {
    vector<int> v = {10, 5, 99, 6, 3, 77, 8, 2, 1, 0};
    int n = v.size();
    pair<int, int> result = divide_and_sort(v, 0, n - 1);
    cout << result.first << " " << result.second;
    return 0;
}
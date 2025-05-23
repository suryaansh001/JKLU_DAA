#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

float calculateEuclideanDistance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

void divideAndConquer(vector<pair<int, int>> points) {
    int n = points.size();

    if (n <= 3) {
        float minDistance = 1000000;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                float distance = calculateEuclideanDistance(points[i], points[j]);
                if (distance < minDistance)
                    minDistance = distance;
            }
        }
        cout << "Minimum distance in subset: " << minDistance << endl;
        return;
    }

    // Divide points into two halves
    int mid = n / 2;
    vector<pair<int, int>> leftSide(points.begin(), points.begin() + mid);
    vector<pair<int, int>> rightSide(points.begin() + mid, points.end());

    divideAndConquer(leftSide);
    divideAndConquer(rightSide);
}

int main() {
    vector<pair<int, int>> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    
    
    sort(points.begin(), points.end());

    divideAndConquer(points);

    return 0;
}

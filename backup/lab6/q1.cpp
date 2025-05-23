#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;

float calculate_euclidena_distance(vector<pair<int,int> vec)
{

    int min_distance=1000000;
    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            float distance=calculate_euclidena_distance(vec[i],vec[j]);
            if(distance<min_distance)
                min_distance=distance;
        }
    }
    return min_distance;
}

float divide_and_conquer(vector<pair<int,int> vec){
    int n=vec.size();
    //base case if the number of points are less than  or equal to 3
    if(n<=3){
        float min_distance=calculate_euclidena_distance(vec);
        return min_distance;
    }
    else{
        int mid=n/2;
        vector<int,int> left_side;
        vector<int,int> right_side;
        for(int i=0;i<mid;i++){
            left_side.push_back(vec[i]);
        }
        for(int i=mid;i<n;i++){
            right_side.push_back(vec[i]);
        }
        divide_and_conquer(left_side);
        divide_and_conquer(right_side);
    }
}

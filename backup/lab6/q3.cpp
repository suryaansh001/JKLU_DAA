#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;
// Q3. Using Greedy approach, solve the following problem:
// There are items {i1,i2...in} and placed at {d1,d2......dn}. We have to place guards
// to protect the items. Each guard can protect only 1 unit distance to his right
// and 1 unit distance to his left. Find the minimum number of guards required to
// guard the items.
// Input: {i1,i2,i3,i4} placed at {12,7,11,4}.
// Output: the number of guards needed is 3
// Hint: Sort the items based on their positions and start from any one end.
// Remember to place the guard in-between wherever possible, for getting the
// minimum number. Maintain an array for storing the distance/position of the
// guard for easier calculations.

int num_of_guards(vector<int> &sorted_postion){
   int n=sorted_postion.size();
   //{4,7,11,12}
   vector<int> guard;
   for (int i=1;i<n;i++){
       int dist=sorted_postion[i]-sorted_postion[i-1];
       if(dist>1){
           guard.push_back(sorted_postion[i]);

 }
}

int main(){
 vector<int>items={3,4,5,6};
  vector<int> positions={12,7,11,4};
  sort(positions.begin(),positions.end());
}

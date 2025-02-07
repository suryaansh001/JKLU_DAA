#include<iostream>
#include<vector>

using namespace std ;
struct item{
  int weight;
  int value;
};

int knapsackRrrr(int index,int capacity,vector<item> &arr)
{
  int lele = 0;
  lele = knapsackRrrr(index,capacity - arr[index].weight)
  int lele2 = 0;
  lele2 = knapsackRrrr(index+1,capacity,arr);
  return max(lele,lele2);

}
int main(){
  int n;
  cout<<"Enter the number of items: ";
  cin>>n;
  vector<item> arr(n);
  for(int i=0;i<n;i++){
    cout<<"Enter the weight and value for item "<<i+1<<": ";
    cin>>arr[i].weight>>arr[i].value;
  }
  int capacity;
  cout<<"Enter the maximum weight capacity of the knapsack: ";
  cin>>capacity;
  cout<<"The maximum value that can be accomodated in the knapsack is: "<<knapsackRrrr(0,capacity,arr)<<endl;
  return 0;
  
}
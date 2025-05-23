// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namsespace std ;
//
// struct Item{
//   int value;
//   int weight;
//   float ration;
// }Item;
//
// static bool cmp(struct Item a, struct Item b)
// {
//     double r1 = (double)a.profit / (double)a.weight;
//     double r2 = (double)b.profit / (double)b.weight;
//     return r1 > r2;
// }
//
// void knapsack(vector<Item> arr,int W){
//   sort(arr.begin(),arr.end(),cmp); 
//   
//   
//   double curr_wt=0;
//   double curr_value=0
//
//   for(int i=0;i<arr.size();i++){
//     if (curr_wt + arr[i].weight <= W){
//       //normal add
//       curr_wt += arr[i].weight;
//       curr_value += arr[i].value;
//
//
//     }
//     else{
//       curr_value += (arr[i].value/arr[i].weight)*(W-curr_wt);
//     }
//   }
//   return curr_value;
//   
// }
//
//
// int main()
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
    float ratio;
};

static bool cmp(const Item &a, const Item &b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double knapsack(vector<Item> arr, int W) {
    sort(arr.begin(), arr.end(), cmp); 

    double curr_wt = 0;
    double curr_value = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (curr_wt + arr[i].weight <= W) {
            curr_wt += arr[i].weight;
            curr_value += arr[i].value;
        } else {
            curr_value += (arr[i].value / (double)arr[i].weight) * (W - curr_wt);
            break;
        }
    }
    return curr_value;
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    double max_value = knapsack(items, W);
    cout << "Maximum value in Knapsack = " << max_value << endl;

    return 0;
}


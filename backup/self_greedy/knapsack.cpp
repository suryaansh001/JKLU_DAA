#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Structure to represent an item
struct Item {
    int profit;
    int weight;
    float ratio; // Profit-to-weight ratio
};

// Comparison function to sort items by their profit-to-weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // Sort in descending order
}

// Function to calculate the maximum profit
float max_profit(vector<Item>& items, int maxWeight) {
    float totalProfit = 0.0;

    for (const auto& item : items) {
        if (maxWeight == 0) {
            break; // No more weight capacity left
        }

        if (item.weight <= maxWeight) {
            // Take the whole item
            totalProfit += item.profit;
            maxWeight -= item.weight;
        } else {
            // Take the fractional part of the item
            totalProfit += item.ratio * maxWeight;
            maxWeight = 0; // Knapsack is full now
        }
    }
    
    return totalProfit;
}

int main() {
    int size;
    cout << "Enter the number of objects: ";
    cin >> size;

    vector<Item> items(size);

    // Input profits and weights
    for (int i = 0; i < size; i++) {
        cout << "Enter the profit for object " << i + 1 << ": ";
        cin >> items[i].profit;
        cout << "Enter the weight for object " << i + 1 << ": ";
        cin >> items[i].weight;
        
        // Calculate profit-to-weight ratio
        items[i].ratio = static_cast<float>(items[i].profit) / items[i].weight;
    }

    int maxWeight;
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> maxWeight;

    // Sort items based on profit-to-weight ratio
    sort(items.begin(), items.end(), compare);

    // Calculate maximum profit
    float result = max_profit(items, maxWeight);
    
    cout << "Maximum profit: " << result << endl;

    return 0;
}


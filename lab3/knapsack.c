#include<stdio.h>
#include<stdlib.h>


double fractional_knapsack(int *arr, int *weight, int size, int W){
    double value = 0;
    double weight_sum = 0;
    for(int i = 0; i < size; i++){
        if(weight_sum + weight[i] > W){
            value += (W - weight_sum) * arr[i] / weight[i];
            break;
        }
        value += arr[i];
        weight_sum += weight[i];
    }
    return value;
}
int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    int *weight = (int *)malloc(size * sizeof(int));


    for(int i = 0; i < size; i++){
        printf("Enter the value of the element: ");
        scanf("%d", &arr[i]);
        printf("Enter the weight of the element: ");
        scanf("%d", &weight[i]);
    }
    int W;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    double value = fractional_knapsack(arr, weight, size, W);
    printf("The maximum value that can be obtained is: %.2f", value);
    return 0;
    
}
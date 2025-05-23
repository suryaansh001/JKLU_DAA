// huffman code with self-greedy method
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    int freq;
    struct node *left, *right;
};

struct node *newNode(int data, int freq)
{
    struct node *temp = new node;
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}
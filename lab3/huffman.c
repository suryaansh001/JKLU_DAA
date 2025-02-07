#include <stdio.h> 
#include <stdlib.h> 

#define MAX_HT 100 

struct Node { 
    char ch; 
    unsigned freq; 
    struct Node *left, *right; 
}; 

struct Heap { 
    unsigned size; 
    unsigned cap; 
    struct Node** arr; 
}; 

struct Node* createNode(char ch, unsigned freq) { 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->left = temp->right = NULL; 
    temp->ch = ch; 
    temp->freq = freq; 
    return temp; 
} 

struct Heap* createHeap(unsigned cap) { 
    struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap)); 
    h->size = 0; 
    h->cap = cap; 
    h->arr = (struct Node**)malloc(h->cap * sizeof(struct Node*)); 
    return h; 
} 

void swapNodes(struct Node** a, struct Node** b) { 
    struct Node* t = *a; 
    *a = *b; 
    *b = t; 
} 

void heapify(struct Heap* h, int idx) { 
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 

    if (left < h->size && h->arr[left]->freq < h->arr[smallest]->freq) 
        smallest = left; 

    if (right < h->size && h->arr[right]->freq < h->arr[smallest]->freq) 
        smallest = right; 

    if (smallest != idx) { 
        swapNodes(&h->arr[smallest], &h->arr[idx]); 
        heapify(h, smallest); 
    } 
} 

int isSingleNode(struct Heap* h) { 
    return (h->size == 1); 
} 

struct Node* extractMin(struct Heap* h) { 
    struct Node* temp = h->arr[0]; 
    h->arr[0] = h->arr[h->size - 1]; 
    --h->size; 
    heapify(h, 0); 
    return temp; 
} 

void insertHeap(struct Heap* h, struct Node* node) { 
    ++h->size; 
    int i = h->size - 1; 

    while (i && node->freq < h->arr[(i - 1) / 2]->freq) { 
        h->arr[i] = h->arr[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 

    h->arr[i] = node; 
} 

void buildHeap(struct Heap* h) { 
    int n = h->size - 1; 
    for (int i = (n - 1) / 2; i >= 0; --i)
        heapify(h, i);  
} 

void printArray(int arr[], int n) {  
    for (int i = 0; i < n; ++i)  
        printf("%d", arr[i]);  
    printf("\n");  
}  

int isLeaf(struct Node* root) {  
    return !(root->left) && !(root->right);  
}  

struct Heap* createAndBuildHeap(char data[], int freq[], int size) {  
    struct Heap* h = createHeap(size);  
    for (int i = 0; i < size; ++i)  
        h->arr[i] = createNode(data[i], freq[i]);  
        
   h->size = size;  
   buildHeap(h);  
   
   return h;  
}  

struct Node* buildHuffmanTree(char data[], int freq[], int size) {  
   struct Node *left, *right, *top;  
   struct Heap* h = createAndBuildHeap(data, freq, size);  

   while (!isSingleNode(h)) {  
       left = extractMin(h);  
       right = extractMin(h);  

       top = createNode('$', left->freq + right->freq);  
       top->left = left;  
       top->right = right;  

       insertHeap(h, top);  
   }  

   return extractMin(h);  
}  

void printCodes(struct Node* root, int arr[], int top) {  
   if (root->left) {  
       arr[top] = 0;  
       printCodes(root->left, arr, top + 1);  
   }  

   if (root->right) {  
       arr[top] = 1;  
       printCodes(root->right, arr, top + 1);  
   }  

   if (isLeaf(root)) {  
       printf("%c: ", root->ch);  
       printArray(arr, top);  
   }  
}  

void HuffmanCodes(char data[], int freq[], int size) {   
   struct Node* root = buildHuffmanTree(data, freq, size);   
   int arr[MAX_HT], top = 0;   
   printCodes(root, arr, top);   
}  

int main() {   
   char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };   
   int freq[] = { 5, 9, 12, 13, 16, 45 };   
   int size = sizeof(arr) / sizeof(arr[0]);   
   HuffmanCodes(arr, freq, size);   
   return 0;
}


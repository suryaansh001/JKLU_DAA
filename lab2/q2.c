#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int hash_function(int x, int size) {
    return (x + 2) % size;
}

void insert(Node **hash_table, int size, int element) {
    int index = hash_function(element, size);
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

void display(Node **hash_table, int size) {
    for (int i = 0; i < size; i++) {
        printf("Index %d: ", i);
        Node *current = hash_table[i];
        if (current == NULL) {
            printf("EMPTY\n");
        } else {
            while (current != NULL) {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    int size, num_elements, element;

    printf("Enter the size of the hash table: ");
    scanf("%d", &size);

    Node **hash_table = (Node **)malloc(size * sizeof(Node *));
    for (int i = 0; i < size; i++) {
        hash_table[i] = NULL;
    }

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insert(hash_table, size, element);
    }

    printf("Hash table:\n");
    display(hash_table, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        Node *current = hash_table[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table);

    return 0;
}
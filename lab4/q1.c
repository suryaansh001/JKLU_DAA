#include <stdio.h>

typedef struct {
    int start;
    int end;
} inter;

int main() {
    inter inters[] = {{1, 3}, {2, 5}, {7, 12}, {9, 13}, {14, 16}, {6, 18}};
    int n = sizeof(inters) / sizeof(inters[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (inters[j].end > inters[j + 1].end) {
                inter temp = inters[j];
                inters[j] = inters[j + 1];
                inters[j + 1] = temp;
            }
        }
    }

    int count = 0;
    int end = 0;
    inter selected_inters[n];
    int selected_count = 0;

    for (int i = 0; i < n; i++) {
        if (end <= inters[i].start) {
            selected_inters[selected_count++] = inters[i];
            count++;
            end = inters[i].end;
            printf("selected %d \n", inters[i].end);
        } else {
            printf("conflict at %d\n", inters[i].end);
        }
    }

    printf("selected inters ");
    for (int i = 0; i < selected_count; i++) {
        printf("(%d, %d) ", selected_inters[i].start, selected_inters[i].end);
    }
    printf("\n");

    return 0;
}
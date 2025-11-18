#include <stdio.h>
#define SIZE 7   
int hash(int key) {
    return key % SIZE;
}
int main() {
    int table[SIZE];
    int n, key;
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }
    printf("Enter number of keys to insert: ");
    scanf("%d", &n);
    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        int index = hash(key);
        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }
        table[index] = key;
    }
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1)
            printf("Slot %d: %d\n", i, table[i]);
        else
            printf("Slot %d: EMPTY\n", i);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

int arr[MAX_SIZE];
int size = 0;

void display() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Current Array: ");
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void insertAtBeginning(int val) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return;
    }
    for (int i = size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = val;
    size++;
    printf("Inserted %d at beginning\n", val);
}

void insertAtPos(int pos, int val) {
    if (pos < 0 || pos > size || size == MAX_SIZE) {
        printf("Invalid position or array is full\n");
        return;
    }
    for (int i = size - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    size++;
    printf("Inserted %d at pos %d\n", val, pos);
}

void deleteFromBeginning() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    int del = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Deleted %d from beginning\n", del);
}

void deleteAtEnd() {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    int del = arr[size - 1];
    size--;
    printf("Deleted %d from end\n", del);
}

void deleteFromPos(int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position\n");
        return;
    }
    int del = arr[pos];
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Deleted %d at pos %d\n", del, pos);
}

void readAtPos(int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position\n");
        return;
    }
    printf("Element at position %d is %d\n", pos, arr[pos]);
}

void updateAtPos(int pos, int val) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position\n");
        return;
    }
    arr[pos] = val;
    printf("Updated position %d with value %d\n", pos, val);
}

void search(int val) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            printf("Value %d found at position %d\n", val, i);
            found = 1;
        }
    }
    if (!found)
        printf("Value %d not found in array\n", val);
}

void length() {
    printf("Current size of array: %d\n", size);
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\n -------- List Menu -----------\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at specified pos\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at specified pos\n");
        printf("7. Read at position\n");
        printf("8. Update at position\n");
        printf("9. Search for a value\n");
        printf("10. Display\n");
        printf("11. Length\n");
        printf("12. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice:\t");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &val);
                if (size == MAX_SIZE) {
                    printf("Array is full\n");
                    break;
                }
                arr[size++] = val;
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 3:
                printf("Enter the position (0 to %d): ", size);
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &val);
                insertAtPos(pos, val);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteFromPos(pos);
                break;
            case 7:
                printf("Enter the position: ");
                scanf("%d", &pos);
                readAtPos(pos);
                break;
            case 8:
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the new value: ");
                scanf("%d", &val);
                updateAtPos(pos, val);
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 10:
                display();
                break;
            case 11:
                length();
                break;
            case 12:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

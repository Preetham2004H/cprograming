#include <stdio.h>
#include <stdlib.h>
#define max 5

int q[max], r = -1, f = -1;
int i;

void insertcq() {
    if (f == (r + 1) % max)
        printf("Circular queue is overflow");
    else {
        if (f == -1) {
            f = 0;
        }
        r = (r + 1) % max;
        printf("Enter element to be inserted: ");
        scanf("%d", &q[r]);
    }
}

void deletecq() {
    if (f == -1) {
        printf("\nQueue is empty");
    } else {
        printf("\nElement deleted is %d", q[f]);
        if (f == r) {
            f = r = -1;
        } else {
            f = (f + 1) % max;
        }
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty \n");
    } else {
        printf("Queue elements: \n");
        int count = (r - f + max) % max + 1;
        for (i = 0; i < count; i++) {
            printf("%d\t", q[(f + i) % max]);
        }
        printf("\nFront is at: %d \nRear is at: %d", q[f], q[r]);
    }
}

int main() {
    printf("Circular Queue Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Quit\n");

    int ch;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insertcq();
                break;
            case 2:
                deletecq();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice...!");
        }
    } while (1);

    return 0;
}

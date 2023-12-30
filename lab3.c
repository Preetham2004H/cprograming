#include <stdio.h>
#define siz 5

int top, status;

void push(int stack[], int item) {
    if (top == siz - 1) {
        status = 0;  // Set status to 0 for overflow
    } else {
        status = 1;
        top++;
        stack[top] = item;
    }
}

int pop(int stack[]) {
    int ret;
    if (top == -1) {
        ret = 0;
        status = 0;  // Set status to 0 for underflow
    } else {
        ret = stack[top];
        top--;
    }
    return ret;
}

void display(int stack[]) {
    int i;
    printf("\nStack is:\n");
    if (top == -1) {
        printf("Empty\n");
    } else {
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int stack[siz], quit, item, ch;
    quit = 0;
    top = -1;

    do {
        printf("Your choice:\n");
        printf("1. Push\n2. Pop\n3. Quit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to push:\n");
                scanf("%d", &item);
                push(stack, item);
                if (status == 0) {
                    printf("Stack is overflow\n");
                }
                break;
            case 2:
                item = pop(stack);
                if (status) {
                    printf("The popped element is %d\n", item);
                    display(stack);
                }
                else {
                    printf("Stack is underflow\n");
                }
                break;
            case 3:
                quit = 1;
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (!quit);

    return 0;
}

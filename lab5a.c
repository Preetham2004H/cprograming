#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

float stack[50], n1, n2, res, value, finalres;
int i, j, top = 0;

void push(float);
float pop(void);

int main()
{
    char p[50];
    printf("Enter postfix expression: \n");
    fgets(p, 50, stdin);
    j = strlen(p);
    printf("Length or number of characters in postfix expression: %d\n", j);
    for (i = 0; i < j; i++)
    {
        if ((p[i] >= '0') && (p[i] <= '9'))
        {
            push(p[i] - '0');
        }
        else if (((p[i] >= 'a') && (p[i] <= 'z')) || ((p[i] >= 'A') && (p[i] <= 'Z')))
        {
            printf("Enter value of %c: ", p[i]);
            scanf("%f", &value);
            push(value);
        }
        else if (p[i] == ' ' || p[i] == '\n') // Skip spaces and newlines
        {
            continue;
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (p[i])
            {
            case '^':
                res = pow(n2, n1);
                push(res);
                break;
            case '*':
                res = (n2 * n1);
                push(res);
                break;
            case '/':
                res = (n2 / n1);
                push(res);
                break;
            case '+':
                res = (n2 + n1);
                push(res);
                break;
            case '-':
                res = (n2 - n1);
                push(res);
                break;
            default:
                printf("Invalid postfix expression\n");
                return 1;
            }
        }
    }
    finalres = pop();
    printf("Value of expression = %f\n", finalres);
    return 0;
}

void push(float item)
{
    stack[++top] = item;
}

float pop()
{
    if (top == 0)
    {
        printf("Invalid expression\n");
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}

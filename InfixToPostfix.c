#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR_SIZE 100

typedef struct stack
{
    int top;
    int size;
    int* array;
} stack;

// function to create a stack of given capacity
stack* createStack(int size)
{
    stack* s = malloc(sizeof(stack));
    s->size = size;
    s->top = -1;
    s->array = malloc(s->size * sizeof(int));
    return s;
}

// stack is full when top is equal to the last index
int isFull(stack* s)
{
    return s->top == s->size - 1;
}

// stack is empty when top is equal to -1
int isEmpty(stack* s)
{
    return s->top == -1;
}

// function to add an item to stack
// it increases top by 1
void push(stack* s, int item)
{
    if (isFull(s))
    {
        return;
    }
    s->array[++s->top] = item;
}

// function to remove an item from stack
// it decreases top by 1
int pop(stack* s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->array[s->top--];
}

// function to peek at the top of the stack
int peek(stack* s)
{
    if (isEmpty(s))
    {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return s->array[s->top];
}

// function to get the precedence of a given operator
// higher return value means higher precedence
int getPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

// function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix)
{
    int i = 0, j = 0;
    stack* s = createStack(MAX_EXPR_SIZE);

    while (infix[i] != '\0')
    {
        // if current character is an operand, add it to the postfix expression
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        // if current character is an opening parenthesis, push it to the stack
        else if (infix[i] == '(')
            push(s, infix[i]);
        // if current character is a closing parenthesis
        else if (infix[i] == ')')
        {
            // keep popping and adding to the postfix expression until an opening parenthesis is encountered
            while (!isEmpty(s) && peek(s) != '(')
                postfix[j++] = (char)pop(s);
            // pop the opening parenthesis from the stack, but do not add it to the postfix expression
            if (!isEmpty(s) && peek(s) == '(')
                pop(s);
        }
        // if current character is an operator
        else
        {
            // while the stack is not empty and the precedence of the current operator is less than or equal to the precedence of the operator at the top of the stack
            while (!isEmpty(s) && getPrecedence(infix[i]) <= getPrecedence(peek(s)))
                postfix[j++] = (char)pop(s);
            // push the current operator to the stack
            push(s, infix[i]);
        }
        i++;
    }

    // pop all remaining operators from the stack and add them to the postfix expression
    while (!isEmpty(s))
        postfix[j++] = (char)pop(s);

    postfix[j] = '\0';
}

// function to evaluate a postfix expression
int evaluatePostfix(char* postfix)
{
    stack* s = createStack(MAX_EXPR_SIZE);

    int i = 0;
    while (postfix[i] != '\0')
    {
        // if current character is an operand, push it to the stack
        if (isdigit(postfix[i]))
            push(s, postfix[i] - '0');
        // if current character is an operator
        else
        {
            // pop two operands from the stack
            int op2 = pop(s);
            int op1 = pop(s);
            // perform the operation and push the result back to the stack
            if (postfix[i] == '+')
                push(s, op1 + op2);
            else if (postfix[i] == '-')
                push(s, op1 - op2);
            else if (postfix[i] == '*')
                push(s, op1 * op2);
            else if (postfix[i] == '/')
                push(s, op1 / op2);
            else if (postfix[i] == '^')
                push(s, (int)pow(op1, op2));
        }
        i++;
    }

    // the result is the top element of the stack
    return peek(s);
}

int main()
{
    char infix[MAX_EXPR_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    char postfix[MAX_EXPR_SIZE];
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

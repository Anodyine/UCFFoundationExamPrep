#include "../../../../DataStructures/Stacks/ArrayStack.h"
#include <string.h>
#include <stdio.h>

typedef struct node_s
{
    int data;
    struct node_s *next;
} node_t;

typedef struct
{
    node_t *top;
} stack_t;

// Initializes a stack to be empty.
void init(stack_t *s);

// Pushes data onto the stack pointed to by s.
void push(stack_t *s, int data);

// Removes and returns the integer at the top of the stack pointed to by s.
int pop(stack_t *s);

// Returns 1 if and only if the stack pointed to by s is empty. Returns 0
// otherwise.
int empty(stack_t *s);

int computeScore (char *moves) {
    ArrayStack* stack = malloc(sizeof(ArrayStack));
    ArrayStack_init(stack);

    int i = 0;
    while (moves[i] != '\0') {
        if ('0' <= moves[i] && moves[i] <= '9') {
            ArrayStack_Push(stack, moves[i] - 48);
        }

        if (moves[i] == '+') {
            int temp1 = ArrayStack_Pop(stack);
            int temp2 = ArrayStack_Pop(stack);
            int newScore = temp1 + temp2;
            ArrayStack_Push(stack, temp2);
            ArrayStack_Push(stack, temp1);
            ArrayStack_Push(stack, newScore);
        }

        i++;
    }

    int result = 0;
    while (!ArrayStack_IsEmpty(stack)) {
        result += ArrayStack_Pop(stack);
    }

    return result;
}

int main (int) {
    int result = computeScore("25+3++1");
    printf("%d", result);
}


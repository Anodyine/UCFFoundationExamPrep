#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../../DataStructures/Stacks/LinkedStack.h"

bool isOperand (char a);
bool isOperator (char a);
int getPriorityOfOperator (char a);
char* convertInfixToPostfix (char* infixExpression);

int main (int) {
    char result[100];

    strcpy(result, convertInfixToPostfix ("1^7+2^2*3^2/7"));

    printf("The result is: %s\n", result);
}

char* convertInfixToPostfix (char* infixExpression) {
    int postFixExpressionSize = 0;
    char* postFixExpression = malloc(sizeof(char) * (strlen(infixExpression) + 1));

    // initializing postfix expression to all \0
    for (int i = 0; i < (strlen(infixExpression) + 1); i++) {
        *(postFixExpression + i) = '\0';
    }

    LinkedStack* stack = new_LinkedStack("char", sizeof(char));

    for (int i = 0; i < strlen(infixExpression); i++) {
        char currentCharacter = *(infixExpression + i);
        // if char is an operand append it to the postfix expression
        if (isOperand(currentCharacter)) {
            *(postFixExpression + strlen(postFixExpression)) = currentCharacter;
        }

        // if char is an operator
        if (isOperator(*(infixExpression + i))) {
            if (LinkedStack_IsEmpty(stack)) {
                LinkedStack_Push(stack, (infixExpression + i));
            } else {
                //pop operators until the current operator is higher than the priority of the operator at the top of the stack
                char operatorToCompare = *(char*)LinkedStack_Peek(stack);
                while (getPriorityOfOperator (currentCharacter) <= getPriorityOfOperator (operatorToCompare) ) {
                    LinkedStack_RemoveTop(stack);
                    //popped operators are appended to the post fix expression
                    *(postFixExpression + strlen(postFixExpression)) = operatorToCompare;
                    if (LinkedStack_IsEmpty(stack)) {
                        break;
                    }
                    operatorToCompare = *(char*)LinkedStack_Peek(stack);
                }

                //then push the current character to the stack
                LinkedStack_Push(stack, (infixExpression + i));
            }
        }
    }

    while (!LinkedStack_IsEmpty(stack)) {
        *(postFixExpression + strlen(postFixExpression)) = *(char*)LinkedStack_Peek(stack);
        LinkedStack_RemoveTop(stack);
    }

    return postFixExpression;
}

bool isOperand (char a) {
    return a >= '0' && a <= '9';
}

bool isOperator (char a) {
    return a == '+' 
        || a == '-'
        || a == '/'
        || a == '*'
        || a == '^';
}

int getPriorityOfOperator (char a) {
    switch (a) {
        case '^':
            return 3;
            break;
        case '*':
        case '/':
        case '%':
            return 2;
            break;
        case '+':
        case '-':
            return 1;
            break;
        default:
            printf("Error: character passed to getPriorityOfOperator was not a known operator.");
            break;
    }
    return -1;
}
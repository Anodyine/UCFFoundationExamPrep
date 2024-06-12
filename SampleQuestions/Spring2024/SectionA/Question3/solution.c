#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../../DataStructures/Stacks/LinkedStack.h"

bool isOperand (char a);
bool isOperator (char a);
bool isOpeningParenthesis (char a);
bool isClosingParenthesis (char a);
int getPriorityOfOperator (char a);
char* convertInfixToPostfix (char* infixExpression);

int main (int) {
    char* result;

    result = convertInfixToPostfix ("3 + 1-7*(4/2+5)*8-7/(5-3+(5+7)/(3*2))");

    printf("The result is: %s\n", result);

    free(result);
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
                while (!isOpeningParenthesis(operatorToCompare) 
                    && getPriorityOfOperator (currentCharacter) <= getPriorityOfOperator (operatorToCompare))
                {
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

        if (isOpeningParenthesis(*(infixExpression + i))) {
            LinkedStack_Push(stack, (infixExpression + i));
        }

        if (isClosingParenthesis(*(infixExpression + i))) {
            //pop operators until we encounter an opening parenthesis
            char operatorToCompare = *(char*)LinkedStack_Peek(stack);
            while (!isOpeningParenthesis(operatorToCompare)) {
                LinkedStack_RemoveTop(stack);
                if (LinkedStack_IsEmpty(stack)) {
                    printf("Error: closing parenthesis was found without matching opening parenthesis");
                    break;
                }
                //popped operators are appended to the post fix expression
                *(postFixExpression + strlen(postFixExpression)) = operatorToCompare;
                operatorToCompare = *(char*)LinkedStack_Peek(stack);
            }

            //then remove the opening parenthesis from the stack
            LinkedStack_RemoveTop(stack);
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

bool isOpeningParenthesis (char a) {
    return a == '(';
}

bool isClosingParenthesis (char a) {
    return a == ')';
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
            printf("Error: character '%c' was passed to getPriorityOfOperator is not a known operator.", a);
            break;
    }
    return -1;
}
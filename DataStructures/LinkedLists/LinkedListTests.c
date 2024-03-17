#include "LinkedList.h"
#include "../DynamicMemoryManagement/Point.c"

int testLinkedListWithInts();
int testLinkedListWithPointStructs();

int main (int) {
    if (testLinkedListWithInts() == -1) {
        return -1;
    }

    if (testLinkedListWithPointStructs() == -1) {
        return -1;
    }

    printf("LinkedList Tests Passed.\n");
    return 0;
}

int testLinkedListWithInts() {
    char* currentFunctionName = malloc(80);    
    char* currentAction = malloc(200);    
    char* errorDescription = malloc(400);

    printf("Testing Linked List with ints\n");
    currentFunctionName = "new_LinkedList";
    printf("Testing %s\n", currentFunctionName);

    currentAction = "creating a list";
    LinkedList* myList = new_LinkedList("int", sizeof(int));
    if (myList->head != NULL) {
        errorDescription = "myList->head did not point to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->tail != NULL) {
        errorDescription = "myList->tail did not point to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->length != 0) {
        errorDescription = "myList->length was not 0.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (strcmp(myList->typeName, "int") != 0) {
        errorDescription = "myList->typeName was not saved.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->typeSize != sizeof(int)) {
        errorDescription = "myList->typeSize was not saved.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentFunctionName = "LinkedList_Add";
    printf("Testing %s\n", currentFunctionName);
    currentAction = "adding a the first int item";
    int* temp = malloc(sizeof(int));
    *temp = 9;
    LinkedList_Add(myList, temp);
    if (myList->head == NULL) {
        errorDescription = "myList->head points to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->tail == NULL) {
        errorDescription = "myList->tail points to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (*(int*)myList->head->data != 9) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentAction = "adding a second int item";
    Node* previousHead = myList->head;
    *temp = 14;
    LinkedList_Add(myList, temp);
    if (myList->head == previousHead) {
        errorDescription = "myList->head was not updated.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (*(int*)myList->head->data != 14) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentFunctionName = "LinkedList_GetByIndex";
    printf("Testing %s\n", currentFunctionName);
    int firstElement = *(int*)LinkedList_GetByIndex(myList, 0);
    if (firstElement != 9) {
        currentAction = "getting the item at index 0";
        errorDescription = "Expected: 9";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, firstElement);
        return -1;
    }
    int secondElement = *(int*)LinkedList_GetByIndex(myList, 1);
    if (secondElement != 14) {
        currentAction = "getting the item at index 1";
        errorDescription = "Expected: 14";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, secondElement);
        return -1;
    }

    currentFunctionName = "LinkedList_GetFirst";
    printf("Testing %s\n", currentFunctionName);
    int firstElement2 = *(int*)LinkedList_GetFirst(myList);
    if (firstElement2 != 9) {
        currentAction = "getting the first item";
        errorDescription = "Expected: 9";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, firstElement2);
        return -1;
    }

    currentFunctionName = "LinkedList_GetLast";
    printf("Testing %s\n", currentFunctionName);
    int lastElement = *(int*)LinkedList_GetLast(myList);
    if (lastElement != 14) {
        currentAction = "getting the last item";
        errorDescription = "Expected: 14";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, lastElement);
        return -1;
    }

    *temp = 26;
    LinkedList_Add(myList, temp);
    *temp = 38;
    LinkedList_Add(myList, temp);
    *temp = 48;
    LinkedList_Add(myList, temp);

    currentFunctionName = "LinkedList_RemoveByIndex";
    printf("Testing %s\n", currentFunctionName);
    LinkedList_RemoveByIndex(myList, 3);
    currentAction = "removing item at index in the middle of the array";
    if (*(int*)myList->head->next->data != 26) {
        errorDescription = "next pointer was not updated in node before removed node.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (*(int*)myList->head->next->next->previous->data != 26) {
        errorDescription = "previous pointer was not updated in node after removed node.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    LinkedList_RemoveByIndex(myList, myList->length - 1);
    if (*(int*)myList->head->data != 26) {
        currentAction = "removing item at index equal to length - 1";
        errorDescription = "head was not updated. Expected head to point to value of 26";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, *(int*)myList->head->data);
        return -1;
    }
    LinkedList_RemoveByIndex(myList, 0);
    if (*(int*)myList->tail->data != 14) {
        currentAction = "removing item at index 0";
        errorDescription = "tail was not updated. Expected: 14";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, lastElement);
        return -1;
    }

    currentFunctionName = "LinkedList_Destroy";
    printf("Testing %s\n", currentFunctionName);
    LinkedList_Destroy(myList);

    free(temp);

    return 0;
}


int testLinkedListWithPointStructs() {
    char* currentFunctionName = malloc(80);    
    char* currentAction = malloc(200);    
    char* errorDescription = malloc(400);

    printf("Testing Linked List with structs\n");
    currentFunctionName = "new_LinkedList";
    printf("Testing %s\n", currentFunctionName);

    currentAction = "creating a list";
    LinkedList* myList = new_LinkedList("Point", sizeof(Point));
    if (strcmp(myList->typeName, "Point") != 0) {
        errorDescription = "myList->typeName was not saved.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->typeSize != sizeof(Point)) {
        errorDescription = "myList->typeSize was not saved.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentFunctionName = "LinkedList_Add";
    printf("Testing %s\n", currentFunctionName);
    currentAction = "adding a the first Point item";
    Point* temp = malloc(sizeof(Point));
    temp->x = 10;
    temp->y = 15;
    strcpy(temp->label, "point1");

    LinkedList_Add(myList, temp);

    if (((Point*)myList->head->data)->x != 10) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (((Point*)myList->head->data)->y != 15) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (strcmp(((Point*)myList->head->data)->label, "point1") != 0) {
        errorDescription = "the value of the label property was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentAction = "adding a second Point item";
    temp->x = 20;
    temp->y = 25;
    strcpy(temp->label, "point2");
    LinkedList_Add(myList, temp);
    if (((Point*)myList->head->data)->y != 25) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentFunctionName = "LinkedList_GetByIndex";
    printf("Testing %s\n", currentFunctionName);
    Point* firstElement = (Point*)LinkedList_GetByIndex(myList, 0);
    if (firstElement->x != 10) {
        currentAction = "getting the item at index 0";
        errorDescription = "Expected: 10";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, firstElement->x);
        return -1;
    }
    Point* secondElement = (Point*)LinkedList_GetByIndex(myList, 1);
    if (strcmp(secondElement->label, "point2") != 0) {
        currentAction = "getting the item at index 1";
        errorDescription = "Expected: point2";
        printf("%s test failed: After %s, %s, Actual: %s\n", currentFunctionName, currentAction, errorDescription, secondElement->label);
        return -1;
    }

    currentFunctionName = "LinkedList_GetFirst";
    printf("Testing %s\n", currentFunctionName);
    Point* firstElement2 = (Point*)LinkedList_GetFirst(myList);
    if (firstElement2->y != 15) {
        currentAction = "getting the first item";
        errorDescription = "Expected: 15";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, firstElement2->y);
        return -1;
    }

    currentFunctionName = "LinkedList_GetLast";
    printf("Testing %s\n", currentFunctionName);
    Point* lastElement = (Point*)LinkedList_GetLast(myList);
    if (lastElement->y != 25) {
        currentAction = "getting the last item";
        errorDescription = "Expected: 24";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, lastElement->y);
        return -1;
    }

    temp->x = 30;
    temp->y = 35;
    strcpy(temp->label, "point3");
    LinkedList_Add(myList, temp);
    temp->x = 40;
    temp->y = 45;
    strcpy(temp->label, "point4");
    LinkedList_Add(myList, temp);
    temp->x = 50;
    temp->y = 55;
    strcpy(temp->label, "point5");
    LinkedList_Add(myList, temp);

    currentFunctionName = "LinkedList_RemoveByIndex";
    printf("Testing %s\n", currentFunctionName);
    LinkedList_RemoveByIndex(myList, 3);
    currentAction = "removing item at index in the middle of the array";
    if (((Point*)myList->head->next->data)->x != 30) {
        errorDescription = "next pointer was not updated in node before removed node.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (((Point*)myList->head->next->next->previous->data)->y != 35) {
        errorDescription = "previous pointer was not updated in node after removed node.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    LinkedList_RemoveByIndex(myList, myList->length - 1);
    if (((Point*)myList->head->data)->x != 30) {
        currentAction = "removing item at index equal to length - 1";
        errorDescription = "head was not updated. Expected head to point to value of (30, 35, point3)";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, *(int*)myList->head->data);
        return -1;
    }
    LinkedList_RemoveByIndex(myList, 0);
    if (((Point*)myList->tail->data)->y != 25) {
        currentAction = "removing item at index 0";
        errorDescription = "tail was not updated. Expected: 14";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, lastElement);
        return -1;
    }

    currentFunctionName = "LinkedList_Destroy";
    printf("Testing %s\n", currentFunctionName);
    LinkedList_Destroy(myList);

    free(temp);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR 200

typedef struct Node {
    char data[MAX_EXPR];
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = newNode->right = NULL;
    return newNode;
}

void skipSpaces(const char** expr) {
    while (isspace(**expr)) {
        (*expr)++;
    }
}

Node* parseExpressionRec(const char** expr) {
    skipSpaces(expr);

    if (**expr == '(') {
        (*expr)++;

        Node* left = parseExpressionRec(expr);
        skipSpaces(expr);

        char op = **expr;
        (*expr)++;

        Node* right = parseExpressionRec(expr);
        skipSpaces(expr);

        if (**expr == ')') {
            (*expr)++;
        }else {
            printf("Not closed bracket.\n");
            return NULL;
        }

        char operatorStr[2] = {op, '\0'};
        Node* root = createNode(operatorStr);
        root->left = left;
        root->right = right;

        return root;
    }else if(isdigit(**expr)) {
        char token[MAX_EXPR];
        int i = 0;

        while(isdigit(**expr)) {
            token[i++] = **expr;
            (*expr)++;
        }
        token[i] = '\0';

        return createNode(token);
    }else {
        printf("Invalid character: '%c'\n", **expr);
        return NULL;
    }
}

Node* parseExpression(const char* expression) {
    const char* expr = expression;
    return parseExpressionRec(&expr);
}

// 
void printPrefix(Node* root) {
    if (root) {
        printf("%s ", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

void printPostfix(Node* root) {
    if (root) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%s ", root->data);
    }
}

// ypologismos parastasis
int evaluate(Node* root) {
    if (!root) return 0;

    if (!root->left && !root->right) {
        return atoi(root->data);
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    if (strcmp(root->data, "+") == 0) return leftValue + rightValue;
    if (strcmp(root->data, "-") == 0) return leftValue - rightValue;
    if (strcmp(root->data, "*") == 0) return leftValue * rightValue;
    if (strcmp(root->data, "/") == 0) return leftValue / rightValue;
    if (strcmp(root->data, "%") == 0) return leftValue % rightValue;

    return 0;
}

void printTree(Node* root, int level) {
    if (root == NULL) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("(%s)\n", root->data);
    printTree(root->left, level + 1);
}
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int validateExpression(const char* expr) {
    int parenthBalance = 0;
    int expectingOperand = 1; // perimenoume arithmo h parenthesi

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (isspace(c)) {
            continue;
        }
        if (isdigit(c)) {
            expectingOperand = 0;
            continue;
        }
        if (c == '(') {
            parenthBalance++;
            expectingOperand = 1;
        } else if(c == ')') {
            parenthBalance--;
            if (parenthBalance < 0) {
                printf("Too many closed brackets\n");
                return 0;
            }
            expectingOperand = 0; 
        } else if(strchr("+-*/%", c)) {
            if(expectingOperand) {
                printf("Operant with no previous number or parenthesis \n");
                return 0;
            }
            expectingOperand = 1;
        } else {
            printf("Invalid character '%c'.\n", c);
            return 0;
        }
    }
    if(parenthBalance != 0) {
        printf("Unbalanced parenthesis.\n");
        return 0;
    }
    if(expectingOperand) {
        printf("Expression ends with operand or empty.\n");
        return 0;
    }
    return 1;
}

int getValidChoice() {
    int choice;
    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Wrong input! Insert a number.\n");
            continue;
        }
        if(choice >= 0 && choice <= 5) {
            return choice;
        } else {
            printf("Invalid choice. Insert a number between 0 to 5.\n");
        }
    }
}

int main() {
    char expression[MAX_EXPR];
    Node* root = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter expression\n");
        printf("2. Calculate expression\n");
        printf("3. Display prefix form\n");
        printf("4. Display postfix form\n");
        printf("5. Print binary tree\n");
        printf("0. Exit\n");
        choice = getValidChoice();
        switch (choice) {
            case 1:
                printf("Enter expression (infix form): ");
                getchar();
                fgets(expression, MAX_EXPR, stdin);
                expression[strcspn(expression, "\n")] = '\0';
                if (validateExpression(expression)) {
                    freeTree(root);  
                    root = parseExpression(expression);
                } else {
                    printf("Please enter a valid expression.\n");
                }
                break;
            case 2:
                if (root) {
                    printf("Result: %d\n", evaluate(root));
                } else {
                    printf("No tree detected.\n");
                }
                break;
            case 3:
                if (root) {
                    printf("Prefix form: ");
                    printPrefix(root);
                    printf("\n");
                } else {
                    printf("No tree detected.\n");
                }
                break;
            case 4:
                if (root) {
                    printf("Postfix form: ");
                    printPostfix(root);
                    printf("\n");
                } else {
                    printf("No tree detected.\n");
                }
                break;
            case 5:
                if(root) {
                    printTree(root,0);
                }else {
                    printf("No tree detected.\n");
                }
                break;
            case 0:
                printf("Exiting...\n");
                freeTree(root);
                break;
        }     
    } while (choice != 0);

    return 0;
}

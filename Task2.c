#include <stdio.h>
#include <conio.h>
#include "header.h"
#include <string.h>

typedef unsigned char         uint8;

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* top=NULL;

void push(uint8 data)
{
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = top;
    top = temp;
}

uint8 pull()
{
    Node* temp = top;
    top = top->next;
    uint8 data = temp->data;
    free(temp);
    return data;
}
void printStack()
{
    Node* temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}

uint8* balancedParentheses(uint8* expression)
{
    int i = 0;
    while (expression[i] != '\0')
    {
        if (expression[i] == '{' || expression[i] == '(')
        {
            push(expression[i]);

        }
        else if (expression[i] == '}' || expression[i] == ')')
        {
            uint8 value = pull();
            if (expression[i] == '}' && value != '{')
            {
                return "UNBALANCED";
            }
            else if (expression[i] == ')' && value != '(')
            {
                return "UNBALANCED";
            }
        }
        i++;
    }
    return "BALANCED";
}

int main()
{
    char str[100];
    gets(str);
    printf("%s", balancedParentheses(str));
  
    return 0;
}



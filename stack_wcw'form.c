#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct Stack Stack;
typedef struct Node Node;

struct Node {
    void *data;         // Generic pointer to any type of data
    Node *next;         // Pointer to next node
};

struct Stack {
    Node *top;          // Pointer to head node of the linked list being used as stack
};

Stack *    newStack    ();
void       push        (Stack *, void *);
void *     pop         (Stack *);
void *     peek        (Stack *);
int        isEmpty     (Stack *);
int        size        (Stack *);
void       clear       (Stack *);


/* Defining methods to handle stack */

Stack * newStack()
{
    Stack *newstack = (Stack *) malloc(sizeof(Stack));

    if (newstack == NULL)
        return NULL;

    newstack -> top = NULL;
    return newstack;
}


void push(Stack *S, void *data)
{
    Node *newnode = (Node *) malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = (*S).top;
    (*S).top = newnode;
}


void * pop(Stack *S)
{
    if ((*S).top == NULL)
        return NULL;

    Node *ptr = (*S).top;
    void *data = (*S).top -> data;
    (*S).top = (*S).top -> next;

    free(ptr);
    return data;
}


void * peek(Stack *S)
{
    if ((*S).top == NULL)
        return NULL;

    return (*S).top -> data;
}


int isEmpty(Stack *S)
{
    return (*S).top == NULL;
}


int size(Stack *S)
{
    int nodeCount = 0;
    Node *ptr = (*S).top;

    while (ptr != NULL)
    {
        nodeCount++;
        ptr = ptr -> next;
    }

    return nodeCount;
}


void clear(Stack *S)
{
    Node *ptr;
    while ((*S).top != NULL)
    {
        ptr = (*S).top;
        (*S).top = (*S).top -> next;
        free(ptr);
    }
}

int hasLessPriority(char op1, char op2)    // Return 1 if the priority of 1st operator is less than that of 2nd
{
    char priority[256] = {0};
    priority['('] = 4;

    priority['^'] = 3;

    priority['*'] = 2;
    priority['/'] = 2;

    priority['+'] = 1;
    priority['-'] = 1;

    if(priority[op1] <= priority[op2])
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if(ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch =='/' || ch=='^')    return 1;
    else    return 0;
}

int isOperand(char ch)
{
    if(!isOperator(ch))    return 1;
    else    return 0;
}
int main()
{
    char str[100];
    int i;

    Stack *operands = newStack();  // Allocate a new stack
    Stack *operators = newStack();  // Allocate a new stack

    scanf("%s", str);

    for(i = 0; str[i]; i++)
    {
        if(isOperand(str[i]))
            push(operands, &str[i]);
        else
        if(isOperator(str[i]))
        {
            while(!isEmpty(operators) && *(char *)peek(operators) != '(' && hasLessPriority(str[i], *(char *)peek(operators)))
                push(operands, &*(char *)pop(operators));

            if(str[i] == ')')
            {
                while(!isEmpty(operators) && *(char *)peek(operators) != '(')
                    push(operands, &*(char *)pop(operators));

                if(!isEmpty(operators))
                    pop(operators); // Pop the opening bracket '(' but not store anywhere.
            }

            if(str[i] != ')')
                push(operators, &str[i]);
        }
    }

    while(!isEmpty(operators))
        push(operands, &*(char *)pop(operators));

/*    while(!isEmpty(operands))
        printf("%c ", *(char *)pop(operands));
    printf("\n\n");
*/

    char s[100];
    int j=0;
    while(!isEmpty(operands))
    {
           s[j++] = *(char *)pop(operands);
//           if(s[j-1] == '(')
//                j--;
    }
    s[j] = '\0';

    for(i=j-1; i>=0; i--)
        printf("%c", s[i]);

    return 0;
}

/*
Print the operand as they arrive.
If the stack is empty or contains a left parenthesis on top, push the incoming operator on to the stack.
If the incoming symbol is '(', push it on to the stack.
If the incoming symbol is ')', pop the stack and print the operators until the left parenthesis is found.
If the incoming symbol has higher precedence than the top of the stack, push it on the stack.
If the incoming symbol has lower precedence than the top of the stack, pop and print the top of the stack. Then test the incoming operator against the new top of the stack.
If the incoming operator has the same precedence with the top of the stack then use the associativity rules. If the associativity is from left to right then pop and print the top of the stack then push the incoming operator. If the associativity is from right to left then push the incoming operator.
At the end of the expression, pop and print all the operators of the stack.
Let's understand through an example.

Infix expression: K + L - M*N + (O^P) * W/U/V * T + Q
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 50

int precedence(char operator) {
    int precendence = 0;
    switch(operator) {
        case '+':
        case '-': {return 1;}
        case '*':
        case '/': {return 2;}
        case '^' :{return 3;}
        default : {return -1;}
    }
}



typedef struct _opers {
    char data[STACK_SIZE];
    int top;
} opers;

opers operators;

bool is_empty () { return operators.top == -1;}
bool is_full()   { return operators.top == STACK_SIZE - 1;}
char peek ()     { return operators.data[operators.top];}
char pop  ()     { return operators.data[operators.top--];}
void push(char c){ operators.data[++operators.top] = c;}

bool compare_prec(char ch) {
    char stack_top = peek();
    int result  = precedence(ch) > precedence(stack_top) ? 1 : 0;
    if (result == 0) {
        result = precedence(ch) < precedence(stack_top) ? -1 : 0;
    }
    if (result == 0) {
        if (ch == '^') result = -2;
    }
    printf ("Precedence: Stack:%c, Incoming:%c compare:%d\n", stack_top, ch, result);
    return result < 0 ? true: false;
}
char output[STACK_SIZE];
int j=0;
void accept(char ch) {
    if ( isalnum(ch) )    output[j++] = ch;
    else if ( ch == '(' )  push(ch);
    else if (ch == ')' ) {
        while (is_empty() && peek() != '(') output[j++] = pop();
        pop();
    } else {
        while (!is_empty() && compare_prec(ch)) output[j++] = pop();
        push(ch);
    }
}
void process(char * input) {
    for (int i = 0; i < STACK_SIZE; i++, input++) {
        if (is_full()) {
            printf("Stack overflow!!\n ");
            return;
        }
        if (!isspace(*input))
            accept(*input);
    }
    while(! is_empty()) {
        output[j++] = pop();
    }
    output[j++]='\0';
}

int main(int argc, char*argv[]) {
    process("K + L - (M * N) + (O^P) * W/U/V * T + Q");
    printf("%s\n",output);
}

// infix_postfix
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50
#define NIL  '\0'

// Input
char infix[SIZE];
int  i = 0;
char input()          { return infix[i++]; }

//Stack
char stack[SIZE];
int top = -1;
void push (char ch)   { stack[++top] = ch;  }
char peek ()          { return stack[top];  }
char pop  ()          { return stack[top--];}

//Output
char pofix[SIZE];
int k = 0;
void output(char ch)  { pofix[k++] = ch; }

//Precedence
int precedence(char ch) {
    switch (ch) {
        case '#' : return 0;
        case '(' : return 1;
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' :
        case '%' : return 3;
        case '^' : return 4;
        default  : return -1;
    }
}

int main() {
    //strcpy(infix, "K+L-M*N+(O^P)*W/U/V*T+Q^J^A");
    //printf ("In infix: %s\n", infix);
    printf ("Enter new:\n");
    scanf("%s", infix);

    // ------------------- START OF LOGIC -----------------------------------//
    /*  Algorithm

    1. push '#'
    2. for (in = first char in input; in != '\0'; in = next char) {
          if   in == '(' then push
          else if alpha-numeric (in) then output
          else if (in == ')') then
              while (stack-top != '(')
                pop the stack and output

              pop the '(' but dont put it to output
          else
              while (prec(stack-top) >= prec (in) && stack-top != '^')
                pop the stack and output

              push (in)
       }
    3. while(stack-top != #)
          pop the stack and output

    4. Zero terminate the output. (so that it is sgtring pritnable)

    */
    push('#');                     // First push '#'

    // Run the loop
    char ch;
    while ((ch = input()) != '\0') {// get the input character --> in
        //printf("%c", ch);
        if ( ch == '(')            // If in = left braces push to stack
            push(ch);
        else if (isalnum(ch))      // If in = alpha-numeric output it
            output(ch);
        else if (ch == ')') {      // If in = right braces then
            while( peek() != '(') {// drain the stack till '(' and output the pop from stack
                output(pop());
            }
            pop();                 // evict '(' from stal
        } else {
            while (precedence(peek()) >= precedence(ch)) {
                output(pop());     // if prec(stack) >= prec(in) and stach!='^' then output the pop from stack
            }
            push(ch);              // push the input character
        }
    }

    while(peek() != '#')           // Drain the stack if any
        output(pop());             // output the pop from stack

    output('\0');                   // Zero terminate
// ------------------- END OF LOGIC -----------------------------------//
    printf ("Actual  : %s\n", pofix);
    //printf ("Expected: %s\n", "KL+MN*-OP^W*U/V/T*+QJA^^+");
    return 0;
}

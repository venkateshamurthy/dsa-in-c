#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define SIZE 50
//input
char pofix[SIZE];
int i=-1;
char input()         { return pofix[++i];   }

//Char to Integer
int to_int (char ch) { return ch - '0';     }
//Stack
int  stack[SIZE];
int  top = -1;
void push (int elem) { stack[++top] = elem;  }
int  pop  ()         { return stack[top--];  }

int operation (int op2, int op1, char operator) {
    switch(operator) {
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '%' : return op1 % op2;
        case '^' : return (int) pow(op1, op2);
        default  : {
            printf("Invalid operator:%c\n hence exiting!", operator);
            exit(-1);
        }
    }
}

int evaluate() {
    char ch;
    while( (ch = input() ) != '\0') {         // Read ch from postfix until '\0'
        int result = isdigit(ch) ?
            to_int(ch)           :            // Convert to integer
            operation(pop()/* op2 */,pop()/* op1 */,ch); //operate on two operands op2, op1;
        push(result);
    }
    return pop();                             //pop final result
}

int main() {
    printf("Enter POS fix expression:\n");
    //512+4*+3-     14
    scanf("%s", pofix);
    printf("Result:%-d\n", evaluate());
}

/* 512+4*+3-
   result 14
Input   Action         Stack     Details
  5     push value     5
  1     push value     5 1
  2     push value     5 1 2
  +     add            5 3       pop 2, pop 1, push 1+2=3
  4     push value     5 3 4
  x     multiply       5 12      pop 4, pop 3, push 3x4=12
  +     add            17        pop 12, pop 5, push 5+12=17
  3     push value     17 3
  -     subtract       14        pop 3, pop 17, push 17-3=14
  */
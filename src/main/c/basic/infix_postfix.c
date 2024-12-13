#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 50

char infix[SIZE], stack[SIZE], pofix[SIZE];

int  top = -1;
int  i   =  0;
int  k   =  0;

void push (char elem)     { stack[++top] = elem;  }
char peek ()              { return stack[top];    }
char pop  ()              { return stack[top--];  }
void output(char elem)    { pofix[k++] = elem;    }

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
    printf ("Get the infix string\n");
    scanf("%s", infix);

    // First push a hash character that helps in terminating condition
    push('#');

    // Run the loop
    char ch;
    while( (ch = infix[i++]) != '\0') {
        if      ( ch == '('  )    push  (ch);
        else if (isalnum (ch))    output(ch);
        else if (ch == ')'   ) {
            while( peek() != '(')
                output(pop());
            pop(); //'(' evicted
        } else {
            while (precedence(peek()) >= precedence(ch))
                output(pop());
            push(ch);
        }
    }

    while(peek() != '#')
        output(pop());
    output('\0');

    printf ("Post fix : %s\n", pofix);
    return 0;
}
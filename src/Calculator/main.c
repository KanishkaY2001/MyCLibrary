#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isOp(char c)
{
    return c == '+' || c == '-' || c == '/' || c == '*';
}

void getNum(char in[], int b1, int b2, int* r)
{
    char num[10];
    int i, j = 0;

    for (i = b1; i < b2; ++i)
    {
        char c = in[i];
        if (isdigit(c) != 0)
        {
            num[j++] = c;
            printf("%d", j);
        }
        else if (isOp(c))
        {

            r[0] = 1; // change this to return actual number
            r[1] = i;
            break;
        }
    }
}

int tokenize(char in[], int len)
{
    char num1[10], num2[10];
    int r[2];
    char op;

    getNum(in, 0, len, r);
    printf("%d, %d", r[0], r[1]);
    /*
    
    int i = 0;
    int j = 0;
    for (i = 0; i < strlen(in); ++i)
    {
        char c = in[i];
        if (isdigit(c) != 0)
        {
            num1[j++] = c;
        }
        else if (isOp(c))
        {
            op = c;
            break;
        }
    }
    */

    //j = 0;
    printf("%s\n%c\n", num1, op);
}

void main()
{
    char in[220];

    char* ptr;
    double ret;

    // https://stackoverflow.com/questions/53689670/is-it-better-to-implement-strtol-without-errno


    while (1)
    {
        scanf("%219s", in);
        ret = strtod(in, &ptr);
        printf("The number(unsigned long integer) is %lf\n", ret);
        printf("String part is |%s|", ptr);
        //tokenize(in, strlen(in));
    }
}
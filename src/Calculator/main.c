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
    /*
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
    */
}
  /*
int tokenize(char in[], int len)
{
  
    char num1[10], num2[10];
    int r[2];
    char op;

    getNum(in, 0, len, r);
    printf("%d, %d", r[0], r[1]);
    
    
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
    

    //j = 0;
    printf("%s\n%c\n", num1, op);
    
}
*/

char *calculate(char in[220], int len)
{
    bool invalid = false;
    bool opExist = false;

    char n1[110];
    char n2[110];
    int n1L = 0;
    int n2L = 0;
    char op = '!';

    for (int i = 0; i < len; ++i)
    {
        char c = in[i];
        if (isdigit(c))
        {
            if (opExist)
            {
                n2[n2L++] = c;
                continue;
            }
            n1[n1L++] = c;
        }
        else if (isOp(c))
        {
            if (opExist)
            {
                invalid = true;
                break;
            }
            op = c;
            opExist = true;
        }
        else
        {
            invalid = true;
            break;
        }
    }
    
    if (n1L == 0 | n2L == 0 | op == '!' | invalid)
    {
        return "Invalid input\n";
    }

    n1[n1L++] = '\0';
    n2[n2L++] = '\0';
    
    printf("'%s' '%c' '%s' = ?\n", n1, op, n2);
    return "Valid!!!!";
}


void main()
{
    float x = 1.2e2;
    printf("%f", x);
    char in[220];
    while (1)
    {
        scanf("%s219", in);
        printf("%s\n", calculate(in, strlen(in)));
    }
}
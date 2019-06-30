#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 300

char productions[MAX][MAX]; //array of strings
int parseTable[MAX][MAX];
char terminals[MAX] = {0};
char nonTerminals[MAX] = {0};
int N; //number of productions

void getInput()
{
    printf("\n ");
    printf("Enter number of Productions : ") ; 
    scanf("%d", &N);

    int i,j,t ; 
    for (i = 0; i < N; i++)
    {
        printf("\nEnter production %d : ", i);
        scanf("%s", productions[i]);

        for (j = 3; productions[i][j]; j++)
        {
            if (isupper(productions[i][j]))
                nonTerminals[productions[i][j]]++;
            else 
                terminals[productions[i][j]]++;
        }
    }
    terminals['#'] = 0 ; 
    terminals['$']++ ; 

    for (i = 0; i < MAX; i++)
    {
        char nonTerm = i;
        if (nonTerminals[nonTerm] > 0)
        {
            for (t = 0; t < MAX; t++)
            {
                if (terminals[t] > 0)
                {
                    printf("Enter production number for M [ %c , %c ] : ", nonTerm, t);
                    fflush(stdin);
                    scanf("%d", &parseTable[nonTerm][t]);
                }
            }
        }
    }
}

void predictiveParsingAlgorithm()
{
    char stack[MAX] = {"$"}, top = 0; // stack of strings
    stack[++top] = productions[0][0];

    char input[MAX];
    int inputPointer = 0;
    int k ; 
    int parseTableEntry;
    printf("\nEnter the input string :");
    scanf("%s", input);
    strcat(input , "$") ; 

    printf("\n\nSTACK\t\tINPUT\t\tAction\n");
    printf("-------\t\t------\t\t-------\n");
    while (top >0)
    {
        printf("%s\t\t%s\t\t", stack, input + inputPointer);

        char topChar = stack[top--];

        if (topChar == input[inputPointer])
        {
            printf("MATCH %c\n", input[inputPointer++]);
        }
        else if (islower(topChar))
        {
            printf("\nERROR DETECTED ! ");
            exit(1);
        }
        else if ((parseTableEntry = parseTable[topChar][input[inputPointer]]) == -1)
        {
            printf("\nERROR DETECTED ! ");
            exit(2);
        }
        else
        {
            printf("O/P : %s\n", productions[parseTableEntry]);
            for (k = strlen(productions[parseTableEntry]) - 1; k >= 3; k--)
            {
                if (productions[parseTableEntry][k] != '#')
                    stack[++top] = productions[parseTableEntry][k];
            }
        }

        stack[top+1] = 0 ; //trim excess text from stack string
    }

    printf("%s\t\t%s\t\t", stack, input + inputPointer);
    if(top==0 && input[inputPointer]=='$') printf("ACCEPT STRING :) ") ; 
    else printf("REJECT STRING :( ") ; 
}

int main()
{
    getInput();
    predictiveParsingAlgorithm();
}

/*

E--TA
A--+TA
A--#
T--FB
B--*FB
B--#
F--(E)
F--d

2
-1
2
-1
1
-1
5
-1
5
4
5
-1
-1
0
-1
-1
-1
0
-1
6
-1
-1
-1
7
-1
3
-1
-1
-1
3

*/
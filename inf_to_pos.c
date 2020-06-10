#include <stdio.h>
int S[20],out[20],top = -1,j=0;
int priority(char x)
{
    if(x == '/')
    return 4;
    if(x == '*')
    return 3;
    if(x == '+')
    return 1;
    if( x == '-')
    return 2;
    if( x == '^')
    return 5;
}
char pop()
{
    return S[top--];
}
void push(char s)
{
    S[++top] = s;
    if((S[top-1] != '\0') && (priority(s) < priority(S[top - 1])))
    out[j++] = pop();

}
int main()
{
    char str[20];
    int i;
    printf("Enter the string expression\n");
    scanf("%s",str);
    for(i = 0;str[i] != '\0';i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
           push(str[i]);
        else if(str[i] == ')')
           while(top != -1)
           pop();
        else if(str[i] == '(')
           continue;
        else
           out[j++] = str[i];
    }
    printf("Hello\n");
    for(i=0;out[i] != '\0';i++)
    printf(" %s ",out[i]);
    return 0;
}

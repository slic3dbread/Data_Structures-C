/***********************Student Name: Benjamin McConville
************************Date: 2014-09-22
************************Assignment 1
************************Filename: ackermann.c*/

#include <stdio.h>
#include <strings.h>

/*This function represents the ackermann function it will take the users input and out
 * the results through recursion since certain conditions require the functions input to
 * be itself.
 * The output of the function is answer to the functions inputs*/
int ackermann(int m,int n)
{
    if (m==0&&n>=0)
        return n+1;
    else if(m>0&&n==0)
        return ackermann(m-1,1);
    else if(m>0&&n>0)
        return ackermann(m-1,ackermann(m,n-1));
    else
        return 0;

}
/*Asks for user input and calls the function ackermann.
 * outputs the answer to the ackermann function*/
void ackermann_main()
{
    int m,n;
    int answer;

    printf("Input the m value for the Ackermann function\n");
    scanf("%d",&m);

    printf("input the n value for the Ackermann function\n");
    scanf("%d",&n);

    answer = ackermann(m,n);/*Call of the recursive function*/

    printf("A(%d,%d)=%d\n",m,n,answer);

}

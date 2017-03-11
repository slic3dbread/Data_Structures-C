/***********************Student Name: Benjamin McConville
************************Date: 2014-09-22
************************Assignment 1
************************Filename: main.c*/


#include <stdio.h>
#include <strings.h>
#include <math.h>


/*The function that outputs all possible combinations of carbon*/
void carbon(char* word,int value);
/*carbons main function*/
void carbon_main();
/*The function that asks for a number and estimates the square root of it*/
double newton(double a,double x);
/*newtons main*/
void newton_main();
/*The function that uses the Ackermann function A(m,n)*/
int ackermann(int m,int n);
/*ackermann main*/
void ackermann_main();


int main(void)
{
    char input;

    do {
        printf("\nInput either (c)Carbon, (a)Ackerman, (n)Newton  to run the function or\n(q)to quit\n");

        scanf(" %c",&input);

        switch (input) {
            case 'c':
                carbon_main();/*Calls the carbon function*/
                break;
            case 'a':
                ackermann_main();/*Calls the ackermann function*/
                break;
            case 'n':
                newton_main();/*Calls the newton function*/
                break;
            case 'q':/*quit statement*/
                break;
        }
    }while(input!='q');

    return 0;
}

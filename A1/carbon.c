/***********************Student Name: Benjamin McConville
************************Date: 2014-09-22
************************Assignment 1
************************Filename: carbon.c*/

#include <stdio.h>
#include <string.h>

/*remaining is the input sting, while j is the count of the position
 * the function itself swaps through the characters and leaves the remaining
 * characters to pass through the function again to be swapped until all possible
 * outcomes are displayed*/
void carbon(char* remaining,int j)
{
    int i=0;
    int determinator= strlen(remaining)-1;
    char temp;

    if (j==determinator) {/*Stopping condition*/
        printf("%s\n",remaining);
    }
    else {
        for (i = j; i<=determinator; i++) {/*will loop through every character*/

            temp = *(remaining+j);/*Switches characters*/
            *(remaining+j) = *(remaining+i);
            *(remaining+i) = temp;


            carbon(remaining,j+1);/*calls the function again*/

            temp = *(remaining+j);/*Switches characters back*/
            *(remaining+j) = *(remaining+i);
            *(remaining+i) = temp;
        }
    }
    return;
}

/*passes the string carbon and calls the function carbon*/
void carbon_main()
{
    char remaining[7]= "carbon";

    carbon(remaining,0);
}



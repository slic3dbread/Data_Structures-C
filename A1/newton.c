/***********************Student Name: Benjamin McConville
************************Date: 2014-09-22
************************Assignment 1
************************Filename: newton.c*/

#include <stdio.h>
#include <math.h>


/*Calls the guess value a and the value to be square rooted x
 * Outputs the estimated value of the root (y) after the recursive method*/
double newton(double a, double x)
{
    double y;/*decleration of the output*/

    if (fabs((a*a)/x-1)<=0.00001){/*the stopping condition and the small condition*/
        y=a;
        return y;
    }
    else {
        a=(a+(x/a))/2;
        y=newton(a,x);/*Call of the function again to repeat untill the stopping condition is met*/
        return y;
    }
}


/*Gets input  from user on what number they want square rooted then divides it by two to get the first esitmate.
 * It calls the newton fuction to estimate it till it is within approximation then it outputs the answer.
 * After that it does the same estimate just not recursively and outputs that answer as well*/
void newton_main()
{
    double x=0,a=0,y=0;

    printf("Input a real number to be square rooted:\n");
    scanf("%lf",&x);/*Gets users input to be estimated*/

    a=x/2;/*guess value*/

    y=newton(a,x);
    printf("Recursive output: ");
    printf("%lf\n",y);

    a=x/2;/*guess value is reset for non-recursive method*/

    while (fabs((a*a)/x-1)>=0.00001) {/*while the value is bigger then
                                       *the terminating estimate it continues*/
      a=(a+(x/a))/2;

    };

    printf("Non-recursive method: ");
    printf("%lf\n",a);

}

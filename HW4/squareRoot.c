#include <math.h>
#include <stdio.h>
//
// Created by Thomas Keller on 10/14/22.
//
// approximating the square root of a non-negative real number b
// compute the difference (in absolute value) with respect to sqrt() in <math.h>
double squareRoot(double b, double n){

    // get value b to calculate root square
    /*
    double b; // b value
    int checkVar = 1;
    while (checkVar) {
        printf("Enter a number for b to approximate the square root: \n");
        scanf("%lf", &b);
        if (b > 0)
            checkVar = 0;
        else {
            printf("Not a valid input! Number must be a non negative real number!\n");
        }
    }
    printf("b = %lf\n", b);
*/

    double x0 = 1;
    double xn = 0;
/*
    //int n = 10;
    double newRoot;

    const double tolerance = 0.1;
    while(1) {
        newRoot = 0.5*(xn+(b/xn));
        if((xn-newRoot)< tolerance){
            break;
        }
        xn = newRoot;
    }


    printf("%f\n", xn);
*/
    for(n=0;n<10;n++){
        // calculation for first element
        if (xn == 0){
            xn = 0.5*(x0+(b));
            // printf("part1: %f\n", xn);
        }
        // calculation for all elements except first one
        else{
            xn = 0.5*(xn+(b/xn));
            // printf("part2: %f\n", xn);
        }
    }

    // calculation for "exact" square root
    double realSqrt = sqrt(b);
    printf("Approx square root is : %f\n", xn);
    printf("Real square root is : %f\n", realSqrt);

    // error calculation e = |rootApprox - root|
    double error = fabs(xn - realSqrt);

    return error;
}

int main( )
{
    double b = 25;
    double n = 100;

    double error = squareRoot(b,n);
    printf("Error is: %f",error);
}

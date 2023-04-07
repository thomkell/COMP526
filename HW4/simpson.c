//
// Created by Thomas Keller on 10/14/22.
//
// double simpson(double a, double b, pointer to function f, int n);

#include <stdio.h>
#include <math.h>

// returning function: x*x-cos(x)
double test2(double x) {

    // calculate function values for simpson
    return (double) x*x-cos(x);
}

double simpson(double a, double b, double (*test2)(), int n){

    double h = (b-a)/n;

    double xi[100];
    double xii[100];
    int i;

    // calculate xi
    for(i = 0; i <= n; i++){
        xi[i] = a+i*h;
    }

    // calculate xii (xi hat)
    for(i = 0; i < n; i++){
        xii[i] = (xi[i]+xi[i+1])/2;
    }

    // calculate sum for simpson
    double sum1 = 0;
    double sum2 = 0;
    for(i = 1; i <= n; i++){
        sum1 += ((test2(xi[i-1])+test2(xi[i]))/2);
        sum2 += test2(xii[i-1]);
    }

    // calculate result
    double result2 = (h/3)*sum1+(2*h/3)*sum2;

    printf("Simpson result is: %f\n", result2);

    return result2;
}

int main() {
    double a = 0;
    double b = 10;
    int n = 10;

    double result3 = simpson(a, b, &test2, n);

    printf("Simpson result is: %f\n", result3);

    return 0;
}

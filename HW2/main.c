// Thomas Keller 09/14/2022
// COMP526: Computational Methods for Scientists
// Assignment 2
#include <stdio.h>
#include <math.h> // math lib for pow and sqrt

// Functions
// Calculate the surface A of the triangle
double areaTriangle(double t, double c){
    double a = sqrt(pow((c*t),2)+pow(t,2)); // v1-v2
    double b = sqrt(pow((c*t),2)+pow(t,2)); // v3-v1
    double d = 2*c*t; // v2-v3
    double s = (a+b+d)/2; // Calculate s for area formula

    double A = sqrt(s*(s-a)*(s-b)*(s-d)); // Calculate Area with s and a,b,d
    return A;
}

// Calculate function f(x)
double functionF(double x){
    double f = 1/(1+pow(x,2)); // f(x) = 1/(1+x^2)
    return f;
}

// Calculate function h(x)
double functionH(double t, double x){
    double h = pow(t,2)+pow(x,2); //h(x) = t^2+x^2
    return h;
}

// Solve Integrand -sin(x)
double Integral(double t, double x, double c){
    double I = cos(x+c*t)-cos(x-c*t); //Integral of -sin(x)
    return I;
}

// Main Function
int main() {

    printf("--------------------Input-----------------------\n");

    // Variable declaration
    double c = 2;
    double t = 1;
    double x = 0;
    printf("c = %f\n", c);
    printf("t = %f\n", t);
    printf("x = %f\n", x);

    if(t <= 0){
        printf("t has to be greater than 0!\n");
        return 0;
    }

    printf("--------------intermediate results--------------\n");

    // sub results
    // Calculate area of triangle, input t, x, c
    double A = areaTriangle(t,c);
    printf("Area A = %f\n", A);

    // Calculate function f(x), input x
    double f = functionF(x);
    printf("f(x) = %f\n", f);

    // Calculate function h(x), input t, x
    double h = functionH(t, x);
    printf("h(x) = %f\n", h);

    // Calculate Integral, input t, x, c
    double I = Integral(t, x, c);
    printf("Integral = %f\n", I);

    // Calculate f(x), input x-ct & x+ct
    double f1 = functionF(x-c*t);
    double f2 = functionF(x+c*t);
    printf("f1(x) = %f\n", f1);
    printf("f2(x) = %f\n", f2);

    printf("-------------------Output-----------------------\n");

    // declarations of inputs for h function -> v1, v2, v3
    double h1 = x-(0.5*c*t); // input for t
    double h2 = 0.5*t; // input for x

    double h11 = x+(0.5*c*t); // input for t
    double h12 = 0.5*t; // input for x

    double h111 = x; // input for t
    double h112 = 0; // input for x

    // this part is only for testing
    // double test = (1/(2*c))*(A/3)*(functionH(h1,h2)+functionH(h11,h12)+functionH(h111,h112));
    // printf("test  %f\n", test);

    // Calculate result from d'alembert formula for triangle
    double result = (0.5*(f1+f2))+((1.0/(2.0*c))*I)+(1.0/(2.0*c))*(A/3)*(functionH(h1,h2)+functionH(h11,h12)+functionH(h111,h112));

    printf("Result of d'Alembert formula u(t,x) = %f\n", result);

    printf("------------------------------------------------\n");
    printf("------------------------------------------------\n");

    return 0;
}
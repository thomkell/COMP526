// COMP526 Assign3 by Thomas Keller, 10/05/22
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// const values
// 10e-16
const double e = 1e-15;

// const for natural log
const double ln_a = 0;
const double ln_b = INFINITY;

// const for tan
const double tan_a = -M_PI_2;
const double tan_b = M_PI_2;

// const for arcsin
const double asin_a = -1;
const double asin_b = 1;

// const for cosh
const double cosh_a = -INFINITY;
const double cosh_b = INFINITY;

// const for arctanh
const double atanh_a = -1;
const double atanh_b = 1;

// Struct
struct input {

    // inputs
    int selectedFunction;
    double a;
    double b;
    int n;

    // xj
    double xj[100];

    // derivative
    double ValuesdhX[100];
    double ValuesdHX[100];
    double derivativeApprox[100];
    double derivativeExact[100];
    double errorDerv[100];

    // integral
    double integralApprox;
    double integralExact;
    double errorInt;
};

// ask for function, interval [a, b], and n
struct input getInput(){

    struct input interV; // create struct for inputs and calculations
    int checkInput = 1; // checkInput variable for while loop variable for function

    // users choice of function
    printf("------------------------------------------------------\n");
    printf("Choose a function of the following by enter the number: \n");
    printf(" 1. Natural logarithm\n 2. Tangent\n 3. Arc sine\n 4. Hyperbolic cosine\n 5. Hyperbolic arc tangent\n 6. Exit\n");

    while(checkInput == 1) {

        printf("Enter an integer: ");
        scanf("%d", &interV.selectedFunction);
        checkInput = 0; // while loop stop

        switch (interV.selectedFunction){
            case 1:
                printf("You selected: Natural logarithm\n");
                break;
            case 2:
                printf("You selected: Tangent\n");
                break;
            case 3:
                printf("You selected: Arc sine\n");
                break;
            case 4:
                printf("You selected: Hyperbolic cosine\n");
                break;
            case 5:
                printf("You selected: Hyperbolic arc tangent\n");
                break;
            case 6:
                printf("byebye\n");
                exit(0);
            default:
                printf("Select a number from 1 to 5!\n");
                checkInput = 1; // while loop repeat
        }
    }

    printf("------------------------------------------------------\n");
    printf("Choose a,b for an interval [a,b], b > a \n");

    int checkInput2 = 1; // checkInput variable for while loop variable for interval

    while (checkInput2 == 1) {
        printf("a = ");
        scanf("%lf", &interV.a);
        printf("b = ");
        scanf("%lf", &interV.b);
        printf("a = %f, b = %f\n", interV.a, interV.b);
        checkInput2 = 0;

        // Check b>a
        if (interV.b > interV.a) {
            // Check if interval valid
            switch (interV.selectedFunction) {
                case 1:
                    if (interV.a > ln_a && interV.b < ln_b) {
                    }
                    else {
                        printf("Select valid domain for ln(x): (0,infinity)!\n");
                        checkInput2 = 1;
                    }
                    break;
                case 2:
                    if (interV.a > tan_a && interV.b < tan_b ) {
                    } else {
                        // tan derivatives and integrals are the same for n time the interval, for example it doesn't matter if
                        // we calculate tan around 0 or PI or -PI, results are the same
                        printf("Select valid domain for tan(x): (-PI/2,PI/2)!\n");
                        checkInput2 = 1;
                    }
                    break;
                case 3:
                    if ( (interV.a > asin_a && interV.b < asin_b)) {
                    } else {
                        printf("Select valid domain for asin(x): (-1,1)!\n");
                        checkInput2 = 1;
                    }
                    break;
                case 4:
                    if (interV.a > cosh_a && interV.b < cosh_b) {
                    } else {
                        printf("Select valid domain for cosh(x): (-infinity, infinity)!\n");
                        checkInput2 = 1;
                    }
                    break;
                case 5:
                    if (interV.a > atanh_a && interV.b < atanh_b) {
                    } else {
                        printf("Select valid domain for atanh(x): (-1,1)!\n");
                        checkInput2 = 1;
                    }
                    break;
                default:
                    printf("Something went wrong, sorry!\n");
                    checkInput2 = 1;
            }
        }
        else {
            printf("Select b > a on a valid domain!\n");
            checkInput2 = 1;
        }
    }

    int checkInput3 = 1; // checkInput variable for while loop variable for n

    printf("------------------------------------------------------\n");
    printf("Enter a positive integer n <= 100: \n");

    while (checkInput3) {
        printf("n = ");
        scanf("%i", &interV.n);
        if (interV.n <= 100 && interV.n > 0) {
            checkInput3 = 0;
        }
        else{
            printf("Select a valid integer!\n");
        }
    }

    return interV;
}

// calculate array xj and derivatives
struct input calculate(struct input inputCollect) {
    int i;
    for (i = 1 ; i < inputCollect.n-1; i++)
    {
        inputCollect.xj[i] = inputCollect.a + i*((inputCollect.b-inputCollect.a)/inputCollect.n);
    }

    // switch case to calc dh depend on function chosen
    switch (inputCollect.selectedFunction){
        case 1:
            // Calculate dhX for ln(x)

            for (i = 1; i < inputCollect.n-1; i++) {
                // log(x)/(-1/x^2)
                double temp = fabs(log(inputCollect.xj[i]) / (-1 / (inputCollect.xj[i] * inputCollect.xj[i])));
                inputCollect.ValuesdhX[i] = 2 * sqrt(e * temp);
            }
            break;
        case 2:
            // Calculate dhX for tan(x)

            for (i = 1; i < inputCollect.n-1; i++) {
                // tan(x)/(sin(x)/cos^2(x))
                double temp = fabs(tan(inputCollect.xj[i]) / (2*sin(inputCollect.xj[i]) / pow(cos(inputCollect.xj[i]),2)));
                inputCollect.ValuesdhX[i] = 2 * sqrt(e * temp);

            }
            break;
        case 3:
            // Calculate dhX for arcsin(x)
            for (i = 1; i < inputCollect.n-1; i++) {
                // tan(x)/(sin(x)/cos^2(x))
                double temp = fabs(asin(inputCollect.xj[i]) / (inputCollect.xj[i] / pow(1 - pow(inputCollect.xj[i],2),(3/2))));
                // double temp = (asin(inputCollect.xj[i]));

                inputCollect.ValuesdhX[i] = 2 * sqrt(e *(temp));
            }
            break;
        case 4:
            // Calculate dhX for cosh(x)
            for (i= 1; i < inputCollect.n-1; i++) {
                // cosh(x)/cosh(x)
                double temp = fabs(cosh(inputCollect.xj[i]) / cosh(inputCollect.xj[i]));
                // double temp = ((exp(inputCollect.xj[i])+exp(-inputCollect.xj[i]))/2)/((exp(inputCollect.xj[i])+exp(-inputCollect.xj[i]))/2);
                inputCollect.ValuesdhX[i] = 2 * sqrt(e * (temp));
            }
            break;
        case 5:
            // Calculate dhX for arctanh(x)
            for (i = 1; i < inputCollect.n-1; i++) {
                // arctanh(x)/(2x)/(1-x^2)^2
                double temp = fabs(atanh(inputCollect.xj[i]) / ((2 * inputCollect.xj[i]) / (pow(1 - pow(inputCollect.xj[i], 2), 2))));
                // double temp = (atanh(inputCollect.xj[i]) / ((2 * inputCollect.xj[i]) / ((1 - inputCollect.xj[i]* inputCollect.xj[i])*(1 - inputCollect.xj[i]* inputCollect.xj[i]))));
                inputCollect.ValuesdhX[i] = 2 * sqrt(e * (temp));
            }
            break;
        default:
            printf("Something went wrong, sorry!\n");
    }

    // calc dHx = min{dhx,(b-a)/2n}
    for (i = 1; i < inputCollect.n-1; i++) {

        if (inputCollect.ValuesdhX[i] < (inputCollect.b-inputCollect.a)/(2*inputCollect.n))
        {
            inputCollect.ValuesdHX[i] = inputCollect.ValuesdhX[i];
        }
        else{
            inputCollect.ValuesdHX[i] = (inputCollect.b-inputCollect.a)/(2*inputCollect.n);
        }

        switch (inputCollect.selectedFunction){
            case 1:
                // Calculate derivatives for ln(x)
                //calc approx derivative of f(x)
                inputCollect.derivativeApprox[i] = (log(inputCollect.xj[i]+inputCollect.ValuesdHX[i])-log(inputCollect.xj[i]-inputCollect.ValuesdHX[i]))/(2*inputCollect.ValuesdHX[i]);

                //calc exact derivative of f(x)
                inputCollect.derivativeExact[i] = (1/inputCollect.xj[i]);

                // calculate error exact-approx
                inputCollect.errorDerv[i] = fabs(inputCollect.derivativeExact[i]-inputCollect.derivativeApprox[i]);
                break;

            case 2:
                // Calculate derivative for tan(x)
                //calc approx derivative of f(x)
                inputCollect.derivativeApprox[i] = (tan(inputCollect.xj[i]+inputCollect.ValuesdHX[i])-tan(inputCollect.xj[i]-inputCollect.ValuesdHX[i]))/(2*inputCollect.ValuesdHX[i]);

                //calc exact derivative of f(x)
                inputCollect.derivativeExact[i] = 1/(pow(cos(inputCollect.xj[i]),2));

                // calculate error exact-approx
                inputCollect.errorDerv[i] = fabs(inputCollect.derivativeExact[i]-inputCollect.derivativeApprox[i]);
                break;

            case 3:
                // Calculate derivative for arcsin(x)
                //calc approx derivative of f(x)
                inputCollect.derivativeApprox[i] = (asin(inputCollect.xj[i]+inputCollect.ValuesdHX[i])-asin(inputCollect.xj[i]-inputCollect.ValuesdHX[i]))/(2*inputCollect.ValuesdHX[i]);

                //calc exact derivative of f(x)
                inputCollect.derivativeExact[i] = 1/sqrt(1-pow(inputCollect.xj[i],2));

                // calculate error exact-approx
                inputCollect.errorDerv[i] = fabs(inputCollect.derivativeExact[i]-inputCollect.derivativeApprox[i]);
                break;

            case 4:
                // Calculate derivative for cosh(x)
                //calc approx derivative of f(x)
                inputCollect.derivativeApprox[i] = (cosh(inputCollect.xj[i]+inputCollect.ValuesdHX[i])-cosh(inputCollect.xj[i]-inputCollect.ValuesdHX[i]))/(2*inputCollect.ValuesdHX[i]);

                //calc exact derivative of f(x)
                inputCollect.derivativeExact[i] = sinh(inputCollect.xj[i]);

                // calculate error exact-approx
                inputCollect.errorDerv[i] = fabs(inputCollect.derivativeExact[i]-inputCollect.derivativeApprox[i]);
                break;

            case 5:
                // Calculate derivative for arctanh(x)
                //calc approx derivative of f(x)
                inputCollect.derivativeApprox[i] = (atanh(inputCollect.xj[i]+inputCollect.ValuesdHX[i])-atanh(inputCollect.xj[i]-inputCollect.ValuesdHX[i]))/(2*inputCollect.ValuesdHX[i]);

                //calc exact derivative of f(x)
                inputCollect.derivativeExact[i] = 1/(1-pow(inputCollect.xj[i],2));

                // calculate error exact-approx
                inputCollect.errorDerv[i] = fabs(inputCollect.derivativeExact[i]-inputCollect.derivativeApprox[i]);
                break;

            default:
                printf("Something went wrong, sorry!\n");
        }
    }

    return inputCollect;
}

// output derivatives
struct input outputTable(struct input inputCollect){

    printf("------------------------------------------------------\n");
    printf("----------------------Derivative----------------------\n");

    printf("xj               Exact         Approx            Error\n");

    int i;
    for (i = 1; i < inputCollect.n-1; i++) {
        printf("%5.9f | %5.9f | %5.9f | %5.9f\n", inputCollect.xj[i], inputCollect.derivativeExact[i], inputCollect.derivativeApprox[i], inputCollect.errorDerv[i]);
    }
    printf("------------------------------------------------------\n");
}
// calculate integrals
struct input calculateIntegral(struct input inputCollect){

    double sum = 0; // sum of integral approx
    double temp; // save variable for calculation
    int i; // for loops

    // switch case to calc dh depend on function chosen
    switch (inputCollect.selectedFunction){
        case 1:
            // Calculate Approx integral for ln(x) with trapezoidal rule
            // calculate sum

            for (i = 1; i <= inputCollect.n-1; i++)
            {
                temp = log(inputCollect.a+i*((inputCollect.b-inputCollect.a)/inputCollect.n));
                sum = sum + temp;
            }

            inputCollect.integralApprox = ((inputCollect.b-inputCollect.a)/inputCollect.n)*((log(inputCollect.a)/2)+sum+log(inputCollect.b)/2);

            //calc exact integral for f(x) = ln(x)
            // x*log(x)-x
            inputCollect.integralExact = (inputCollect.b*log(inputCollect.b)-inputCollect.b)-(inputCollect.a*log(inputCollect.a)-inputCollect.a);

            break;
        case 2:
            // Calculate Approx integral for tan(x) with trapezoidal rule
            // calculate sum
            for (i = 1; i <= inputCollect.n-1; i++)
            {
                temp = tan(inputCollect.a+i*((inputCollect.b-inputCollect.a)/inputCollect.n));
                sum = sum + temp;
            }

            inputCollect.integralApprox = ((inputCollect.b-inputCollect.a)/inputCollect.n)*((tan(inputCollect.a)/2)+sum+tan(inputCollect.b)/2);

            //calc exact integral for f(x)=tan(x)
            // -log(cos(x))
            inputCollect.integralExact = (-log(cos(inputCollect.b)) )- (-log(cos(inputCollect.a)));

            break;
        case 3:
            // Calculate Approx integral for arcsin(x) with trapezoidal rule
            // calculate sum
            for (i = 1; i <= inputCollect.n-1; i++)
            {
                temp = asin(inputCollect.a+i*((inputCollect.b-inputCollect.a)/inputCollect.n));
                sum = sum + temp;
            }

            inputCollect.integralApprox = ((inputCollect.b-inputCollect.a)/inputCollect.n)*((asin(inputCollect.a)/2)+sum+asin(inputCollect.b)/2);

            // calc exact integral for f(x)=arcsin(x)
            // sqrt(1-pow(x,2))+x*asin(x)
            inputCollect.integralExact = sqrt(1-pow(inputCollect.b,2))+inputCollect.b*asin(inputCollect.b)-(sqrt(1-pow(inputCollect.a,2))+inputCollect.a*asin(inputCollect.a));
            break;
        case 4:
            // Calculate Approx integral for cosh(x) with trapezoidal rule
            // calculate sum
            for (i = 1; i <= inputCollect.n-1; i++)
            {
                temp = cosh(inputCollect.a+i*((inputCollect.b-inputCollect.a)/inputCollect.n));
                sum = sum + temp;
            }

            inputCollect.integralApprox = ((inputCollect.b-inputCollect.a)/inputCollect.n)*((cosh(inputCollect.a)/2)+sum+cosh(inputCollect.b)/2);

            // calc exact integral for f(x)=arcsin(x)
            // sinh(x)
            inputCollect.integralExact = sinh(inputCollect.b)-sinh(inputCollect.a);
            break;
        case 5:
            // Calculate Approx integral for arctanh(x) with trapezoidal rule
            // calculate sum
            for (i = 1; i <= inputCollect.n-1; i++)
            {
                temp = atanh(inputCollect.a+i*((inputCollect.b-inputCollect.a)/inputCollect.n));
                sum = sum + temp;
            }

            inputCollect.integralApprox = ((inputCollect.b-inputCollect.a)/inputCollect.n)*((atanh(inputCollect.a)/2)+sum+atanh(inputCollect.b)/2);

            // calc exact integral for f(x)=arctanh(x)
            // 0.5*log(1-x^2)+x*atanh(x)
            inputCollect.integralExact = 0.5*log(1-pow(inputCollect.b,2))+inputCollect.b*atanh(inputCollect.b)-(0.5*log(1-pow(inputCollect.a,2))+inputCollect.a*atanh(inputCollect.a));
            break;
        default:
            printf("Something went wrong, sorry!\n");
    }

        // calculate error |exact-approx|
        inputCollect.errorInt = fabs(inputCollect.integralExact-inputCollect.integralApprox);

    return inputCollect;
}

// output integrals
struct input outputIntegral(struct input inputCollect){

    printf("-----------------------Integral-----------------------\n");
    printf("Exact                 Approx                Error\n");
    printf("%5.9f   |   %5.9f   |     %5.9f\n", inputCollect.integralExact, inputCollect.integralApprox, inputCollect.errorInt);
    printf("------------------------------------------------------\n");

    return inputCollect;
}

int main() {
    while(1) {

        // define struct for inputs
        struct input inputCollect;

        // User has to choose inputs: function/interval/n
        inputCollect = getInput();
        printf("------------------------------------------------------\n");
        printf("You choose function number: %i\n", inputCollect.selectedFunction);
        printf("You choose interval [a,b] = [%f,%f] \n", inputCollect.a, inputCollect.b);
        printf("You choose a positive integer n: %i\n", inputCollect.n);

        // calculate derivatives
        struct input inputCollect2 = calculate(inputCollect);

        // output derivatives
        outputTable(inputCollect2);

        // calculate integrals
        struct input inputCollect4 = calculateIntegral(inputCollect2);

        // output integrals
        outputIntegral(inputCollect4);
    }
}
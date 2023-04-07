//
// Created by Thomas Keller on 10/17/22.
//
#include <stdio.h>
#include <stdlib.h>

int main() {

    //file pointer
    char readFileData[4];

    FILE *fp;
    fp = fopen("dimension.txt", "r");
    fread(readFileData, sizeof(readFileData), 1, fp);
    fclose(fp);

    printf("Read file successfully\n");

    printf("Intdata is = %s\n", readFileData);

    // save read input to variables, make code more readable
    int P = (int)readFileData[0];
    int Q = (int)readFileData[1];
    int R = (int)readFileData[2];
    int S = (int)readFileData[3];

    // for some reason always reading 49 50 51 52
    printf("%i %i %i %i\n", P, Q, R, S);

    int ****my_array = malloc(P*sizeof(*my_array));;

    // allocate memory
    int x, y, z;
    for(x = 0; x<P; x++) {
        my_array[x] = malloc(sizeof *my_array*Q);
        for (y = 0; y < Q; y++) {
            my_array[x][y] = malloc(R* sizeof(*my_array[x][y]));
            for (z = 0; z < R; z++) {
                my_array[x][y][z] = malloc(S *sizeof(*my_array[x][y][z]));
            }
        }
    }

    // Calculate values
    int i,j,k,l;
    for(i=0; i<P; i++){
        for(j=0; j<Q; j++){
            for(k=0; k<R; k++){
                for(l=0; l<S; l++){
                    my_array[i][j][k][l] = (i-j)+(k-l);
                    printf("%i %i %i %i = %i\n", i,j,k,l,my_array[i][j][k][l]);
                }
            }
        }

    }

    //free memory
    free(my_array);

    return 0;
}

/*
double test2(double x) {

    // calculate function values for simpson
    return (double) x*x;
}

double simpson(double a, double b, double (*test2)(), int n){

    double h = (b-a)/n;
    printf("h = %f\n", h);

    double xi[100];
    double xii[100];
    int i;

    // calculate xi
    for(i = 0; i <= n; i++){
        xi[i] = a+i*h;
        printf("%f\n", xi[i]);
    }

    // calculate xii hat
    for(i = 0; i < n; i++){

        xii[i] = (xi[i]+xi[i+1])/2;
        printf("%f\n", xii[i]);
    }

    // calculate sum for simpson
    double sum1 = 0;
    double sum2 = 0;
    for(i = 1; i <= n; i++){
        sum1 += ((test2(xi[i-1])+test2(xi[i]))/2);
        sum2 += test2(xii[i-1]);
        //printf("%f\n", sum1);
    }

    // calculate result
    double result2 = (h/3)*sum1+(2*h/3)*sum2;
    printf("Result2 = %f\n", result2);

    return result2;
}


int main() {
    double a = 0;
    double b = 10;
    int n = 10;

    // double (*fun_ptr)(double, double, int);

    // fun_ptr = &test3;


    double result3 = simpson(a, b, &test2, n);

    printf("Simpson result: %f\n", result3);
    //printf("Simpson result: %f\n", (*fun_ptr)(10,10,10));

    return 0;
}
 */
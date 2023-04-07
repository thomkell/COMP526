#include <stdio.h>
#include <string.h>
#include <math.h>

// #include <math.h>
// function declarations
void aaTranspose(double matrix[][3], double mul[][2], int row, int col);
//double simpson(double a, double b, void *simpsonApprox, int n){

// calculate simpson's rules
//int simpson(int n, int m) {
//    return n+m;
//}

// calculate square root
double squareRoot();

// create dimension.bin file
// void dimToFile();
//void dimToFile(int argc, char** argv);

int foo(char* filename, int A[], int* countPtr){
    FILE* fp=NULL;
    int num = 0;
    if((fp=fopen(filename, "r")) != NULL){
        while(fscanf(fp, "%d", &num) > 0){
            A[*countPtr]=num;
            *countPtr += 1;
            printf("%i", A[*countPtr]);
        } return 0;
    }else
        return 1;
}

void test() {
    printf("hello world\n");
}

double test2(double x) {

    double result;
    result = cos(x);
    printf("%f\n", result);

    return result;
}

// The main function should output the product on the terminal row by row.
int main() {

    // 1. aTimesATranspose
    double matrix[2][3] = {{1, 2,  0},
                           {4, -3, -1}};
    double product[2][2]; // result of matrix*matrix^T
    int row = 2; // number of rows of matrix*matrix^T

    // calculate the product
    aaTranspose(matrix, product, 2, 3);

    printf("aaTranspose is:\n");
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < row; j++) {
            printf("%f\t", product[i][j]);
        }
        printf("\n");
    }
/*
    // 2. simpson approximation
    //double a, b, h;
    int n;
    int a = 2;
    int b = 2;

    int (*functionPtr)(int, int);
    functionPtr = &simpson;
    double sum = (*functionPtr)(2, 3);

    // double simpsonApprox = simpson( a,  b);
    printf("simpson approx = %f\n", sum);
*/
    ////////////////////////////////////////



    //////////////////////////////////////////////////

    //return 0;
    // 3. square root (bug)
    double error = squareRoot();
    printf("Absolute error is: %f\n", error);

    return 0;
    // 4. dimensions write to dimension.bin
    // dimToFile();

    // 5. write a main function that allocates (and at the end deallocates) space for a four-
    // dimensional array of dimensions p × q × r × s, using quadruple pointer
    //char filename = "dimension.txt";
/*
    //file pointer
    FILE *fp = NULL;
    char readFileData[10] = {0};

    //open the file
    fp = fopen("dimension.txt", "r");
    if(fp == NULL)
    {
        printf("Error in opening the file\n");
        return 0;
    }

    // Read 4 characters from stream
    fread(readFileData,sizeof(char),5, fp);

    //Display data
    printf("%s\n", readFileData);

    //close the file
    fclose(fp);
    printf("Read file successfully\n");
*/
    int a[10] = {1,2,3,4,5,6,7,8,9};
    //int i;
    int n = 2;

    for (i=0; i < 10; i++){
        a[i] *= n;
        printf("1. %i\n", a[i]);
    }
    for (i=0; i < 10; i++){
        printf("1. ALL %i\n", a[i]);
    }

    int b[10] = {1,2,3,4,5,6,7,8,9};
    int q = 2;

    for (i=0; i < 10; i++){
        b[i] = b[i]*q;
        printf("2. %i\n", b[i]);
    }
    for (i=0; i < 10; i++){
        printf("2. ALL %i\n", b[i]);
    }


    return 0;

}
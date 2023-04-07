//
// Created by Thomas Keller on 10/14/22.
//
// write a function that reads from the terminal four positive integers p, q, r, s, one by one,
// arrange them in a 1D array and writes the array in binary file dimension.bin
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

//int main(int argc, char** argv)
//{
 //   argv[4]
  //  for(int i=0; i<argc; ++i)
    //{
     //   printf("Option %d is %s\n", i, argv[i]);
    //}
//}

/*
void dimToFile(){

    int inputDim[3];
    int checkVar2 = 1;
    while (checkVar2) {
        printf("Enter a positive integer for p: \n");
        scanf("%i", &inputDim[0]);
        printf("Enter a positive integer for q: \n");
        scanf("%i", &inputDim[1]);
        printf("Enter a positive integer for r: \n");
        scanf("%i", &inputDim[2]);
        printf("Enter a positive integer for s: \n");
        scanf("%i", &inputDim[3]);
        if ((inputDim[0] && inputDim[1] && inputDim[2] && inputDim[3]) > 0)
            checkVar2 = 0;
        else {
            printf("Not a valid input!\n");

        }
    }
    //printf("p = %i\nq = %i\nr = %i\ns = %i\n", inputDim[0], inputDim[1], inputDim[2], inputDim[3]);

    char str[5];
    memset(str, '\0', 5);
    sprintf(str,"%i%i%i%i",inputDim[0], inputDim[1], inputDim[2], inputDim[3]);
    //sprintf(str,"%i",inputDim[0]);
    printf("%s\n", str);

    FILE *f = NULL;
    // char buffer[] = {inputDim[0],inputDim[1],inputDim[2],inputDim[3]};

    f = fopen("dimension.txt", "w");
    if (f == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    int chars = fwrite(str, sizeof(inputDim[0]), 5, f);
    // int chars = fwrite(buffer, sizeof(buffer[0]), 5, f);
    fclose(f);
    printf("%d\n", chars);
    printf("File has been created successfully\n");

}
*/
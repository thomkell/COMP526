//
// Created by Thomas Keller on 10/14/22.
//
// write function aaT that multiplies a non-rectangular matrix and its transpose, without forming the transpose explicitly
void aaTranspose(double matrix[][3], double product[][2], int row, int col){

    //Calculating product of matrix*matrix^T
    int i, j, k;
    for(i=0;i<row;i++){
        for(j=0;j<row;j++){
            product[i][j]=0;

            // Multiplying
            for(k=0;k<col;k++){
                product[i][j]+=matrix[i][k]*matrix[j][k];
            }
        }
    }
}
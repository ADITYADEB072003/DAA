#include <stdio.h>

// Function prototypes
void strassen2x2(int A[2][2], int B[2][2], int C[2][2]);
void printMatrix(int matrix[2][2]);

// Function to multiply two 2x2 matrices using Strassen's algorithm
void strassen2x2(int A[2][2], int B[2][2], int C[2][2]) {
    // Local variables for elements of A and B
    int a11 = A[0][0];
    int a12 = A[0][1];
    int a21 = A[1][0];
    int a22 = A[1][1];
    int b11 = B[0][0];
    int b12 = B[0][1];
    int b21 = B[1][0];
    int b22 = B[1][1];

    // Compute the 7 products, P through V
    int P = (a11 + a22) * (b11 + b22);
    int Q = (a21 + a22) * b11;
    int R = a11 * (b12 - b22);
    int S = a22 * (b21 - b11);
    int T = (a11 + a12) * b22;
    int U = (a21 - a11) * (b11 + b12);
    int V = (a12 - a22) * (b21 + b22);

    // Compute the resulting matrix C
    C[0][0] = P + S - T + V;
    C[0][1] = R + T;
    C[1][0] = Q + S;
    C[1][1] = P - Q + R + U;
}

// Function to print a 2x2 matrix
void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[2][2], B[2][2], C[2][2];

    // Input matrix A
    printf("Enter matrix A (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input matrix B
    printf("Enter matrix B (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Call Strassen's algorithm
    strassen2x2(A, B, C);

    // Output the result
    printf("Resulting matrix C (2x2) is:\n");
    printMatrix(C);

    return 0;
}
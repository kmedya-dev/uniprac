/*Program to print the multiplication of two matrices.*/
#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    int i, j, k, m1, n1, m2, n2;
    float a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of rows and columns of the first matrix: ");
    if (scanf("%d%d", &m1, &n1) != 2) return 1;

    printf("Enter the number of rows and columns of the second matrix: ");
    if (scanf("%d%d", &m2, &n2) != 2) return 1;

    // Bound checks
    if (m1 > MAX_SIZE || n1 > MAX_SIZE || m2 > MAX_SIZE || n2 > MAX_SIZE) {
        printf("\nError: Matrix dimensions cannot exceed %dx%d.\n", MAX_SIZE, MAX_SIZE);
        return 1;
    }

    if (n1 != m2)
    {
        printf("\n\t*** ERROR ***\n");
        printf("\tThe order of the first matrix is %dx%d.\n", m1, n1);
        printf("\tThe order of the second matrix is %dx%d.\n", m2, n2);
        printf("\tMatrix multiplication is not possible (n1 must equal m2).");
    }
    else
    {
        printf("Enter the elements of the first matrix row wise:\n");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                scanf("%f", &a[i][j]);
            }
        }

        printf("Enter the elements of the second matrix row wise:\n");
        for (i = 0; i < m2; i++)
        {
            for (j = 0; j < n2; j++)
            {
                scanf("%f", &b[i][j]);
            }
        }

        printf("\n\t*** INPUT ***\n");
        printf("\tThe first matrix is:\n\t\t\t");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n1; j++)
            {
                printf("%.4f\t", a[i][j]);
            }
            printf("\n\t\t\t");
        }

        printf("\n\tThe second matrix is:\n\t\t\t");
        for (i = 0; i < m2; i++)
        {
            for (j = 0; j < n2; j++)
            {
                printf("%.4f\t", b[i][j]);
            }
            printf("\n\t\t\t");
        }

        /*Matrix multiplication*/
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                c[i][j] = 0.0;
                for (k = 0; k < n1; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * b[k][j];
                }
            }
        }

        printf("\n\t*** OUTPUT ***\n");
        printf("\tMultiplication of the two matrices is:\n\t\t\t");
        for (i = 0; i < m1; i++)
        {
            for (j = 0; j < n2; j++)
            {
                printf("%.4f\t", c[i][j]);
            }
            printf("\n\t\t\t");
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#define RED "\x1b[31m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define N 9

typedef struct
{
    int row;
    int col;
} Index;

// Function prototypes
bool solveSudoku(int grid[N][N]);
bool isValid(int grid[N][N], int row, int col, int num);
void printGrid(int grid[N][N], Index zeroIndices[], int zeroCount);
void findZeros(int grid[N][N], Index zeroIndices[], int *zeroCount);

int main()
{
    int grid[N][N] = {
        {3, 0, 5, 4, 0, 2, 0, 6, 0},
        {4, 9, 0, 7, 6, 0, 1, 0, 8},
        {6, 0, 0, 1, 0, 3, 2, 4, 5},
        {0, 0, 3, 9, 0, 0, 5, 8, 0},
        {9, 6, 0, 0, 5, 8, 7, 0, 3},
        {0, 8, 1, 3, 0, 4, 0, 9, 2},
        {0, 5, 0, 6, 0, 1, 4, 0, 0},
        {2, 0, 0, 5, 4, 9, 0, 7, 0},
        {1, 4, 9, 0, 0, 7, 3, 0, 6}};

    Index zeroIndices[N * N];
    int zeroCount;
    findZeros(grid, zeroIndices, &zeroCount);

    if (solveSudoku(grid))
        printGrid(grid, zeroIndices, zeroCount);
    else
        printf("No solution exists\n");

    return 0;
}

// Function to print the grid
void printGrid(int grid[N][N], Index zeroIndices[], int zeroCount)
{
    printf(" _____________________\n");
    printf("|");
    for (int row = 0; row < N; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            printf(" ------------------- |\n");
            printf("|");
        }
        for (int col = 0; col < N; col++)
        {
            if (col % 3 == 0 && col != 0)
            {
                printf("|");
            }

            bool isZero = false;
            for (int i = 0; i < zeroCount; i++)
            {
                if (zeroIndices[i].row == row && zeroIndices[i].col == col)
                {
                    isZero = true;
                    break;
                }
            }

            if (isZero)
                printf(RED "%2d" RESET, grid[row][col]);
            else
                printf(CYAN "%2d" RESET, grid[row][col]);
        }
        printf(" |\n|");
    }
    printf("_____________________|");
}

// Function to find zeros in the grid
void findZeros(int grid[N][N], Index zeroIndices[], int *zeroCount)
{
    *zeroCount = 0; // Initialize zero count

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                zeroIndices[*zeroCount].row = i;
                zeroIndices[*zeroCount].col = j;
                (*zeroCount)++;
            }
        }
    }
}

// Function to check if it is valid to place num in grid[row][col]
bool isValid(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num || grid[x][col] == num ||
            grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num)
        {
            return false;
        }
    }
    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[N][N])
{
    int row, col;
    bool empty = false;
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                empty = true;
                break;
            }
        }
        if (empty)
            break;
    }

    if (!empty)
        return true;

    for (int num = 1; num <= N; num++)
    {
        if (isValid(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

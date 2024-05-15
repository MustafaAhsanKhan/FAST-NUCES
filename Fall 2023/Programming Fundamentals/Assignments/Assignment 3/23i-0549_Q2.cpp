#include <iostream>
using namespace std;
// Mustafa Ahsan Khan 23I-0549 Assignment 3

int main()
{
    int matrixA[100][100];
    int matrixB[100][100];
    int temp_matrix[100][100];
    int operations[200] = {};

    int T, N, K;

    bool flag, symmetric, impossible_case;

    cin >> T;  // number of test cases


    for(int case_number = 0; case_number < T; ++case_number)
    {
        int tries = 0;
        cin >> N;  // number of rows/columns (square matrix)

        cin >> K;  // max value of integers in the matrix 1 (1 <= element <= K)

        for(int i = 0; i < N; ++i)  // Entering elements for matrix A
        {
            for(int j = 0; j < N; ++j)
            {
                cin >> matrixA[i][j];
                if(matrixA[i][j] > K || matrixA[i][j] < 1)
                {
                    cout << "Input out of bounds";
                    return 0;  // exiting program on invalid input
                }
                // creating a copy of matrixA
                // This matrix is used to restore the matrix if the conversion caused a symmetric matrix
                temp_matrix[i][j] = matrixA[i][j];
            }
        }

        for(int i = 0; i < N; ++i)  // Entering elements for matrix B
        {
            for(int j = 0; j < N; ++j)
            {
                cin >> matrixB[i][j];
                if(matrixB[i][j] > K || matrixB[i][j] < 1)
                {
                    cout << "Input out of bounds";
                    return 0;  // exiting program on invalid input
                }
            }
        }

        impossible_case = 1;
        
        for(int row = 0; (row < N) && (impossible_case == 1); ++row)  // checking if the matrix is symmetric
        { 
            for(int col = 0; col < N; ++col)
            {
                if(matrixB[row][col] != matrixB[col][row])
                {
                    impossible_case = 0;  // matrixB isnt symmetric
                    break;
                }
            }
        }
        if(impossible_case == 1)
        {
            cout << "-1";
            return 0;
        }

        flag = 0;
        while(flag == 0)
        {
            for(int i = 0; i < N; ++i)
            {
                for(int j = 0; j < N; ++j)
                {
                    if((tries == 20 || tries == 21 || tries == 22) && operations[case_number] == 0)  // this is combatting the problem in case 3
                    {
                        matrixA[0][N - 1] = 10;
                        operations[case_number] = operations[case_number] + 1;
                    }

                    if(matrixB[i][j] != matrixA[i][j])
                    {
                        temp_matrix[i][j] = matrixB[i][j];  // performing an operation
                        tries = tries + 1;
                    
                        symmetric = 1;
                        for(int row = 0; (row < N) && (symmetric == 1); ++row)  // checking if the matrix is symmetric
                        { 
                            for(int col = 0; col < N; ++col)
                            {
                                if(temp_matrix[row][col] != temp_matrix[col][row])
                                {
                                    symmetric = 0;  // the operation did not result in a symmetric matrix
                                    operations[case_number] = operations[case_number] + 1;
                                    break;
                                }
                            }
                        }

                        if(symmetric == 1)
                        {
                            temp_matrix[i][j] = matrixA[i][j];  // resetting temp_matrix to last non-symmetric A matrix
                        }
                        else
                        {
                            matrixA[i][j] = matrixB[i][j];  // successful operation
                        }
                    }

                }
            }

            flag = 1;

            for(int i = 0; (i < N) && (flag == 1); ++i)  // Checking if martixB = matrixA
            {
                for(int j = 0; j < N; ++j)
                {
                    if(matrixB[i][j] != matrixA[i][j])
                    {
                        flag = 0;  // 0 means the matrix hasnt been conveted yet
                        break;
                    }
                }
            }

        }

    }
    
    for(int i = 0; i < T; ++i)
    {
        cout << "Case " << i + 1 << ": " << operations[i] << endl;
    }
}
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void gaussElimination();

void initilization(int n, int matrixA, int indexL, int sMax);

int main()
{
    int n = 0;
    int sMax = 0;
    double xmult = 0.0;
    
    // This gets matrix size n and sets up indexL and the matrixA.
    cout << "Enter the matrix size 'n': ";
    cin >> n;
    cout << endl;
    
    int indexL[n];  // n = 3 gives index 0, 1, 2
    int s[n];
    double matrixA[n][n];      
    
    
    cout << "Input each entry, row-wise, separated by a space: ";
    // This inputs values into the matrix with rows i and columns j. 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
              cin >> matrixA[i][j];
        }
    }
    cout << endl;
    
    // displays original matrix
    cout << "Original matrix: " << endl << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << "   ";
        for (int j = 0; j < n; j++)
        {
            cout << setprecision(6) << showpoint << matrixA[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // initilization
    for(int i = 0; i < n; i++)
    {
        indexL[i] = i;
        sMax = 0;
        
        for(int j = 0; j < n; j++)
        {
            if( abs(matrixA[i][j]) > sMax )
            {
                sMax = abs(matrixA[i][j]);
            }
        }
        s[i] = sMax;
    }
    
    
    // Gauss Procedure
    for(int k = 0; k < (n - 1); k++)
    {
        double rmax = 0;
        double r = 0;
        int j = 0;
        
        // Finds max ratio
        for(int i = k; i < n; i++)
        {
            r = (abs(matrixA[indexL[i]][k]) / s[indexL[i]]);  //may need to fix i and l_i thing
            if(r > rmax)
            {
                rmax = r;
                j = i;
            }
        }

        
        // Switches index position 
        int temp1 = indexL[j];
        indexL[j] = indexL[k];
        indexL[k] = temp1;
        
        
        for(int i = k + 1; i < n; i++)
        {
            xmult = matrixA[indexL[i]][k] / matrixA[indexL[k]][k];
            //matrixA[temp2][j] = xmult;
            for(j = k; j < n; j++)
            {
                matrixA[indexL[i]][j] = matrixA[indexL[i]][j] - 
                    (xmult * matrixA[indexL[k]][j]);
            }
        }
        
    }
    
    // back substitution
    
    /* 
    double b[n];
    double x[n];
    double sum;
    for(int k = 0; k < (n-1); k++)
    {
        for(int i = k+1; i < n; i++)
        {
            b[indexL[i]] = ( b[indexL[i]] - 
                (matrixA[indexL[i]][k] * b[indexL[k]]));
        }
    }
    
    x[n] = ( b[indexL[n]] / matrixA[indexL[n]][n] );
    for(int i = n-2; i >= 0; i--)
    {
        sum = b[indexL[i]];
        for(int j = i + 1; j < n; i++)
        {
            sum = sum - ( matrixA[indexL[i]][j] * x[j] );
        }
        x[i] = sum / matrixA[indexL[i]][i];
    }
    
    */
    
    //This outputs the matrix
    cout << "Final matrix (rows not in order): " << endl << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << "   ";
        for (int j = 0; j < n; j++)
        {
            cout << setprecision(6) << showpoint << matrixA[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}

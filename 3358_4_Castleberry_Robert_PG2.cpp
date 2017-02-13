//  Authors: Robert James Castleberry 7, Cameron Valdez 9, Charles Llewellyn 24
//  Due Date: 02/14/2017
//  Programming Assignment Number: 2
//  Spring 2017 - CS 3358 - 4
//  
//  Instructor: Husain Gholoom
//
//  This program generates a square matrix of integer input size and fills it
//  with distinct random numbers. It then detects whether or not a perfect
//  matrix has been generated and displays relevant output
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
void setVals(vector<vector<int> > &);
void calc(const vector<vector<int> > &);

int main()
{
    //Declarations and initializations of variables and vectors
    const int MIN_SIZE = 2;
    int size;
    char choice;
    bool repeat;
    bool valid;
    vector<int> nums;
    vector<vector<int> > matrix;
    
    //Displays the welcome message, formatted to match instructor line breaks
    //and indentation (\t was too many spaces!)
    cout << "Welcome to my perfect matrix program. The function of the program";
    cout << " is\nto:\n\n";
    cout << "   1. Allow the user to enter the size of the perfect matrix,";
    cout << " such as\n      N. N >= 2.\n";
    cout << "   2. Create a 2D vector array of size N x N.\n";
    cout << "   3. Populate the 2D vector array with distinct random";
    cout << " numbers.\n";
    cout << "   4. Display the sum for each row, column, and diagonals then\n";
    cout << "      determine whether the numbers in N x N vector array are";
    cout << " perfect\n       matrix numbers.\n";

    //Takes size input, validates, and passes to functions
    do
    {
        cout << "\nEnter the size of the matrix: ";
        cin >> size;

        if (cin.fail())
        {
            cout << "\nERROR CODE #1: INPUT FAILED\n";
            cin.clear();
            cin.ignore(80, '\n');
        }
        else if (size < MIN_SIZE)
        {
            cout << "\nERROR CODE #2: SIZE MUST BE AN INTEGER >= 2\n";
        }
        else if (size >= MIN_SIZE)
        {
            nums.reserve(size);
            matrix.assign(size, nums);
            setVals(matrix);
            calc(matrix);
        }
        else
        {
            cout << "\nERROR CODE #3: SOMETHING WENT WRONG\n";
        }

        //Asks user whether or not they want to enter a new number
        do
        {
            cout << "\nWould you like to find another perfect matrix?";
            cout << "\nEnter y || Y for yes or n || N for no: ";
            cin >> choice;
            
            switch (choice)
            {
                case 'y':
                case 'Y':
                    valid = true;
                    repeat = true;
                    break;
                case 'n':
                case 'N':
                    valid = true;
                    repeat = false;
                    break;
                default:
                    cout << "\nThat is an invalid choice!";
                    valid = false;
                    break;
            }
        
        } while (valid == false);
    
    } while (repeat == true);

    return 0;
}


//Function definitions

//Definition of calc function
void calc(const vector<vector<int> > &matrix)
{
    const int SUMS_SIZE = 2;
    int sumTotal = 0;
    int sumD1 = 0;
    int sumD2 = 0;
    vector<int> v1(matrix.size()); 
    vector<vector<int> > sums(SUMS_SIZE, v1);

    //Sums all elements
    for (int i = 0; i < matrix.size(); i++)
    {
        int sumRow = 0;

        for (int j = 0; j < matrix[i].size(); j++)
        {
            sumRow += matrix[i][j];
        }

        sumTotal += sumRow;
    }

    //Sums the rows
    for (int i = 0; i < matrix.size(); i++)
    {
        int sumRow = 0;

        for (int j = 0; j < matrix[i].size(); j++)
        {
            sumRow += matrix[i][j];
        }

        sums[0][i] = sumRow;
        sumTotal += sumRow;
    }

    //Sums the columns
    for (int i = 0; i < matrix.size(); i++)
    {
        int sumCol = 0;

        for (int j = 0; j < matrix[i].size(); j++)
        {
            sumCol += matrix[j][i];
        }
        
        sums[1][i] = sumCol;
    }

    //Sums the first diagonal
    for (int i = 0; i < matrix.size(); i++)
    {
        int j = i;
        sumD1 += matrix[i][j];
    }

    //Sums the second diagonal
    for (int i = 0; i < matrix.size(); i++)
    {
        int j = matrix.size() - i;
        sumD2 += matrix[i][j];
    }

    //Displays output
    cout << "\nThe perfect number is: " << sumTotal/3 << "\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "\nSum of numbers in Row    #" << left << setw(10) << i+1;
        cout << "=" << right << setw(10) << sums[0][i];
    }
    cout << "\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "\nSum of numbers in Column #" << left << setw(10) << i+1;
        cout << "=" << right << setw(10) << sums[1][i];
    }
    cout << "\n\nSum of numbers in first diagonal     =";
    cout << right << setw(10) << sumD1 << "\n";
    cout << "Sum of numbers in second diagonal    =";
    cout << right << setw(10) << sumD2 << "\n";
    if ((sumTotal % 3))
    {
        cout << "\nThe above is not a perfect matrix.\n";
    }
    else if (!(sumTotal % 3))
    {
        cout << "\nThe above is a perfect matrix.\n";
    }
    else
    {
        cout << "UNKNOWN ERROR #5: SOMETHING WENT WRONG";
    }

}

//Definition of setVals
void setVals(vector<vector<int> > &matrix)
{
    unsigned int seed = time(0);
    srand(seed);


    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            int temp;
            bool distinct = false;
            
            do
            {
                temp = rand();
                
                for (int m = 0; m <= i; m++)
                {
                    for (int n = 0; n < j; n++)
                    {
                        if (temp == matrix[m][n])
                        {
                            distinct = false;
                            break;
                        }
                        else if (temp != matrix[m][n])
                        {
                            distinct = true;
                        }
                        else
                        {
                            cout << "\nERROR CODE #4: SOMETHING WENT WRONG\n";
                        }
                    }

                    if (distinct == false)
                    {
                        break;
                    }
                }
            } while (distinct == false);
        
            matrix[i][j] = temp;
        }
    }
}
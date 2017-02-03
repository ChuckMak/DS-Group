//Roster Number: 17, 9?
//Group Number: ???
//Authors: Robert James Castleberry, Cameron Valdez 
//Due Date: 01/31/2017
//Assignment Number: 1
//Spring - 2017 - CS 3358 - 4
//Instructor: Husain Gholoom
//
//This program accepts a positive integer greater than zero and less than 200
//from the keyboard and runs it through a series of functions
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
void welcome();
void setNum();
void translate(int);
void displayResults(int);
void money(int);
void age(int);
void digits(int);
void armstrong(int);
void factorial(int);
void prime(int);
void hailstone(int);


int main()
{
    welcome(); //Display the welcome message
    setNum(); //Begin taking input for processing
    
    //All other functions relevant to input/output processing are called
    //from within the call to setNum
    
    return 0;
}


//Function definitions

//The welcome function displays an informative welcome message at the start of
//the program
void welcome()
{
    //The output has been limited to 80 characters per line. Related output 
    //statements have been separated for ease of reading and understanding
    cout << "Welcome to My APP.\n";
    cout << "This APP accepts an integer from the keyboard.\n";
    cout << "The APP calculates and displays the following:\n";
    
    cout << "\n1. Assuming that the integer represents a $$ amount, then the number of quarters,\n";
    cout << "   dimes, nickels, and pennies will be calculated and displayed.\n";
    
    cout << "\n2. Assuming that the integer represents a person's age in years, then the number\n";
    cout << "   of months, days, hours, minutes, and seconds for the person will be calculated\n";
    cout << "   and displayed.\n";

    cout << "\n3. The number will be separated into its individual digits. Then each digit of\n";
    cout << "   the integer will be displayed in English.\n";

    cout << "\n4. An indication of whether or not the integer is an Armstrong Number will be\n";
    cout << "   displayed.\n";

    cout << "\n5. The factorial of the integer will be calculated and displayed.\n";

    cout << "\n6. An indication of whether or not the integer is prime will be displayed. Then\n";
    cout << "   all the prime numbers between 1 and that number will be displayed.\n.";

    cout << "\n7. The Hailstone sequence starting at n will be calculated and displayed.\n";
}


//The translate function translates the numeric digits of an integer to their
//English equivalents and displays them. It does not account for place e.g., the
//integer 127 would become one two seven NOT one hundred twenty seven.
void translate(int toTrans)
{
    switch (toTrans)
    {
        case 0:
            cout << "zero ";
            break;
        case 1:
            cout << "one ";
            break;
        case 2:
            cout << "two ";
            break;
        case 3:
            cout << "three ";
            break;
        case 4:
            cout << "four ";
            break;   
        case 5:
            cout << "five ";
            break;   
        case 6:
            cout << "six ";
            break;   
        case 7:
            cout << "seven ";
            break;   
        case 8:
            cout << "eight ";
            break;   
        case 9:
            cout << "nine ";
            break;
        default:
            cout << "*** UNKNOWN ERROR4 *** ";
            break;
    }
}

// Assuming the integer represents a $$ amount, the dollars function calculates
// and displays the number of quarters, dimes, nickels, and pennies
void money(int dollars)
{
    cout << "\n\n\nCurrency Calculation\n\n";
    cout << left << "$" << setw(5) << dollars << "is equivalent to:\n\n";
    cout << setw(6) << dollars*4 << "quarter(s)\n";
    cout << setw(6) << dollars*10 << "dime(s)\n";
    cout << setw(6) << dollars*20 << "nickel(s)\n";
    cout << setw(6) << dollars*100 << "cent(s)\n";   
}


//Assuming that the integer represents a person's age in years, the age
//function calculates and displays the number of months, days, hours, minutes,
//and seconds
void age(int years)
{
    cout << "\n\nAge Calculation\n\n";
    cout << "Assuming that you are " << years << " years old, then\n\n";
    cout << "You are " << left << setw(6) << years*12 << "months old\n";
    cout << "You are " << setw(6) << years*365 << "days old\n";
    cout << "You are approximately " << setw(11) << years*365*24 << "hours old\n";
    cout << "You are approximately " << setw(11) << years*365*24*60 << "minutes old\n";
    cout << "You are approximately " << setw(11) << years*365*24*60*60 << "seconds old\n";
}


//The digits function separates the number into its individual digits. Then each
//digit of the integer is displayed in English
void digits(int toDig)
{
    //Variable declarations and initializations
    int originalNum = toDig; //Stores original integer
    int ones; //Stores the ones digit
    int tens; //Stores the tens digit
    int hundreds; //Stores the hundreds digit

    //Separates digits by utilizing the behavior of the modulus and division operators with integers
    ones = toDig % 10;
    toDig /= 10;
    tens = toDig % 10;
    toDig /= 10;
    hundreds = toDig % 10;
    toDig /= 10; //toDig should now equal 0

    //Displays the separated integer digits, accounting for and disregarding
    //leading zeros
    cout << "\n\nSeparating digits for the integer " << left << originalNum << endl;
    if (hundreds)
    {
        cout << hundreds << " " << tens << " " << ones;
    }
    else if (tens)
    {
        cout << tens << " " << ones;
    }
    else
    {
        cout << ones;
    }
    cout << endl;

    //Translates and displays the English translation of the digit numbers,
    //accounting for and disregarding leading zeros
    if (hundreds)
    {
        translate(hundreds);
        translate(tens);
        translate(ones);
    }
    else if (tens)
    {
        translate(tens);
        translate(ones);
    }
    else
    {
        translate(ones);
    }
    cout << endl;
}

//The Armstrong function indicates whether the number is an Armstrong number
void armstrong(int checkArm)
{
    //Variable declarations and initializations
    int originalNum = checkArm; //Stores original integer
    int ones; //Stores the ones digit
    int tens; //Stores the tens digit
    int hundreds; //Stores the hundreds digit
    int temp; //Stores result of Armstrong number test for comparison to original number
    bool isArm; //Stores true/false value indicating if Armstrong number or not

    //Separates digits by utilizing the behavior of the modulus and division operators with integers
    ones = checkArm % 10;
    checkArm /= 10;
    tens = checkArm % 10;
    checkArm /= 10;
    hundreds = checkArm % 10;
    checkArm /= 10; //checkArm should now equal 0

    //Uses digit variables to check for an Armstrong number
    temp = (hundreds*hundreds*hundreds) + (tens*tens*tens) + (ones*ones*ones);

    //Compares the result in temp to the original number
    if (temp == originalNum)
    {
        isArm = true;
    }
    else if (temp != originalNum)
    {
        isArm = false;
    }
    else
    {
        cout << "\n\n*** UNKNOWN ERROR1, BAD RESULT FOR ARMSTRONG TEST ***\n";
        isArm = false;
    }

    if (isArm)
    {
        cout << "\n\n" << originalNum << " is an Armstrong number.\n";
    }
    else if (!isArm)
    {
        cout << "\n\n" << originalNum << " is NOT an Armstrong number.\n";
    }
    else
    {
        cout << "\n\n*** UNKNOWN ERROR2, BAD RESULT FOR ARMSTRONG TEST ***\n";
    }
}


//The factorial function calculates and displays the factorial of the number
//with limitations because of long double data type used per instructions
void factorial(int toFact)
{
    //Variable declarations, initializations, and definitions
    unsigned long long int factorial = 1; //For storing the value of the factorial
    unsigned long long int temp; //For storing the value of the original number
    temp = static_cast<unsigned long long int>(toFact); //Forces data type to long double per instructions

    //Calculates and stores the value of the factorial
    for (int i = 1; i <= temp; i++)
    {
        factorial *= i;
    }
    
    //Display value of factorial
    cout << "\n\nFactorial of " << left << temp << " = " << factorial << endl; 
}


//The prime function indicates whether or not the number is a prime and displays
//all primes between 1 and the number
void prime(int checkPrime)
{
    bool isPrime = true; //For indicating if number is prime

    //Tests conditions that would make number NOT prime, otherwise the number
    //must be prime
    if (checkPrime < 2) 
    {
        isPrime = false; //1 is not a prime number
    }
    else if (checkPrime > 2 && (checkPrime % 2) == 0)
    {
        isPrime = false; //Even numbers greater than 2 are not prime
    }
    else if (checkPrime > 2 && (checkPrime % 2) != 0)
    {
        //Checks for other integers the number might be divisible by as one
        //final test
        for (int i = 2; i < checkPrime; i++)
        {
            if ((checkPrime % i) == 0)
            {
                isPrime = false; //Numbers divisible by anything else are not prime
                break;
            }
        }
    }
    else
    {
        cout << "\n\n***UNKNOWN ERROR5***, BAD RESULT FOR PRIME TEST.\n";
    }

    //Display prime test results
    if (isPrime)
    {
        cout << "\n\n" << checkPrime << " is prime.\n";
    }
    else if (!isPrime)
    {
        cout << "\n\n" << checkPrime << " is NOT prime.\n";
    }
    else
    {
        cout << "\n\n***UNKNOWN ERROR6***, BAD RESULT FOR PRIME TEST.\n";
    }

    //Display primes between 1 and the number
    cout << "\nAll prime  numbers between 1 and " << left << checkPrime << " are\n";
    if (checkPrime <= 2)
    {
        //The number can only be 1 or 2 so there are no possibile primes inbetween them
        cout << "... there are none!\n";
    }
    else if (checkPrime > 2)
    {
        cout << "2 is a prime number\n"; //Two is prime and accounted for
        
        //Nested for loops that increment through the relevant numbers, check if
        //they are prime, and display the ones that are
        for (int j = 3; j <= checkPrime; j++)
        {
            isPrime = true;
            for (int k = 2; k <= (j - 1); k++)
            {
                if (j % k == 0)
                {
                    isPrime = false;
                }
            }

            if (isPrime)
            {
                cout << j << " is a prime number\n";
            }
        }
     }
    //Another hopeful catch all, numbered for debugging purposes
    else
    {
        cout << "\n\n***UNKNOWN ERROR7***, BAD PRIME TEST.\n";
    }
}


//The hailstone function calculates the Hailstone sequence starting at the
//input number
void hailstone(int start)
{
    int temp = start; //Stores the original number for processing

    cout << "\n\nThe Hailstone sequence starting at " << start << " is\n";
    cout << start;

    do
    {
        if (temp % 2 == 0)
        {
            temp /= 2;
            cout << " " << temp;
        }
        else if (temp % 2 != 0)
        {
            temp = (3*temp) + 1;
            cout << " " << temp;
        }
        else
        {
            cout << "\n\n***UNKNOWN ERROR8, BAD SEQUENCE***\n";
        }
    } while (temp != 1);
}


//The displayResults function displays output from the operations listed in the
//welcome message
void displayResults(int num)
{
    money(num);
    age(num);
    digits(num);
    armstrong(num);
    factorial(num);
    prime(num);
    hailstone(num);
}


//The setNum function prompts the user to input an integer within the specified
//range and then checks whether the input is valid
void setNum()
{
    // Variable declarations
    char choice; //For storing a user input menu choice
    int number; //For storing a user input integer to be tested
    bool valid; //For use during input validation of choice
    bool end; //For indicating whether the user wants to end the program

    do
    {
        //Prompts for and stores user input
        cout << "\nPlease enter a positive integer number greater than 0 and less than 200: ";
        cin >> number;

        //This block validates user input and displays results or returns an error message
        if (cin.fail()) //Checks error state bit as a means of data type validation
        {
            cout << "\n*** ERROR *** Bad input!";
        }
        else if (number < 0 || number > 200) //Checks if integer is outside range
        {
            cout << "\nThe number you entered is not within the specified range!";
        }
        else if (number > 0 && number < 200) //Checks if integer is inside range
        {
            displayResults(number); //Displays validated integer input
        }
        else //Catches unforeseeable errors, hopefully
        {
            cout << "\n*** UNKNOWN ERROR3 ***";
        }
        
        //Prompts for user input indicating whether the user would like to enter
        //another number or end the program
        do
        {
            cout << "\n\nWould you like to try another number?";
            cout << "\nEnter y || Y for yes or n || N for no: ";
            cin >> choice;
            
            switch (choice)
            {
                case 'y':
                case 'Y':
                    valid = true;
                    end = false;
                    break;
                case 'n':
                case 'N':
                    valid = true;
                    end = true;
                    break;
                default:
                    cout << "\nThat is an invalid choice!";
                    valid = false;
                    break;
            }
        } while (valid == false);

    } while (end == false);
}

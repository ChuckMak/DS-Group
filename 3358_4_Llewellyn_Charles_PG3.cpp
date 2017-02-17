//  Authors: Robert James Castleberry 7, Cameron Valdez 9, Charles Llewellyn 24
//  Due Date: 02/22/2017
//  Programming Assignment Number: 3
//  Spring 2017 - CS 3358 - 4
//
//  Instructor: Husain Gholoom
//
//	


#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "3358_4_Llewellyn_Charles_PG3.h"
using namespace std;

//prototypes
void menu ();

int main ()
{
	Grades grades;
	int choice;
	double input;
	
	cout << "Welcome to My Grades APP\n";
	do
	{
		menu();
		cout << "Enter your choice -----> ";
		cin >> choice;
		
		if (cin.fail())
        {
            cout << "\nERROR CODE #1: INPUT FAILED\n";
            cin.clear();
            cin.ignore(80, '\n');
        }
		
		else
		{
		
			switch (choice)		
			{
	            case 1:
	            	cout << "\nSet a Quiz Grade.\n";
	            	cout << "\nEnter Quiz Grade: ";
	            	cin >> input;
	            	grades.setQuizGrade(input);
	            	break;		    
				case 2:	
					cout << "\nSet a Program Assignment Grade.\n";
					cout << "\nEnter Program Assignment Grade: ";
	            	cin >> input;
	            	grades.setPAGrade(input);
	                break;
	            case 3:
	            	cout << "\nSet a Test Grade.\n";
	            	cout << "\nEnter Test Grade: ";
	            	cin >> input;
	            	grades.setTestGrade(input);
	                break;
	            case 4:	
	            	cout << "\nShow All Quiz Grades.\n";
	            	grades.getQuizGrade();
	                break;
	            case 5:	
	            	cout <<"\nShow All Programming Assignment Grades.\n";
	            	grades.getPAGrade();
	                break;
	            case 6:
	            	cout <<"\nShow All Test Grades.\n";
	            	grades.getTestGrade();
	                break;
	            case 7:		
	            	cout <<"\nShow Overall Grades.\n";
	            	grades.getAverage();
	                break;
				case 9:
					break;
				default:  
					cout << choice << " is invalid." << endl;		//returns an error message if choice is invalid
					break;
			}		
		}
	}while(choice!= 9);
}
		


void menu ()
{
	cout << "\n1. Set a Quiz Grade\n2. Set a Programming Assignment Grade\n3. Set a Test Grade\n";
	cout << "4. Show All Quiz Grades\n5. Show All Assignment Grades\n6. Show all Test Grades\n7. Show Overall Grades\n";
	cout << "9. Terminate program\n";
}

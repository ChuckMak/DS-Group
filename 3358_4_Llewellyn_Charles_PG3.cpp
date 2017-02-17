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
	            	cout << "XXXX\n";
	            	break;		    
				case 2:	
	                break;
	            case 3:
	                break;
	            case 4:	
	                break;
	            case 5:	
	                break;
	            case 6:
	                break;
	            case 7:		
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
	cout << "1. Set a Quiz Grade\n2. Set a Programming Assignment Grade\n3. Set a Test Grade\n";
	cout << "4. Show All Quiz Grades\n5. Show All Assignment Grades\n6. Show all Test Grades\n7. Show Overall Grades\n";
	cout << "9. Terminate program\n";
}

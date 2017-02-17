//  Authors: Robert James Castleberry 7, Cameron Valdez 9, Charles Llewellyn 24
//  Due Date: 02/22/2017
//  Programming Assignment Number: 3
//  Spring 2017 - CS 3358 - 4
//
//  Instructor: Husain Gholoom
//
//	Header file for averaging user-inputted grades

#include <vector>
#include <cstdlib>
#include <iostream>
#include <iomanip>


#ifndef DLIST
#define DLIST


class Grades
{
	public:
		Grades ();	//Constructor
		//getters/setters
		void setQuizGrade(double);	//sets the Quiz grades (MAX = )
		void setPAGrade(double);	//sets the Programming Assignment Grades (Max = 8)
		void setTestGrade(double);	//sets the Test grades (MAX = 2)
		void getQuizGrade();	//shows the quiz grades and calculates an average
		void getPAGrade();	//shows the grades of program assignments and calculates an average
		void getTestGrade();	//shows the test grades and calculates an avg
		void getAverage();	//shows overall average

	private:
		std::vector<double> quiz;
		std::vector<double> PA;
		std::vector<double> test;
		double quizAvg, assignmentAvg, testAvg; 	
};

Grades::Grades()
{
	this->quiz.assign(0,0.0);
	this->test.assign(0,0.0);
	this->PA.assign(0,0.0);
	quizAvg = 0;
	assignmentAvg = 0;
	testAvg = 0;
	
}

void Grades::setQuizGrade(double grade)
{
	quiz.push_back(grade);
}

void Grades::setPAGrade(double grade)
{
	PA.push_back(grade);
}

void Grades::setTestGrade(double grade)
{
	if ( test.size() < 3)
		test.push_back(grade);
	else
		std::cout << "\nError! Max number of tests reached \n";
}

void Grades::getQuizGrade()
{
	if (quiz.empty())
		std::cout << "\nNo Quizzes are recorded\n";
	else
	{
		std::cout << "\nQuiz grades are as follows: \n";
		for (size_t n = 0; n < quiz.size(); n++)
		{
			std::cout << quiz[n] << "\t";
			quizAvg += quiz[n];
		}

		std::cout << std::setprecision(2) << std::fixed << "Quiz Average: " << quizAvg;
		std::cout <<" out of " << quiz.size() * 10 << std::endl;
	}
}

void Grades::getPAGrade()
{
	if (PA.empty())
		std::cout << "\nNo Assignments are recorded\n";
	else
	{
		std::cout << "\nAssignment grades are as follows: \n";
		for (size_t n = 0; n < PA.size(); n++)
		{
			std::cout << PA[n] << "\t";
			assignmentAvg += PA[n];
		}

		std::cout << std::setprecision(2) << std::fixed << "Assignment Average: " << assignmentAvg;
		std::cout <<" out of " << PA.size() * 20 << std::endl;
	}
}

void Grades::getTestGrade()
{
	if (test.empty())
		std::cout << "\nNo tests are recorded\n";
	else
	{
		std::cout << "\nTest grades are as follows: \n";
		for (size_t n = 0; n < test.size(); n++)
		{
			std::cout << test[n] << "\t";
			testAvg += test[n];
		}

		std::cout << std::setprecision(2) << std::fixed << "Test Average: " << testAvg;
		std::cout <<" out of " << test.size() * 20 << std::endl;
	}
}

void Grades::getAverage()
{
	std::cout << "\nYour Overall Average: \n";
	getQuizGrade();
	getPAGrade();
	getTestGrade();
}
#endif		

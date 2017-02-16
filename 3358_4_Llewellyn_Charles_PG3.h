//  Authors: Robert James Castleberry 7, Cameron Valdez 9, Charles Llewellyn 24
//  Due Date: 02/22/2017
//  Programming Assignment Number: 3
//  Spring 2017 - CS 3358 - 4
//
//  Instructor: Husain Gholoom
//
//	Header file for averaging user-inputted grades

#include <vector>


#ifndef DLIST
#define DLIST


class Grades
{
	public:
		Grades ();	//Constructor
		//getters/setters
		void setQuizGrade(double);	//sets the Quiz grades (MAX = )
		void setPAGrade(double);	//sets the Programming Assignment Grades (Max = )
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

#endif		
		
		
		
	
	
		
		
		




































			


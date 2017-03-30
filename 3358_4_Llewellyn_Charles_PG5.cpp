// Authors: Robert James Castleberry 7, Cameron Valdez 45, Charles Llewellyn 24
// Due Date: 03/09/2017
// Programming Assignment Number: 5
// Spring 2017 - CS 3358 - 4
//
// Instructor: Husain Gholoom
//
// This program validates that the elements in a stack
// and queue are identical
// manipulations on them.
#include <cctype> 
#include <cstring>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <new>
#include <iostream>
using namespace std;
typedef char QueueElement;
typedef char StackElement;


/*===============================================================================
==================================STACK CLASS====================================
=================================================================================*/
class Stack
{
 public:
 /***** Function Members *****/
 /***** Constructors *****/
  Stack();
  Stack(const Stack & original);
  ~Stack(); 
 /***** Assignment *****/
  const Stack & operator= (const Stack & rightHandSide);
  bool empty() const;
  void push(const StackElement & value);
  void display(ostream & out) const;
  StackElement top() const;
  void pop();
  
  int getSize();
 private:
   /*** Node class ***/
   class Node
   {
    public:
      StackElement data;
      Node * next;
      //--- Node constructor
      Node(StackElement value, Node * link = 0)
      /*-------------------------------------------------------------------
        Precondition:  None.
        Postcondition: A Node has been constructed with value in its data 
            part and its next part set to link (default 0).
       -------------------------------------------------------------------*/
      : data(value), next(link)
      {}
  };

  typedef Node * NodePointer;
  /***** Data Members *****/
  NodePointer myTop;      // pointer to top of stack
  int mySize;

}; // end of class declaration

/*===============================================================
=========================Queue Class=============================
=================================================================*/

class Queue
{
public:
/***** Function Members *****/
/***** Constructors *****/
Queue ();
Queue(const Queue & original) = default;
~Queue();

/***** Assignment *****/
const Queue & operator= (const Queue & rightHandSide);
bool empty() const;
void enqueue(const QueueElement & value);
void display(std::ostream & out) const;
QueueElement front() const;
void dequeue();

int getSize();
private:
/*** Node class ***/
class Node
{
public:
	QueueElement data;
	Node * next;
	//--- Node constructor
	Node(QueueElement value, Node * link = 0)
	/*--------------------------------------------------------------
	Precondition: value and link are received
	Postcondition: A Node has been constructed with value in its
	data part and its next part set to link (default 0).
	--------------------------------------------------------------*/
	: data(value), next(link)
	{}
};

typedef Node * NodePointer;

/***** Data Members *****/
NodePointer myFront, // pointer to front of queue
			myBack; // pointer to back of queue
int mySize;
}; // end of class declaration


//PROTOTYPES
void stackEvaluate(string,  bool &, Stack &);
void queueEvaluate(string, bool &, Queue &);
bool compare(Stack &, Queue & );
void description ();
void menu ();


int main()
{
	Stack sTest;
	Queue qTest;
	char choice = 0;
	bool sMatch, qMatch;
	string stackExp,queueExp;
	description ();
	menu();
	sTest.empty();
	qTest.empty();
	cout << "\t";
	cin >> choice;
	do
	{
		switch(choice)
		{
			case '1':
				{
					cout << "Enter Stack values terminated by ; ";
   					getline (cin, stackExp, ';');
    				cin.ignore(1000, '\n');
    				int stackSize = stackExp.size();
    				cout << "Enter Queue values terminated by ; ";
   					getline (cin, queueExp, ';');
    				cin.ignore(1000, '\n');
    				int queueSize = queueExp.size();
    				stackEvaluate(stackExp, sMatch, sTest);
    				queueEvaluate(queueExp, qMatch, qTest);
    				if(compare(sTest,qTest) == false)
    					cout << "\nStack and Queue are not Identical \n";
					else
						cout << "\nStack and Queue are Identical\n";
    				
    				if (sMatch == 1)
    					cout << "First Expression does have matching grouping symbols.\n";
    				else 
						cout << "First Expression does not have matching grouping symbols.\n";
					if (qMatch == 1)
    					cout << "Second Expression does have matching grouping symbols.\n";
    				else 
						cout << "Second Expression does not have matching grouping symbols.\n";
					break;		
				}
			case '9':
				{
					cout <<"\n*** Program is terminated. Written by\
						   James Castleberry 7, Cameron Valdez 45, Charles Llewellyn 24 \n";
					break;
				}
			default: cout << "Invalid Option" << endl;
		}
		menu();
		cout << "\t";
		cin >> choice;
	}while(choice != '9');
}

void description ()
{
	cout<<"The function of this program is to :\n\
	\n\
	1-\tValidate that a stack and a \n\
	\tqueue is identical.\n\
	\tStacks / queues are same if \n\
	\tthey have the same number of elements , symbols ,\n\
	\tand their elements and symbols at the\n\
	\tcorresponding positions\n\
	\n\
	2-\tThe program also outputs whether the elements\n\
	\tdo have the same matching group symbols\n";
}

void menu()
{
	cout <<"\n\n\
  Select from the following menu:\n\
  1. \tEnter Stack / Queue Values.\n\
  9. \tTerminate the program.";
  
}

void stackEvaluate(string stackExp, bool & sMatch, Stack &sTest)
{


	int lpCounter = 0;
	int	rpCounter = 0;
	int	lbCounter = 0;
	int	rbCounter = 0;
	int	laCounter = 0;
	int	raCounter = 0;


	for(int i = 0; stackExp[i]; i++ )    //scan the character array
	{
	
		if (isspace(stackExp[i]))  {}
		
		else if (ispunct(stackExp[i]))
		{
			sTest.push(stackExp[i]);
			switch(stackExp[i])
			{
				case '(':
					lpCounter ++;
					break;
				case ')':
					rpCounter ++;
					break;
				case '{':
					rbCounter++;
					break;
				case '}':
					lbCounter++;
					break;
				case '<':
					laCounter++;
					break;
				case '>':
					raCounter++;
					break;
			}	
		}		
		else       
			sTest.push(stackExp[i]);	
	}
	int total = lpCounter + rpCounter + lbCounter + rbCounter + laCounter +raCounter;
	if (total == 0)
		sMatch = 0;
	else if (lpCounter == rpCounter && lbCounter == rbCounter && laCounter == raCounter)
		sMatch = 1;
	else 
		sMatch = 0;
}

void queueEvaluate(string queueExp, bool & qMatch, Queue &qTest)
{
	int lpCounter = 0;
	int	rpCounter = 0;
	int	lbCounter = 0;
	int	rbCounter = 0;
	int	laCounter = 0;
	int	raCounter = 0;

	for(int i = 0; queueExp[i]; i++ )    //scan the character array
	{
	
		if (isspace(queueExp[i]))  {}
		
		else if (ispunct(queueExp[i]))
		{
			qTest.enqueue(queueExp[i]);
			switch(queueExp[i])
			{
				case '(':
					lpCounter ++;
					break;
				case ')':
					rpCounter ++;
					break;
				case '{':
					rbCounter++;
					break;
				case '}':
					lbCounter++;
					break;
				case '<':
					laCounter++;
					break;
				case '>':
					raCounter++;
					break;
			}	
		}		
		else       
			qTest.enqueue(queueExp[i]);	
	}
	int total = lpCounter + rpCounter + lbCounter + rbCounter + laCounter +raCounter;
	if (total == 0)
		qMatch = 0;
	else if (lpCounter == rpCounter && lbCounter == rbCounter && laCounter == raCounter)
		qMatch = 1;
	else 
		qMatch = 0;
}

bool compare(Stack & sTest, Queue & qTest)
{
	Stack reverseStack;
	
	if (sTest.getSize() != qTest.getSize())
	{
		return false;
	}
	
	for (int i = 0, initSize = sTest.getSize(); i < initSize; i++)
	{
		reverseStack.push(sTest.top());
		sTest.pop();
	}
	
	for (int i = 0; i < reverseStack.getSize(); i++)
	{
		if (reverseStack.top() == qTest.front())
		{
			reverseStack.pop();
			qTest.dequeue();
		}
		else
			return false;
	}
	return true;
}

/*=========STACK DEFINITIONS============*/

//--- Definition of Stack constructor
Stack::Stack()
: myTop(0)
{mySize = 0;}

//--- Definition of Stack copy constructor
Stack::Stack(const Stack & original)
{
   myTop = 0;
   if (!original.empty())
   {
      // Copy first node
      myTop = new Stack::Node(original.top());

      // Set pointers to run through the stacksÕ linked lists
      Stack::NodePointer lastPtr = myTop,
      origPtr = original.myTop->next;

      while (origPtr != 0)
      {
         lastPtr->next = new Stack::Node(origPtr->data);
         lastPtr = lastPtr->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Stack destructor
Stack::~Stack()
{     
   // Set pointers to run through the stack
   Stack::NodePointer currPtr = myTop,  // node to be deallocated
                      nextPtr;          // its successor
   while (currPtr != 0)
   {
      nextPtr = currPtr->next;
      delete currPtr;
      currPtr = nextPtr;
   }
}

//--- Definition of assignment operator
const Stack & Stack::operator=(const Stack & rightHandSide)
{
   if (this != &rightHandSide)         // check that not st = st
   {
      this->~Stack();                  // destroy current linked list
      if (rightHandSide.empty())       // empty stack
         myTop = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myTop = new Stack::Node(rightHandSide.top());

         // Set pointers to run through the stacks' linked lists
         Stack::NodePointer lastPtr = myTop,
                            rhsPtr = rightHandSide.myTop->next;

         while (rhsPtr != 0)
         {
            lastPtr->next = new Stack::Node(rhsPtr->data);
            lastPtr = lastPtr->next;
            rhsPtr = rhsPtr->next;
         } 
      }
   }
   return *this;
}

//--- Definition of empty()
bool Stack::empty() const
{ 
   return (myTop == 0); 
}

//--- Definition of push()
void Stack::push(const StackElement & value)
{
   myTop = new Stack::Node(value, myTop);
   mySize++;
}

//--- Definition of display()
void Stack::display(ostream & out) const
{
   Stack::NodePointer ptr;
   for (ptr = myTop; ptr != 0; ptr = ptr->next)
      out << ptr->data << endl;
}

//--- Definition of top()
StackElement Stack::top() const
{
   if (!empty())
      return (myTop->data);
   else
   {
      cerr << "*** Stack is empty "
              " -- returning garbage ***\n";
      StackElement * temp = new(StackElement);  
      StackElement garbage = *temp;     // "Garbage" value
      delete temp;
      return garbage;
   }
}

//--- Definition of pop()
void Stack::pop()
{
   if (!empty())
   {
      Stack::NodePointer ptr = myTop;
      myTop = myTop->next;
      delete ptr;
      mySize--;
   }   
   else
      cerr << "*** Stack is empty -- can't remove a value ***\n";
}

int Stack::getSize()
{
	return mySize;
}


/*==============Queue Definitions====================*/

//--- Definition of Queue constructor
Queue::Queue()
: myBack(0)
{mySize = 0;}

//--- Definition of Queue copy constructor
//Queue::Queue(const Queue & original)
/* this program does not contain a copy constructor */

//--- Definition of Queue destructor
Queue::~Queue()
{
	// Set pointer to run through the queue
	Queue::NodePointer prev = myBack->next,
					   ptr;
	do
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}while (prev != myBack->next);				   
}

//--- Definition of assignment operator
//const Queue & Queue::operator=(const Queue & rightHandSide)
/* this program does not contain an assignment operator*/

//--- Definition of empty()
bool Queue::empty() const
{
	return (myBack == 0);
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
	Queue::NodePointer newptr = new Queue::Node(value);
					   
	if (empty())
		myBack = newptr;
	
	else if(myBack->next == NULL)
	{
		myBack->next = newptr;
		newptr->next = myBack;
	}
	else
	{
		newptr->next = myBack->next;
		myBack->next = newptr;
	}	
	
	myBack = newptr;
	mySize++;
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
	Queue::NodePointer ptr = myBack->next;
	do
	{
		out << ptr->data << " ";
		ptr=ptr->next;	
	}while(ptr != myBack->next);
	out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
	if (!empty())
		return (myBack->next->data);
	else
	{
		cerr << "*** queue is empty "
				"-- returning garbage ***/n";
		QueueElement * temp = new(QueueElement);
		QueueElement garbage = *temp;
		delete temp;
		return garbage;
	}
}

//---Definition of dequeue()
void Queue::dequeue()
{
	if (!empty())
	{
		Queue::NodePointer ptr = myBack->next;
		myBack->next = ptr->next; 
		delete ptr;
		if (myBack == myBack->next) // queue is now empty
			myBack = 0;
		mySize--;
	}
	else
		cerr <<"*** Queue is empty -- can't remove a value ***" << endl;
}


int Queue::getSize()
{
	return mySize;
}



















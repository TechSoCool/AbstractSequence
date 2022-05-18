// Name: Sterling Gerard
// Date: 4/12/22
// Write a program using a class represents an abstract sequence 
// together with operations for generating a member of 
// the sequence (odd numbers), printing the sequence of odd number,
// and summing the sequence. Square the sequence, and then sum the square 
// of sequence. Allow user to selevt number of sequence

#include<iostream>
using namespace std;

class AbstractSequence
{
public:
	virtual int fun(int k) = 0;
	void printSequence(int k, int m)
	{
		cout << "sequence range from " << k << "th term to " << m << "th term" << endl;
		for (int i = k; i <= m; i++)
			cout << fun(i) << ", ";
		cout << endl;
	}
	int sumSequence(int k, int m)
	{
		int sum = 0;
		for (int i = k; i <= m; i++)
			sum += fun(i);
		return sum;
	}
};

class OddSequence : public AbstractSequence //Odd Class inheriting the Abstract Sequence 
{
public:
	int fun(int k)
	{
		return 2 * k - 1;
	}
};

//represent square numbers 1, 2, 9, 16, 25 , ....
class SquareSequence : public AbstractSequence //Square class inheriting the Abstract Sequence
{
public:
	int fun(int k)
	{
		return (k + 1) * (k + 1);
	}
};

//++++++++++++++Main Program++++++++++++++++++++++
int main()
{
	int k, m; // initializing variables
	OddSequence odd; // Odd sequence creating an object called odd
	SquareSequence square; // Square sequence creating an object called square 

	cout << "Enter starting term number (starting from 0) k: ";
	cin >> k;
	cout << "Enter ending term number (starting from 0) m: ";
	cin >> m;
	cout << "Odd sequence: ";
	odd.printSequence(k, m);
	cout << "Sum of odd sequence: " << odd.sumSequence(k, m) << endl << endl;
	cout << "Sqare sequence: ";
	square.printSequence(k, m);
	cout << "Sum of square sequence: " << square.sumSequence(k, m) << endl << endl;

	system("pause");
	return 0;
}
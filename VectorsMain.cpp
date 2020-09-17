#include <iostream>
#include <fstream>
#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include "Line.h"
#include "Segment.h"
#include "Triangle.h"
#include "EqualPointException.h"
#include "Tetrahedron.h"

using namespace std;

// Function to check if we enter correct number from the list
size_t CheckList(size_t border, size_t list)
{
	ofstream files;
	ifstream infile;

	if (list < 1 || list > border)
	{
		cout << "Your choice must be between 1 - " << border << " !" << endl;
		if (infile) { cout << "Enter new number: ";  infile >> list; }
		if (!infile) { cout << "Enter new number: "; cin >> list; }
		files << list << endl;
	}
	return list;
}

// Function to check if we enter correct answer to the question
char CheckQuestion(char question)
{
	ofstream files;
	ifstream infile;

	if (question != 'y' && question !='n')
	{
		cout << "You must enter 'y' or 'n' to be vaid input!" << endl;
		if (infile) { cout << "Enter new number: ";  infile >> question; }
		if (!infile) { cout << "Enter new number: "; cin >> question; }
		files << question << endl;
	}
	return question;
}

int main() 
{
	// File streams
	ofstream files;
	ifstream infile;

	char asks; 
	char ask;

	// Choose if you want to write information to your file
	cout << "Do you want to write information to your file? (y/n): ";
	cin >> asks;
	// Function for check if your answer is correct
	asks = CheckQuestion(asks);
	// If your answer is yes -> open the file and write info
	if (asks == 'y') 
		files.open("FileVector.txt");

	// Choose if you want to read from your file
	cout << "Do you want to read from your file? (y/n): ";
	cin >> ask;
	// Function for check if your answer is correct
	ask = CheckQuestion(ask);
	// If your answer is yes -> open the file and read from it
	if (ask == 'y') 
		infile.open("FileVector2.txt");

	// Check if write file is right
	if (files.fail())
	{
		cout << "Error opening file. " << endl;
		return 1;
	}

	// Check if read file is right
	if (infile.fail())
	{
		cout << "Error opening file. " << endl;
		return 1;
	}

	// LIST 1 (console print)
	unsigned list;
	cout << "Please select a geometric object: " << endl;
	cout << "(1) Point " << endl;
	cout << "(2) Vector " << endl;
	cout << "(3) Line " << endl;
	cout << "(4) Segment " << endl;
	cout << "(5) Triangle " << endl;
	cout << "(6) Tetrahedron " << endl;

	// FILE (write to file and print)
	files << "Please select a geometric object: " << endl
	<< "(1) Point " << endl
	<< "(2) Vector " << endl
	<< "(3) Line  " << endl
	<< "(4) Segment  " << endl
	<< "(5) Triangle  " << endl
	<< "(6) Tetrahedron " << endl;

	// Variables
	Point p1, p2, p3, p4;
	Vector v1, v2, v3, v4;
	Line line1(p1, p2);
	Line line2(p3, p4);
	Segment segm(p1, v1, 3.0, 6.0);
	Triangle t1;
	Tetrahedron t2;

	char choice;
	do
	{
		// Choose from list
		cout << "Choose a number from above: ";
		if (infile) { infile >> list; } // to read from file
		if (!infile) { cin >> list; } // to read from console

		cout << "Your choice: " << list << endl; // write in console
		files << "Your choice: " << list << endl; // write in file

		list = CheckList(6, list); // Check List function for numbers

		// LIST - Points
		if (list == 1) // LIST - Points
		{
			// Enter points and choise if it's from console or file

			// *From File
			if (infile) { infile >> p1; cout << p1 << endl; infile >> p2; cout << p2 << endl; }
			// *From Console
			if (!infile) { cout << "Point 1: " << endl; cin >> p1; cout << "Point 2: " << endl; cin >> p2; }

			// Save and print in the file
			files << "Point 1: x, y, z = " << p1 << endl;
			files << "Point 2: x, y, z = " << p2 << endl;

			// Result print in console or in the file
			cout << "Are 'Point 1' and 'Point 2' matching? " << boolalpha << (p1 == p2) << endl;
			files << "Are 'Point 1' and 'Point 2' matching? " << boolalpha << (p1 == p2) << endl;
		}

		// LIST - Vector
		if (list == 2) // LIST - Vector
		{
			unsigned list2;
			if (infile) { infile >> v1; cout << v1 << endl; } // to read from file
			if (!infile) { cin >> v1; cout << v1 << endl; } // to read from console
			files << "x, y, z: " << v1 << endl; // write in file

			// LIST 2 - Vector
			cout << "Please select an operation for the object: " << endl
				<< "1 - Vector length" << endl
				<< "2 - Vector direction" << endl
				<< "3 - Check Zero vector" << endl
				<< "4 - Check for parallelism of two vectors" << endl
				<< "5 - Check for perpendicularity of two vectors" << endl
				<< "6 - Addition of two vectors" << endl
				<< "7 - Subtraction of two vectors" << endl
				<< "8 - Multiplication of a vector by a real number" << endl
				<< "9 - Dot product of two vectors" << endl
				<< "10 - Cross product of two vectors" << endl
				<< "11 - Mixed product of three vectors" << endl;

			// FILE (write to file and print)
			files << "Please select an operation for the object: " << endl
				<< "1 - Vector length" << endl
				<< "2 - Vector direction" << endl
				<< "3 - Check Zero vector" << endl
				<< "4 - Check for parallelism of two vectors" << endl
				<< "5 - Check for perpendicularity of two vectors" << endl
				<< "6 - Addition of two vectors" << endl
				<< "7 - Subtraction of two vectors" << endl
				<< "8 - Multiplication of a vector by a real number" << endl
				<< "9 - Dot product of two vectors" << endl
				<< "10 - Cross product of two vectors" << endl
				<< "11 - Mixed product of three vectors" << endl;

			char choice2;
			do {
				cout << "Choose a number from above: ";

				// to read from file
				if (infile)
				{
					infile >> list2; 
					cout << "Your choice: " << list2 << endl; 
					list2 = CheckList(11, list2);
				}

				// to read from console
				if (!infile)
				{
					cin >> list2; 
					cout << "Your choice: " << list2 << endl; 
					list2 = CheckList(11, list2);
				}

				files << "Your choice: " << list2 << endl;

				// 1) Vector length
				if (list2 == 1)
				{
					cout << "Length = " << v1.VectorLength() << endl;
					files << "Length = " << v1.VectorLength() << endl;
				}
				
				// 2) Vector direction
				if (list2 == 2)
				{
					cout << "Direction = " << v1.DirectionOfVector() << endl;
					files << "Direction = " << v1.DirectionOfVector() << endl;
				}

				// 3) Check Zero vector
				if (list2 == 3)
				{
					cout << "Zero vector check -> " << boolalpha << v1.CheckZero() << endl;
					files << "Zero vector check -> " << boolalpha << v1.CheckZero() << endl;
				}

				// 4) Check for parallelism of two vectors
				if (list2 == 4)
				{
					if (infile) { infile >> v2; cout << "x, y, z: " << v2 << endl; }
					if (!infile) { cin >> v2; cout << "x, y, z: " << v2 << endl; }
					files << "x, y, z: " << v2 << endl;
					cout << "Check for parallelism: " << boolalpha << v1.CheckParallel(v2) << endl;
					files << "Check for parallelism: " << boolalpha << v1.CheckParallel(v2) << endl;
				}

				// 5) Check for perpendicularity of two vectors
				if (list2 == 5)
				{
					if (infile) { infile >> v2; cout << "x, y, z: " << v2 << endl; }
					if (!infile) { cin >> v2; cout << "x, y, z: " << v2 << endl; }
					files << "x, y, z: " << v2 << endl;
					cout << "Check for perpendicularity: " << boolalpha << v1.CheckPerpendicular(v2) << endl;
					files << "Check for perpendicularity: " << boolalpha << v1.CheckPerpendicular(v2) << endl;
				}

				// 6) Addition of two vectors
				if (list2 == 6)
				{
					if (infile) { infile >> v2; cout << "x, y, z: " << v2 << endl; }
					if (!infile) { cin >> v2; cout << "x, y, z: " << v2 << endl; }
					files << "x, y, z: " << v2 << endl;
					cout << "Result of addition: " << v1 + v2 << endl;
					files << "Result of addition: " << v1 + v2 << endl;
				}

				// 7) Subtraction of two vectors
				if (list2 == 7)
				{
					if (infile) { infile >> v2; cout << "x, y, z: " << v2 << endl; }
					if (!infile) { cin >> v2; cout << "x, y, z: " << v2 << endl; }
					files << "x, y, z: " << v2 << endl;
					cout << "Result of subtraction: " << v1 - v2 << endl;
					files << "Result of subtraction: " << v1 - v2 << endl;
				}

				// 8) Multiplication of a vector by a real number
				if (list2 == 8)
				{
					int num;
					cout << "Please, enter a real number: ";
					if (infile) { infile >> num; cout << "Number: " << num << endl; }
					if (!infile) { cin >> num; cout << "Number: " << num << endl; }
					files << "Number: " << num << endl;
					cout << "Result of multiplication: " << v1 * num << endl;
					files << "Result of multiplication: " << v1 * num << endl;
				}

				// 9) Dot product of two vectors
				if (list2 == 9)
				{
					if (infile) { infile >> v2; cout << "x, y, z: " << v2 << endl; }
					if (!infile) { cin >> v2; cout << "x, y, z: " << v2 << endl; }
					files << "x, y, z: " << v2 << endl;
					cout << "Dot product result: " << v1 * v2 << endl;
					files << "Dot product result: " << v1 * v2 << endl;
				}

				// 10) Cross product of two vectors
				if (list2 == 10)
				{
					if (infile) { infile >> v2; cout << "x, y, z: " << v2 << endl; }
					if (!infile) { cin >> v2; cout << "x, y, z: " << v2 << endl; }
					files << "x, y, z: " << v2 << endl;
					v4 = v1 ^ v2;
					cout << "Cross product result: " << v4 << endl;
					files << "Cross product result: " << v4 << endl;
				}

				// 11) Mixed product of three vectors
				if (list2 == 11)
				{
					// Vector 1, x,y,z
					if (infile) { infile >> v2; cout << "x, y, z: " << v2 << endl; }
					if (!infile) { cin >> v2; cout << "x, y, z: " << v2 << endl; }
					files << "x, y, z: " << v2 << endl;

					// Vector 2, x,y,z
					if (infile) { infile >> v3; cout << "x, y, z: " << v3 << endl; }
					if (!infile) { cin >> v3; cout << "x, y, z: " << v3 << endl; }
					files << "x, y, z: " << v3 << endl;
					cout << "Mixed product: " << v1(v2, v3) << endl;
					files << "Mixed product: " << v1(v2, v3) << endl;
				}

				if (infile) { files << "Do you want to select a new operation (y/n)?"; infile >> choice2; files << choice2 << endl; }
				if (!infile) { cout << "Do you want to select a new operation (y/n)?"; cin >> choice2; choice2 = CheckQuestion(choice2); }

			} while (choice2 == 'y');
		}

		// LIST - Line
		if (list == 3) // LIST - Line
		{
			unsigned list3;

			// LIST - Line
			cout << "Please, select an operation from the list: " << endl
				<< "1 - Find the direction of the line - returns a vector parallel to the line" << endl
				<< "2 - Find a normal vector - returns a vector perpendicular to the line" << endl
				<< "3 - Find the angle between two lines - returns the value of the angle in radians" << endl
				<< "4 - Check if point is on line with operator +" << endl
				<< "5 - Check if line is parallel to another line with operator ||" << endl
				<< "6 - Check if lines are equal with operator ==" << endl
				<< "7 - Check if line cross another line with operator &&" << endl
				<< "8 - Check if Skew lines with operator !=" << endl
				<< "9 - Check if lines are perpendicullar with operator |" << endl;

			// FILE (write to file and print)
			files << "Please, select an operation from the list: " << endl
				<< "1 - Find the direction of the line - returns a vector parallel to the line" << endl
				<< "2 - Find a normal vector - returns a vector perpendicular to the line" << endl
				<< "3 - Find the angle between two lines - returns the value of the angle in radians" << endl
				<< "4 - Check if point is on line with operator +" << endl
				<< "5 - Check if line is parallel to another line with operator ||" << endl
				<< "6 - Check if lines are equal with operator ==" << endl
				<< "7 - Check if line cross another line with operator &&" << endl
				<< "8 - Check if Skew lines with operator !=" << endl
				<< "9 - Check if lines are perpendicullar with operator |" << endl;

			char choice3;
			do
			{
				cout << "Choose a number from above: ";

				// to read from file
				if (infile)
				{
					infile >> list3;
					cout << "Your choice: " << list3 << endl;
					list3 = CheckList(9, list3);
				}

				// to read from console
				if (!infile)
				{
					cin >> list3;
					cout << "Your choice: " << list3 << endl;
					list3 = CheckList(9, list3);
				}
				files << "Your choice: " << list3;

				// 1) Find the direction of the line - returns a vector parallel to the line
				if (list3 == 1)
				{
					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl; 
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
					}

					if (!infile) // to read from console
					{ 
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
					} 

					Line line1(p1, p2);

					// Print in the console
					cout << "Direction of the line = ";
					cout << line1.LineDirection();
					cout << endl;
					// Save and print in the file
					files << "Direction of the line = " << line1.LineDirection() << endl;
				}

				// 2) Find a normal vector - returns a vector perpendicular to the line
				if (list3 == 2)
				{
					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
					}

					Line line1(p1, p2);

					// Print in the console
					cout << "Normal vector = " << line1.NormalVector() << endl;
					// Save and print in the file
					files << "Normal vector = " << line1.NormalVector() << endl;
				}

				// 3) Find the angle between two lines - returns the value of the angle in radians
				if (list3 == 3)
				{
					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; infile >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; infile >> p4; cout << p4 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; cin >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; cin >> p4; cout << p4 << endl;
					}

					Line line1(p1, p2);
					Line line2(p3, p4);

					// Print in the console
					cout << "The angle between two lines =  " << line1.LineAngle(line2) << endl;
					// Save and print in the file
					files << "The angle between two lines =  " << line1.LineAngle(line2) << endl;
				}

				// 4) Check if point is on line with operator +
				if (list3 == 4)
				{
					Line line1(p1, p2);
					if (infile) // to read from file
					{
						cout << "Line: " << endl; infile >> line1; cout << line1 << endl;
						cout << "Point: " << endl; infile >> p3; cout << p3 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Line: " << endl; cin >> line1; cout << line1 << endl;
						cout << "Point: " << endl; cin >> p3; cout << p3 << endl;
					}

					// Check if point is on line with operator +
					if (line1 + p1) 
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else 
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 5) Check if line is parallel to another line with operator ||
				if (list3 == 5)
				{
					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; infile >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; infile >> p4; cout << p4 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; cin >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; cin >> p4; cout << p4 << endl;
					}

					// Check if line is parallel to another line with operator ||
					if (line1 || line2)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 6) Check if lines are equal with operator ==
				if (list3 == 6)
				{
					Line line1(p1, p2);
					Line line2(p3, p4);

					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; infile >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; infile >> p4; cout << p4 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; cin >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; cin >> p4; cout << p4 << endl;
					}

					if (line1 == line2) //6 - Check if lines are equal with operator ==
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 7) Check if line cross another line with operator && 
				if (list3 == 7)
				{
					Line line1(p1, p2);
					Line line2(p3, p4);

					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; infile >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; infile >> p4; cout << p4 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; cin >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; cin >> p4; cout << p4 << endl;
					}

					// Check if line cross another line with operator && 
					if (line1 && line2)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 8) Check if Skew lines with operator != 
				if (list3 == 8)
				{
					Line line1(p1, p2);
					Line line2(p3, p4);

					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; infile >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; infile >> p4; cout << p4 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; cin >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; cin >> p4; cout << p4 << endl;
					}

					// Check if Skew lines with operator != 
					if (line1 != line2)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 9) Check if lines are perpendicullar with operator |
				if (list3 == 9)
				{
					Line line1(p1, p2);
					Line line2(p3, p4);

					if (infile) // to read from file
					{
						cout << "Point 1: " << endl; infile >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; infile >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; infile >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; infile >> p4; cout << p4 << endl;
					}

					if (!infile) // to read from console
					{
						cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
						cout << "Point 2: " << endl; cin >> p2; cout << p2 << endl;
						cout << "Point 3: " << endl; cin >> p3; cout << p3 << endl;
						cout << "Point 4: " << endl; cin >> p4; cout << p4 << endl;
					}

					// Check if lines are perpendicullar with operator |
					if (line1 | line2)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

			if (infile) { files << "Do you want to select a new operation (y/n)?"; infile >> choice3; files << choice3 << endl; }
			if (!infile) { cout << "Do you want to select a new operation (y/n)?"; cin >> choice3; choice3 = CheckQuestion(choice3); }

			} while (choice3 == 'y');
		}

		// LIST 4 - Segment
		if (list == 4)
		{
			unsigned list4;
			// LIST 4 - Segment
			cout << "Please select an operation for the object: " << endl
				<< "1 - Find the length of a segment that returns a positive real number" << endl
				<< "2 - Find the middle of a segment  that returns a point with coordinates" << endl
				<< "3 - Check if the point is on the segment with operator ==" << endl;

			// FILE (write to file and print)
			files << "Please select an operation for the object: " << endl
				<< "1 - Find the length of a segment that returns a positive real number" << endl
				<< "2 - Find the middle of a segment  that returns a point with coordinates" << endl
				<< "3 - Check if the point is on the segment with operator ==" << endl;

			char choice4;
			do
			{
				cout << "Choose a number from above: ";

				// to read from file
				if (infile)
				{
					infile >> list4;
					cout << "Your choice: " << list4 << endl;
					list4 = CheckList(3, list4);
				}

				// to read from console
				if (!infile)
				{
					cin >> list4;
					cout << "Your choice: " << list4 << endl;
					list4 = CheckList(3, list4);
				}
				files << "Your choice: " << list4;

				if (infile) // to read from file
				{
					cout << "Point: " << endl; infile >> p1; cout << p1 << endl;
					cout << "Vector: " << endl; infile >> v1; cout << v1 << endl;
				}

				if (!infile) // to read from console
				{
					cout << "Point 1: " << endl; cin >> p1; cout << p1 << endl;
					cout << "Vector: " << endl; cin >> v1; cout << v1 << endl;
				}

				//SEGMENT
				Segment segm(p1, v1, 3.0, 6.0);

				// 1) Find the length of a segment that returns a positive real number
				if (list4 == 1)
				{
					// Print in the console
					cout << "The length of a segment = " << segm.SegmentLength() << endl;
					// Save and print in the file
					files << "The length of a segment = " << segm.SegmentLength() << endl;
				}

				// 2) Find the middle of a segment  that returns a point with coordinates
				if (list4 == 2)
				{
					// Print in the console
					cout << "The middle of a segment = " << segm.SegmentMiddle() << endl;
					// Save and print in the file
					files << "The middle of a segment = " << segm.SegmentMiddle() << endl;
				}

				// 3) Check if the point is on the segment with operator ==
				if (list4 == 3)
				{
					if (p1 == v1)
					{
						cout << "Point on segment? " << boolalpha << true << endl;
						files << "Point on segment? " << boolalpha << true << endl;
					}
					else
					{
						cout << "Point on segment? " << boolalpha << false << endl;
						files << "Point on segment? " << boolalpha << false << endl;
					}
				}

				if (infile) { files << "Do you want to select a new operation (y/n)?"; infile >> choice4; files << choice4 << endl; }
				if (!infile) { cout << "Do you want to select a new operation (y/n)?"; cin >> choice4; choice4 = CheckQuestion(choice4); }

			} while (choice4 == 'y');
		}

		// LIST 5 - Triangle
		if (list == 5)
		{
			unsigned list5;

			// LIST 5 - Triangle
			cout << "Please select an operation for the object: " << endl
				<< "1 - Type of triangle" << endl
				<< "2 - Area of triangle" << endl
				<< "3 - Perimeter of triangle" << endl
				<< "4 - Medicenter of the triangle by returning a Point object" << endl
				<< "5 - Check if point is in triangle (inside) with operator <" << endl
				<< "6 - Check if point is outside triangle with operator >" << endl
				<< "7 - Check if point is on one of the sides of triangle with operator ==" << endl;

			// FILE (write to file and print)
			files << "Please select an operation for the object: " << endl
				<< "1 - Type of triangle" << endl
				<< "2 - Area of triangle" << endl
				<< "3 - Perimeter of triangle" << endl
				<< "4 - Medicenter of the triangle by returning a Point object" << endl
				<< "5 - Check if point is in triangle (inside) with operator <" << endl
				<< "6 - Check if point is outside triangle with operator >" << endl
				<< "7 - Check if point is on one of the sides of triangle with operator ==" << endl;
			
			char choice5;
			do
			{
				cout << "Please, choice from menu above: ";

				// to read from file
				if (infile) 
				{ 
					infile >> list5;
					cout << "Your choice: " << list5 << endl;
					list5 = CheckList(7, list5); // Check number function
				}

				// to read from console
				if (!infile) 
				{ 
					cin >> list5; 
					cout << "Your choice: " << list5 << endl; 
					list5 = CheckList(7, list5); // Check number function
				}

				files << "Your choice: " << list5 << endl;


				// 1) Type of triangle" << endl
				if (list5 == 1)
				{
					if (infile) { infile >> t1; }
					if (!infile) { cin >> t1; }
					files << t1 << endl;
					t1.TriangleType();
				}

				// 2) Area of triangle
				if (list5 == 2)
				{
					if (infile) { infile >> t1; }
					if (!infile) { cin >> t1; }
					files << t1 << endl;
					files << "Area = " << t1.TriangleArea() << endl;
					cout << "Area = " << t1.TriangleArea() << endl;
				}

				// 3) Perimeter of triangle
				if (list5 == 3)
				{
					if (infile) { infile >> t1; }
					if (!infile) { cin >> t1; }
					files << t1 << endl;
					cout << "Perimeter =  " << t1.TrianglePerimeter() << endl;
					files << "Perimeter =  " << t1.TrianglePerimeter() << endl;
				}

				// 4) Medicenter of the triangle by returning a Point object
				if (list5 == 4)
				{
					if (infile) { infile >> t1; }
					if (!infile) { cin >> t1; }
					files << t1 << endl;
					cout << "Medicenter =  " << t1.TriangleMedicenter() << endl;
					files << "Medicenter =  " << t1.TriangleMedicenter() << endl;
				}

				// 5) Check if point is in triangle (inside) with operator <
				if (list5 == 5)
				{
					if (infile) { infile >> p1 >> t1; }
					files << p1 << t1 << endl;
					cout << "Please, enter POINT: " << endl;
					cin >> p1;
					cout << "Please, enter points of TRIANGLE: " << endl;
					cin >> t1;
					if (p1 < t1)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 6) Check if point is outside triangle with operator >
				if (list5 == 6)
				{
					if (infile) { infile >> p1 >> t1; }
					files << p1 << t1 << endl;
					cout << "Please, enter POINT: " << endl;
					cin >> p1;
					cout << "Please, enter points of TRIANGLE: " << endl;
					cin >> t1;
					if (p1 > t1)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 7) Check if point is on one of the sides of triangle with operator ==
				if (list5 == 7)
				{
					if (infile) { infile >> p1 >> t1; }
					files << p1 << t1 << endl;
					cout << "Please, enter POINT: " << endl;
					cin >> p1;
					cout << "Please, enter points of TRIANGLE: " << endl;
					cin >> t1;
					if (p1 == t1)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				if (infile) { files << "Do you want to select a new operation (y/n)?"; infile >> choice5; files << choice5 << endl; }
				if (!infile) { cout << "Do you want to select a new operation (y/n)?"; cin >> choice5; choice5 = CheckQuestion(choice5); }

			} while (choice5 == 'y');
		}

		// LIST 6 - Tetrahedron
		if (list == 6)
		{
			unsigned list6;

			// LIST 6 - Tetrahedron
			cout << "Please select an operation for the object: " << endl
				<< "1 - Check if Tetrahedron is regular (all edges are =)" << endl
				<< "2 - Check if Tetrahedron is orthogonal (every 2 opposite edges are perpendicular)" << endl
				<< "3 - Find the surrounding surface" << endl
				<< "4 - Find volume" << endl
				<< "5 - Check if point is in Tetrahedron (inside) with operator <" << endl
				<< "6 - Check if point is outside Tetrahedron with operator >" << endl
				<< "7 - Check if point is on one of the sides of Tetrahedron with operator ==" << endl;

			// FILE (write to file and print)
			files << "Please select an operation for the object: " << endl
				<< "1 - Check if Tetrahedron is regular (all edges are =)" << endl
				<< "2 - Check if Tetrahedron is orthogonal (every 2 opposite edges are perpendicular)" << endl
				<< "3 - Find the surrounding surface" << endl
				<< "4 - Find volume" << endl
				<< "5 - Check if point is in Tetrahedron (inside) with operator <" << endl
				<< "6 - Check if point is outside Tetrahedron with operator >" << endl
				<< "7 - Check if point is on one of the sides of Tetrahedron with operator ==" << endl;

			char choice6;
			do
			{
				cout << "Please, choice from menu above: ";

				// to read from file
				if (infile) 
				{ 
					infile >> list6; 
					cout << list6 << endl;
					list6 = CheckList(7, list6);
				}

				// to read from console 
				if (!infile)
				{ 
					cin >> list6;
					cout << list6 << endl; 
					list6 = CheckList(7, list6);
				}
				
				files << "Your choice: " << list6 << endl;

				// TETRAHEDRON
				Tetrahedron t2;

				// 1) Check if Tetrahedron is regular (all edges are =)
				if (list6 == 1)
				{
					if (infile) { infile >> t2; cout << t2 << endl;	files << t2 << endl; }
					if (!infile) { cin >> t2; cout << t2 << endl; files << t2 << endl; }
					cout << "Is the tetrahedron regular? " << boolalpha << t2.RegularTetrahedron() << endl;
					files << "Is the tetrahedron regular? " << boolalpha << t2.RegularTetrahedron() << endl;
				}

				// 2) Check if Tetrahedron is orthogonal (every 2 opposite edges are perpendicular)
				if (list6 == 2)
				{
					if (infile) { infile >> t2; cout << t2 << endl; }
					if (!infile) { cin >> t2; cout << t2 << endl; }
					files << t2 << endl;
					cout << "Is the tetrahedron orthogonal? " << boolalpha << t2.OrthogonalTetrahedron() << endl;
					files << "Is the tetrahedron orthogonal? " << boolalpha << t2.OrthogonalTetrahedron() << endl;
				}

				// 3) Find the surrounding surface
				if (list6 == 3)
				{
					if (infile) { infile >> t2; cout << t2 << endl; }
					if (!infile) { cin >> t2; cout << t2 << endl; }
					files << t2 << endl;
					cout << "Surrounding surface = " << t2.SurroundingSurface() << endl;
					files << "Surrounding surface = " << t2.SurroundingSurface() << endl;
				}

				// 4) Find volume
				if (list6 == 4)
				{
					if (infile) { infile >> t2; cout << t2 << endl; }
					if (!infile) { cin >> t2; cout << t2 << endl; }
					files << t2 << endl;
					cout << "Volume = " << t2.TetrahedronVolume() << endl;
					files << "Volume = " << t2.TetrahedronVolume() << endl;
				}

				// 5) Check if point is in Tetrahedron (inside) with operator <
				if (list6 == 5)
				{
					if (infile) { infile >> p1 >> t2; }
					files << p1 << t2 << endl;
					cout << "Please, enter POINT: " << endl;
					cin >> p1;
					cout << "Please, enter points of Tetrahedron: " << endl;
					cin >> t2;
					if (p1 < t2)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 6) Check if point is outside Tetrahedron with operator >
				if (list6 == 6)
				{
					if (infile) { infile >> p1 >> t2; }
					files << p1 << t2 << endl;
					cout << "Please, enter POINT: " << endl;
					cin >> p1;
					cout << "Please, enter points of Tetrahedron: " << endl;
					cin >> t2;
					if (p1 > t2)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}

				// 7) Check if point is on one of the sides of Tetrahedron with operator ==
				if (list6 == 7)
				{
					if (infile) { infile >> p1 >> t1; }
					files << p1 << t1 << endl;
					cout << "Please, enter POINT: " << endl;
					cin >> p1;
					cout << "Please, enter points of Tetrahedron: " << endl;
					cin >> t1;
					if (p1 == t1)
					{
						cout << "True" << endl;
						files << "True" << endl;
					}
					else
					{
						cout << "False" << endl;
						files << "False" << endl;
					}
				}
			
				if (infile) { files << "Do you want to select a new operation (y/n)?"; infile >> choice6; files << choice6 << endl; }
				if (!infile) { cout << "Do you want to select a new operation (y/n)?"; cin >> choice6; choice6 = CheckQuestion(choice6); }

			} while (choice6 == 'y');
		}

		// NEW GEOMETRIC OBJECT ?
		if (infile) { files << "Do you want to select a new geometric object(y/n)?"; infile >> choice; files << choice << endl; }
		if (!infile) { cout << "Do you want to select a new geometric object(y/n)?"; cin >> choice; choice = CheckQuestion(choice); }

	} while (choice == 'y');

	cout << endl;
	cout << "*********************************" << endl;
	cout << "Thank you for your attention! :) " << endl;

	// CLOSE
	files.close();
	infile.close();
	return 0;
}
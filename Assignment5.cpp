/******************************************

Assignment 5

Create a program that will prompt the user for a file name to work with. Then prompt the user for a string to search for. The program will search the file for the string the user provided, each line in the file is a string. So a line should be read from the file, search the line for the string. If the string is in that line then it should display the line. If the string is not in the line then it should read the next line from the file. The program should also keep track of how many times it found the string and how many line from the file it has read completely. Provide the text file you created for this program.

Author: Cesar Roncancio

Created : 10/03/2021

Revisions : 10/03/2021 I was confused about the prompt if it wanted me to search the whole text or if it just wanted to print the first occurrence and stop there, so I kinda did both.
******************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	ifstream file;     // File stream object
	string name;       // To hold the file name
	string inputLine;  // To hold a line of input
	string word;
	int found = 0;
	int count = 0;
	int lines = 1;     // Line counter

	// Get the file name.
	cout << "Enter the file name: ";
	getline(cin, name);
	cout << "Enter a string to search for: "<< endl;
	cin >> word;
	// Open the file.
	file.open(name);

	// Test for errors.
	if (!file)
	{
		// There was an error so display an error
		// message and end the program.
		cout << "Error opening " << name << endl;
	}
	else {
		//I was confused about the wording on the assignment so this first while is to read a line if it finds the string it print the line and tells how many lines it read to get there
		//if it reads a line and the string is not there then it reads the next line until he finds the string and prints the first ocurrence and tell how many lines it read.
		while (!file.eof()) {
			getline(file, inputLine, '\n');
			found = inputLine.find(word);
			if (found > -1) {
				cout << inputLine << endl;
				count++;
				break;
			}
			lines++;
		}

		cout << "the string '" << word << "' was found " << ", and a total of " << lines << " line(s) were read to find it." << endl;
		
		//Due to the confusion on the prompt this second while, reads a line if it finds the string it prints the line and reads the next to search for the string and prints it
		//Then it tells how many lines it read to find the string in multiple lines in the whole text not just the first ocurrence.
		while (!file.eof()) {
			getline(file, inputLine, '\n');
			found = inputLine.find(word);
			if (found > -1) {
				cout << inputLine << endl;
				count++;
			}
			lines++;
		}

		cout << "the string '" << word << "' was found " << count << " time(s) in the text, and a total of " << lines << " line(s) were read to find it." << endl;
		// Close the file.
		file.close();
	}
	return 0;
}
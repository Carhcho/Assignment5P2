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

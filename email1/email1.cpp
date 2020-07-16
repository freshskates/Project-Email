#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <fstream>
#include <regex> 
string getFileName(string file, string prompt, int path);
int processLine(string lineFromFile);
void readFile(string line);
void introduction();
int processLine(string line) 
{
	int count = 0; //Line counter
	for (int i = 0; i < line.length(); i++) 
	{
		if (line[i] == '@') count++; // This will traverse through every character in the line and check how many @ signs it has.
	}
	return count; // Will return how many @ signs there are
}
void readFile(string file) //reads every line in the file
{ 
	string line; 
	int count = 0;  //@ sign counter
	ifstream fin; 
	fin.open(file.c_str());
	if (!(fin.good())) throw "I/O Error";
	while (fin.good())
	{
		getline(fin, line);
		if (processLine(line) == 1) cout << line << endl; //Calls processLine function, and the amount of @ signs should be only 1
		if (fin.good()) count++; 
	}
	if (count == 0) cout << file << " is Empty."; //If it reads 0 lines that is because the file is empty.
	fin.close();
}
string getFileName(string file, string prompt, int path) 
{
	string dFileName; 
	if (path == 1) dFileName = "fileContainingEmails.txt"; else if (path == 2) dFileName = "x.txt";
	bool good;
	do {
		cout << prompt; 
		getline(cin, file);
		if (file.length() == 0) { file = dFileName; good = true; }
		else if (file.length() > 10 || file.length() < 5) good = false;
		else 
			{
			if (file.substr(file.length() - 4, file.length()) == ".txt") good = true; //if the ending of the file is .txt, it will make the bool good true
			else good = false;
			for (int i = 0; i < file.length(); i++) if (file[i] == ' ') good = false; //if string has empty space will return good = false; 
			}
		} while (good == false); // Will keep running until good = true
		return file; 
}

int main()
{
	void introduction();
	string iFileName, oFileName;
	iFileName = getFileName(iFileName, "Enter input filename[default: fileContainingEmails.txt]: ", 1);
	oFileName = getFileName(oFileName, "Enter output filename[default: x.txt]: ", 2);
	cout << "Input file: " << iFileName << endl << "Output file: " << oFileName << endl << "press ENTER key to continue:" << endl;
	cin.ignore(1000, 10);
	readFile(iFileName);
}


void introduction()
{
	cout << "Objective: This program will allow user input with deep validation";
	cout << "Programmer: Robert Cacho Ruiz\n";
	cout << "Editor(s) used: Notepad\n";
	cout << "Compiler(s) used: TDM MinGW\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
	cout << endl << "Instructions: Enter file names you want to check emails for." << endl;
}

	

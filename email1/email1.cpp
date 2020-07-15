#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
bool txtcheck(string file);
void getflinename(string& file, string& dFileName, string prompt, int path);
bool txtcheck(string file) {
	string temp; bool good = true;
	for (int i = 1; i < 5; i++) temp += file[file.length() - i];
	if (temp != "txt.") good = false;
	for (int i = 0; i < file.length(); i++) if (file[i] == ' ') good = false; 
	return good; 
}

void getflinename(string &file, string& dFileName, string prompt, int path) {
	if (path == 1) dFileName = "fileContainingEmails.txt";
	else if (path == 2) dFileName = "x.txt";
	bool good = true;
	do {
		cout << prompt;
		getline(cin, file);
		if (file.length() == 0) { file = dFileName; good = true; }
		else if (file.length() > 10 || file.length() < 5)good = false;
		else good = txtcheck(file);
	} while (good == false);
}


int main()
{
	string dFileName, iFileName, oFileName;
	getflinename(iFileName, dFileName, "Enter input filename[default: fileContainingEmails.txt]: ", 1);
	getflinename(oFileName, dFileName, "Enter output filename[default: x.txt]: ", 2);
	cout << "Input file: " << iFileName << endl << "Output file: " << oFileName << endl << "press ENTER key to continue:" << endl;
	cin.ignore(1000, 10);
}
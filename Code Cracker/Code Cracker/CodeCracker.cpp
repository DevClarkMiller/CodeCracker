#include "CrackerFunctions.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	vector<string> args;

	if (argc <= 1) {
		cerr << "Error: Incorrect Number of File Arguments!" << endl;
		return EXIT_FAILURE;
	}

	for (int i = 0; i < argc; i++) {
		args.push_back(argv[i]);
	}
	
	string filename = argv[1];

	fstream file(filename);

	if (file.is_open()) {
		map<char, double> letterPercents;
		string code = "";
		string input;
		while (getline(file, input)) {
			code += input;
		}
		setNewlines(code);
		string updatedCode = code;

		char replacing;
		char substitute;

		setPercents(code, letterPercents);

		//Main loop
		do {
			system("CLS");
			cout << "Original Code" << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << code << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << "Updated Code" << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << updatedCode << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;
			printMap(letterPercents);

			cout << "Enter letter to replace: ";
			cin >> replacing;

			if (replacing == '~') {
				break;
			}

			cout << "Enter substitute: ";
			cin >> substitute;

			string codeCopy = code;
			replaceChar(codeCopy, replacing, substitute);
			combineStrings(code, updatedCode, codeCopy);

		} while (replacing != '~');
	}
	else {
		cerr << "File not found, quitting now!" << endl;
		return EXIT_FAILURE;
	}
}
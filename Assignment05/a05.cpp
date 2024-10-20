/******************************************************************************
# Author:           Kyle Noyes
# Assignment:       Assignment05 (CS161A)
# Date:             July 24, 2024
# Description:      This program will check if either phrase matches against the
#					other, and generate a funny output if it does.
#					If equal or no match found, user is alerted
# Input:            Str phrase1
#					Str phrase2
#					String usingFerry
# Output:			String: userInput for phrase1
#					String: userInput for phrase2
#					String Phrase match; phrase not found in phrase; substring of phrase

# Sources:          Assignment 5 specifications
#******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
	/* Declarations - no globals needed */
	string phrase1 = "";
	string phrase2 = "";
	string phraseLong = "";
	string phraseShort = "";
	string mergedPhrase = "";
	int lenPhraseShort = 0;
	int indexFoundStart = 0;
	int runState = 0;

	/* Introduction */
	cout << "Welcome to the Phrases and Subphrases program!" << endl;
	cout << endl;

	/* User inputs */
	cout << "Enter Phrase 1: ";
	getline(cin, phrase1);
	cout << "You entered: " << phrase1 << endl;

	cout << "Enter Phrase 2: ";
	getline(cin, phrase2);
	cout << "You entered: " << phrase2 << endl;
	cout << endl;

	/* Check if equal, if not then get longest/shortest phrase */
	if (phrase1 == phrase2) {
		cout << "Both phrases match" << endl;
		runState = 1;
	}
	else if (phrase1.length() < phrase2.length()) {
		phraseLong = phrase2;
		phraseShort = phrase1;
		lenPhraseShort = phrase1.length();
	}
	else {
		phraseLong = phrase1;
		phraseShort = phrase2;
		lenPhraseShort = phrase2.length();
	}

	/* Check if short is in long, if not then create end run state */
	if (phraseLong.find(phraseShort) == string::npos) {
		cout << "No match" << endl;
		runState = 1;
	}

	/* If no end run state detected, complete parsing of strings */
	if (runState != 1) {
		indexFoundStart = phraseLong.find(phraseShort);
		mergedPhrase = phraseShort + (phraseLong.substr(indexFoundStart + lenPhraseShort));
		cout << phraseShort << " is found in " << phraseLong << endl;
		cout << mergedPhrase << endl;
	}
	cout << endl;

	cout << "Thank you for using my program!" << endl;

	return 0;
}
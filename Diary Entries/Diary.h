#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Diary
{
public:
	Diary();
	void openDiaryTextFileForEditing(); //opens text file for editing
	void openDiaryTextFileForReading(); //opens text file for reading
	void getMenu(); //gets menu
	void getMenuOption(); //gets menu option
	void addDiaryEntry(); //function that adds diary entry
	void getDiaryEntries(); //reads all Diary Entries
	void deleteDiaryEntry(); //deletes a diary Entry
	~Diary();
private:
	std::string date; //used to store date for entry
	std::string writeDiaryEntry; //used to get text user enters for diary entry
	std::string readDiaryEntry;
	std::ofstream outfile; //used to output users diary entry to text file
	std::ifstream infile; //used to read diary entries from text file
	int entryDiaryNumber; //keeps track of diary entry number
};


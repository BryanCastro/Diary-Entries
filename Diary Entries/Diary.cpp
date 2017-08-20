#include "Diary.h"
#include <sstream>


Diary::Diary()
{
	openDiaryTextFileForEditing(); //opens text file for editing
	outfile.close();

	entryDiaryNumber = 0;
}

void Diary::openDiaryTextFileForEditing()
{
	outfile.open("diary entry.txt", std::ios::app); //creates .txt file used to get users diary entry

	if (outfile.fail()) { //if text file fails to be created this code runs
		std::cerr << "Error creating text file!" << std::endl;
	}


}

void Diary::openDiaryTextFileForReading()
{
	infile.open("diary entry.txt"); //opens text file for reading

	if (infile.fail()) { //error if txt file fails to open
		std::cerr << "Failed to open diary entry.txt!"<<std::endl;
	}

}

void Diary::getMenu()
{

	std::cout << "=====================" << std::endl;
	std::cout << "=Diary Entry Program=" << std::endl;
	std::cout << "=====================" << std::endl;
	std::cout << std::endl;
	std::cout << "01.Add Entry"<<std::endl;
	std::cout << "02.Read Entries" << std::endl;
	std::cout << "03.Exit" << std::endl;
	std::cout << std::endl;

	getMenuOption();
}

void Diary::getMenuOption()
{
	int option;

	std::cout << "Enter option:";
	std::cin >> option;
	std::cin.ignore(); //gets rid of '\n' in order to allow getline to run properly later in code

	if (option == 1) {
		addDiaryEntry(); //takes user to data 
	}
	else if (option == 2) {
		getDiaryEntries(); //reads all Diary Entries
	}
	else if (option == 3) {
		exit(1);
	}
	else {
		std::cerr << "Error! Invalid option chosen....";
		std::cin.fail();
		std::cin.clear();
		std::cin.ignore();
		system("CLS");
		getMenu();
	}
}

void Diary::addDiaryEntry()
{
	openDiaryTextFileForEditing(); //opens text file for editing 
	entryDiaryNumber++; //increases diary entry number

	std::cout << std::endl;
	std::cout << "Enter Date Format(Month, Day, Year) :";
	getline(std::cin, date);
	std::cout << std::endl;
	std::cout << "Enter your diary entry below, type '/end' to end entry: " << std::endl;
	std::cout << std::endl;
	
	outfile << "Diary Entry # " << entryDiaryNumber << std::endl;
	outfile << "Date: " << date << std::endl << std::endl; //stores date into text file

	while (writeDiaryEntry != "/end") { //gets user text and stores to text file until user types /end

		getline(std::cin, writeDiaryEntry);
		outfile << writeDiaryEntry << std::endl;
		
	}

	outfile << std::endl; //used to add space after every entry
	writeDiaryEntry =""; //sets diary entry to empt so while loop runs again if user wants to input another entry
	outfile.close(); //closes txt file for editing

	std::cout << std::endl;
	std::cout <<"Press any key to return to menu...."<< std::endl; //pauses menu before returning user to menu
	std::cin.ignore(); //allows user to enter a key without it being stored in cin
	system("CLS"); //clears screen

	getMenu();
}

void Diary::getDiaryEntries()
{
	openDiaryTextFileForReading();

	std::cout << std::endl;
	
	while (!infile.eof()) {
		getline(infile, readDiaryEntry);
		std::cout << readDiaryEntry << std::endl;
	}
	
}

void Diary::deleteDiaryEntry()
{

}


Diary::~Diary()
{
}


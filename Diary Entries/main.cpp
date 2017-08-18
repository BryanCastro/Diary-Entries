#include <iostream>
#include <string>
#include <fstream>

int main() {

	std::string date;
	std::string diaryEntry;

	std::ofstream outfile;
	outfile.open("diary entry.txt");

	if (outfile.fail()) {
		std::cerr << "Error creating text file!" << std::endl;
	}

	std::cout << "Enter Date Format(Month, Day, Year) :";
	getline(std::cin, date);
	std::cout << std::endl;
	std::cout << "Enter your diary entry below, type '/end' to end entry: " << std::endl;
	std::cout << std::endl;
	
	outfile << "Date: " << date << std::endl << std::endl;

	while (diaryEntry != "/end") {
		getline(std::cin, diaryEntry);
		outfile << diaryEntry << std::endl;
	}

	std::string option;
	std::cout << "Again:(Y/N):";
	getline(std::cin, option);

	if (option == "Y") {
		main();
	}
	else {
		exit(1);
	}

	return 0;
}
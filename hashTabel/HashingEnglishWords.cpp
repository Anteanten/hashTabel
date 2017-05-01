#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "HashTable.h"
#include "EngWord.h"

int readFromFile(std::string filename, std::string arr[]) {
	std::ifstream file;
	file.open("C:/temp/" + filename);
	std::string line;
	int i = 0;
	while (std::getline(file, line) ) {
		arr[i++] = line;
	}
	file.close();

	return i - 1;
}

void hashArray(HashTable<EngWord> &hashTable,std::string arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		hashTable.insert(arr[i]);
	}
	std::cout << "Load Factor: " + std::to_string(hashTable.loadFactor()) << std::endl;
}
void insertWord(HashTable<EngWord> &hashTable) {
	std::cout << "Write the words you want to insert" << std::endl;
	std::string input;
	std::cin >> input; std::cin.ignore();
	if (!hashTable.insert(input)) {
		std::cout << input + " was not added" << std::endl;
	}
}
void removeWord(HashTable<EngWord> &hashTable) {
	std::cout << "Write the words you want to remove" << std::endl;
	std::string input;
	std::cin >> input; std::cin.ignore();
	if (!hashTable.remove(input)) {
		std::cout << input + " was not removed" << std::endl;
	}
}
void existWord(HashTable<EngWord> &hashTable) {
	std::cout << "Write the words you want to check" << std::endl;
	std::string input;
	std::getline(std::cin, input);
	std::istringstream str(input);
	while (str) {
		std::string string;
		str >> string;
		if (string != "") {
			if (hashTable.contains(string) != -1) {
				std::cout << string + " exists in the table" << std::endl;
			} else {
				std::cout << string + " doesn't exist in the table" << std::endl;
			}
		}
	}
}

int main() {
	HashTable<EngWord> hashTable(1998);
	std::string arr[999];
	std::cout << "Inserting EngWords" << std::endl;
	hashArray(hashTable, arr, readFromFile("engWords.txt", arr));
	std::string input = "";
	while (strcmp("exit", input.c_str()) != 0) {
		std::cout << "Hash Menu" << std::endl;
		std::cout << "Write 'insert' to insert new words" << std::endl;
		std::cout << "Write 'remove' to remove a word" << std::endl;
		std::cout << "Write 'exist' to check if words exist in the table" << std::endl;
		std::cout << "Write 'exit' to close the program" << std::endl;
		std::cin >> input; std::cin.ignore();
		if(strcmp(input.c_str(), "insert") == 0){
			insertWord(hashTable);
		}
		if (strcmp(input.c_str(), "remove") == 0) {
			removeWord(hashTable);
		}
		if (strcmp(input.c_str(), "exist") == 0) {
			existWord(hashTable);
		}
		getchar();
		system("cls");
	}
	
	return 0;
}
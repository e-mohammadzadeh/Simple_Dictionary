// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Word.h"
#include "List.h"
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int mainMenu();
int printMenu();
int deleteMenu();
int sortMenu();
int editMenu();
void printCase(List, Word);
void sortCase(List);
void deleteCase(List);
void editCase(string, List);
bool setterCheck(string &);
bool fileCheck();
bool fileSearch(string &);
List readData();
void writeData(List);

int main()
{
	List myList;
	Word myWord;
	fstream myFile;
	Word *address;
	string w, t, p, s, pos, deleteWord, editWord, replaceWord;
	string searchWord, searchSynonym, searchTranslation, searchPronunciation, searchPartOfSpeech;
	int flag = 1;
	char answer;
	bool check1;

	myList = readData();

	while (flag)
	{
		system("cls");
		cout << "\n*************** Dictionary ***************\n\n";
		cout << "Number of Words in dictionary is => " << myList.getSize() << "\n\n";
		switch (mainMenu())
		{
		case 1:
		{
			cin.get();
			cout << "Enter the word that you want to translate : ";
			getline(cin, searchWord);
			myWord.setWord(searchWord);
			searchWord = myWord.getWord();
			address = myList.search(searchWord, searchTranslation, searchPronunciation, searchPartOfSpeech, searchSynonym, 1);
			if (address == NULL)
			{
				cout << "\nThere is not such word in this dictonary,Sorry !!!\n";
				Beep(1568, 500);
				cin.get();
			}
			else
			{
				myList.printAWord(address);
			}
			system("cls");
			break;
		}
		case 2:
		{
			cin.get();
			cout << "plz enter a word to find a synonym for it : ";
			getline(cin, searchWord);
			myWord.setWord(searchWord);
			searchWord = myWord.getWord();
			address = myList.search(searchWord, searchTranslation, searchPronunciation, searchPartOfSpeech, searchSynonym, 5);
			if (address == NULL)
			{
				cout << "\nThere is not such Synonym in this dictonary,Sorry !!!\n";
				Beep(1568, 500);
				cin.get();
			}
			else
			{
				myList.printAWord(address);
			}
			system("cls");
			break;
		}
		case 3:
		{
			cin.get();
			cout << "<<<<< Adding a new word to Dictionary >>>>>\n\n"
				<< "Enter word : ";
			getline(cin, w);
			check1 = setterCheck(w);
			if (check1)
			{
				if (fileSearch(w))
				{
					myWord.setWord(w);
					cout << "Enter translation of the word : ";
					getline(cin, t);
					myWord.setTranslation(t);
					cout << "Enter pronunciation of the word : ";
					getline(cin, p);
					myWord.setPronunciation(p);
					cout << "Enter part of speech of this word (type) : ";
					getline(cin, pos);
					myWord.setPartOfSpeech(pos);
					cout << "Do you want to add a synonym to this new word (y/n) ?  ";
					cin >> answer;
					if (answer == 'y' || answer == 'Y')
					{
						cin.get();
						cout << "Enter a synonym for this word : ";
						getline(cin, s);
						check1 = setterCheck(s);
						if (check1)
						{
							myWord.setSynonym(s);
						}
						else
						{
							cout << "\nPress any key to come back to main menu " << endl;
							cin.get();
							exit(1);
						}
					}
					else if (answer == 'n' || answer == 'N')
					{
						cout << "The End of adding a word !!!!\a";
						s = '-';
						myWord.setSynonym(s);
						cin.get();
						cin.get();
					}
					else
					{
						cout << "========================================\n\n"
							<< "\nError: your choice is invalid, Sorry!!!!\n";
						Beep(1568, 500);
						s = '-';
						myWord.setSynonym(s);
						cin.get();
						cin.get();
					}
					myList.addWord(myWord);
				}
				else
				{
					break;
				}
			}
			else
			{
				cout << "\nPress any key to come back to main menu " << endl;
				cin.get();
				break;
			}
			break;
		}
		case 4:
		{
			printCase(myList, myWord);
			break;
		}
		case 5:
		{
			sortCase(myList);
			break;
		}
		case 6:
		{
			deleteCase(myList);
			break;
		}
		case 7:
		{
			string newPartOfWord, oldWord;
			cout << "Enter a word that you want to edit : ";
			cin >> oldWord;
			editCase(oldWord, myList);
			break;
		}
		case 8:
		{
			cout << "Programe is finished !!!!!\n"
				<< "GOOD LUCK\n\n";
			Beep(200, 100); Beep(300, 100); Beep(400, 100); Beep(500, 100); Beep(600, 100); Beep(700, 100); Beep(800, 100); Beep(900, 100); Beep(1000, 100);
			flag = 0;
			cin.get();
			cin.get();
			break;
		}
		}
	}
	system("cls");
	writeData(myList);
	return 0;
}


int mainMenu()
{
	int choice;
	cout << "=============================================\n"
		<< "1. Translate a word\n"
		<< "2. Search synonym of the word\n"
		<< "3. Add a word to dictionary\n"
		<< "4. Print\n"
		<< "5. Sort the words\n"
		<< "6. Delete\n"
		<< "7. Edit\n"
		<< "8. Exit\n\n"
		<< "=============================================\n";
	cout << "# Select your choice, Plz : ";
	cin >> choice;
	if (choice > 8 || choice < 1)
	{
		cout << "Error :\nYour choice is invalid, Plz re-enter your choice : ";
		Beep(1568, 500);
		cin >> choice;
	}
	system("cls");
	return choice;
}


int printMenu()
{
	int choice;
	cout << "\n*************** PRINT ***************\n\n"
		<< "========================================\n\n"
		<< "1. Print all words\n"
		<< "2. Print a word\n"
		<< "3. Back to main Menu\n\n"
		<< "========================================\n";
	cout << "# Select your choice, Plz : ";
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Error :\nYour choice is invalid, Plz re-enter your choice : ";
		Beep(1568, 500);
		cin >> choice;
	}
	system("cls");
	return choice;
}


int deleteMenu()
{
	int choice;
	cout << "\n*************** DELETE ***************\n\n"
		<< "========================================\n\n"
		<< "1. Delete all words\n"
		<< "2. Delete a word\n"
		<< "3. Back to main Menu\n\n"
		<< "========================================\n";
	cout << "# Select your choice, Plz : ";
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Error :\nYour choice is invalid, Plz re-enter your choice : ";
		Beep(1568, 500);
		cin >> choice;
	}
	system("cls");
	return choice;
}


int sortMenu()
{
	int choice;
	cout << "\n*************** SORT ***************\n\n"
		<< "========================================\n\n"
		<< "1. Sort By (A-Z)\n"
		<< "2. Sort By (Z-A)\n"
		<< "3. Back to main Menu\n\n"
		<< "========================================\n";
	cout << "# Select your choice, Plz : ";
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Error :\nYour choice is invalid, Plz re-enter your choice : ";
		Beep(1568, 500);
		cin >> choice;
	}
	system("cls");
	return choice;
}


int editMenu()
{
	int choice;
	cout << "\n*************** EDIT ***************\n\n"
		<< "========================================\n\n"
		<< "1. Edit word\n"
		<< "2. Edit Translation\n"
		<< "3. Edit pronunciation\n"
		<< "4. Edit part of speech\n"
		<< "5. Edit synonym\n"
		<< "6. Back to main Menu\n\n"
		<< "==================================================\n";
	cout << "# Select which part of word do you want to edit, Plz : ";
	cin >> choice;
	if (choice > 6 || choice < 1)
	{
		cout << "Error :\nYour choice is invalid, Plz re-enter your choice : ";
		Beep(1568, 500);
		cin >> choice;
	}
	system("cls");
	return choice;
}


void printCase(List myList, Word myWord)
{
	string searchWord, searchSynonym, searchTranslation, searchPronunciation, searchPartOfSpeech;
	Word *address;
	bool exit = false;
	while (!exit)
	{
		switch (printMenu())
		{
		case 1:
		{
			myList.printAllWords();
			cin.get();
			break;
		}
		case 2:
		{
			cin.get();
			cout << "Enter a word to print all information about it : ";
			getline(cin, searchWord);
			myWord.setWord(searchWord);
			searchWord = myWord.getWord();
			address = myList.search(searchWord, searchTranslation, searchPronunciation, searchPartOfSpeech, searchSynonym, 1);
			if (address == NULL)
			{
				cout << "\nThere is NOT such word in this dictonary,Sorry !!!\n";
				Beep(2000, 300);
				cin.get();
			}
			else
			{
				myList.printAWord(address);
			}
			break;
		}
		case 3:
		{
			exit = true;
			break;
		}
		}
		system("cls");
	}
}


void sortCase(List myList)
{
	//bool exit = false;
	//while (!exit)
	//{			these are unnecessary in all these functions.
		system("cls");
		switch (sortMenu())
		{
		case 1:
		{
			myList.sort(1);
			cout << "List of words sorted by A-Z\n";
			Beep(500, 500);
			cin.get();
			cin.get();
			break;
		}
		case 2:
		{
			myList.sort(2);
			cout << "List of words sorted by Z-A\n";
			Beep(500, 500);
			cin.get();
			cin.get();
			break;
		}
		case 3:
		{
			//exit = true;
			break;
		}
		system("cls");
		}
	/*}*/
}


void deleteCase(List myList)
{
	char answer;
	string deleteWord;
	bool exit = false;
	while (!exit)
	{
		system("cls");
		switch (deleteMenu())
		{
		case 1:
		{
			cout << "Caution!!!!!\n\a"
				<< "Do you really want to DELETE all words of dictionary (y/n) ? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				if (myList.getHead() == NULL)
				{
					cout << "\nList is empty, Nothing were deleted !!!\n";
					Beep(2000, 300);
					cin.get();
				}
				else
				{
					myList.deleteList();
					cout << "\nAll Words Of Dictionary Were Deleted Successfully \n\n";
					cin.get();
				}
				cin.get();
			}
			else if (answer == 'n' || answer == 'N')
			{
				cout << "\n# Press any key to return to delete menu\n\a";
				cin.get();
				cin.get();
				continue;
				break;
			}
			else
			{
				cout << "\nError: your choice is invalid, Sorry!!!!\n";
				cin.get();
				cin.get();
			}
			break;
		}
		case 2:
		{
			cin.get();
			cout << "Plz, Enter the word that you want to delete : ";
			getline(cin, deleteWord);
			Word* address = myList.search(deleteWord, deleteWord, deleteWord, deleteWord, deleteWord, 1);
			if (address == NULL)
			{
				cout << "\nSorry, this word does NOT exist in dictionary.\n";
				Beep(2000, 300);
				cin.get();
				break;
			}
			else
			{
				myList.deleteWord(address);
				cout << "\nDONE\a\n";
				cin.get();
			}
			break;
		}
		case 3:
		{
			exit = true;
			break;
		}
		system("cls");
		}
	}
}


void editCase(string oldWord, List myList)
{
	bool exit = false;
	Word *address = NULL;
	string newPartOfWord;
	address = myList.search(oldWord, oldWord, oldWord, oldWord, oldWord, 1);
	while (!exit)
	{
		system("cls");
		switch (editMenu())
		{
		case 1:
		{
			cin.get();
			cout << "Enter new 'word' that you want to replace :";
			getline(cin, newPartOfWord);
			myList.edit(newPartOfWord, address, 1);
			break;
		}
		case 2:
		{
			cin.get();
			cout << "Enter new 'translation' that you want to replace :";
			getline(cin, newPartOfWord);
			myList.edit(newPartOfWord, address, 2);
			break;
		}
		case 3:
		{
			cin.get();
			cout << "Enter new 'pronunciation' that you want to replace :";
			getline(cin, newPartOfWord);
			myList.edit(newPartOfWord, address, 3);
			break;
		}
		case 4:
		{
			cin.get();
			cout << "Enter new 'part of speech' that you want to replace :";
			getline(cin, newPartOfWord);
			myList.edit(newPartOfWord, address, 4);
			break;
		}
		case 5:
		{
			cin.get();
			cout << "Enter new 'synonym' that you want to replace :";
			getline(cin, newPartOfWord);
			myList.edit(newPartOfWord, address, 5);
			break;
		}
		case 6:
		{
			exit = true;
			break;
		}
		system("cls");
		}
	}
}


bool setterCheck(string &ch)
{
	int count = 3;
	size_t i;
	while (count > 0)
	{
		for (i = 0; i < ch.size(); i++)
		{
			if (ch.at(i) >= '0' && ch.at(i) <= '9')
			{
				cout << "\nDon't use number in a word\nEnter word again : ";
				Beep(800, 80);
				getline(cin, ch);
				count--;
				break;
			}
		}
		count--;
	}
	for (i = 0; i < ch.size(); ++i)
		if (ch.at(i) >= '0' && ch.at(i) <= '9')
		{
			cout << "\n=============================================\n"
				<< "Error,You have entered an invalid input...!\n";
			Beep(1568, 500);
			return 0;
		}
	return 1;
}


bool fileCheck()
{
	fstream myFile;
	myFile.open("data file.txt", ios::app);
	if (!myFile.is_open())
	{
		cout << "Caution !!!\nFile is NOT open in 'fileCheck' function, Plz open it.\n";
		Beep(111, 555);
		exit(1);
	}
	myFile.seekg(0, ios::end);
	streamoff length = myFile.tellg();
	if (length == 0)
	{
		return 0;
	}
	return 1;
	myFile.close();
}


bool fileSearch(string &searchWord)
{
	fstream myFile;
	string fileWord;
	string searchword;
	int result, chance = 0;
	myFile.open("MainFile.txt", ios::in);
	if (!myFile)
	{
		cout << "Caution !!!\nFile is NOT open for checking dictational error, Plz open it.\n";
		Beep(111, 555);
		exit(1);
	}
	else
	{
		do
		{
			while (myFile >> fileWord)
			{
				result = fileWord.compare(searchWord);
				if (result == 0)
				{
					return 1;
				}
			}
			++chance;
			cout << "\nThere is a dictational error\nEnter word again without misspelling\n\n"
				<< "Enter word : ";
			getline(cin, searchWord);
			myFile.clear();
			myFile.seekg(0, ios::beg);
		} while (chance <= 2);
		myFile.close();
	}
	return 0;
}


List readData()
{
	List myList;
	Word myWord;
	fstream myFile;
	string word, translation, pronunciation, partOfSpeech, synonym;

	myFile.open("data file.txt", ios::in);
	if (myFile.fail())
	{
		cout << "Caution !!!\nFile is NOT open for reading data, Plz open it.\n";
		Beep(111, 555);
		exit(1);
	}
	if (fileCheck() == 0)
	{
		cout << "File is empty !!!\n\a";
		cout << "For using Dictionary add some word yourself, Thanks\n";
		cin.get();
	}
	else
	{
		while (myFile >> word >> translation >> pronunciation >> partOfSpeech >> synonym)
		{
			myWord.setWord(word);
			myWord.setTranslation(translation);
			myWord.setPronunciation(pronunciation);
			myWord.setPartOfSpeech(partOfSpeech);
			myWord.setSynonym(synonym);
			myList.addWord(myWord);
		}
		cout << "Reading data is finished\n";
		cout << "Information of dictoinary were copied to list with success \n\n";
		cin.get();
	}
	myFile.close();
	return myList;
}


void writeData(List myList)
{
	fstream myFile;
	Word *p = myList.getHead();
	string word, translation, pronunciation, partOfSpeech, synonym;

	myFile.open("data file.txt", ios::out);
	if (!myFile.is_open())
	{
		cout << "Caution !!!\nFile is NOT open for writing data, Plz open it.\n";
		Beep(111, 555);
		exit(1);
	}

	for (; p != NULL; p = p->next)
	{
		myFile << p->getWord() << "\t" << p->getTranslation() << "\t " << p->getPronunciation() << "\t" << p->getPartOfSpeech() << "\t" << p->getSynonym() << endl;
		myFile << endl;
	}

	cout << "Writing data is finished\n";
	cout << "Information of list were copied to file with success\n";
	myFile.close();
}
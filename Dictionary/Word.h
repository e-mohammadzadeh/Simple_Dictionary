#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <fstream>

using namespace std;


class Word
{
private:
	string word, translation, pronunciation, partOfSpeech, synonym;
public:
	Word *next;
	Word(string = "", string = "", string = "", string = "", string = "", int = 0);
	void setWord(string);
	string getWord();
	void setTranslation(string);
	string getTranslation();
	void setPronunciation(string);
	string getPronunciation();
	void setPartOfSpeech(string);
	string getPartOfSpeech();
	void setSynonym(string);
	string getSynonym();
};
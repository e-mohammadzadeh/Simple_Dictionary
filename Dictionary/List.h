#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <fstream>
#include "Word.h"


using namespace std;


class List
{
private:
	static int size;
	static Word *Head;
	static Word *Last;

public:
	List();
	void printAllWords();
	void printAWord(Word *);
	void addWord(Word);
	void deleteList();
	void deleteWord(Word *);
	Word *search(string, string, string, string, string, int);
	void sort(int);
	Word *getHead();
	Word *getLast();
	int getSize();
	void swap(Word *, Word *);
	void edit(string, Word *, int);
};
#include "stdafx.h"
#include <iostream>
#include "Word.h"

using namespace std;


Word::Word(string word, string translation, string pronunciation, string partOfSpeech, string synonym, int numberOfWords)
{
	setWord(word);
	getWord();
	setTranslation(translation);
	getTranslation();
	setPronunciation(pronunciation);
	getPronunciation();
	setPartOfSpeech(partOfSpeech);
	getPartOfSpeech();
	setSynonym(synonym);
	getSynonym();
}


void Word::setWord(string w)
{
	word = w;
}


string Word::getWord()
{
	return word;
}


void Word::setTranslation(string t)
{
	translation = t;
}


string Word::getTranslation()
{
	return translation;
}


void Word::setPronunciation(string p)
{
	pronunciation = p;
}


string Word::getPronunciation()
{
	return pronunciation;
}


void Word::setPartOfSpeech(string pos)
{
	partOfSpeech = pos;
}


string Word::getPartOfSpeech()
{
	return partOfSpeech;
}


void Word::setSynonym(string s)
{
	synonym = s;
}


string Word::getSynonym()
{
	return synonym;
}


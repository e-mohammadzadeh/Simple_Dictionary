#include "stdafx.h"
#include <iostream>
#include "List.h"


using namespace std;


int List::size;
Word *List::Head;
Word *List::Last;

List::List()
{
	Head = NULL;
	Last = NULL;
	size = 0;
}


Word *List::getHead()
{
	return Head;
}


Word *List::getLast()
{
	return Last;
}


int List::getSize()
{
	return size;
}


void List::printAllWords()
{
	Word *current = Head;
	if (current == NULL)
	{
		cout << "Dictionary is empty\n\n\a";
	}
	else
	{
		cout << left << setw(10) << "* Word *" << internal << setw(17) << "* Translation *" << internal << setw(20) << "* Pronunciation *" << internal
			<< setw(20) << "* Part Of Speech *" << internal << setw(13) << "* Synonym *" << endl;
		cout << "******************************************************************************************\n";
		for (; current != NULL; current = current->next)
		{
			cout << left << setw(15) << current->getWord() << left << setw(15) << current->getTranslation() << internal << setw(13) << current->getPronunciation()
				<< internal << setw(15) << current->getPartOfSpeech() << internal << setw(20) << current->getSynonym() << endl;
			cout << "======================================================================================\n\n";
		}
	}
	cin.get();
}


void List::printAWord(Word *address)
{
	cout << "\n# " << "> " << address->getWord() << " ( " << address->getPartOfSpeech() << " )  " << "\tpro: " << address->getPronunciation() << "\ttra: "
		<< address->getTranslation() << "  SYNONYM => " << address->getSynonym() << endl;
	cin.get();
}


void List::addWord(Word myWord)
{
	string newWord, newTranslation, newPronunciation, newPartOfSpeech, newSynonym;
	newWord = myWord.getWord();
	newTranslation = myWord.getTranslation();
	newPronunciation = myWord.getPronunciation();
	newPartOfSpeech = myWord.getPartOfSpeech();
	newSynonym = myWord.getSynonym();
	if (Head == NULL || Last == NULL)
	{
		Word *new_Word = new Word(newWord, newTranslation, newPronunciation, newPartOfSpeech, newSynonym);
		Head = new_Word;
		Last = new_Word;
	}
	else
	{
		Word *new_Word = new Word(newWord, newTranslation, newPronunciation, newPartOfSpeech, newSynonym);
		Last->next = new_Word;
		Last = new_Word;
	}
	++size;
	sort(1);
}


void List::deleteList()
{
	while (Head != NULL)
	{
		Word *temp = Head;
		Head = Head->next;
		delete temp;
	}
	delete Head;
	size = 0;
}


void List::deleteWord(Word *word)
{
	Word *current = Head, *previous = Head;
	while (current != NULL)
	{
		if (word == current)
		{
			if (current == Head)
			{
				Head = current->next;
				--size;
				delete current;
				break;
			}
			else
			{
				if (current == Last)
					Last = previous;
				previous->next = current->next;
				--size;
				delete current;
				break;
			}
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}


Word *List::search(string sWord, string sTranslation, string sPronunciation, string sPartOfSpeech, string sSynonym, int type)
{
	Word *p = Head;
	switch (type)
	{
	case 1:
	{
		while (p != NULL && p->getWord() != sWord)
		{
			p = p->next;
		}
		break;
	}
	case 2:
	{
		while (p != NULL && p->getTranslation() != sTranslation)
		{
			p = p->next;
		}
		break;
	}
	case 3:
	{
		while (p != NULL && p->getPronunciation() != sPronunciation)
		{
			p = p->next;
		}
		break;
	}
	case 4:
	{
		while (p != NULL && p->getPartOfSpeech() != sPartOfSpeech)
		{
			p = p->next;
		}
		break;
	}
	case 5:
	{
		while (p != NULL && p->getSynonym() != sSynonym)
		{
			p = p->next;
		}
		break;
	}
	default:
	{
		p = NULL;
		break;
	}
	}
	return p;
}


void List::sort(int type)
{
	Word *a;
	Word *b;
	switch (type)
	{
	case 1:
	{
		for (a = getHead(); a != NULL; a = a->next)
			for (b = a->next; b != NULL; b = b->next)
				if (a->getWord() > b->getWord())
				{
					swap(a, b);
				}
		break;
	}
	case 2:
	{
		for (a = getHead(); a != NULL; a = a->next)
			for (b = a->next; b != NULL; b = b->next)
				if (a->getWord() < b->getWord())
				{
					swap(a, b);
				}
		break;
	}
	}
}


void List::swap(Word *a, Word *b)
{
	string tempWord, tempTranslation, tempPronunciation, tempPartOfSpeech, tempSynonym;

	tempWord = a->getWord();
	a->setWord(b->getWord());
	b->setWord(tempWord);
	tempTranslation = a->getTranslation();
	a->setTranslation(b->getTranslation());
	b->setTranslation(tempTranslation);
	tempPronunciation = a->getPronunciation();
	a->setPronunciation(b->getPronunciation());
	b->setPronunciation(tempPronunciation);
	tempPartOfSpeech = a->getPartOfSpeech();
	a->setPartOfSpeech(b->getPartOfSpeech());
	b->setPartOfSpeech(tempPartOfSpeech);
	tempSynonym = a->getSynonym();
	a->setSynonym(b->getSynonym());
	b->setSynonym(tempSynonym);
}


void List::edit(string newPartOfWord, Word *address, int type)
{
	switch (type)
	{
	case 1:
	{
		address->setWord(newPartOfWord);
		cout << "Information of new word after editing : \n\n";
		printAWord(address);
		break;
	}
	case 2:
	{
		address->setTranslation(newPartOfWord);
		cout << "Information of new word after editing : \n\n";
		printAWord(address);
		break;
	}
	case 3:
	{
		address->setPronunciation(newPartOfWord);
		cout << "Information of new word after editing : \n\n";
		printAWord(address);
		break;
	}
	case 4:
	{
		address->setPartOfSpeech(newPartOfWord);
		cout << "Information of new word after editing : \n\n";
		printAWord(address);
		break;
	}
	case 5:
	{
		address->setSynonym(newPartOfWord);
		cout << "Information of new word after editing : \n\n";
		printAWord(address);
		break;
	}
	}
}
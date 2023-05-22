#include <istream>
#include <fstream>
#include "TextualFileWordIterator.h"

using namespace std;

TextualFileWordIterator::TextualFileWordIterator(string path, char f_sep) : FileWordIterator(path), sep(f_sep) {}

string TextualFileWordIterator::get_next_word() 
{
	string temp;
	this->fin >> temp;
	return temp;
}
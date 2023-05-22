#include <istream>
#include <fstream>
#include "TextualFileWordIterator.h"
#include <iostream>

using namespace std;

TextualFileWordIterator::TextualFileWordIterator(string path, char f_sep) : FileWordIterator(path), sep(f_sep) {}

string TextualFileWordIterator::get_next_word() 
{
	string temp;

	try {
		this->fin >> temp;
	}
	catch (const std::ios_base::failure& fail) {
		std::cout << fail.what() << '\n';
		return "";
	}
	return temp;
}
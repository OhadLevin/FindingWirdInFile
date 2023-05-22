#include <istream>
#include <fstream>
#include "FileWordIterator.cpp"

using namespace std;

class TextualFileWordIterator : public FileWordIterator
{
public:
	TextualFileWordIterator(string path, char sep);
	string get_next_word() override;
protected:
	char sep;
};

TextualFileWordIterator::TextualFileWordIterator(string path, char f_sep) : FileWordIterator(path), sep(f_sep) {}

string TextualFileWordIterator::get_next_word() 
{
	string temp;
	this->fin >> temp;
	return temp;
}
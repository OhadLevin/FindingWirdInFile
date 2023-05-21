#include <stdio.h>
#include <iostream>
#include <string.h>
#include "TextualFileWordIterator.cpp"
#define CASE_SENSATIVE_FLAG "-c"
#define SUB_TEXT_FLAG "-s"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Wrong usage, this program gets 2 arguments, the file to search in path and the word to search in the file\n"
			<< "example: FindWordInFile test_file.txt hello\n" 
			<< "Use " << CASE_SENSATIVE_FLAG << " to be case sensative\n"
			<< "Use " << SUB_TEXT_FLAG << " to search word as a sub text too\n";
	}
	
	bool case_sensative = false;
	bool sub_text = false;
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], CASE_SENSATIVE_FLAG) == 0)
		{
			cout << "running case sensative \n";
			case_sensative = true;
		}
		else if (strcmp(argv[i], SUB_TEXT_FLAG) == 0)
		{
			cout << "running as sub text too \n";
			sub_text = true;
		}
	}

	string path = argv[1];
	string word = argv[2];
	TextualFileWordIterator wi(path, ' ');
	WordFinder wf(&wi);
	if (wf.is_word_in_file(word, case_sensative, sub_text))
	{
		cout << "the word \"" << word << "\" is in the file\n";
	}
	else
	{
		cout << "the word \"" << word << "\" is not in the file\n";
	}

	return 1;
}
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "TextualFileWordIterator.cpp"
#define CASE_SENSATIVE_FLAG "-c"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Wrong usage, this program gets 2 arguments, the file to search in path and the word to search in the file\n"
			<< "example: FindWordInFile test_file.txt hello\n" 
			<< "Use " << CASE_SENSATIVE_FLAG << " to be case sensative\n";
	}
	
	bool case_sensative = false;
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], CASE_SENSATIVE_FLAG) == 0)
		{
			cout << "running case insensative \n";
			case_sensative = true;
		}
	}

	string path = argv[1];
	string word = argv[2];
	TextualFileWordIterator wi(path, ' ');
	WordFinder wf(&wi);
	if (wf.is_word_in_file(word, case_sensative))
	{
		cout << "the word \"" << word << "\" is in the file\n";
	}
	else
	{
		cout << "the word \"" << word << "\" is not in the file\n";
	}

	return 1;
}
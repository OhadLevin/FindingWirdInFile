#include <iostream>
#include "FileWordIterator.h"

using namespace std;


FileWordIterator::FileWordIterator(string i_path): path(i_path)
{
	cout << "openning file " << i_path << '\n';
	try {
		this->fin = ifstream(i_path, ifstream::in); 
		this->fin.exceptions(std::ifstream::failbit); 
	}
	catch (const std::ios_base::failure& fail) {
		std::cout << fail.what() << '\n';
	}
}

FileWordIterator::~FileWordIterator()
{
	cout << "closing file " << this->path << '\n';
	this->fin.close();
}


void FileWordIterator::go_to_start()
{
	this->fin.clear();
	this->fin.seekg(0);
}


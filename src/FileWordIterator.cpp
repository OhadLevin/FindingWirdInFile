#include <iostream>
#include "FileWordIterator.h"

using namespace std;


FileWordIterator::FileWordIterator(string i_path): path(i_path)
{
	cout << "openning file " << i_path << '\n';
	this->fin = ifstream(i_path, ifstream::in);
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


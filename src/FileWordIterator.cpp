#include <string>
#include <fstream>
#include <iostream>
#include "WordFinder.cpp"

using namespace std;

class FileWordIterator : public WordIterator
{
public:
	FileWordIterator(string path);
	virtual string get_next_word() = 0;
	void go_to_start();
	~FileWordIterator();

protected:
	ifstream fin;
	string path;
};

FileWordIterator::FileWordIterator(string path)
{
	cout << "openning file " << this->path << '\n';
	this->fin = ifstream(path, ifstream::in);
	this->path = path;
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


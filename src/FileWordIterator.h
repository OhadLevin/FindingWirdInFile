#include "WordFinder.h"
#include <fstream>

class FileWordIterator : public WordIterator
{
public:
	FileWordIterator(std::string path);
	virtual std::string get_next_word() = 0;
	void go_to_start() override;
	~FileWordIterator();

protected:
	std::ifstream fin;
	std::string path;
}; 

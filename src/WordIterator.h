#include <string>

class WordIterator
{
public:
	virtual std::string get_next_word() = 0;
	virtual void go_to_start() = 0;
};

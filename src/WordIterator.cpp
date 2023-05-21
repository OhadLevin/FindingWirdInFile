#include <iostream>
#include <string>

using namespace std;

class WordIterator
{
public:
	virtual string get_next_word() {
		return ""; };
	virtual void go_to_start() {};
};

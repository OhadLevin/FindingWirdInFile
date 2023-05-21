#include <iostream>
#include <string>

using namespace std;

class WordIterator
{
public:
	virtual string get_next_word() {
		cout << "WordIterator gets next\n";
		return ""; };
	virtual void go_to_start() {};
};

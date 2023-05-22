#include "WordIterator.h"

class WordFinder
{
private:
	WordIterator* wi;
public:
	WordFinder(WordIterator* wi);
	bool is_word_in_file(std::string word, bool case_sensative = false, bool sub_text_case = false);
};

#include "FileWordIterator.h"


class TextualFileWordIterator : public FileWordIterator
{
public:
	TextualFileWordIterator(std::string path, char sep);
	std::string get_next_word() override;
protected:
	char sep;
};

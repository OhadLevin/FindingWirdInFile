#include "WordIterator.cpp"

class WordFinder
{
private:
	WordIterator* wi;
public:
	WordFinder(WordIterator* wi);
	bool is_word_in_file(string word, bool case_sensative = false);
};

WordFinder::WordFinder(WordIterator* wi)
{
	this->wi = wi;
}

bool compare_string(string str1, string str2, bool case_sensative = false);

bool WordFinder::is_word_in_file(string word, bool case_sensative /*= false*/)
{
	wi->go_to_start();
	string temp;
	while ((temp = wi->get_next_word()) != "")
	{
		if (compare_string(temp, word, case_sensative))
		{
			return true;
		}
	}
	return false;
}

const int CAPITAL_TO_NON_CAPITAL = 'a' - 'A';

bool compare_case_insensative(string str1, string str2)
{
	int len;
	char c1, c2;
	if (str1.length() != (len = str2.length()))
	{
		return false;
	}
	for (int i = 0; i < len; i++) //started from the end just to use the length
	{
		c1 = ((str1[i] <= 'Z') && (str1[i] >= 'A')) ? str1[i] + CAPITAL_TO_NON_CAPITAL : str1[i];
		c2 = ((str2[i] <= 'Z') && (str2[i] >= 'A')) ? str2[i] + CAPITAL_TO_NON_CAPITAL : str2[i];
		if (c1 != c2)
		{
			return false;
		}
	}
	return true;
}

bool compare_string(string str1, string str2, bool case_sensative)
{
	if (!case_sensative)
	{
		return compare_case_insensative(str1, str2);
	}
	return (str1 == str2);
}
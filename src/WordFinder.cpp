#include "WordFinder.h"
#include <string>

using namespace std;

WordFinder::WordFinder(WordIterator* i_wi) : wi(i_wi) {}

bool compare_string(string str1, string str2, bool case_sensative = false);
bool is_sub_text(string original, string sub_text, bool case_sensetive);

const int CAPITAL_TO_NON_CAPITAL = 'a' - 'A';

bool WordFinder::is_word_in_file(string word, bool case_sensative /*= false*/, bool sub_text_case /*= false*/)
{
	wi->go_to_start();
	string temp;
	while ((temp = wi->get_next_word()) != "")
	{	
		if (sub_text_case)
		{
			return is_sub_text(temp, word, case_sensative);
		}
		else if (compare_string(temp, word, case_sensative))
		{
			return true;
		}
	}
	return false;
}


char get_char_in_string(string str, int ind, bool case_sensative)
{
	return (case_sensative) ? str[ind] : ((str[ind] <= 'Z') && (str[ind] >= 'A')) ? str[ind] + CAPITAL_TO_NON_CAPITAL : str[ind];
}

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

bool is_sub_text(string original, string sub_text, bool case_sensetive)
{
	int len, j = 0;
	char o1, s2;
	if (sub_text.length() > (len = original.length()))
	{
		return false;
	}
	for (int i = 0; i < len; i++) //started from the end just to use the length
	{
		o1 = get_char_in_string(original, i, case_sensetive);
		s2 = get_char_in_string(sub_text, j, case_sensetive);;
		if (o1 == s2)
		{
			j++;
		}
		else
		{
			j = 0;
		}

		if (j == sub_text.length())
		{
			return true;
		}
	}
	return false;
}

bool compare_string(string str1, string str2, bool case_sensative)
{	
	if (!case_sensative)
	{
		return compare_case_insensative(str1, str2);
	}
	return (str1 == str2);
}
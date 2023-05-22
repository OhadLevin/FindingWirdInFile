#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class RegexState {
public:
    char ch;
    vector<RegexState*> nexts;
    RegexState(char ch);
};

RegexState::RegexState(char i_ch): ch(i_ch){}

class RegexSegment {
public:
    RegexState* start;
    vector<RegexState*> ends;
    RegexSegment(RegexState* start);
};

RegexSegment::RegexSegment(RegexState* i_start): start(i_start){
    ends.push_back(start);
}


string normal2postfix(string normal);

RegexSegment* convert_postfix_to_regex_state(string postfix);

int operators_hirarchey(char op);

bool validate_string_with_pattern(string str, string postfix_pattern);

int main(int argc, char* argv[])
{
    string postfix_pattern = normal2postfix(argv[1]);
	cout << "from " << argv[1] << " to -> " << postfix_pattern << '\n';
    validate_string_with_pattern(argv[2], postfix_pattern);
}

int operators_hirarchey(char op)
{
    switch (op) {
    case '+':
    case '*':
    case '?':
        return 3;
    case '|':
        return 1;
    case '@':
        return 2;
    default:
        return -1;
    }
}

string normal2postfix(string normal)
{
    int len = normal.length();
    char ch;
    stack<char> stk;
    string output = "";
    for (int i = 0; i < len; i++)
    {
        cout << output << '\t';
        ch = normal[i];
        if (ch == '(')
        {
            stk.push(ch);
        }
        else
        {
            if (isalnum(ch))
            {
                output += ch;
            }
            else if (ch == ')')
            {
                while (!stk.empty() && (stk.top() != '('))
                {
                    output += stk.top();
                    stk.pop();
                }
                stk.pop();

            }
            else
            {
                while (!stk.empty() && (stk.top() != '(') && (operators_hirarchey(stk.top()) >= operators_hirarchey(ch)))
                {
                    output += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
            if ((i == len - 1) || (isalnum(normal[i + 1]) || ch == '('))
            {
                while (!stk.empty() && (stk.top() != '(') && (operators_hirarchey(stk.top()) >= operators_hirarchey(ch)))
                {
                    output += stk.top();
                    stk.pop();
                }
                stk.push('@');
            }
        }
        

    }
    while (!stk.empty())
    {
        output += stk.top();
        stk.pop();
    }
    return output;
}

void print_state(RegexState* state)
{
    cout << '(' << &state << ") value - " << state->ch << " nexts: ";
    /*for (auto& next : state->nexts)
    {
        print_state(next);
    }*/
}

void print_segment(RegexSegment* seg)
{
    cout << "start: ";
    print_state(seg->start);
    cout << "ends: \n";

    for (auto& end : seg->ends)
    {
        cout << end;
    }
    cout << '\n';
}

RegexSegment* convert_postfix_to_regex_state(string postfix)
{
    int len = postfix.length();
    char ch;
    stack<RegexSegment*> st;
    for (int i = 0; i < len; i++)
    {
        ch = postfix[i];

        cout << "handlling " << ch << '\n';
        if (isalpha(ch))
        {
            RegexState* temp = new RegexState(ch);
            cout << temp << '\n';
            st.push(new RegexSegment(temp));
        }
        else
        {
            switch (ch)
            {
            case '@':
            {
                RegexSegment* to = st.top();
                st.pop();
                if (st.empty())
                {
                    st.push(to);
                    break;
                }
                RegexSegment* from = st.top();
                st.pop();

                cout << "concat from - ";
                print_segment(from);
                cout << " to ";
                print_segment(to);
                for (auto& end : from->ends)
                {
                    end->nexts.push_back(to->start);
                }
                from->ends = to->ends;
                st.push(from);
                break;
            }
            case '+':
            {
                RegexSegment* to_add = st.top();
                st.pop();
                RegexSegment* to_add_copy = new RegexSegment(*to_add);
                for (auto& end : to_add->ends)
                {
                    end->nexts.push_back(to_add_copy->start);
                }
                for (auto& end : to_add_copy->ends)
                {
                    end->nexts.push_back(to_add_copy->start);
                }
                st.push(to_add);
                break;
            }
            case '*':
            {
                RegexSegment* to_repeat = st.top();
                st.pop();
                RegexState* temp = new RegexState('\0');
                for (auto& end : to_repeat->ends)
                {
                    end->nexts.push_back(to_repeat->start);
                    end->nexts.push_back(temp);
                }
                to_repeat->ends.push_back(temp);
                st.push(to_repeat);

                break;
            }

            }
        }
    }
    cout << "top - " << st.top() << '\n';
    print_segment(st.top());

    return st.top();
}

bool validate_string_with_pattern(string str, string postfix_pattern)
{
    RegexSegment* r = convert_postfix_to_regex_state(postfix_pattern);
    print_segment(r);
    RegexState* temp = new RegexState('\0');
    temp->nexts.push_back(r->start);
    int i = 0;
    char ch;
    cout << "string " << str << " postfix_pattern " << postfix_pattern << '\n';
    while (i < str.length()) {
        cout << "searching for " << i  << " with temp " << temp << '\n';
        for (auto& state : temp->nexts)
        {
            cout << "i = " << i << ", state = " << state->ch << '\n';
            if (state->ch == str[i])
            {
                temp = state;
                goto found_next;
            }
        }
        cout << "not found for i = " << i << '\n';
        return false;
    found_next:

        i++;
    }

    

    cout << "temp - " << temp << '\n';
    bool cont = true;
    while(cont)
    {
        for (auto& end : r->ends)
        {
            cout << "end - " << end << '\n';
            if (end == temp)
            {
                cout << "\n matches!!!" << '\n';
                return true;
            }
        }
        cont = false;
        for (auto& next : temp->nexts)
        {
            if (next->ch == '\0')
            {
                
                temp = next;
                cont = true;
                break;
            }
        }
    }

    cout << "no valid end found\n";
    return false;
}
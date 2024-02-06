#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <chrono>
#include <cstdio>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function accepts string query and two stack<int> stack as parameters.
 */
void queueTwoStacks(string query, stack<int> &s, stack<int> &r)
{
    switch (query[0])
    {
    case '1': // push
        s.push(stoi(query.substr(2, query.size() - 2)));
        break;
    case '2': // pop
        if (!r.empty())
        {
            r.pop();
        }
        else
        {
            while (s.size() > 1)
            {
                r.push(s.top());
                s.pop();
            }
            s.pop();
            break;
        }
        break;
    case '3': // top
        if (r.empty())
        {
            while (!s.empty())
            {
                r.push(s.top());
                s.pop();
            }
        }
        cout << r.top() << endl;
        break;
    default:
        break;
    }
}

void queueTwoStacksAlt(string query, stack<int> s)
{
    stack<int> copiedStack = s;
    stack<int> reverseStack;
    switch (query[0])
    {
    case '1': // push
        s.push(stoi(query.substr(2, query.size() - 2)));
        break;
    case '2': // pop
        while (s.size() > 1)
        {
            reverseStack.push(s.top());
            s.pop();
        }
        s.pop();
        while (!reverseStack.empty())
        {
            s.push(reverseStack.top());
            reverseStack.pop();
        }
        break;
    case '3': // top
        while (copiedStack.size() > 1)
        {
            copiedStack.pop();
        }
        cout << copiedStack.top() << endl;
        break;
    default:
        break;
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);
    int t = stoi(ltrim(rtrim(t_temp)));
    stack<int> s, r;
    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string m_temp;
        getline(cin, m_temp);
        queueTwoStacks(ltrim(rtrim(m_temp)), s, r);
    }
    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c)
                { return !ispunct(c); }));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c)
                { return !ispunct(c); })
            .base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

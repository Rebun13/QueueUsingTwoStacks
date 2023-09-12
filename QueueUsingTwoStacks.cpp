#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
* The function accepts string query and stack<int> stack as parameters.
 */
void queueTwoStacks(string query, stack<int> &s) {
    stack<int> reverseStack;
    switch (query[0])
    {
    case '1':
        s.push(stoi(query.substr(2, query.size() - 2)));
        break;
    case '2':
        while(s.size() > 1) {
            reverseStack.push(s.top());
            s.pop();
        }
        s.pop();
        while(!reverseStack.empty()) {
            s.push(reverseStack.top());
            reverseStack.pop();
        }
        break;
    case '3':
        while(s.size() > 1) {
            reverseStack.push(s.top());
            s.pop();
        }
        cout << s.top() << endl;
        while(!reverseStack.empty()) {
            s.push(reverseStack.top());
            reverseStack.pop();
        }
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
    stack<int> s;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string m_temp;
        getline(cin, m_temp);
        
        queueTwoStacks(ltrim(rtrim(m_temp)), s);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


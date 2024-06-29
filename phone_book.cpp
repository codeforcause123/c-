#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Problem
{
    string type, name;
    int number;
};

vector<Problem> read_question()
{
    int n;
    cin >> n;
    vector<Problem> issue(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> issue[i].type;
        if (issue[i].type == "add")
            cin >> issue[i].number >> issue[i].name;
        else
            cin >> issue[i].number;
    }
    return issue;
}

void write_responses(const vector<string> &result)
{
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_issue(const vector<Problem> &issue)
{
    vector<string> result;
    vector<Problem> contacts;
    map<int, string> phonebook;
    for (size_t i = 0; i < issue.size(); ++i)
    {
        int num = issue[i].number;
        if (issue[i].type == "add")
        {
            bool was_founded = false;
            if (phonebook.find(num) != phonebook.end())
            {
                phonebook[num] = issue[i].name;
            }
            else
            {
                phonebook[num] = issue[i].name;
            }
        }
        else if (issue[i].type == "del")
        {
            if (phonebook.find(num) != phonebook.end())
            {
                phonebook.erase(phonebook.find(num));
            }
        }
        else
        {
            string response = "not found";
            if (phonebook.find(num) != phonebook.end())
            {
                response = phonebook[num];
            }
            result.push_back(response);
        }
    }
    return result;
}

int main()
{
    write_responses(process_issue(read_question()));
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using namespace std;

auto Comparator = [](const pair<int, long long> o1, const pair<int, long long> o2)
{
    if ((o1.second) == (o2.second))
        return (o1.first > o2.first);
    else
        return ((o1.second) > (o2.second));
};

class Numberparallel
{
private:
    int earner;
    vector<int> tasks;

    vector<int> alotearner;
    vector<long long> begintime;

    void WriteResponse() const
    {
        for (int i = 0; i < tasks.size(); ++i)
        {
            cout << alotearner[i] << " " << begintime[i] << "\n";
        }
    }

    void ReadData()
    {
        int m;
        cin >> earner >> m;
        tasks.resize(m);
        for (int i = 0; i < m; ++i)
            cin >> tasks[i];
    }

    void AssignJobs()
    {
        alotearner.resize(tasks.size());
        begintime.resize(tasks.size());
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(Comparator)> q(Comparator);
        for (int i = 0; i < earner; i++)
        {
            q.push(make_pair(i, 0));
        }
        for (int i = 0; i < tasks.size(); i++)
        {
            int time = tasks[i];
            pair<int, long long> p;
            p = q.top();
            q.pop();
            alotearner[i] = p.first;
            begintime[i] = p.second;
            q.push(make_pair(p.first, p.second + time));
        }
    }

public:
    void Solve()
    {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    Numberparallel job_queue;
    job_queue.Solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> pr = {1, 2};
    pair<int, int> pr1 = {1, 3};
    pair<int, int> pr2 = {2, 2};
    cout << pr.first << " " << pr.second << endl;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(pr);
    pq.push(pr1);
    pq.push(pr2);
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
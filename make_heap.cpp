#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;
using namespace std;

class ArraytoHeap
{
private:
    vector<int> info_;
    vector<pair<int, int>> switch1;
    int n;

    void WriteResponse() const
    {
        cout << switch1.size() << "\n";
        for (int i = 0; i < switch1.size(); ++i)
        {
            cout << switch1[i].first << " " << switch1[i].second << "\n";
        }
    }

    void ReadData()
    {
        cin >> n;
        info_.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> info_[i];
    }

    void sink(int k)
    {
        while (2 * k <= n)
        {
            int j = 2 * k;
            if (j < n && greater(j, j + 1))
            {
                j++;
            }
            if (!greater(k, j))
            {
                break;
            }
            swap(info_, k, j);
            k = j;
        }
    }

    bool greater(int i, int j)
    {
        return info_[i] > info_[j];
    }

    void swap(vector<int> &data, int i, int j)
    {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        switch1.push_back(make_pair(i - 1, j - 1));
    }

    void GenerateSwaps()
    {

        for (int i = n / 2; i >= 1; i--)
        {
            sink(i);
        }
    }

public:
    void Solve()
    {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    ArraytoHeap heap_builder;
    heap_builder.Solve();
    return 0;
}
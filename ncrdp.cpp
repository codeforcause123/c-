#include <bits/stdc++.h>
using namespace std;
vector<long long> memo(100, 1);
long long fact(long long n)
{
    memo[0] = 1;
    if (memo[n] != 1)
    {
        return memo[n];
    }
    for (long long i = 1; i <= n; i++)
    {
        memo[i] = i * memo[i - 1];
    }
    return memo[n];
}
long long ncr(long long n, long long r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int main()
{
    long long n = 20, r = 10;
    cout << ncr(n, r) << endl;
    return 0;
}
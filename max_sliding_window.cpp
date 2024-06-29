#include <iostream>
#include <vector>
#include<deque>
using namespace std;
void max_sliding_window_naive(vector<int> const & V, int k) {
    deque<int> dq;
    for(int i=0;i<V.size();i++){
        if(!dq.empty() && i-dq.front()==k) dq.pop_front();
        while(!dq.empty() && V[i]>V[dq.back()])
            dq.pop_back();
        dq.emplace_back(i);
        if(i-k+1>=0) cout<<V[dq.front()]<<" ";
    }
    cout<<endl;
    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> V(n);
    for (int i = 0; i < n; ++i)
        cin >> V.at(i);

    int k = 0;
    cin >> k;
    max_sliding_window_naive(V, k);
    return 0;
}
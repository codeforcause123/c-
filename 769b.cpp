#include<bits/stdc++.h>
using namespace std;
#define Endl '\n'
typedef long long int lli;
typedef pair<int, int> ii;
void solve();
int main(int argc, char const *argv[]){
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  solve();
}
void solve(){
  int n;
  cin>>n;
  ii a[n];
  int a2[n];
  for(int i=0;i<n;i++)
    cin>>a[i].first, a[i].second = i, a2[i] = a[i].first;
 
 
  sort(a+1, a+n, greater<>());
  int order[n];
  for(int i=0;i<n;i++)
    order[i] = a[i].second;
 
  bool visited[n] = {false};
  visited[0] = true;
  deque<int> qs; qs.push_front(0);
  int total = 0;
  vector<ii> ans;
  while(qs.size()!=0){
    int next = qs.front();
    qs.pop_front();
    for(int i=0;i<n;i++){
      if(visited[order[i]] !=1){
        visited[order[i]] = true;
        total++;
        qs.push_front(order[i]);
        ans.push_back(ii(next+1, order[i]+1));
        a2[next]--;
      }
      if(a2[next] == 0)
        break;
    }
  }
 
for(int i=0;i<n;i++)
  if(visited[i] == false){
    cout<<-1<<endl;
    return;
  }
 
  cout<<total<<endl;
  for(ii i: ans){
    cout<<i.first<<" "<<i.second<<endl;
  }
}
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
#define pii pair<int,int>
#define INFL 2047483647
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
const int N = 305;
int processed[N],d[N];
int adj[N][N];
int p[N];
int sp[N];
int n;
void dijkstra(int s) {
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    sp[s] = s;
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (int to=0;to<n;to++) {
            int len = adj[v][to];
            if( len<=0 ) continue;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                if( v == s ) sp[to] = to;
                else sp[to] = sp[v];
                q.insert({d[to], to});
            }
        }
    }
}


int main(){
    FASTIO;

    cin>>n;


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    for(int s=0;s<n;s++){
        for(int i=0;i<n;i++){
            d[i] = INFL;
            p[i] = -1;
            sp[i] = -1;
        }
        dijkstra(s);
//        for(int i=0;i<n;i++){
//            cout<<i<<" "<<p[i]<<" "<<sp[i]<<" "<<d[i]<<endl;
//        }
        int mn = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( adj[i][j]<=0 ) continue;
                if( p[i] == j or p[j] == i ) continue;
                if( sp[i] == sp[j] ) continue;
                int tmp = d[i]+d[j]+adj[i][j];
                if( mn == -1 ) mn = tmp;
                mn = min(mn,tmp);
            }
        }
        cout<<mn<<endl;
    }
}
/*
4
0 9 1 1
9 0 -1 1
1 -1 0 -1
1 1 -1 0


*/

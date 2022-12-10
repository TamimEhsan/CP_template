#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct My_Pq{

    priority_queue<ll, vector<ll>, greater<ll> > ins;
    priority_queue<ll, vector<ll>, greater<ll> > ers;

    void erase(ll u){
        ers.push(u);
    }
    void push(ll u){
        ins.push(u);
    }
    bool empty(){
        while( ers.size()!=0 and ins.top() == ers.top() ) {
            ers.pop();
            ins.pop();
        }
        return ins.empty();
    }
    ll top(){
        while( ers.size()!=0 and ins.top() == ers.top() ) {
            ers.pop();
            ins.pop();
        }
        if( !ins.empty() ) return ins.top();
        return 0;
    }
    void pop(){
        while( ers.size()!=0 and ins.top() == ers.top() ) {
            ers.pop();
            ins.pop();
        }
        if( !ins.empty() ) ins.pop();
    }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	solve();
}



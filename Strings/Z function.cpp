#include<bits/stdc++.h>
using namespace std;


// The Z-function for this string is an array of length n
// where the i-th element is equal to the greatest number
// of characters starting from the position i that coincide
// with the first characters of s.

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    string S;
    cin>>S;
    int n = S.size();
    auto z = z_function(S);
    set<int>s;
    int res = -1;
    for(int i=1;i<n;i++){
        if( s.lower_bound(z[i])!=s.end() and z[i] + i == n ) res = max(res,z[i]);
        s.insert(z[i]);
    }
    if(res>0)
        cout<<S.substr(n-res,res);
    else
        cout<<"Just a legend";
}

// https://codeforces.com/problemset/problem/126/B

#include<bits/stdc++.h>
using namespace std;

// Complexity O(n)
// The prefix function for this string is defined
// as an array π of length n, where π[i] is the length
// of the longest proper prefix of the substring s[0…i]
// which is also a suffix of this substring.
// eg.  a b c a b c d
//      0 0 0 1 2 3 0  => in abcabc there is a length of 3 substring which is both prefix and suffix
// Kind of same as Z function :/  so pretty useless it is

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    for(auto v: prefix_function("abcabcd")) cout<<v<<" ";
}

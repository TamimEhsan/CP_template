// Copied shamelessly from https://github.com/ShahjalalShohag/code-library
// 0 Indexed
// Matrix entry A.a[i][j]

#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
struct Mat {
    int n, m;
    vector<vector<int>> a;
    Mat() { }
    Mat(int _n, int _m) {n = _n; m = _m; a.assign(n, vector<int>(m, 0)); }
    Mat(vector< vector<int> > v) { n = v.size(); m = n ? v[0].size() : 0; a = v; }
    inline void make_unit() {
        assert(n == m);
        for (int i = 0; i < n; i++)    {
            for (int j = 0; j < n; j++) a[i][j] = i == j;
        }
    }
    inline Mat operator + (const Mat &b) {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return ans;
    }
    inline Mat operator - (const Mat &b) {
        assert(n == b.n && m == b.m);
        Mat ans = Mat(n, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans.a[i][j] = (a[i][j] - b.a[i][j] + mod) % mod;
            }
        }
        return ans;
    }
    inline Mat operator * (const Mat &b) {
        assert(m == b.n);
        Mat ans = Mat(n, b.m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < b.m; j++) {
                for(int k = 0; k < m; k++) {
                    ans.a[i][j] = (ans.a[i][j] + 1LL * a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return ans;
    }
    inline Mat pow(long long k) {
        assert(n == m);
        Mat ans(n, n), t = a; ans.make_unit();
        while (k) {
            if (k & 1) ans = ans * t;
            t = t * t;
            k >>= 1;
        }
        return ans;
    }
    inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
    inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
    inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
    inline bool operator == (const Mat& b) { return a == b.a; }
    inline bool operator != (const Mat& b) { return a != b.a; }
};

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    Mat A(n,m);
    Mat B(m,k);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>A.a[i][j];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++)
            cin>>B.a[i][j];
    }
    Mat C = A*B;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++)
            cout<<C.a[i][j]<<" ";
        cout<<endl;
    }
}


//https://judge.yosupo.jp/problem/matrix_product


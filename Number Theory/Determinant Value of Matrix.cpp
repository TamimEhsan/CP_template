#include<bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

/*
    Kirchhoff’s theorem provides a way to calculate
    the number of spanning trees of a graph as a
    determinant of a special matrix.
*/

const double EPS = 1E-9;
vector< vector<int> > adj;

// Finding determinant of a matrix in O(n^3)  by using the Gaussian method.
double determinant(vector< vector<double> > a, int n){

    double det = 1;
    for (int i=0; i<n; ++i) {
        int k = i;
        for (int j=i+1; j<n; ++j)
            if (abs (a[j][i]) > abs (a[k][i]))
                k = j;
        if (abs (a[k][i]) < EPS ) {
            det = 0;
            break;
        }
        swap (a[i], a[k]);
        if (i != k)
            det = -det;
        det *= a[i][i];
        for (int j=i+1; j<n; ++j)
            a[i][j] /= a[i][i];
        for (int j=0; j<n; ++j)
            if (j != i && abs (a[j][i]) > EPS)
                for (int k=i+1; k<n; ++k)
                    a[j][k] -= a[i][k] * a[j][i];
    }

    return det;
}

int findSpanningTreeNumber(){
    int n = adj.size();
    vector< vector<double> > laplace(n, vector<double> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) laplace[i][j] = 0;
    }
    for(int i=0;i<n;i++) {
        laplace[i][i] = adj[i].size();
    }
    for(int i=0;i<n;i++){
        for(int v:adj[i]){
            laplace[i][v] = -1;
        }
    }
    return determinant(laplace,n-1);
}

int main(){
    vector<vector<double>> det
    {
        {1, 2, 3},
        {4, 5, 11},
        {7, 8, 10}
    };
    cout<<determinant(det,det.size()); // 27
}

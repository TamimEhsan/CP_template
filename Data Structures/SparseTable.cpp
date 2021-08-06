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
    Sparse table may be used for a range query where
    the existence of an element matters, but not the count of
    the element. ie just presence.
    example: min,max,gcd,and etc
    not possible: xor,sum etc
*/
/*
    All the datatypes T should be same
    for the comparator function, the return type and parameters too
*/

template <class T>
class STable
{
    int n;
    pair<int,int> *cal;
    vector<T> *SparseTable;
    T (*comp)(T,T);
    void initialize()
    {
        int i,j;
        cal[1].second=1;
        for(i=1,j=1<<i; j<=n; i++,j=1<<i)
        {
            cal[j].first=1;
            cal[j].second=j;
        }
        for(i=2; i<=n; i++)
        {
            cal[i].first=cal[i].first+cal[i-1].first;
            if(cal[i].second==0) cal[i].second=cal[i-1].second;
        }
    }
public:
    STable(vector<T> &arr,T (*f)(T,T))
    {
        n=arr.size();
        comp=f;
        cal=new pair<int,int>[n+1];
        initialize();
        SparseTable=new vector<T>[n];
        int i,j,m;
        for(i=0,j=0; i<n; i++)
        {
            SparseTable[i].push_back(arr[i]);
        }
        for(j=0,m=1<<j; m<n; j++,m=1<<j)
        {
            for(i=0; i+m<n; i++)
            {
                SparseTable[i].push_back(comp(SparseTable[i][j],SparseTable[i+m][SparseTable[i+m].size()-1]));
            }
        }
    }
    T query(int l,int r)
    {
        int difference=(r-l+1);
        return comp(SparseTable[l][cal[difference].first],SparseTable[r-cal[difference].second+1][cal[difference].first]);
    }
    ~STable()
    {
        int i;
        for(i=0;i<n;i++)
        {
            SparseTable[i].clear();
        }
        delete []SparseTable;
        delete []cal;
        comp=0;
    }
};
pair<char,int> minimum(pair<char,int> a,pair<char,int> b)
{
    if( a.F<= b.F ) return a;
    else return b;
}
vector<pair<char,int>> arr;//Push your data here

int main(){

    int tc = 1;
    //cin>>tc;
    while(tc--){
        string s;
        int k;
        cin>>s>>k;
        int n = s.size();
        for(int i=0;i<n;i++)
            arr.pb(mp(s[i],i)); // vector which is to be used for creating parse table
            //Code here
        STable<pair<char,int>> st_min(arr,minimum);
        //*st_min.query(l,r) (0 indexed)*//
        int firstPos = 0;
        int lastPos = n-k;
        for(int i=0;i<k;i++){
            pair<char,int> p = st_min.query(firstPos,lastPos);
            cout<<firstPos<<" "<<lastPos<<" "<<s[p.S]<<endl;;
            firstPos= p.S+1;
            lastPos++;
        }
    }
}

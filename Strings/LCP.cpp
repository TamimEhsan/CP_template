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

// Finds the longest common prefix of two consecutive element of suffix array

class Substring{
    public:
    string s;
    int n;
    vector<int> suffix_array,lcp,c;
    Substring(string str){
        s = str;
        s+="$";
        n = s.size();
        suffix_array_construction();
    }
    vector<int> sort_cyclic_shifts() {
       // int n = s.size();
        const int alphabet = 256;
        vector<int>  p(n),cnt(max(alphabet, n), 0);
        c.resize(n);
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 1; i < alphabet; i++)
            cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++)
            p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (s[p[i]] != s[p[i-1]])
                classes++;
            c[p[i]] = classes - 1;
        }
        vector<int> pn(n), cn(n);
        for (int h = 0; (1 << h) < n; ++h) {
            for (int i = 0; i < n; i++) {
                pn[i] = p[i] - (1 << h);
                if (pn[i] < 0)
                    pn[i] += n;
            }
            fill(cnt.begin(), cnt.begin() + classes, 0);
            for (int i = 0; i < n; i++)
                cnt[c[pn[i]]]++;
            for (int i = 1; i < classes; i++)
                cnt[i] += cnt[i-1];
            for (int i = n-1; i >= 0; i--)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
                pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
                if (cur != prev)
                    ++classes;
                cn[p[i]] = classes - 1;
            }
            c.swap(cn);
        }
        return p;
    }
    void suffix_array_construction() {
        suffix_array = sort_cyclic_shifts();
    }
    vector<int> get_suffix_array(){
        vector<int> sorted_shifts = suffix_array;
        sorted_shifts.erase(sorted_shifts.begin());
        return sorted_shifts;
    }
    vector<int> get_lcp(){
        vector<int> _lcp = lcp;
        _lcp.erase(_lcp.begin());
        return _lcp;
    }
    int getSubstringNumber(string t){
        int m = t.size();
        int L = 0,R = n-1;
        bool isPres = true;
        for(int i=0;i<m;i++){
            int l = L,r = R;
            int res = R+1;
            // upper bound
            while(l<=r){
                int mid = (l+r)/2;
                if( suffix_array[mid]+i>=n or s[ suffix_array[mid]+i ]<=t[i] ){
                    l = mid+1;
                }else{
                    res = mid;
                    r = mid-1;
                }
            }
            if(  res == 0 or suffix_array[res-1]+i>=n or s[ suffix_array[res-1]+i ] != t[i] ){
                isPres = false;
                break;
            } else{
                R = res-1;
            }
            // lower bound
            l = L; r = R;
            res = -1;
            while(l<=r){
                int mid = (l+r)/2;
                if( suffix_array[mid]+i>=n or s[ suffix_array[mid]+i ]<t[i] ){
                    l = mid+1;
                }else{
                    res = mid;
                    r = mid-1;
                }
            }
            if( res == -1 or suffix_array[res]+i>=n or s[ suffix_array[res]+i ] != t[i] ){

                isPres = false;
                break;
            } else{
                L = res;
            }
        }
        if( isPres ){
            return R-L+1;
        } else{
            return 0;
        }
    }

    void createLCP(){
        int k = 0;
        lcp.resize(n);
        for(int i=0;i<n-1;i++){
            int pi = c[i];
            int j = suffix_array[pi-1];
            while( s[i+k] == s[j+k] ) k++;
            lcp[pi] = k;
            k = max(k-1,0);
        }
    }
};

int main(){
    string s = "ababba";
   // cin>>s;
    int n = s.size();
    Substring sbstr = Substring(s);
    // Output suffix array
    vector<int> suffix = sbstr.get_suffix_array();
    for(int i=0;i<suffix.size();i++){
        printf("%d ",suffix[i]);
    }
    printf("\n");
    // creating and output Longest common prefix array
    sbstr.createLCP();
    vector<int> lcp = sbstr.get_lcp();
    for(int i=0;i<lcp.size();i++){
        printf("%d ",lcp[i]);
    }
    printf("\n");

    // Counting number of different substring
    ll substrng_cnt = 0;
    for(int i=0;i<n;i++){
        substrng_cnt+= n-suffix[i]-lcp[i];
    }
    cout<<"Number of different substrings are "<<substrng_cnt<<endl;

    // Finding longest common substring in two string
    string t = "baba";
    int m = t.size();
    string st = s+"%"+t;
    Substring sub = Substring(st);
    sub.createLCP();
    lcp = sub.get_lcp();
    suffix = sub.get_suffix_array();
    int mx = -1,pos = -1;
    for(int i=1;i<suffix.size();i++){
        if(( suffix[i]>n and suffix[i-1]<n ) or ( suffix[i]<n and suffix[i-1]>n )){
            if( lcp[i]>mx ){
                mx = lcp[i];
                pos = suffix[i];
            }
        }
    }
    cout<<"Longest common substring of string "<<s<<" "<<t<<" is "<<st.substr(pos,mx)<<endl;


}

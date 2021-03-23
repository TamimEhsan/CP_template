#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFL 9223372036854775807
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define M 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353



struct xor_save {
    int v,pos;

    xor_save() {}

    xor_save(int _v, int _pos)
        : v(_v), pos(_pos) {}
};

int findmsb(int n){
    int pos = 0;
    while(n){
        n/=2;
        pos++;
    }
    return pos;
}

struct xor_with_rollbacks {
    vector<int> basis;
    int maxXor;
    stack<xor_save> op;
    int bits = 35;

    xor_with_rollbacks() {
        basis.resize(bits);
        for (int i = 0; i < bits; i++) {
            basis[i] = 0;
        }
        maxXor = 0;
    }

    bool inserts(int v){
        bool inserted = false;
        int pos;
        while(v){
            pos = findmsb(v);
            if( basis[pos] == 0 ){
                basis[pos] = v;
                inserted = true;
                break;
            }else{
                v = v^basis[pos];
            }
        }
        if(!inserted) return false;
        op.push( xor_save(v,pos) );
        return true;
    }



    void rollback() {
        if (op.empty())
            return;
        xor_save x = op.top();
        op.pop();
        basis[x.pos] = 0;
    }
    int calculateXor(){
        int xorr = 0;
        for(int i=33;i>0;i--){
            if( (xorr^basis[i])>xorr ) xorr = xorr^basis[i];
        }
        return xorr;
    }
};

struct query {
    int v;
    bool united;
    query(int _v) : v(_v){
    }
};

struct QueryTree {
    vector<vector<query>> t;
    xor_with_rollbacks dynamic;
    int T;

    QueryTree() {}

    QueryTree(int _T, int n) : T(_T) {
        dynamic = xor_with_rollbacks();
        t.resize(4 * T + 4);
    }
    // don;t touch
    void add_to_tree(int v, int l, int r, int ul, int ur, query& q) {
        if (ul > ur)
            return;
        if (l == ul && r == ur) {
            t[v].push_back(q);
            return;
        }
        int mid = (l + r) / 2;
        add_to_tree(2 * v, l, mid, ul, min(ur, mid), q);
        add_to_tree(2 * v + 1, mid + 1, r, max(ul, mid + 1), ur, q);
    }

    void add_query(query q, int l, int r) {
        add_to_tree(1, 0, T - 1, l, r, q);
    }
    //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    void dfs(int v, int l, int r, vector<int>& ans,vector<int>& isaquery) {
        for (query& q : t[v]) {
            q.united = dynamic.inserts(q.v); //<< saving if inserted the value or not
        }
        if (l == r  ){
            if(isaquery[l])ans[l] = dynamic.calculateXor(); //<< store the query answer here in leaf node and was asked to answer
        } else {
            int mid = (l + r) / 2;
            dfs(2 * v, l, mid, ans,isaquery);
            dfs(2 * v + 1, mid + 1, r, ans,isaquery);
        }
        for (query q : t[v]) {
            if (q.united)
                dynamic.rollback(); // if this value was inserted then we roll back
        }
    }

    vector<int> solve(vector<int>& isaquery ) {
        vector<int> ans(T);
        dfs(1, 0, T - 1, ans,isaquery);
        return ans;
    }
};

int main(){
   // freopen("connect.in","r",stdin);
  //  freopen("connect.out","w",stdout);
    int n,q,a,b;
    scanf("%d %d",&n,&q);
    QueryTree qt(q+1,n);
    vector<int> isaquery;
    isaquery.resize(q+5,0);
    map< int,int> e;
    for(int i=1;i<=q;i++){
        char c;
        cin>>c;
        isaquery[i] = 0;
        if( c == '+' ){

            scanf("%d",&a);
            e[a] = i; // marking the start of an edge
        } else if( c == '-' ){
            // here the node got destroyed right? so it was alive for e[{a,b}] to i-1
            scanf("%d",&a);
            qt.add_query( query(a),e[a],i-1 );
            e.erase(a); // deleting the occurance of this
        }else{
            isaquery[i] = 1;
        }
    }
    // so now we have handled all the created and deleted nodes.
    // so all that lefts are nodes who remained alive for all the time
    for( auto it = e.begin();it!=e.end();++it ){
        qt.add_query( query( it->F ),it->S,q ); // remember we stored e[{a,b}] = position. so starts at pos and ends at q (always was)
    }

    vector<int> res = qt.solve(isaquery);
        for(int i=1;i<=q;i++){
        if(isaquery[i])
        {
            printf("%d\n",res[i]);
        }
    }

   // fclose(stdout);
    return 0;
}
/*

9 10
+ 1
+ 2
?
+ 3
?
- 2
?
+ 4
+ 2
?

*/

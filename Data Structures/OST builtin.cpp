#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define pii pair<int,int>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r){return uniform_int_distribution<int>(l,r) (rng);}

typedef tree < int,  null_type,  less < int >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;
typedef tree < pair < int, int >,  null_type,  less < pair < int, int > >,  rb_tree_tag,  tree_order_statistics_node_update > o_setp;
 o_set s;


/**
the tree supports the same operations as the set
but also there are two new features —
find_by_order() : The first returns an iterator to the k-th largest element (counting from zero)
order_of_key() : The number of items in a set that are strictly smaller than our item.
*/

int main(){

    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(8);
    s.insert(16);

    cout<<*s.find_by_order(1)<<endl; // 2
    cout<<*s.find_by_order(2)<<endl; // 4
    cout<<*s.find_by_order(4)<<endl; // 16
    cout<<endl;
    cout<<(end(s)==s.find_by_order(6))<<endl; // true
    cout<<endl;
    cout<<s.order_of_key(-5)<<endl;  // 0
    cout<<s.order_of_key(1)<<endl;   // 0
    cout<<s.order_of_key(3)<<endl;   // 2
    cout<<s.order_of_key(4)<<endl;   // 2
    cout<<s.order_of_key(400)<<endl; // 5
    cout<<endl;
    cout<<(end(s)==s.find(18))<<endl; //true 1 => 18 is not present in set
    cout<<(end(s)==s.find(8))<<endl; //false 0 => 8 is present in set
    cout<<endl;
    cout<<s.size()<<endl; // 5
    s.erase(2);
    cout<<s.size()<<endl; // 4
}

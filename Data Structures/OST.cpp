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
#define M 1000'000'007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

/**
    OST using BIT
    1- indexed
    order_of_key(x):    find the the number of entries lower than or equal to x
    find_by_order(k):   find the kth smallest number
    find(x):            find if a number is present in set
    erase(x):           delete a entry
    insert(x):          enter a entry
*/

class OST{
    int MAX_VAL = 1429450;
    vector<int> BIT;
    void update(int i, int add){
        while (i > 0 && i < BIT.size()){
            BIT[i] += add;
            i = i + (i & (-i));
        }
    }

    int sum(int i){
        int ans = 0;
        while (i > 0){
            ans += BIT[i];
            i = i - (i & (-i));
        }
        return ans;
    }
public:
    OST(int val){
        MAX_VAL = val;
        BIT.resize(MAX_VAL);
    }
    int find_by_order(int k){
        int l = 0;
        int h = BIT.size();
        while (l < h){
            int mid = (l + h) / 2;
            if (k <= sum(mid))
                h = mid;
            else
                l = mid+1;
        }
        return l;
    }

    void insert(int x){
        if( /*find(x) or*/ x<=0 or x>=BIT.size() ) return;
        update(x, 1);
    }

    void erase(int x){
        if( !find(x) ) return;
        update(x, -1);
    }


    int order_of_key(int x){
        if( x<=0 ) return 0;
        if( x>BIT.size() ) return sum( BIT.size()-1 );
        return sum(x);
    }
    bool find(int x){
        if( x<=0 or x>=BIT.size() ) return false;
        return sum(x)-sum(x-1)>0 ;
    }
    int size(){
        return sum( BIT.size()-1 );
    }

};
int main(){
    OST s(100); // we can add numbers from 1 to 99
    s.insert(1);s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(8);
    s.insert(16);
    s.insert(16);


    cout<<s.find_by_order(1)<<endl; // 1
    cout<<s.find_by_order(2)<<endl; // 2
    cout<<s.find_by_order(4)<<endl; // 8

    cout<<s.find_by_order(6)<<endl; // 100 = size means the element is not in set
    cout<<endl;

    cout<<endl;
    // order of key = number of elements less than or equal to key
    cout<<s.order_of_key(-5)<<endl;  // 0
    cout<<s.order_of_key(1)<<endl;   // 1
    cout<<s.order_of_key(3)<<endl;   // 2
    cout<<s.order_of_key(4)<<endl;   // 3
    cout<<s.order_of_key(20)<<endl; // 5
    cout<<endl;
    cout<<s.find(18)<<endl; //false 0 => 18 is not present in set
    cout<<s.find(8)<<endl; //true 1 => 8 is present in set
    cout<<endl;
    cout<<s.size()<<endl; // 5
    s.erase(2);
    s.erase(3);
    cout<<s.size()<<endl; // 4

}

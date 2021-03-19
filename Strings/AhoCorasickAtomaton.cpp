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
//#define M 1000000007
#define M 998244353
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define take(x) scanf("%d",&x)
#define DE(x) printf("\ndebug %d\n",x);
#define vout(x) for(int i=0;i<x.size();i++) printf("%d ",x[i]);
#define pie acos(-1)
#define MOD 998244353

#define maxn 100005

vector <int> wasHere[maxn] , pos[maxn] , active ;

class ahoCorasic
{
public:
    int sigma , maxSize , curSize ;
    int **to , *link ;
    vector <int> *endedHere ;
    //0 based trie, 0 is the root, curSize denote the number of states now, 0 ,1,....,curSize-1
    //endedHere[i] = the strings ended in the i'th node of trie
    //to[i][j] = 0, if there is no such state, otherwise it denotes the state to go from i, after adding j'th symbol
    //g[i][....] contains the node whose suffix link is to i, that means link[ g[i][j] ] = i
    //sigma = size of alphabet , link[i] points to the max suffix of string ended at i'th node

    ahoCorasic( int _sigma , int _maxSize )
    {
        sigma = _sigma ;
        maxSize = _maxSize ;
        to = new int*[maxSize+2] ;
        for(int i=0 ; i<maxSize+2 ; i++)
        {
            to[i] = new int[sigma] ;
            for(int j=0 ; j<sigma ; j++) to[i][j] = 0 ;
        }
        link = new int[maxSize+2] ;
        curSize = 1 ;
        endedHere = new vector<int>[maxSize+2] ;
    }
    void addString(string const& S ,int idx )
    {
        int cur = 0 ;
        for( auto ch : S )
        {
            if( to[cur][ ch-'a' ]==0 ) to[cur][ch-'a'] = curSize++ ;
            cur = to[cur][ ch-'a' ] ;
        }
        endedHere[cur].pb(idx) ;
        // now the value of cur is where the string ended , you may do whatever you want
    }
    void findSuffixLink()
    {
        int i ;
        queue < int > q ;
        for(i=0 ; i<sigma ; i++)  // finds if a node exists or not from 0. if not, then point to first node.
        {
            if( to[0][i] != 0 )
            {
                link[ to[0][i] ] = 0 ;
                q.push(to[0][i]) ;
            }
        }

        while(!q.empty())
        {
            int state = q.front() ;
            q.pop() ;

            for(int ch = 0 ; ch<sigma ; ch++)
            {
                if( to[state][ch]!=0 )
                {
                    int failure = link[state] ;
                    while( failure != 0 && to[failure][ch]==0 ) failure = link[failure] ;
                    link[ to[state][ch] ] = to[ failure ][ch] ;
                    q.push( to[state][ch] ) ;
                }
            }
        }
    }
    int findNextState( int state , int input)
    {
        while( state!=0 && to[ state ][input]==0 ) state = link[state] ;
        return to[ state ][input] ;
    }
    void searchWord( string const& S )
    {
        int cur = 0 ;
        for(int i=0; i<S.size(); i++)
        {
            char ch = S[i] ;
            cur = findNextState(cur,ch-'a') ; // found the state where machine would come after S[0...i]

            // printing the words ending here
            cout<<"ends at  "<<i<<" ";
            for(int j=0;j<endedHere[cur].size();j++){
                cout<<endedHere[cur][j]<<" ";
            }
            cout<<endl;
        }
        return ;
    }
    ~ahoCorasic()
    {
        for(int i=0 ; i<maxSize+2 ; i++)
        {
            delete to[i] ;
            endedHere[i].clear() ;
        }
        delete to ;
        delete endedHere ;
        delete link ;
    }
};

int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    ahoCorasic ac(26,10);
    string strings[n];
    for(int i=0;i<n;i++){
        cin>>strings[i];
        ac.addString(strings[i],i);
    }
    ac.findSuffixLink();
    ac.searchWord(s);
}

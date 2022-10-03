#include<bits/stdc++.h>
using namespace std;

const int N = 1000006;
int n,bridge,m;
int bcc[N],comp[N], link[N],SZ[N];
void init()
{
    for(int i = 0;i < n; i ++ ){
        bcc[i] = comp[i] = i;   // BCC and CC of a node, Initially all are isolate.
        link[i] = -1;           // Link to the parent in a CC
        SZ[i] = 1;              // Size of a CC
    }
    bridge = 0;
}
// Output the BCC of a node
int getBCC(int a)
{
    if(a==-1)return -1;
    if(bcc[a]==a) return a;
    else return bcc[a] = getBCC(bcc[a]);
}
// Output the root of the component where a is.
int getCOMP(int a)
{
    if(comp[a]==a) return a;
    else return comp[a] = getCOMP(comp[a]);
}
// Merging two path, a->lca, b->lca.
int cs = 0, vis[N];
void MergePath(int a,int b)
{
    cs++;
    a = getBCC(a);
    b = getBCC(b);
    vector<int> va,vb;
    int lca = -1;
    while(1) {
        if(a!=-1) {
            a = getBCC(a);
            va.push_back(a);
            if(vis[a] == cs) {
                lca = a;
                break;
            }
            vis[a] = cs;
            a = link[a];
        }
        if(b!=-1) {
            b = getBCC(b);
            vb.push_back(b);
            if(vis[b]==cs) {
                lca = b;
                break;
            }
            vis[b] = cs;
            b = link[b];
        }
    }
    for(int i = 0;i < va.size();i  ++) {
        bcc[va[i]] = lca;   // Compressing in same BCC
        if(va[i]==lca) break;
        bridge --;
    }
    for(int i = 0;i < vb.size() ; i ++ ) {
        bcc[vb[i]] = lca;   // Compressing in same BCC
        if(vb[i]==lca) break;
        bridge --;
    }

}

// This reverses the edge of a to root of the connected component
void MakeRoot(int a)
{
    int root = a,child = -1;
    while(a!=-1) {
        int p = getBCC(link[a]);
        link[a] = child;
        comp[a] = root;
        child = a;
        a = p;
    }
    SZ[root] = SZ[child];
}


void addEdge(int a,int b)
{
    a = getBCC(a), b= getBCC(b);
    if(a==b) return;   // Case 1

    int u = getCOMP(a), v = getCOMP(b);
    if(u!=v) {      // Case 2
        bridge ++;
        if(SZ[u] > SZ[v]) {
            swap(a,b);
            swap(u,v);
        }
        MakeRoot(a);
        link[a] = comp[a] = b;
        SZ[v] += SZ[a];
    }
    else MergePath(a,b);    // Case 3
}
int main()
{

    int t;
    cin >> t;
    for(int i=1;i<=t;i++) {
        cin >> n >> m;
        init();
        printf("Case %d: \n",i);
        for(int i= 1;i <= m; i ++ ) {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;b--;
            addEdge(a,b);
            double somethn = bridge;
            somethn/=i;
            printf("%.4f\n",somethn);
        }
    }
    return 0;
}

///aho corasick///
namespace AC{
    const int AlphabetSize=26;
    struct Vertex{
        int next[AlphabetSize];
        int go[AlphabetSize];
        int leaf=-1;
        int p=-1;
        char pch;
        int elink=-1;//link to the maximum proper suffix of current string
        int vlink=-1;//link to the maximum proper suffix of current string which is also a string in the given set
        Vertex(int  p=-1,char pch='$'):p(p),pch(pch)
        {
            memset(next,-1,sizeof(next));
            memset(go,-1,sizeof(go));
        }
        void reset()
        {
            memset(next,-1,sizeof(next));
            memset(go,-1,sizeof(go));
            leaf=p=elink=vlink=-1;
        }
    };
    const int MaxLength=1e6;
    Vertex trie[MaxLength];
    int curSize=1;

    //returns identifier of the string currently at the end vertex of s
    int addString(const string& s,int id)//id should be unique identifier of the string
    {
        int v=0;
        for(char ch:s)
        {
            int c=ch-'a';
            if(trie[v].next[c]==-1)
            {
                trie[curSize].p=v;
                trie[curSize].pch=ch;
                trie[v].next[c]=curSize++;
            }
            v=trie[v].next[c];
        }
        if(trie[v].leaf==-1)
            trie[v].leaf=id;
        return trie[v].leaf;
    }
    int addString(char* s,int id)
    {
        int v=0;
        while(*s!='\0')
        {
            int c=*s-'a';
            if(trie[v].next[c]==-1)
            {
                trie[curSize].p=v;
                trie[curSize].pch=*s;
                trie[v].next[c]=curSize++;
            }
            v=trie[v].next[c];
            ++s;
        }
        if(trie[v].leaf==-1)
            trie[v].leaf=id;
        return trie[v].leaf;
    }

    //should be called after adding all string to the trie
    void constructAutomation(void)
    {
        trie[0].elink=0;
        trie[0].vlink=0;//assume that empty string always exist in the set
        queue<int> Q;
        for(int i=0;i<AlphabetSize;++i)
        {
            trie[0].go[i]=(trie[0].next[i]==-1?0:trie[0].next[i]);
            if(trie[0].next[i]==-1)
            {
                trie[0].go[i]=0;
            }
            else
            {
                trie[0].go[i]=trie[0].next[i];
                Q.push(trie[0].next[i]);
            }
        }
        while(!Q.empty())
        {
            int v=Q.front();
            Q.pop();
            int p=trie[v].p;
            char pch=trie[v].pch;
            trie[v].elink=trie[trie[p].elink].go[pch-'a'];
            if(trie[v].elink==v)
                trie[v].elink=0;
            if(trie[trie[v].elink].leaf!=-1)
                trie[v].vlink=trie[v].elink;
            else
                trie[v].vlink=trie[trie[v].elink].vlink;
            for(int i=0;i<AlphabetSize;++i)
            {
                if(trie[v].next[i]==-1)
                {
                    trie[v].go[i]=trie[trie[v].elink].go[i];
                }
                else
                {
                    trie[v].go[i]=trie[v].next[i];
                    Q.push(trie[v].next[i]);
                }
            }
        }
    }
    int go(int v,char ch)//implementation of function that older code used
    {
        return trie[v].go[ch-'a'];
    }
    int getLink(int v)//implementation of function that older code used
    {
        return trie[v].elink;
    }

    int nMatch[MaxLength];
    const int MaxNumberOfString=1e6;
    int ans[MaxNumberOfString];

    //O(n+m^2) where m is the number of distinct length of string in the set added to the structure
    void dfs(int v)
    {
        if(trie[v].leaf!=-1)
        {
            int vv=v;
            while(vv>0)
            {
                ans[trie[vv].leaf]+=nMatch[v];
                vv=trie[vv].vlink;
            }
        }
        for(int i=0;i<AlphabetSize;++i)
        {
            if(trie[v].next[i]==-1)
                continue;
            dfs(trie[v].next[i]);
        }
    }
    //O(n)
    void reverseBFS(int v)//should be faster than dfs,but in loj its runtime was slowar than about 100 ms than dfs,but was faster in cses
    {
        stack<int> st;
        queue<int> q;
        q.push(v);
        while(!q.empty())
        {
            v=q.front();
            q.pop();
            if(trie[v].leaf!=-1)
                st.push(v);
            for(int i=0;i<AlphabetSize;++i)
            {
                if(trie[v].next[i]!=-1)
                {
                    q.push(trie[v].next[i]);
                }
            }
        }
        while(!st.empty())
        {
            v=st.top();
            st.pop();
            ans[trie[v].leaf]+=nMatch[v];
            nMatch[trie[v].vlink]+=nMatch[v];
        }
    }
    //compute number of occurrence of each of the string added to the trie
    //store the result to ans[]
    //call constructAutomation() before calling this function
    //important: careful about multiple occurrence of same string in the trie
    //trie can only hold id for 1 string
    void computeAllMatch(const string& s)
    {
        int v=0;
        for(char ch:s)
        {

            v=trie[v].go[ch-'a'];
            if(trie[v].leaf!=-1)
            {
                ++nMatch[v];
            }
            else
                ++nMatch[trie[v].vlink];
        }
        //dfs(0);
        reverseBFS(0);
    }
    void reset(){
        for(int i=0;i<curSize;++i)
        {
            trie[i].reset();
            nMatch[i]=ans[i]=0;
        }
        curSize=1;
    }
}

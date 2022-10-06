int failure[1000001];
void build_failure(string &str)
{
    int i,j,k;
    int cur;
    memset(failure,0,sizeof failure);
    failure[0]=0;
    failure[1]=0;
    for(i=2;i<=str.length();i++){
        cur=i-1;
        while(cur!=0){
           if(str[failure[cur]]==str[i-1]){
              failure[i]=failure[cur]+1;
              break;
           }
           cur=failure[cur];
        }
    }
}
int kmp(string &text,string &pat)
{
    int i,j,k;
    int cur=0;
    int ocur=0;
    for(i=0;i<text.length();i++){
        if(cur==pat.length()){
            ocur++;
        }
        while(cur and text[i]!=pat[cur])
                cur=failure[cur];
        if(text[i]==pat[cur])
            cur++;
    }
    if(cur==pat.length())
        ocur++;
    return ocur;
}

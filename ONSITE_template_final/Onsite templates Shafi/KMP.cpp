int failure[1000001];
void build_failure(string &str){
    int i,j,k;
    int cur;
    memset(failure,0,sizeof failure);
    failure[0]=0;
    failure[1]=0;
    for(i=2;i<=str.length();i++){
        cur=i-1;
        while(cur!=0){
           if(str[failure[cur]] == str[i-1]){
              failure[i]= failure[cur]+1;
              break;}
           cur=failure[cur];}}}
int kmp(string &text,string &pat){
    int i,j,k;
    int cur=0;
    int ocur=0;
    for(i=0;i<text.length();i++){
        if(cur==pat.length()){
            ocur++;}
        while(cur and text[i]!= pat[cur])
                cur= failure[cur];
        if(text[i]==pat[cur])
            cur++;}
    if(cur==pat.length())
        ocur++;
    return ocur;}
void z_function(const string& str, vector<int>& z){
    int sz=str.size();
    z[0]=0;
    int i,l=0,r=0,j,k;
    for(i=1;i<sz;i++){
        z[i]=0;
        if(i<=r){
            z[i]=min(r-i+1, z[i-l]);
        }
        while(i+z[i]<sz&&str[z[i]] == str[i+z[i]])z[i]++;
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;}}
    return;}

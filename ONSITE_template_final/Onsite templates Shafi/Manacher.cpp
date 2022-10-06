int pal[100001];
string str_mod(string str)
{
       string mstr;
       mstr.push_back('#');
       for(int i=0;i<str.length();i++){
           mstr.push_back(str[i]);
           mstr.push_back('#');
       }
       return mstr;
}
void manacher(string str)
{

     int l,r;
     int lc=0,rc=0;
     int lt,rt;
     int mir=0;
     string mstr=str_mod(str);
     pal[0]=0;
     for(r=1;r<mstr.length();r++){
         l=2*mir-r;
         if(l>=0 && pal[l]<(rc-r))
            pal[r]=pal[l];
         else {
            mir=r;
            pal[mir]=max(0,rc-mir);
            for(rt=max(r+1,rc+1),lt=2*mir-rt;lt>=0 && rt<mstr.size() && mstr[lt]==mstr[rt];rt++,lt=2*mir-rt){
                pal[mir]++;
            }
            rc=rt-1;
            lc=lt+1;
         }
     }
}

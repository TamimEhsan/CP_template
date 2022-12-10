#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
//#define eps 0.00000001
#define pie acos(-1)
//#define pie 3.1415926535


double A,B;
double fun(double theta1,double theta2){
    double res1 = (A*cos(theta1)+B*cos(theta2))*A*sin(theta1)/2.0;
    double res2 = (A*sin(theta1)+B*sin(theta2))*B*cos(theta2)/2.0;
    return res1+res2;
}
void solve(){


    cin>>A>>B;
    double lo1 = 0,lo2 = 0,hi1 = pie/2, hi2 = pie/2;
    double eps = 1e-9;
    while (hi1 - lo1 > eps) {

        lo2 = 0; hi2 = pie/2;

        double f1,f2;

        double m1 = lo1 + (hi1 - lo1) / 3;

        lo2 = 0; hi2 = pie/2;
        while (hi2 - lo2 > eps) {
            double mm1 = lo2 + (hi2 - lo2) / 3;
            double mm2 = hi2 - (hi2 - lo2) / 3;
            double ff1 = fun(m1,mm1);      //evaluates the function at m1
            double ff2 = fun(m1,mm2);      //evaluates the function at m2
            if (ff1 < ff2)
                lo2 = mm1;
            else
                hi2 = mm2;
        }
        f1 = fun(m1,lo2);
        double m2 = hi1 - (hi1 - lo1) / 3;
        lo2 = 0; hi2 = pie/2;
        while (hi2 - lo2 > eps) {
            double mm1 = lo2 + (hi2 - lo2) / 3;
            double mm2 = hi2 - (hi2 - lo2) / 3;
            double ff1 = fun(m2,mm1);      //evaluates the function at m1
            double ff2 = fun(m2,mm2);      //evaluates the function at m2
            if (ff1 < ff2)
                lo2 = mm1;
            else
                hi2 = mm2;
        }
        f2 = fun(m2,lo2);
            //evaluates the function at m2
        if (f1 < f2)
            lo1 = m1;
        else
            hi1 = m2;
    }
    //cout<<lo1<<" "<<lo2<<" ";
    cout<<fun(lo1,lo2);
}

int main(){

    FASTIO;
   // int tc;
  //  cin>>tc;
  cout<<fixed<<setprecision(10);
  //  for(int t=1;t<=tc;t++) {
 //       cout<<"Case "<<t<<": ";
        solve();
  //  }

}

// https://acm.timus.ru/problem.aspx?space=1&num=1874


//  268522JW

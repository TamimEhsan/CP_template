#include<bits/stdc++.h>
using namespace std;
/*
    program to convert Romans to Arabic and Arabic to Romans
    It can convert numbers from 1-3999
    higher forms:
    _I  1000
    _V  5000
    _X  10000
    _L  50000
    _C  100000
    _D  500000
    _M  1000000
    if they are represented by other forms then just change as it is
*/

map<int,string> AtoR;
map<char,int>RtoA;
void preprocess(){
    // Map of arabic to romans
    AtoR[1000] = "M";    AtoR[900] = "CM";    AtoR[500] = "D"; AtoR[400] = "CD";
    AtoR[100] = "C";     AtoR[90] = "XC";     AtoR[50] = "L";  AtoR[40] = "XL";
    AtoR[10] = "X";      AtoR[9] = "IX";      AtoR[5] = "V";   AtoR[4] = "IV";
    AtoR[1] = "I";
    // Map of romans to Arabic
    RtoA['I'] = 1;      RtoA['V'] = 5;
    RtoA['X'] = 10;     RtoA['L'] = 50;
    RtoA['C'] = 100;    RtoA['D'] = 500;
    RtoA['M'] = 1000;
}
// Arabic numerals to Roman
string ArabicToRoman(int A){
    string R = "";
    for(auto i = AtoR.rbegin();i!=AtoR.rend();i++){
        while(A>=i->first){
            R = R+((string)i->second).c_str();
            A-=i->first;
        }
    }
    return R;
}
// Roman numerals to Arabic
int RomanToArabic(string R){
    int value = 0;
    int n = R.size();
    for(int i=0;i<n;i++){
        if( R[i+1] && RtoA[ R[i] ] < RtoA[ R[i+1] ] ){
            value+= RtoA[ R[i+1] ] - RtoA[ R[i] ];
            i++;
        } else{
            value+=RtoA[ R[i] ];
        }
    }
    return value;
}
int main(){
    preprocess();
    cout<<ArabicToRoman(3500)<<endl;
    cout<<RomanToArabic("MMMD")<<endl;
    cout<<ArabicToRoman(3999)<<endl;
    cout<<RomanToArabic("MMMCMXCIX")<<endl;
}

#include <iostream>
using namespace std;
int nCr(int n, int r)
{
    // r cant be more than n so we'd like the
    // program to crash if the user entered
    // wrong input.
    cout<<n<<" "<<r<<endl;
    if (r > n)
        return -1;

    if (n == r)
        return 1;

    if (r == 0)
        return 1;

    // nCr(n, r) = nCr(n - 1, r - 1) + nCr(n - 1, r)
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main(){
    cout<<nCr(5,4);
}

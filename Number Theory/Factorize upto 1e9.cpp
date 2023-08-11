#include <bits/stdc++.h>

using namespace std;

typedef uint32_t u32;

__attribute__((cold))
void factor_helper(auto &vec, u32 &x, u32 y) {
	do {
		vec.push_back(y);
		x /= y;
	} while (x % y == 0);
}

const int maxp = 31623;
const int P = 3401; // number of primes below maxp

constexpr auto primes = []() constexpr {
    int idx = 0;
    array<u32, P> res{};
    array<bool, maxp> comp{};
    for(int p = 2; p < maxp; p++) {
        if(!comp[p]) {
            res[idx++] = p;
            for(int j = p; j < maxp; j += p) {
                comp[j] = 1;
            }
        }
    }
    assert(idx == P);
    return res;
}();

template<int L = 0, int R = P, int M = (L + R) / 2>
constexpr void fact_p(auto &vec, u32 &x) {
    if constexpr (L + 1 < R) {
        fact_p<L, M>(vec, x);
        fact_p<M, R>(vec, x);
    } else if(x % primes[L] == 0) {
        factor_helper(vec, x, primes[L]);
    }
}

vector<u32> factor(u32 x) {
	vector<u32> vec;
	fact_p(vec, x);
	if (x > 1)
		vec.push_back(x);
	return vec;
}

int main() {
    for(int i = 1e9 - 1e6; i <= 1e9; i++) {
        factor(i);
    }
}

#include<bits/stdc++.h>
using namespace std;
const int MaxIdx=1e+5;
int tree[MaxIdx+1];
int read(int idx) {int sum = 0;
  while (idx > 0) {sum += tree[idx];idx -= (idx & -idx);}
  return sum;}
void update(int idx, int val) {while (idx <= MaxIdx) {
    tree[idx] += val;idx += (idx & -idx);}}
int readSingle(int idx) {
  int sum = tree[idx];
  if (idx > 0) { int z = idx - (idx & -idx);idx--;
    while (idx != z) { sum -= tree[idx];idx -= (idx & -idx);}}
  return sum;}
int findG(int cumFre) {int idx = 0;int bitMask=(1<<16);
    while (bitMask != 0) {int tIdx = idx + bitMask;bitMask >>= 1;
    if (tIdx > MaxIdx)continue;
    if (cumFre >= tree[tIdx]) {idx = tIdx;cumFre -= tree[tIdx];}}
    if (cumFre != 0)return -1;else return idx;}


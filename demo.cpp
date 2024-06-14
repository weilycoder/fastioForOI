#include <cstdio>
using namespace std;

/*----------------------------------fastio---------------------------------*/
#define MYBUF (1 << 20)
char buf[MYBUF], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MYBUF, stdin), p1 == p2)   \
       ? EOF                                                               \
       : *p1++)
inline long long rd() {
  long long x = 0;
  char c = gc();
  while (c < '0' || c > '9') c = gc();
  for (; c >= '0' && c <= '9'; c = gc()) x = x * 10 + (c ^ '0');
  return x;
}
char pbuf[MYBUF], *pp = pbuf;
void pc(const char &c) {
  if (pp - pbuf == MYBUF) fwrite(pbuf, 1, MYBUF, stdout), pp = pbuf;
  *pp++ = c;
}
void wt(long long x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) pc(sta[--top] + '0');
}
#undef MYBUF
/*-------------------------------------------------------------------------*/

/*
  some functions
*/
void solve() {
  // long long a = rd(), b = rd(); 注意这种写法调用顺序是不一定的
  long long a, b;
  a = rd();
  b = rd();
  wt(a - b);
  pc('\n');
}

int main() {
  // do something;
  long long T = rd();
  while (T--) solve();
  fwrite(pbuf, 1, pp - pbuf, stdout);
  return 0;
}

/*
程序首先读入 T，代表数据组数
每组数据，
  读入 64 位整数 a, b；
  输出 a - b 的差，以换行符结尾。
*/
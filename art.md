[![github](https://img.shields.io/badge/github-weilycoder-blue?logo=github)](https://github.com/weilycoder/fastioForOI) ![GitHub License](https://img.shields.io/github/license/weilycoder/fastioForOI)

### 更快的输入输出

在可能的比赛中用于避免过分的输入输出要求。

### 使用说明

将两行 `fastio` 注释内的部分复制到你的代码中，然后使用：

+ 宏 `gc` 用于读取单个字符；
+ 函数 `pc` 用于输出单个字符；
+ 函数 `rd` 用于读取 `long long` 类型的数字；
+ 函数 `wt` 用于输出 `long long` 类型的数字。

最后，在程序退出前使用 `fwrite(pbuf, 1, pp - pbuf, stdout);`

如果你使用这套快速读入输出模板，请不要使用其他读入输出函数，这可能导致混乱。

需要指出，这段模板将使用两个长 $2^{20}$ 的 `char` 类型数组用作缓冲区，这是在宏 `MYBUF` 定义的。你可以尝试扩大或缩小它的值，前者可能会带来更高的效率，但是将占用更多的内存空间。

在本地调试时，使用这段模板可能出现输入数据无反应的情况，你可以使用文件读入输出来避免，或者在控制台输入一个等同于文件结束符 `EOF` 的字符。在 `Windows` 下：

+ 前者当然可以使用 `freopen` 解决，但也可以在命令提示符下使用 `sol < foo.in > foo.out` 的形式重定向标准输入输出流，其中 `>` 表示覆盖内容，可以换成 `>>` 表示追加内容；
+ 后者，请在新的一行输入 `Ctrl-Z`（控制台将回显 `^Z`），然后回车。


其他可能的问题请自行阅读或修改代码解决，本人不对使用这段代码造成的任何影响负责。


```cpp
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
inline void pc(const char &c) {
  if (pp - pbuf == MYBUF) fwrite(pbuf, 1, MYBUF, stdout), pp = pbuf;
  *pp++ = c;
}
inline void wt(long long x) {
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

int main() {
  // do something;
  fwrite(pbuf, 1, pp - pbuf, stdout);
  return 0;
}
```

### 并不重要的许可证

WTFPL license.

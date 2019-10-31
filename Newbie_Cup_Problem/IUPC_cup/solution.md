## IUPC奖杯 题解

出题人：成子谦

### 出题idea

原本是没有这道题的，后来大家发现少了一道简单的贪心题，于是~~光速背锅~~赶紧补上。

这个题比较简单，因为出题人~~贪心水平很差~~觉得其他题都有点难，就不为难大家了。

### 解法

原题可以抽象为如下问题：

> 给定一个仅包含数字1或2的字符串，可以交换某两个数字的位置(最多一次)，问：字符串中最长的连续‘1’(下称为“全1串”)有多长？

显然答案的范围在$[0,n]$之间。但我们应该怎么做呢？如果不停地枚举两个被交换的数字的位置，再统计答案，时间复杂度是$O(n^3)$，是完全不可接受的。要解决这个问题，我们不妨冷静下来，分析我们的思考过程。

举个栗子，形如：
$$
111211122111
$$
这样的奖杯序列$(n=12)$，我们能一眼看出答案是$7$。只需选择最后三个$1$中的任意一个，与最靠左的$2$交换位置即可。  

我们是怎么实现求解过程的？

- 首先，我们把原字符串分段，这样就得到`111`、`2`、`111`、`22`、`111`五段字符串。
- 由于我们最多只能交换一次奖杯位置，所以距离$\ge2$的全$1$串都不可能拼接起来。
- 我们反复尝试拼接间隔为1的全$1$串，使得全$1$串能尽量长。

于是就得到了上面的结果。而且容易发现：对于一个全$1$串，只有三种“动作”：要么跟前面的全$1$串拼接，要么跟后面的全$1$串拼接，要么单独成段(不拼接)。所以我们只需要按顺序遍历一次所有的全$1$串，检查一下能否与前后的全$1$串拼接，并统计答案的最大值。

这种做法看上去非常简单，实际上还是有些细节没有考虑到。考察如下情况$(n=11)$：
$$
22111211122
$$
答案显然是$6$。与$(1)$相比，有没有发现什么不同？没错，在$(1)$中，我们用“外界的”$1$与$2$进行交换，**被交换的1并不在两段全1串中**。但在$(2)$中有所不同，**被交换的1在两段全1串中的某串**。我们应如何区分这种情况？

事实上，考虑这样的问题只会加大我们的思维难度(不是不可以这样思考，只是写起来麻烦)，所以我们需要转换角度来思考问题：与其思考“如何拼接两个全$1$串”，不如思考“若当前位置可被替换，则从该位置开始，能”。

最后不要忘记奖杯数量=金杯数量的特殊情况，需要判断一下。

上述算法，预处理复杂度$O(n)$，统计答案复杂度$O(n)$，总时间复杂度$O(n)$。具体实现请看标程。
# Permutation Index I (求数组升序组合的序号)

## 1. Question6 Permutation Index I

### 1.1 举例

```[]
123 -> 1
132 -> 2
213 -> 3
231 -> 4
312 -> 5
321 -> 6
```

以321为例进行分析:

首先考虑第一位3: 3右边比3小的数字有 __两个__ (1和2), 所以以1和2为首位的数字排在3xx的前面, 这样的数字有`2 * 2! = 4`个. 所以以3开头的数字至少排第5.

3已经考虑完, 看后面两位.

```[]
12 -> 1
21 -> 2
```

在321中, 2右边比2小的数字有一个(1), 所以以1为首位的数字排在2x的前面, 这样的数字有`1 * 1! = 1`个.

最后一个1, 只有一个数字, 排在它前面的数字是0个.

综上, 321前面排了5个数字, 所以它的Permutation Index是6.

按照这个思路, 对于从右数第`i`位`A[i](i = 0, 1, 2...)`, 若它的右边有k个数字小于`A[i]`, 那么这一位就会在Permutation Index中贡献`k * i!`.

### 1.2 Code

```cpp
class Solution{
public:
    long long permutationIndex(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;
        long long index = 1;
        for(int i=0; i<A.size(); ++i){  // find each elements order
            long factor = 1;
            int count = 0;
            for(int j=i+1; j<A.size(); ++j){
                factor *= j-i;
                if(A[j] < A[i]) ++count;
            }
            index += count * factor;
        }
        return index;
    }
};
```

## 2. Question7 Permutation Index II

### 2.1 举例

```[]
11223 -> 1
11232 -> 2
11322 -> 3
12123 -> 4
12132 -> 5
12213 -> 6
12231 -> 7
12312 -> 8
12321 -> 9
13122 -> 10
```

考虑`13122`:

* 第一位1, 没有比1再小的数字了, 所以1开头的数字是从第一个开始的.

* 第二位3, 3右边比3小的数字有1和2.

如果1和3互换位置, 后面三位将是数字`2,2,3`. 这三个数字的组合数是`3! / 2! = 3`个.
如果2和3互换位置, 后面三位将是数字`1,2,3`. 这三个数字的组合数是`3! = 6`个.
所以因为第二位比3小(首位是1)而排在`13xxx`前面的数字有9个. 因此`13xxx`一定是从第10个开始的.

至此, 结合上一题, 已经能看出规律: 对于从右数第`i`位`A[i]`, 看它右边的每一个比A[i]小的数字, 假设`A[j] < A[i] (j > i)`, 那么假想`A[j]`和`A[i]`互换位置后, 计算右边的`i-1`个数字的组合数就是这`A[j]`贡献的. 要注意的是, `A[i]`右边可能有多个比`A[i]`小的重复数字, 这些数字只贡献一次.

## 2.2 Code

```cpp
class Solution {
private:
    map<int, int> m;
    long long fac(int num) {
        long long n = 1;
        while (num > 0) {
            n *= num;
            num--;
        }
        return n;
    }

    long generateNum() {
        long long num = 1;
        for (auto it = m.begin(); it != m.end(); ++it) {
            num *= fac(it->second);
        }
        return num;
    }
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        int N = A.size();
        if (N == 0) return 0;
        m.clear();
        long long index = 1;

        for (int num : A) {
            if (m.find(num) != m.end())
                ++m[num];
            else
                m[num] = 1;
        }

        for (int i = 0; i < N; ++i) {
            set<int> s;
            for (int j = i + 1; j < N; ++j) {
                if (A[j] < A[i] && s.find(A[j]) == s.end()) {
                    s.insert(A[j]);     // 加入集合
                    m[A[j]]--;
                    index += fac(N - i - 1) / generateNum();
                    m[A[j]]++;
                }
            }

            m[A[i]]--;
            // 一个循环之后将A[i]减少一个 表示后续A[i]不会再出现
            // 因此使用 generateNum 对 哈希表 进行循环时, 指会循环j之后的元素

            if (m[A[i]] == 0) m.erase(A[i]);
        }
        return index;
    }
};
```
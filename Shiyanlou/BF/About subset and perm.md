# 关于 子集 与 全排列 的生成

## 全排列的生成

### 生成思路

由于要以递增的方式寻找下一个数组排列, 因此搜索方式与 __计数过程__ 类似. 搜索起始时数组排列为升序(此时为最小), 搜索结束时数组为降序(此时为最大排列). 因此在中间过程中, 真个数组必然由前半段的升序序列与后半段的降序序列组成, 且随着数组排列的递增, 降序部分会逐渐扩大. 也就是说, 这是一个找到当前的降序部分, 并且使用升序部分中的元素逐渐填充进去的过程

举个栗子:

```[]
{1,2,3,4} -> {1,2,4,3} -> {1,3,2,4} -> {1,3,4,2} -> ...
```

### 具体过程

* __初始化__: 首先我们假设整个数组/`vector`的初始状态为升序排列(从小到大), 显然是数组元素组成的最小整数. 接下来我们在进行全排列生成中, 按照数组元素组成的整数的升序顺序, 对数组的全排列进行生成.

    e.g `vectot<int> A = {1,3,2,4} ==sort==> {1,2,3,4}`此时对应的`1234`, 为`A`中元素组成的最小整数

    __假设我们当前的数组为`{0,1,2,5,3,3,0}`, 记作 `nums`__

* __step1 寻找降序序列__: 由于在之前的过程中, 我们的操作按照升序的顺序进行, 因此我们必然能够找一个降序序列(若找不到说明该序列已经为最大序列), 其前驱元素即为升序序列的末尾元素, 用于后续的替换(将此元素的下标记为`i`).

    由于`nums[0]->nums[i]`升序, 而`nums[i+1]->nums[end]`降序, 因此`nums[i]`后面的元素已经达到了最大. 如果想让排序继续变大, 则需要 "进位", 即将一个比`nums[i]`大且最小的元素放到`nums[i]`的位置上, 构建新的序列.

    在这里降序序列序列为`{5,3,3,0}`, 用来组成新的最小序列的元素为`{5}`的前驱, 即`{2}`

* __step2 寻找替换元素__: 在降序序列中找到比`nums[i]`大且 __最小最靠后__ 的元素, 即从后向前找到一个比`nums[i]`大的元素, 其下标记作`j`.

    由于`nums[i+1]->nums[end]`构成了一个降序序列, 且`nums[i]<nums[i+1]`, 因此一定可以找到`j`存在.

    在这里我们找到的是`{5,3,3,0}`中的倒数第二个元素, 即`{3}`

* __step3 元素替换__: 将`nums[i]`与`nums[j]`进行交换

    由于`nums[j]>nums[i]`, 因此替换后`nums[i+1]->nums[end]`仍是一个降序序列. 而`nums[i]`位置的元素变大了, 即实现了"进位".

    在这里我们得到的交换结果为`{0,1,2,5,3,3,0} --> {0,1,3,5,3,2,0}`.

* __step4 序列反转__: 将`nums[i+1]->nums[end]`范围内进行反转

    由于`nums[i+1]->nums[end]`为一个降序序列, 反转后变为一个升序序列. 因此反转后的整个序列可视为经过`nums[i]`的进位后的最小序列.

    在这里, 我们反转后的结果为`{0,1,3,0,2,3,5}`, 即为`{0,1,3}`为开头的最小序列.

### Code

* C style

```cpp
bool nextPer(vector<int> & curr){
    // step 1: find the suffix
    int toChange_L = curr.size()-1;

    while(toChange_L > 0 && curr[toChange_L-1] >= curr[toChange_L])
        --toChange_L;
    if(toChange_L == 0) return false;
        --toChange_L;

    // step 2: find where to swap
    int toChange_R = curr.size()-1;
    while(curr[toChange_R] <= curr[toChange_L]) --toChange_R;

    // step 3: swap
    int temp = curr[toChange_L];
    curr[toChange_L] = curr[toChange_R];
    curr[toChange_R] = temp;

    // step 4: reverse
    int i = toChange_L+1, j = curr.size()-1;
    while(i<j){
        temp = curr[i];
        curr[i] = curr[j];
        curr[j] = temp;
        ++i;
        --j;
    }
    return true;
}
```

* Cpp style

```cpp
bool nextPer_cc(vector<int> & curr){

    vector<int>::iterator toChange_L = curr.end()-1;
    while(toChange_L != curr.begin() && *(toChange_L-1) >= *toChange_L) --toChange_L;

    if(toChange_L == curr.begin()) return false;
    --toChange_L;

    vector<int>::iterator toChange_R = curr.end()-1;
    while(*toChange_R <= *toChange_L) --toChange_R;

    iter_swap(toChange_L, toChange_R);

    reverse(toChange_L+1, curr.end());
    return true;
}
```
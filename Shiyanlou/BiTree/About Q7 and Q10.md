# 关于 Question 7 与 Question 10 的代码解释

## Question 7

### Question Statement

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

e.g

```[]
       -10
       /  \
      2    -3
     / \   / \
    3   4 5   7
```

output: 9 => 3+2+4=5+(-3)+7 == 9

### Hints

在处理时，根据分治的思想，我们在处理时，需要将一个结点的左右子树抽象成两个单独的结点进行处理 e.g

```[]
         A                           A
       /   \                       /   \
      B     E         =>          B_    C_
     / \   / \
    C   D F   G
```

其中`B_` 与 `C_` 对应着结点`B` 与 结点`C`对应的单侧路径最大值

在这里，我们需要注意的点有两方面：

1. “最大路径和”并不一定经过`A`结点, 也有可能存在在结点`B`或`C`的局部最大值中，如例子中的 `3+2+4`(`C+B+D`)

2. 如果树中存在负数，在求单侧最大值时，无法采用普通的 __左右子树最大值__ + __根结点值__ 的方法，例如`-2 -> 3 <- -4` ，显然3结点向上传播的值并不是 `max(-2, -4) + 3 = 1`，而是`3`本身. 因此我们还需要对值为负数的结点进行特殊处理

根据第一点，我们在使用递归进行求解时，我们需要保存两个变量，即 __根结点对应的数的局部最大值__(`local_max`)与 __根结点对应的树向上传播的单侧最大值(`node_max`)__

根据第二点，我们需要考虑一下`local_max`与`node_max`的表达式，对于如下子树：

```[]
        mid
       /   \
     left right
(l_node)   (r_node)
(l_local)  (r_local)
```

$$ node\_max=MAX\left\{
\begin{aligned}
    l\_node+ mid \\
    r\_node + mid\\
    mid
\end{aligned}
\right\}=

\left\{
\begin{aligned}
    max\{l\_node, r\_node\}+ mid \\
    mid
\end{aligned}
\right\}.
$$

$$ local\_max=MAX\left\{
\begin{aligned}
    l\_local \\
    r\_node \\
    mid \\
    l\_node+mid \\
    r\_node+mid \\
    l\_node+r\_node+mid
\end{aligned}
\right\}=

\left\{
\begin{aligned}
    max\{l\_node, r\_node\} \\
    mid \\
    max\{l\_node, r\_node\}+ mid \\
    l\_node+r\_node+mid
\end{aligned}
\right\}.
$$

很显然，`node_max`中`mid`与`max(l,r)+mid`的比较以及`local_max`中的后四个分支比较均由于`l_node`或`r_node`小于0 引起的

假如我们令全部小于0的`node_max=0`，那么上述等式可以化简为：

$$node\_max = max \{l\_node, r\_node \} + mid$$

$$ local\_max=MAX\left\{
\begin{aligned}
    l\_local \\
    r\_node \\
    l\_node+r\_node+mid
\end{aligned}
\right\}.
$$

这样我们就可以很愉快的进行代码编写

S.P. 由于可能存在负值，因此我们在初始化`local_node`时应当初始为`INT_MIN`而非0，否则会导致全是负值的树的最大值和为0而非最大负值

### Solution

```c++
class Solution{
public:
    int maxPathSum(TreeNode * root) {
        if(!root) return 0;

        return getSum(root).local_max;
    }
private:
    typedef struct{
        int node_max;
        int local_max;
    } Node;

    Node getSum(TreeNode * root){
        Node node;
        if(!root) {
            node = {0, INT_MIN};
            return node;
        }
        Node l_node = getSum(root->left);
        Node r_node = getSum(root->right);

        int node_max = max(l_node.node_max, r_node.node_max) + root->val;
        node_max = max(node_max, 0);
        node.node_max = node_max;

        int local_max = max(l_node.local_max, r_node.local_max);
        local_max = max(local_max, l_node.node_max + r_node.node_max + root->val);
        node.local_max = local_max;

        return node;
    }
};
```

## Question 10

### Statement

The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree.
The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded(note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

### Hints

此题需要找到树中两个结点之间的最大距离，与 Question 7 思路相同，只是将`local_max`改为以当前`root`的局部最大距离，`node_max`改为最大深度. 由于不需要考虑负值，因此处理起来十分愉快，直接`+1+1`即可

### Solution

```cpp
class Solution{
private:
    typedef struct{
        int node_depth;
        int local_depth;
    }Node_;

    Node_ getDepth(TreeNode * root){
        Node_ node;
        if(!root){
            node = {0,0};
            return node;
        }

        Node_ L_node = getDepth(root->left);
        Node_ R_node = getDepth(root->right);

        int node_depth = max(L_node.node_depth, R_node.node_depth)+1;
        node.node_depth = node_depth;

        int local_depth = max(L_node.local_depth, R_node.local_depth);
        local_depth = max(L_node.node_depth+R_node.node_depth+1, local_depth);
        node.local_depth = local_depth;
        return node;
    }
public:
    int diameter(TreeNode* node){
        if(!node) return 0;
        Node_ node_ = getDepth(node);
        return node_.local_depth;
    }
};
```
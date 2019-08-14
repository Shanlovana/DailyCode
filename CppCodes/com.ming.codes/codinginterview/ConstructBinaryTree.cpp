//
// Created by android on 2019/8/11.
//

/*
前序遍历：
    1.访问根节点
    2.前序遍历左子树
    3.前序遍历右子树
中序遍历：
    1.中序遍历左子树
    2.访问根节点
    3.中序遍历右子树
后序遍历：
    1.后序遍历左子树
    2.后序遍历右子树
    3.访问根节点
 *题目：
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 *思路分析
 * 根据二叉树前序遍历的特点（根-左-右），每次读取的第一个值一定是根节点，这样我们可以在中序遍历的序列中找到当前的根节点的位置。
 * 根据中序遍历的特点（左-根-右），当确定了一个根节点后，其左边序列就是这个根节点的左子树，右边序列就是其右子树。
 * 我们每次都需要在前序遍历中找根节点并创建一个根节点，然后在中序遍历中确定根节点位置，并确定当前根节点的左右子树，
 * 然后以同样的方法去构建左右子树。
 * 这整个过程其实是一个递归的过程。
 */
#include <bits/exception.h>
#include <gtest/gtest.h>

using namespace std;
typedef int ElementType;

typedef struct BinaryTreeNode {
    ElementType elementType;
    BinaryTreeNode *pLeftBinaryTreeNode;
    BinaryTreeNode *pRightBinaryTreeNode;
};

BinaryTreeNode *CreateBinaryTreeNode(int value) {
    BinaryTreeNode *pNode = new BinaryTreeNode();
    pNode->elementType = value;
    pNode->pRightBinaryTreeNode = pNode->pLeftBinaryTreeNode = nullptr;
    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode *pParent, BinaryTreeNode *pLeft, BinaryTreeNode *pRight) {
    if (pParent != nullptr) {
        pParent->pLeftBinaryTreeNode = pLeft;
        pParent->pRightBinaryTreeNode = pRight;
    }
}


BinaryTreeNode *constructCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder) {
    //前序遍历第一个书为root
    int rootValue = startPreOrder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->elementType = rootValue;
    root->pLeftBinaryTreeNode = root->pRightBinaryTreeNode = nullptr;

    if (startPreOrder == endPreOrder) {
        if (startInOrder == endInOrder && *startPreOrder == *startInOrder)
            return root;
        else
            throw exception();
    }
    // 在中序遍历中找到根结点的值
    int *rootInOrder = startInOrder;
    while (rootInOrder <= endInOrder && *rootInOrder != rootValue)
        ++rootInOrder;

    if (rootInOrder == endInOrder && *rootInOrder != rootValue)
        throw exception();

    int leftLength = rootInOrder - startInOrder;
    int *leftPreOrderEnd = startPreOrder + leftLength;
    if (leftLength > 0) {
        // 构建左子树
        root->pLeftBinaryTreeNode = constructCore(startPreOrder + 1, leftPreOrderEnd,
                                                  startInOrder, rootInOrder - 1);
    }
    if (leftLength < endPreOrder - startPreOrder) {
        // 构建右子树
        root->pRightBinaryTreeNode = constructCore(leftPreOrderEnd + 1, endPreOrder,
                                                   rootInOrder + 1, endInOrder);
    }

    return root;
};

BinaryTreeNode *construct(int *preOrder, int *inOrder, int length) {
    if (preOrder == nullptr || inOrder == nullptr || length <= 0)
        return nullptr;

    return constructCore(preOrder, preOrder + length - 1,
                         inOrder, inOrder + length - 1);

}

class Solution {
public:
    BinaryTreeNode *reConstructBinaryTree(int *preOrder, int *inOrder, int length) {
        return construct(preOrder, inOrder, length);
    }
};

TEST(construct, test) {
    const int LENGTH = 8;
    int preOrder[LENGTH] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrder[LENGTH] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *root = (new Solution)->reConstructBinaryTree(preOrder, inOrder, LENGTH);
    EXPECT_EQ(1, root->elementType);

}
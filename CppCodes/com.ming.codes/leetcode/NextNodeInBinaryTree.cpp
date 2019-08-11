//
// Created by android on 2019/8/11.
//

#include <gtest/gtest.h>

typedef int ElementValue;
typedef struct LinkedBinaryTreeNode {
    ElementValue pValue;
    LinkedBinaryTreeNode *m_pLeft;
    LinkedBinaryTreeNode *m_pRight;
    LinkedBinaryTreeNode *m_pParent;
};

LinkedBinaryTreeNode *createLinkedBinaryTreeNode(int value) {
    LinkedBinaryTreeNode *pNode = new LinkedBinaryTreeNode();
    pNode->pValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;

    return pNode;
}

void connectTreeNodes(LinkedBinaryTreeNode *pParent, LinkedBinaryTreeNode *pLeft, LinkedBinaryTreeNode *pRight) {
    if (pParent != nullptr) {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
        if (pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if (pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}

LinkedBinaryTreeNode *getNextTreeNode(LinkedBinaryTreeNode *pNode) {
    if (pNode == nullptr)
        return nullptr;

    LinkedBinaryTreeNode *pNext = nullptr;
    if (pNode->m_pRight != nullptr) {
        LinkedBinaryTreeNode *pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    } else if (pNode->m_pParent != nullptr) {
        LinkedBinaryTreeNode *pCurrent = pNode;
        LinkedBinaryTreeNode *pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight) {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }

        pNext = pParent;
    }

    return pNext;
}

class Solution {
public:
    bool findNextBinaryNode(LinkedBinaryTreeNode *pNode, LinkedBinaryTreeNode *expected) {
        return (expected == getNextTreeNode(pNode));
    }
};

TEST(find, nextnode) {
//            8
//        6      10
//       5 7    9  11
    LinkedBinaryTreeNode *pNode8 = createLinkedBinaryTreeNode(8);
    LinkedBinaryTreeNode *pNode6 = createLinkedBinaryTreeNode(6);
    LinkedBinaryTreeNode *pNode10 = createLinkedBinaryTreeNode(10);
    LinkedBinaryTreeNode *pNode5 = createLinkedBinaryTreeNode(5);
    LinkedBinaryTreeNode *pNode7 = createLinkedBinaryTreeNode(7);
    LinkedBinaryTreeNode *pNode9 = createLinkedBinaryTreeNode(9);
    LinkedBinaryTreeNode *pNode11 = createLinkedBinaryTreeNode(11);

    connectTreeNodes(pNode8, pNode6, pNode10);
    connectTreeNodes(pNode6, pNode5, pNode7);
    connectTreeNodes(pNode10, pNode9, pNode11);

    EXPECT_TRUE((new Solution)->findNextBinaryNode(pNode6, pNode7));
    EXPECT_TRUE((new Solution)->findNextBinaryNode(pNode5, pNode6));

}
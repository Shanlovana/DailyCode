//
// Created by android on 19-8-26.
//
/*
 * 复杂链表的复制
 * 题目：请实现函数RandomListNode* Clone(RandomListNode* pHead)，
 * 复制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
 * 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。
 *
 *
 * 空间换时间，复制label和next的同时建立一个hash表来存放新旧复杂指针的对应关系，
 * 所以后续只需一步就能找到random，算法时间复杂度为O(n)。
 * 我们这里将复杂链表的复制过程分解为三个步骤。在写代码的时候我们每一步定义一个函数，
 * 这样每个函数完成一个功能，整个过程的逻辑也就非常清晰明了了。
 * 我们这里采用三步：
 * 第一步：复制复杂指针的label和next。但是这次我们把复制的结点跟在元结点后面，而不是直接创建新的链表
 * 第二步：设置复制出来的结点的random。因为新旧结点是前后对应关系，所以也是一步就能找到random；
 * 第三步：拆分链表。奇数是原链表，偶数是复制的链表。
 * */
#include <gtest/gtest.h>

using namespace std;
typedef int ElementValue;

typedef struct RandomListNode {
    ElementValue Element;        //    数据域，存放数据
    RandomListNode *Next;        //    指向下一个链表节点
    RandomListNode *Random;        //    指向下一个随机节点
};

RandomListNode *createListNodeRandom(int value) {
    RandomListNode *pNode = new RandomListNode();
    pNode->Element = value;
    pNode->Next = nullptr;
    pNode->Random = nullptr;
    return pNode;
}

void buildNodes(RandomListNode *pNode, RandomListNode *pNext, RandomListNode *pSibling) {
    if (pNode != nullptr) {
        pNode->Next = pNext;
        pNode->Random = pSibling;
    }
}

class Solution {
public:
    //第一步，复制复杂指针的label和next
    void cloneNodes(RandomListNode *pHead) {
        RandomListNode *pNode = pHead;
        while (pNode != nullptr) {
            RandomListNode *pCloned = new RandomListNode();
            pCloned->Element = pNode->Element;
            pCloned->Next = pNode->Next;
            pCloned->Random = nullptr;

            pNode->Next = pCloned;
            pNode = pCloned->Next;//切换为下一个node
        }

    }

    //第二步，处理复杂指针的random
    void connectSiblingNodes(RandomListNode *pHead) {
        RandomListNode *pNode = pHead;
        while (pNode != nullptr) {
            RandomListNode *pCloned = pNode->Next;
            if (pNode->Random != nullptr) {
                pCloned->Random = pNode->Random->Next;

            }
            pNode = pCloned->Next;
        }
    }

    RandomListNode *reConnectNodes(RandomListNode *pHead) {
        RandomListNode *pNode = pHead;
        RandomListNode *pClonedHead = nullptr;
        RandomListNode *pClonedNode = nullptr;
        if (pNode != nullptr) {
            pClonedHead = pClonedNode = pNode->Next;
            pNode->Next = pClonedNode->Next;
            pNode = pNode->Next;

        }
        while (pNode != nullptr) {
            pClonedNode->Next = pNode->Next;
            pClonedNode = pClonedNode->Next;
            pNode->Next = pClonedNode->Next;
            pNode = pNode->Next;
        }
        return pClonedHead;
    }
};

TEST(copy,b1){
    RandomListNode* pNode1 = createListNodeRandom(1);
    RandomListNode* pNode2 = createListNodeRandom(2);
    RandomListNode* pNode3 = createListNodeRandom(3);
    RandomListNode* pNode4 = createListNodeRandom(4);
    RandomListNode* pNode5 = createListNodeRandom(5);

    buildNodes(pNode1, pNode2, pNode3);
    buildNodes(pNode2, pNode3, pNode5);
    buildNodes(pNode3, pNode4, nullptr);
    buildNodes(pNode4, pNode5, pNode2);

    Solution *solution=new Solution();
    solution->cloneNodes(pNode1);
    solution->connectSiblingNodes(pNode1);
    solution->reConnectNodes(pNode1);

}
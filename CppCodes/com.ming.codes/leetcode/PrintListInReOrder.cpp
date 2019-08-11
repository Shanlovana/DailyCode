//
// Created by android on 19-8-9.
//
/* 输入一个链表，从尾到头打印链表每个节点的值
 * 实现
 * 思路：从前向后记录‘ ’数目，从后向前替换‘ ’。 重点：从后向前替换的时候的技巧 例如：“we are lucky”
 * (1) 从头到尾输出比较简单，一种想法是反转结点的指针。但是会破坏原链表的结构，不推荐；
 * (2) 从头遍历链表，先访问的后输出，后访问的先输出，“后进先出”，利用栈来实现；
 * (3) 递归本质上就是一个栈的结构，可以利用递归来实现。
 * 但是当链表比较长的时候，递归会导致函数调用的层级很深，有可能会导致函数调用栈的溢出，故还是推荐使用栈来实现。
 * */
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include <stack>
#include <gtest/gtest.h>

using namespace std;

typedef int ElementType;

typedef struct ListNode {
    ElementType Element;        //    数据域，存放数据
    ListNode *Next;        //    指向下一个链表节点
} Node, *PNode;

ListNode *createListNode(int value) {
    ListNode *pNode = new ListNode();
    pNode->Element = value;
    pNode->Next = nullptr;
    return pNode;
}

void connectListNodes(ListNode *pCurrent, ListNode *pNext) {
    if (pCurrent == nullptr) {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    pCurrent->Next = pNext;
}

class Solution {
public:
    //using stack
    void printListReversingly(ListNode *pHead) {
        stack<ListNode *> nodes;
        ListNode *pNode = pHead;
        while (pNode != nullptr) {
            nodes.push(pNode);
            pNode = pNode->Next;
        }
        while (!nodes.empty()) {
            pNode = nodes.top();
            printf("%d\t", pNode->Element);
            nodes.pop();

        }
    }

    void printListRever_Recursively(ListNode *pHead) {
        if (pHead != nullptr) {
            if (pHead->Next != nullptr) {
                printListRever_Recursively(pHead->Next);
            }
            printf("%d\t", pHead->Element);
        }
    }
};

TEST(print, a1) {

    ListNode *pNode1 = createListNode(1);
    ListNode *pNode2 = createListNode(2);
    ListNode *pNode3 = createListNode(3);
    ListNode *pNode4 = createListNode(4);
    ListNode *pNode5 = createListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);

    (new Solution)->printListReversingly(pNode1);

    (new Solution)->printListRever_Recursively(pNode1);

}
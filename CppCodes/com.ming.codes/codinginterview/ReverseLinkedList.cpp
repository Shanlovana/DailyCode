//
// Created by android on 19-8-15.
//

#include <gtest/gtest.h>

using namespace std;

typedef int ElementValue;

typedef struct ListNode {
    ElementValue Element;        //    数据域，存放数据
    ListNode *Next;        //    指向下一个链表节点
};

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

class Soulution {

public:
    ListNode *reverseLikedList(ListNode *pHead) {
        ListNode *pNode = pHead;
        ListNode *reverseHead = nullptr;
        ListNode *prev = nullptr;
        if (pNode == nullptr) {
            return nullptr;
        }
        while (pNode != nullptr) {
            ListNode *pNext = pNode->Next;
            if (pNext == nullptr) {
                reverseHead = pNode;
            }
            pNode->Next = prev;
            prev = pNode;
            pNode = pNext;
        }
    }

    ListNode *recursive(ListNode *pNode) {
        if (pNode->Next == nullptr) {
            return pNode;
        } else {
            ListNode *next = pNode->Next;
            ListNode *tail = recursive(next);
            next->Next = pNode;
            return tail;
        }
    }

    ListNode *reverseListRecursive(ListNode *pHead) {
        if (pHead == nullptr || pHead->Next == nullptr) {
            return pHead;
        } else {
            ListNode *tail = recursive(pHead);
            pHead->Next = nullptr;
            return tail;
        }

    }
};
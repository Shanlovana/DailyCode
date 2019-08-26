//
// Created by android on 19-8-15.
//
/*题目：
 * 输入一个链表，反转链表后，输出链表的所有元素。
 * 思路
 * 这个很简单，我们使用三个指针，分别指向当前遍历到的结点、它的前一个结点以及后一个结点。
 * 在遍历的时候，做当前结点的尾结点和前一个结点的替换。
 * */

#include <gtest/gtest.h>

using namespace std;

typedef int ElementValue;

typedef struct ListNode {
    ElementValue Element;        //    数据域，存放数据
    ListNode *Next;        //    指向下一个链表节点
};

ListNode *createListNodesim(int value) {
    ListNode *pNode = new ListNode();
    pNode->Element = value;
    pNode->Next = nullptr;
    return pNode;
}

void connectListNodesim(ListNode *pCurrent, ListNode *pNext) {
    if (pCurrent == nullptr) {
        printf("Error to connect two nodes.\n");
        exit(1);
    }
    pCurrent->Next = pNext;
}

class Soulution {

public:
    ListNode *reverseLikedList(ListNode *pHead) {//本题思路
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

TEST(reverse, a0) {
    ListNode *pNode1 = createListNodesim(1);
    ListNode *pNode2 = createListNodesim(2);
    ListNode *pNode3 = createListNodesim(3);
    ListNode *pNode4 = createListNodesim(4);
    ListNode *pNode5 = createListNodesim(5);

    connectListNodesim(pNode1, pNode2);
    connectListNodesim(pNode2, pNode3);
    connectListNodesim(pNode3, pNode4);
    connectListNodesim(pNode4, pNode5);

    ListNode *pReversedHead = (new Soulution)->reverseLikedList(pNode1);

    printf("The reversed list is: \n");
    if (pReversedHead == nullptr) {
        printf("The node is nullptr\n");
    } else {
        printf("The key in node is %d.\n", pReversedHead->Element);
    }

}
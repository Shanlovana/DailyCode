//
// Created by android on 19-8-9.
//

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct ListNode {
    ElementType Element;        //    数据域，存放数据
    ListNode *Next;        //    指向下一个链表节点
} Node, *PNode;

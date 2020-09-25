//
// Created by anjxw on 2020/9/24.
//

#ifndef TEST_LIST_H
#define TEST_LIST_H
#define LIST_NUM
#endif //TEST_LIST_H

struct LIST_ITEM {
    int * data;
    struct LIST_ITEM * pPrevious;
    struct LIST_ITEM * pNext;
};
typedef struct LIST_ITEM ListItem_t;

struct LIST {
    struct LIST_ITEM * pIndex;
    struct LIST_ITEM * pHead;
    struct LIST_ITEM * pTail;
};
typedef struct  LIST List_t;

/**
 * 建立链表
 */
List_t * createList();

void addNodeR(List_t * list, ListItem_t * item);

ListItem_t * createItem(int * data);

List_t * initList(int * data);

ListItem_t * prevItem(List_t * list);

ListItem_t * nextItem(List_t * list);

void delItem(List_t * list,ListItem_t * item);
//调换节点位置
void swapItem(ListItem_t * item1,ListItem_t * item2);
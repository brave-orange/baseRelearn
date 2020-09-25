//
// Created by anjxw on 2020/9/24.
//
#include "stdlib.h"
#include "include/list.h"

/**
 * 创建空链表
 * @return
 */
List_t * createList()
{
    List_t * newList =  (List_t *)malloc(sizeof(List_t));
    return newList;
}

/**
 * 初始化链表
 * @return
 */
List_t * initList(int* data)
{
    ListItem_t * head =  (ListItem_t *)malloc(sizeof(ListItem_t));
    head->data = data;
    List_t * newList =  createList();
    newList->pIndex = head;
    newList->pHead = head;
    newList->pTail = head;
    return newList;
}
/**
 * 增加节点(右侧)
 * @param item
 * @return
 */
void addNodeR(List_t * list, ListItem_t * item)
{
    ListItem_t * tail = list->pTail;
    tail->pNext = item;
    item->pPrevious = tail;
    list->pTail = item;
}

/**
 * 增加节点(左侧)
 * @param item
 * @return
 */
//void addNodeL(List_t * list, ListItem_t * item)
//{
//    ListItem_t * tail = list->pTail;
//    tail->pPrevious = item;
//    list->pTail = item;
//}
/**
 * 创建一个节点
 * @param data
 * @return
 */
ListItem_t * createItem(int * data)
{
    ListItem_t * item = (ListItem_t *)malloc(sizeof(ListItem_t));
    item->data = data;
    return item;
}

/**
 * 链表下移一个
 */
 ListItem_t * nextItem(List_t * list)
 {
     //当前指针下移一个
     list->pIndex = list->pIndex->pNext;
     return list->pIndex;
 }

/**
* 链表上移一个
*/
ListItem_t * prevItem(List_t * list)
{
    //当前指针下移一个
    list->pIndex = list->pIndex->pPrevious;
    return list->pIndex;
}

/**
* 链表删掉一个元素
*/
void delItem(List_t * list,ListItem_t * item)
{

    if(list->pHead == item){
        list->pHead = item->pNext;
    } else if(list->pTail == item){
        list->pTail = item->pPrevious;
    } else{
        item->pPrevious->pNext = item->pNext;
        item->pNext->pPrevious = item->pPrevious;
    }
    free(item);
}

void insertItemR(List_t * list,ListItem_t * target,ListItem_t * item)
{

}

void swapItem(List_t * list,ListItem_t * item1,ListItem_t * item2)
{


}





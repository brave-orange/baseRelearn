//
// Created by anjxw on 2020/9/24.
//
#include "stdlib.h"
#include "include/list.h"
#include "stdio.h"
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
 * 增加节点(尾插法)
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
 * 增加节(头插法)
 * @param item
 * @return
 */
//void addNodeL(List_t * list, ListItem_t * item)
//{
//    ListItem_t * head = list->pTail;
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

//void insertItemR(List_t * list,ListItem_t * target,ListItem_t * item)
//{
//
//}
//
/**
 * 交换元素
 * @param list
 * @param item1
 * @param item2
 */
void swapItem(List_t * list,ListItem_t * item1,ListItem_t * item2)
{
    if (item1 == list->pHead)
    {
        list->pHead = item2;
    }
    if (item2 == list->pHead)
    {
        list->pHead = item1;
    }
    if (item1 == list->pTail)
    {
        list->pTail = item2;
    }
    if (item2 == list->pTail)
    {
        list->pTail = item1;
    }
    //两个节点相邻的情况
    if(item1->pNext == item2 || item1->pPrevious == item2){
        ListItem_t * nextTmp;
        ListItem_t * preTmp;
        ListItem_t * itemTmp;
        if(item1->pNext == item2){
            nextTmp = item2->pNext;
            preTmp = item1->pPrevious;
        }else{
            nextTmp = item1->pNext;
            preTmp = item2->pPrevious;
            itemTmp = item1;
            item1 = item2;
            item2 = itemTmp;
        }
        preTmp->pNext = item2;
        item2->pPrevious = preTmp;
        nextTmp->pPrevious = item1;
        item1->pNext = nextTmp;
        item1->pPrevious = item2;
        item2->pNext = item1;

    }else{
        ListItem_t * nextTmp2 = item2->pNext;
        ListItem_t * preTmp2 = item2->pPrevious;
        ListItem_t * nextTmp1 = item1->pNext;
        ListItem_t * preTmp1 = item1->pPrevious;

        if(item2->pNext == NULL){

        }
        if(item2->pNext != NULL){
            nextTmp2->pPrevious = item1;
        }
        if(item2->pPrevious != NULL){
            preTmp2->pNext = item1;
        }
        if(item1->pNext != NULL){
            nextTmp1->pPrevious = item2;
        }
        if(item1->pPrevious != NULL){
            preTmp1->pNext = item2;     //把要替换的两个节点的左右两个节点的左右指针更新下
        }
        item1->pNext = nextTmp2;
        item1->pPrevious = preTmp2;
        item2->pNext = nextTmp1;
        item2->pPrevious = preTmp1;  // 交换两个节点的左右指针
    }


}






/*蛇形输出数字*/
#include<cstdio>
#include<cstdlib>
#include "include/list.h"
int main()
{
    int arr[6] = {1,2,3,4,5,6};
    List_t * l = initList(&arr[0]);
    if(l->pIndex->pNext == NULL){
        printf("---------------\n");
    }
    ListItem_t * item2 = createItem(&arr[1]);
    ListItem_t * item3 = createItem(&arr[2]);
    ListItem_t * item4 = createItem(&arr[3]);
    ListItem_t * item5 = createItem(&arr[4]);
    ListItem_t * item6 = createItem(&arr[5]);
    addNodeR(l,item2);
    addNodeR(l,item3);
    addNodeR(l,item4);
    addNodeR(l,item5);
    delItem(l,item4);
    addNodeR(l,item6);

//    for(ListItem_t *i = l->pIndex; i != NULL; i = nextItem(l)){
//        printf("%d 111\n", * i->data);
//    }
    ListItem_t *i = l->pIndex;
    while (true)
    {
        printf("%d \n", * i->data);
        if(i->pNext == NULL){
            break;
        }
        i = nextItem(l);
    }

//    while (true)
//    {
//
//        printf("%d --\n", * i->data);
//        i = prevItem(l);
//        if(i->pNext->pNext == NULL){
//            break;
//        }
//    }


    return 0;
}
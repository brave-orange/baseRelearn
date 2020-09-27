
/*蛇形输出数字*/
#include "stdio.h"
#include "include/list.h"
int main()
{
    int arr[6] = {1,2,3,4,5,6};
    List_t * l = initList(&arr[0]);
    ListItem_t * item2 = createItem(&arr[1]);
    ListItem_t * item3 = createItem(&arr[2]);
    ListItem_t * item4 = createItem(&arr[3]);
    ListItem_t * item5 = createItem(&arr[4]);
    ListItem_t * item6 = createItem(&arr[5]);
    addNodeR(l,item2);
    addNodeR(l,item3);
    addNodeR(l,item4);
    addNodeR(l,item5);
    addNodeR(l,item6);
    swapItem(l, l->pHead, l->pTail);

    ListItem_t *i = l->pIndex;
    while (true)
    {
        printf("%d \n", * i->data);
        if(i->pNext == NULL){
            break;
        }
        i = nextItem(l);
    }



    return 0;
}
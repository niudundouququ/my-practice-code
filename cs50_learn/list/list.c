#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *list = malloc(3*sizeof(int));
    //malloc的返回值是分配的内存的第一个byte的地址
    //这段话实际上是将地址存储在一个叫list的指针中

    if (list == NULL)
    {
        return 1;
    }
    //每次分配内存都需要检测一下内存是否有问题


    list[0] = 1;
    list[1] = 2;
    //等价写法：
    *(list + 2) = 3;

    for (int i = 0; i<3 ;i++)
    {
        printf("%i\n",list[i]);
    }

    /*
    list = realloc(list,4*sizeof(int));
    //注意reaclloc的语法与alloc不同，需要指定需重新分配内存的指针
    if (list == NULL)
    {
        free(list);
        return 1;
    }
    list[3] = 4;
    */
    //这里为什么不用list = realloc ，是因为如果这个操作出现了什么问题，就会丢失对原始数据的追踪


    int *temp = realloc(list,4*sizeof(int));
    if (temp == NULL)
    {
        free(list);
        return 1;
    }
    temp[3] = 4;
    list = temp;


    for (int i = 0; i<4 ;i++)
    {
        printf("%i\n",list[i]);
    }

    free(list);

    return 0;
}
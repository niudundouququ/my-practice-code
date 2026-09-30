#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main()
{
    node *list = NULL;

    for (int i = 0; i < 4; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        int numb;
        printf("Number: ");
        scanf("%i",&numb);
        n->number = numb;
        n->next = NULL;

        //sorted_list
        if (list == NULL)
        {
            //n->next = list; 这一行代码好像没必要，毕竟创建的时候已经设置n->next = NULL了
            list = n;
        }
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        else
        {
            /*
            node *ptr = list;
            while (ptr->next->number < n->number)
            {
                if (ptr->number < n->number && n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
            */
           //这一部分必然是错的
            for (node *ptr = list; ptr != NULL;ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
                
                if (n->number < ptr->next->number)
                //只用判小于号，如果大于等于则此次循环跳过，执行下一次直到找到满足条件的
                //这里是一个一个比较，所以不会跳过一些值
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n",ptr->number);
        ptr = ptr->next;
    }

    //free the memory
    for (ptr = list ; ptr != NULL; ptr = ptr->next)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
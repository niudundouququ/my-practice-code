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

    for (int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));//我不知道错哪了
        if (n == NULL)
        {
            return 1;
        }
        int s;
        printf("Number:");
        scanf("%i",&s);
        //scanf函数第一个输入是数据类型，第二个输入是指针，scanf将输入的数据存储到指针所指的地址中
        n->number = s;
        n->next = NULL;

        //prepend
        n->next = list;
        list = n;
        //指针不是随时更新的
    }
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n",ptr->number);
        ptr = ptr->next;
    }

    return 0;
}
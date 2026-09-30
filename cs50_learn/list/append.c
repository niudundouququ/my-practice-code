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

    for (int i = 0;i < 3; i++)
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

        //append
        if (list == NULL)
        {
            list = n;
        }
        else
        {
            node *ptr = list;
            while (ptr->next != NULL)
            //注意这里不能是ptr = NULL，因为如果是这样的话，while执行完ptr指向的是NULL而不是最后一个node
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n",ptr->number);
        ptr = ptr->next;
    }

    //free memory
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}
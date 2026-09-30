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
            n->next = list;
            list = n;
        }
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }
        else
        {
            
            node *ptr = list;
            while (ptr->next->number < n->number)
            {
                if (ptr->number < n->number && n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            /*
            for (node *ptr = list; ptr != NULL;ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
                
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
            */
        }
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n",ptr->number);
        ptr = ptr->next;
    }
}
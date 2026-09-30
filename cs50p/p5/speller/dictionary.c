// Implements a dictionary's functionality
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N] = {NULL}; //开始时一键设置为NULL

int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int h = hash(word);
    //先把所有大写转换成小写
    char temp_word[LENGTH + 1];
    for(int i = 0;i < LENGTH + 1; i++)
    {
        if(isalpha(word[i]))
        {
            temp_word[i] = tolower(word[i]);
        }
        else
        {
            temp_word[i] = word[i];
        }
    }

    node *ptr = table[h];
    while(ptr != NULL)
    {
        if(strcmp(temp_word,ptr->word) == 0) //strcmp在两字符串相等的时候返回0
        {
            return true;
        }
        
        ptr = ptr->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary,"r");
    if(file == NULL)
    {
        return false;
    }

    char c;
    /*node *newword = malloc(sizeof(node));
    newword->next = NULL;*/

    char word_buffer[LENGTH+1];
    int index = 0;

    while(fread(&c,sizeof(char),1,file))
    {
        if(isalpha(c))
        {
            if(index < LENGTH)//谨慎
            {
                word_buffer[index] = c;
                index++;
            }
        }
        else//当读入\n的时候
        {
            word_buffer[index] = '\0'; //补上结尾字符串
            if(index > 0)//防止插入空行
            {
                node *new_word = malloc(sizeof(node));
                //内存分配失败的时候记得先关文件再返回值
                if(new_word == NULL)
                {
                    fclose(file);
                    return false;
                }


                //把word_buffer读取出来的数放入new_word里面
                strcpy(new_word->word ,word_buffer);
                new_word->next = NULL;

                //求哈希值
                int h = hash(new_word->word);


                //推入哈希表
                if (table[h] == NULL)
                {
                    table[h] = new_word;
                    //这两步仔细想想指针指向的哪！
                }
                else
                {
                    //直接插入，不需要补到link末尾
                    new_word->next = table[h];
                    table[h] = new_word;
                }
                word_count++;

            }
            index = 0;
            
        }

    }


    // 【关键】检查 fread 退出循环是因为到了 EOF，还是因为发生了 I/O 错误
    if (ferror(file))
    {
        fclose(file);
        return false;
    }


    // 【关键】检查 fclose 是否成功
    if (fclose(file) != 0)//fclose在括号里面已经被执行了
    {
        return false;
    }


    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    /*
    for(int n = 0;n < N; n++)
    {
        node *ptr = table[n];
        while(ptr != NULL)
        {
            node *temp = ptr;
            if(ptr->next == NULL)
            {
                free(ptr);
            }
            else
            {
                temp = ptr;
                ptr = ptr->next;
                free(temp);
            }
        }
        
    }

    return true;
    */
    for (unsigned int n = 0; n < N; n++)
    {
        node *ptr = table[n];
        while (ptr != NULL)
        {
            node *temp = ptr;      // 保存当前节点
            ptr = ptr->next;       // 指针移向下一个节点
            free(temp);            // 释放当前节点
        }
        table[n] = NULL;           // 释放后将桶置为 NULL，防止野指针
    }
    return true;
}

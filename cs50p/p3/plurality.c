#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char *name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // 获取选民人数 (替换 get_int)
    int voter_count;
    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // 【核心修复】：清空输入缓冲区中残留的字符（包括回车键 \n）
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        // 获取投票名字 (替换 get_string)
        char name[256];
        printf("Vote: ");
        // 使用 fgets 读取一行，最多读取 255 个字符，防止缓冲区溢出
        fgets(name, sizeof(name), stdin);

        // 去除 fgets 读入的末尾换行符 '\n'
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n')
        {
            name[len - 1] = '\0';
        }

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();

    return 0;
}

// Update vote totals given a new vote
bool vote(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // 第一遍遍历：找出最高票数
    int max_vote = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_vote)
        {
            max_vote = candidates[i].votes;
        }
    }

    // 第二遍遍历：打印所有得票等于最高票数的候选人（支持平局）
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
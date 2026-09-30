#include <iostream>
#include <vector> // 引入 vector 头文件

int main() {
    int n; 
    std::cout << "How many problem sets are there? ";
    std::cin >> n;

    // 使用 vector 创建一个大小为 n 的动态数组
    std::vector<int> score(n);
    int sum = 0; // 【修正1】初始化 sum 为 0

    // 第一个循环：专门用于输入所有分数
    for (int i = 0; i < n; i++) {
        std::cout << "What's your score of problem set " << i + 1 << "? ";
        std::cin >> score[i];
    }

    // 第二个循环：专门用于计算总分
    for (int i = 0; i < n; i++) {
        sum = sum + score[i];
    }
    
    // 【修正2 & 3】循环结束后，再计算并输出平均分
    // 注意：整数除法会舍去小数部分。如果需要精确平均值，应将 sum 或 n 转换为浮点数。
    double average = static_cast<double>(sum) / n; 

    std::cout << "Your average score is " << average << std::endl;

    return 0;
}
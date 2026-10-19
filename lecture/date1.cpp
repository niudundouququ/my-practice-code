#include <iostream>
using namespace std;

int main()
{
    //用户输入年份
    cout << "Please input year (2023-2050): ";
    int year;
    cin >> year;
    if (year < 2023 || year > 2050) {
        cout << "Error! Not in range [2023..2050]\n";
        return 1;
    }
     // 计算天数
    int cnt = 0;
    for (int y = 2023; y < year; y++) 
        cnt += (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) ? 366 : 365;
    // 已知2023.01.01是星期日，计算1月1日是星期几 
    int w = cnt % 7; // 1: Mon, 2: Tue, 3: Wed, 4: Thu, 5: Fri, 6: Sat, 0: Sun 
    if (w == 0) w = 7; // 调整一下，方便后续处理1月份的前导空白

    //开始输出指定年份的日历
    cout << "01"; // Jan.
    //输出年前空白（上一年在第一周里所占天数）
    for (int day=0; day<w-1; day++) cout << "   ";
    // 输出各月日历
    for (int month=1; month<=12; month++) {
        int lastday = (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
        if (month == 2) lastday = (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) ? 29 : 28;

        for (int day=1; day<=lastday; day++, w++) {
            printf("%3d", day); // 右对齐，3字符宽，不足补空格
            if (w % 7 == 0) {
                if (lastday - day < 7 && month < 12)
                    printf("\n%02d", month+1); // 01~11月日历最后一行要特殊处理，右对齐，2字符宽，不足补0
                else
                    printf("\n  "); // 一般情况是显示空格
            }
        }
    }

    // 至此，已完成所有日期的输出
    cout << endl;

    return 0;
}

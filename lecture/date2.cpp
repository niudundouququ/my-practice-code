#include<iostream>

using namespace std;

int main()
{
    int year;
    cin >> year;
    if(year < 2023 || year > 2050)
    {
        cout << "no";
        return 1;
    }

    //先算出来year1月1对应的是星期几
    int first_day = 6; //sunday 6  monday 0
    int w = 0; 
    for(int i = 2023; i < year;i++)
    {
        if((i%4) == 0) first_day = (first_day + 366)%7;
        else first_day = (first_day + 365) % 7;
    }

    int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//表示输出值

    if(year%4 == 0) month[1] = 29;

    cout << "01";
    for(w = 0; w < first_day ; w++) cout << "   "; //把不一样的输出解决了
    
    int trigger = 0;//trigger吧类似于
    for(int i = 1; i <= 12; i++)
    {
        for(int j = 1; j <= month[i];j++,w++)
        {
            if(w % 7 == 6 ) //周日判断
            {
                
                if(month[i] - j + 1 < 7)//某行剩下的日期的数量
                {
                    if(i + 1 < 13) printf("\n%02d",i+1);
                    else cout << endl << "  ";
                    printf("%3d",j);
                }
                else if(month[i] - j + 1 == 7)//恰好剩下七个
                {
                    cout << endl << "  ";
                    for( ; j <= month[i]; j++, w++) printf("%3d",j); //把剩下的7个输出完毕
                    if(i + 1 < 13) printf("\n%02d",i+1);
                    w--;
                    j--;
                    trigger = 1;//如果触发这个trigger 那么跳过下一次的打印空行
                }
                else
                {
                    if(i != 1 || j != 1) 
                    {
                        if(trigger == 0) cout << endl << "  "; //解决了2024年的奇怪分支,但是导致了2025的奇怪分支
                        else trigger = 0;
                    }
                    printf("%3d",j);
                }
            }
            else printf("%3d",j);
        }
        
    }
}
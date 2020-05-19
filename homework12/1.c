//guoxuter
//编写一个程序，测试选择排序、冒泡排序和线性插入排序在相同输入情况下的排序效率（比较次数和元素移动次数）。

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Max 300

int compare_num; //比较次数
int move_num;    //移动次数

void Select_Sort(int V[], int n);
void Bubble_Sort(int V[], int n);
void Insert_Sort(int L[], int n);

void Print_Vector(int V[], int n);         //输出数组
void Random_Vector(int V[], int n);        //创建随机数组(100以内的随机数)
void Copy_Vector(int v[], int V[], int n); //实现数组的拷贝

int main(void)
{
    int V[Max] = {0}, v_temp[Max] = {0};
    int n = 3; //数列长度
    Random_Vector(V, n);
    printf("随机生成序列：\n\t");
    Print_Vector(V, n);

    Copy_Vector(v_temp, V, n);//初始化v_temp
    printf("\n选择排序-----------------------\n排序前：");
    Print_Vector(v_temp, n);
    Select_Sort(v_temp, n);
    printf("排序后：");
    Print_Vector(v_temp, n);
    printf("比较次数：%5d\n移动次数：%5d\n", compare_num, move_num);

    Copy_Vector(v_temp, V, n); //恢复原来顺序-----------
    printf("\n冒泡排序-----------------------\n排序前：");
    Print_Vector(v_temp, n);
    Bubble_Sort(v_temp, n);
    printf("排序后：");
    Print_Vector(v_temp, n);
    printf("比较次数：%5d\n移动次数：%5d\n", compare_num, move_num);

    Copy_Vector(v_temp, V, n); //恢复原来顺序-----------
    printf("\n插入排序-----------------------\n排序前:");
    Print_Vector(v_temp, n);
    Insert_Sort(v_temp, n);
    printf("排序后：");
    Print_Vector(v_temp, n);
    printf("比较次数：%5d\n移动次数：%5d", compare_num, move_num);

    getchar();
    return 0;
}

//选择排序算法
void Select_Sort(int V[], int n) //V为数据表名，n为记录数
{
    compare_num = 0;
    move_num = 0;
    int i, j, pos, temp;
    for (i = 1; i < n; i++)
    {
        pos = i; // pos指示关键字值最小的记录
        for (j = i + 1; j <= n; j++)
        {
            compare_num++; //比较次数加一
            if (V[j] < V[pos])
                pos = j;
        }
        if (pos != i)
        {
            temp = V[i];
            V[i] = V[pos];
            V[pos] = temp;
            move_num++; //移动次数加一
        }
    }
}

//冒泡排序算法
void Bubble_Sort(int V[], int n)
{
    compare_num = 0;
    move_num = 0;
    int sign, i, temp, m;
    m = n - 1;
    sign = 1;
    while (m >= 1 && sign == 1)
    {
        i = 1;
        sign = 0;
        while (i <= m)
        {
            compare_num++; //比较次数加一
            if (V[i] > V[i + 1])
            {
                sign = 1;
                temp = V[i];
                V[i] = V[i + 1];
                V[i + 1] = temp; //移动次数加一
                move_num++;
            }
            i = i + 1;
        }
        m = m - 1;
    }
} //Bubble-Sort//

//插入排序算法
void Insert_Sort(int L[], int n) //L为表名，输出时L为有序//
{
    compare_num = 0;
    move_num = 0;
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = L[i + 1]; //待插入记录的关键字值//
        j = i;
        while (j > 0 && x < L[j]) //比较次数加一
        {
            compare_num++;
            L[j + 1] = L[j]; // 插入记录与表中记录比较，并移动//
            move_num++;      //移动次数加一
            j = j - 1;
        }
        if (j > 0)
            compare_num++; //此时虽然没有进入循环，但其仍然进行了判定
        L[j + 1] = x;      //记录的关键字值插入有序表中的位置//
    }
} //Insert-Sort//

//输出数组
void Print_Vector(int V[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%3d", V[i]);
    }
    printf("\n");
}

//创建随机数组(100以内的随机数)
void Random_Vector(int V[], int n)
{
    int Max_num = 99; //随机生成的最大的数字
    int num, i;
    srand(time(NULL));

    for (i = 1; i <= n; i++)
    {
        num = rand() % Max_num + 1;
        V[i] = num;
    }
}

//实现数组的拷贝
void Copy_Vector(int v[], int V[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        v[i] = V[i];
    }
}
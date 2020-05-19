//guoxuter
//实现链式存储下的冒泡排序。

#include <stdlib.h>
#include <stdio.h>
#define Max 300

struct node
{
    int Data;
    struct node *Link;
} * H;
#define LEN sizeof(struct node)

void Bubble_Sort(struct node **, int);
void Random_Link(struct node **H, int n);
void Random_Vector(int V[], int n); //创建随机数组(100以内的随机数)
void Print_Link(struct node *H);

int main(void)
{
    int n = 10;
    Random_Link(&H, n);
    printf("随机链表：");
    Print_Link(H);
    Bubble_Sort(&H, n);
    printf("排序后  ：");
    Print_Link(H);

    getchar();
    return 0;
}

void Bubble_Sort(struct node **H, int n)
{
    struct node *p, *q, *Parent;//Parent在后面为q的双亲结点
    int temp, i;

    if ((*H) == 0) //空链表直接返回
    {
        return;
    }
    for (i = 1; i < n; i++)//控制完成n-1次排序
    {
        p = (*H);
        q = p;
        Parent = (*H);
        while (p->Link != 0)//进行一次排序
        {
            p = p->Link;
            if (q->Data > p->Data)//出现第一个元素大于第二个的情况则交换结点顺序
            {
                if (q != (*H))//对于处于中间的结点直接交换顺序
                {
                    Parent->Link = p;
                    q->Link = p->Link;
                    p->Link = q;
                    p = q;
                }
                else//对于处于头结点处的则直接对头结点赋值，并重置Parent
                {
                    (*H) = p;
                    q->Link = p->Link;
                    p->Link = q;
                    p = q;
                    q = (*H);
                    Parent=(*H);
                }
            }
            if (q != (*H))
            {
                Parent = Parent->Link;
            }
            q = p;
        }
    }
}

//冒泡排序算法
void Bubble_sort(int V[], int n)
{
    int sign, i, temp, m;
    m = n - 1;
    sign = 1;
    while (m >= 1 && sign == 1)
    {
        i = 1;
        sign = 0;
        while (i <= m)
        {
            if (V[i] > V[i + 1])
            {
                sign = 1;
                temp = V[i];
                V[i] = V[i + 1];
                V[i + 1] = temp;
            }
            i = i + 1;
        }
        m = m - 1;
    }
} //Bubble-Sort//

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

//创建随机链表
void Random_Link(struct node **H, int n)
{
    int A[Max];
    Random_Vector(A, n);

    int i;
    struct node *p;
    *H = (struct node *)malloc(sizeof(struct node));
    (*H)->Data = A[1];
    (*H)->Link = 0;
    p = (*H);
    for (i = 2; i <= n; i++)
    {
        p->Link = (struct node *)malloc(sizeof(struct node));
        p = p->Link;
        p->Data = A[i];
        p->Link = 0;
    }
}

//输出链表
void Print_Link(struct node *H)
{
    struct node *p;
    p = H;
    while (p != 0)
    {
        printf("%5d", p->Data);
        p = p->Link;
    }
    printf("\n");
}

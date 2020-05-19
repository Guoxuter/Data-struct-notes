//guoxuter
//ʵ����ʽ�洢�µ�ð������

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
void Random_Vector(int V[], int n); //�����������(100���ڵ������)
void Print_Link(struct node *H);

int main(void)
{
    int n = 10;
    Random_Link(&H, n);
    printf("�������");
    Print_Link(H);
    Bubble_Sort(&H, n);
    printf("�����  ��");
    Print_Link(H);

    getchar();
    return 0;
}

void Bubble_Sort(struct node **H, int n)
{
    struct node *p, *q, *Parent;//Parent�ں���Ϊq��˫�׽��
    int temp, i;

    if ((*H) == 0) //������ֱ�ӷ���
    {
        return;
    }
    for (i = 1; i < n; i++)//�������n-1������
    {
        p = (*H);
        q = p;
        Parent = (*H);
        while (p->Link != 0)//����һ������
        {
            p = p->Link;
            if (q->Data > p->Data)//���ֵ�һ��Ԫ�ش��ڵڶ���������򽻻����˳��
            {
                if (q != (*H))//���ڴ����м�Ľ��ֱ�ӽ���˳��
                {
                    Parent->Link = p;
                    q->Link = p->Link;
                    p->Link = q;
                    p = q;
                }
                else//���ڴ���ͷ��㴦����ֱ�Ӷ�ͷ��㸳ֵ��������Parent
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

//ð�������㷨
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

//�����������(100���ڵ������)
void Random_Vector(int V[], int n)
{
    int Max_num = 99; //������ɵ���������
    int num, i;
    srand(time(NULL));

    for (i = 1; i <= n; i++)
    {
        num = rand() % Max_num + 1;
        V[i] = num;
    }
}

//�����������
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

//�������
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

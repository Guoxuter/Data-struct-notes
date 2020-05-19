//guoxuter
//��дһ�����򣬲���ѡ������ð����������Բ�����������ͬ��������µ�����Ч�ʣ��Ƚϴ�����Ԫ���ƶ���������

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define Max 300

int compare_num; //�Ƚϴ���
int move_num;    //�ƶ�����

void Select_Sort(int V[], int n);
void Bubble_Sort(int V[], int n);
void Insert_Sort(int L[], int n);

void Print_Vector(int V[], int n);         //�������
void Random_Vector(int V[], int n);        //�����������(100���ڵ������)
void Copy_Vector(int v[], int V[], int n); //ʵ������Ŀ���

int main(void)
{
    int V[Max] = {0}, v_temp[Max] = {0};
    int n = 3; //���г���
    Random_Vector(V, n);
    printf("����������У�\n\t");
    Print_Vector(V, n);

    Copy_Vector(v_temp, V, n);//��ʼ��v_temp
    printf("\nѡ������-----------------------\n����ǰ��");
    Print_Vector(v_temp, n);
    Select_Sort(v_temp, n);
    printf("�����");
    Print_Vector(v_temp, n);
    printf("�Ƚϴ�����%5d\n�ƶ�������%5d\n", compare_num, move_num);

    Copy_Vector(v_temp, V, n); //�ָ�ԭ��˳��-----------
    printf("\nð������-----------------------\n����ǰ��");
    Print_Vector(v_temp, n);
    Bubble_Sort(v_temp, n);
    printf("�����");
    Print_Vector(v_temp, n);
    printf("�Ƚϴ�����%5d\n�ƶ�������%5d\n", compare_num, move_num);

    Copy_Vector(v_temp, V, n); //�ָ�ԭ��˳��-----------
    printf("\n��������-----------------------\n����ǰ:");
    Print_Vector(v_temp, n);
    Insert_Sort(v_temp, n);
    printf("�����");
    Print_Vector(v_temp, n);
    printf("�Ƚϴ�����%5d\n�ƶ�������%5d", compare_num, move_num);

    getchar();
    return 0;
}

//ѡ�������㷨
void Select_Sort(int V[], int n) //VΪ���ݱ�����nΪ��¼��
{
    compare_num = 0;
    move_num = 0;
    int i, j, pos, temp;
    for (i = 1; i < n; i++)
    {
        pos = i; // posָʾ�ؼ���ֵ��С�ļ�¼
        for (j = i + 1; j <= n; j++)
        {
            compare_num++; //�Ƚϴ�����һ
            if (V[j] < V[pos])
                pos = j;
        }
        if (pos != i)
        {
            temp = V[i];
            V[i] = V[pos];
            V[pos] = temp;
            move_num++; //�ƶ�������һ
        }
    }
}

//ð�������㷨
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
            compare_num++; //�Ƚϴ�����һ
            if (V[i] > V[i + 1])
            {
                sign = 1;
                temp = V[i];
                V[i] = V[i + 1];
                V[i + 1] = temp; //�ƶ�������һ
                move_num++;
            }
            i = i + 1;
        }
        m = m - 1;
    }
} //Bubble-Sort//

//���������㷨
void Insert_Sort(int L[], int n) //LΪ���������ʱLΪ����//
{
    compare_num = 0;
    move_num = 0;
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = L[i + 1]; //�������¼�Ĺؼ���ֵ//
        j = i;
        while (j > 0 && x < L[j]) //�Ƚϴ�����һ
        {
            compare_num++;
            L[j + 1] = L[j]; // �����¼����м�¼�Ƚϣ����ƶ�//
            move_num++;      //�ƶ�������һ
            j = j - 1;
        }
        if (j > 0)
            compare_num++; //��ʱ��Ȼû�н���ѭ����������Ȼ�������ж�
        L[j + 1] = x;      //��¼�Ĺؼ���ֵ����������е�λ��//
    }
} //Insert-Sort//

//�������
void Print_Vector(int V[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%3d", V[i]);
    }
    printf("\n");
}

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

//ʵ������Ŀ���
void Copy_Vector(int v[], int V[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        v[i] = V[i];
    }
}
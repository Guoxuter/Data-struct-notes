//���ݽṹ��ҵ01
//��С������
#include <stdio.h>

int lcd(int, int);
int main()
{
    int m, n;
    printf("dslfs");
    scanf("%d %d", &m, &n);
    printf("%d��%d����С������Ϊ%d", m, n, lcd(m, n));

    scanf("%d",&m);
    
    return 0;
}

//
int lcd(int m, int n)
{
    int r;
    r = m * n;

    while (1)
    {
        if (m == n)
        {
            return r / m;
        }

        else if (m > n)
        {
            m = m - n;
        }
        else
        {
            n = n - m;
        }
    }
}
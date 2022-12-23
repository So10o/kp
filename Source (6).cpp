#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

const double pi = 3.14;

double F1(double x)
{
    return 2 * sin(pi * x) + sin(3 * pi * x) / (3 * x);
}

double F2(double x)
{
    if (x < 0)
    {
        return 1 + (3 + x) / (1 + x * x);
    }

    if (x < 1)
    {
        return sqrt(1 + (1 - x) * (1 - x));
    }

    if (x >= 1)
        return  (1 + x) / (1 + cos(x) * cos(x));
}



void tabulation(double x1, double x2, double h, double (*f)(double))
{
    printf("x\tF(x)\n");
    for (double i = x1; i <= x2; i += h)
    {
        printf("%.2lf\t%.2lf\n", i, f(i));
    }
}


int main() {
    //������������� ������� ����
    setlocale(LC_ALL, "ru");

    //�������� �� ����� ������������ � ����
    int choose;

    while (1)
    {
        system("cls");// ������ �������

        //----start----- ����� ����������������� ����
        printf("1. ����� �������� F1(x)\n");
        printf("2. ����� �������� F2(x)\n");
        printf("3. ����� �������� F1(x) �� �������� ���������\n");
        printf("4. ����� �������� F2(x) �� �������� ���������\n");
        printf("5. ��������� ������ F1(x)\n");
        printf("6. ��������� ������ F2(x)\n");
        printf("7. ����� �� ���������\n");
        printf("������� �����: \n");
        //----end----- ����� ����������������� ����

        //������ ������������ ������� ����� ����
        scanf("%d", &choose);
        // ������ �������
        system("cls");  


        //�������, ��� ���� ������������
        //���� ���� ���������� �������� - ��������� �������
        //����� ������ ������� ����������������� ����
        if (choose == 1)
        {
            double x;
            printf("������� x: ");
            scanf("%lf", &x);
            printf("F(%lf) = %lf", x, F1(x));
            printf("\n");

        }
        else if (choose == 2)
        {
            double x;
            printf("������� x: ");
            scanf("%lf", &x);
            printf("F(%lf) = %lf", x, F2(x));
            printf("\n");

        }
        else if (choose == 3 || choose == 4)
        {

            //������ ������������ ������ ���������� � ���
            double x1, x2, h;
            printf("������� x1: ");
            scanf("%lf", &x1);

            printf("������� x2: ");
            scanf("%lf", &x2);

            printf("������� h: ");
            scanf("%lf", &h);

            //������ ������������ ������� ��� ����������
         
            int t;
            do {
                printf("�������� ��� ����������: ");
                printf("\n1.[%.1lf; %.1lf]",x1,x2);
                printf("\n2.[%.1lf; %.1lf)", x1, x2);
                printf("\n3.(%.1lf; %.1lf]", x1, x2);
                printf("\n4.(%.1lf; %.1lf)\n", x1, x2);
                scanf("%d", &t);
            } while (t <= 0 && t >= 5);   //���� ������� �� ��������� - ��������� ����


            //������� ������ �������, ���� ��� ������ 2 ��� 4 �����
            if (t == 2 || t == 4)
            {
                x2 -= h;
            }

            //������� ����� �������, ���� ��� ������ 3 ��� 4 �����
            if (t == 3 || t == 4)
            {
                x1 += h;
            }

            //�������� ������� ��������� � �������� ���� ��������� �� �������, ������� ��������� F(x)
            if (choose == 3)
                tabulation(x1, x2, h, F1);
            else
                tabulation(x1, x2, h, F2);
        }
        else if (choose == 5)
        {
            //������ ������ ������� F1
            for (double y = 3.5; y >= -3.5; y -= 0.05)
            {
                for (double x = -2; x < 2; x += 0.01)
                {
                    double fx = F1(x);
                    if (fx >= y && fx < (y + 0.1))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        else if (choose == 6)
        { 
            //������ ������ ������� F2
            for (double y = 20; y >= -1; y -= 0.05)
            {
                for (double x = -20; x < 20; x += 0.05)
                {
                    double fx = F2(x);
                    if (fx >= y && fx < (y + 0.1))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(" ");
                    }

                }
                printf("\n");
            }
        }
        else if (choose == 7)
        {
            //������� �� �����, �������������, � �� ���������
            break;
        }

        system("pause"); 
    }

    return 0;
}
/*
��ʼ��һ��˳���;
��������ż�������˳������;
������ż�Ե���˳��,������ǰ,ż���ں�;
������������ż����ǰ���λ���ϵ���˳���β���ĵ�һ����������,���ν���ֱ������Ԫ��λ�ö���λ
*/
#include<stdio.h>
#include<malloc.h>
#define MaxSize 50

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
} SqList;

//��ʼ�����Ա�
void InitList(SqList *&L)
{
	L = (SqList *)malloc(sizeof(SqList));  //���������Ա�Ŀռ�
	L->length = 0;                         //�ÿ����Ա���Ϊ0
}

//�������Ա�
void DestroyList(SqList *L)
{
	free(L);
}

//�ж����Ա��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList *L)
{
	return(L->length == 0);
}

//��������Ԫ��
bool ListInsert(SqList *&L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1)
		return false;                   //��������ʱ����false
	i--;                                //��˳����߼����ת��Ϊ�������
	for (j = L->length; j > i; j--)            //��data[i]������Ԫ�غ���һ��λ��
		L->data[j] = L->data[j - 1];
	L->data[i] = e;                       //����Ԫ��e
	L->length++;                        //˳�������1
	return true;                        //�ɹ����뷵��true
}

//������Ա�
void DispList(SqList *L)
{
	int i;
	if (ListEmpty(L)) return;
	for (i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

void move(SqList &L)
{
	int i = 0, j = L.length - 1;
	ElemType temp;
	while (i <= j)
	{
		while (L.data[i] % 2 == 1)
		{
			i++;
		}
		while (L.data[j] % 2 == 0)
		{
			j--;
		}
		if (i < j)
		{
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
}

void main()
{
	SqList *L;
	printf("˳���Ļ�����������:\n");
	printf("   (1)��ʼ��˳���L\n");
	InitList(L);
	printf("   (2)��ʱ���Ա�Ϊ��");
	ListInsert(L, 1, 2);
	ListInsert(L, 2, 3);
	ListInsert(L, 3, 6);
	ListInsert(L, 4, 8);
	ListInsert(L, 5, 7);
	ListInsert(L, 6, 1);
	ListInsert(L, 7, 5);
	ListInsert(L, 8, 9);
	DispList(L);

	printf("   (3)�ƶ���żԪ�غ����Ա�Ϊ:");
	move(*L);
	DispList(L);

	printf("   (4)�ͷ�˳���L\n");
	DestroyList(L);

}

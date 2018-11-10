#pragma once
#include<windows.h>
#include<assert.h>
#include<stdio.h>
#include<malloc.h>

typedef int DataType;
typedef struct Node
{
	struct Node* _pNext;
	DataType data;
}Node,*PNode;


typedef struct ComPlexListNode
{
	struct ComPlexListNode* _pNext;
	struct ComPlexListNode* _pRandom;
	DataType data;
}ComPlexListNode,*pComPlexListNode;
////////////////////////////////////////////////
////////////////��������////////////////////////
///////////////////////////////////////////////
//�����ʼ��
void SListInit(PNode* pHead);

//��ýڵ�
PNode BuySListNode(DataType data);

//����β��
void SListPushBack(PNode* pHead, DataType data);

//����βɾ
void SListPopBack(PNode* pHead);

//����ͷ��
void SListPushFront(PNode* pHead, DataType data);

//����ͷɾ
void SListPopFront(PNode* pHead);

//����ֵΪdata�Ľڵ㣬���ظýڵ��������е�λ��
PNode SListFind(PNode pHead, DataType data);

//������posλ�ú����ڵ�
void SListInsert(PNode* pHead, PNode pos, DataType data);

//ɾ������posλ�õĽڵ�
void SListErase(PNode* pHead, PNode pos);

//��������
void SListDestory(PNode* pHead);

//�������еĽڵ����
void SListClear(PNode* pHead);

//�������нڵ�ĸ���
int SListSize(PNode pHead); 

//��ȡ�����������һ���ڵ��λ��
PNode SListBack(PNode pHead);

//��ӡ������
void SListPrint(PNode pHead);

////////////////////////////////////////////////
////////////////������//////////////////////////
///////////////////////////////////////////////

//��β��ͷ��ӡ������
void PrintListFromTail(PNode pHead);

//ɾ����β�ڵ�
void DeleteNotTailNode(PNode pos);

//��posǰ�����ڵ�
void InsertPosFront(PNode pos, DataType data);

//Լɪ��
void JosephCircle(PNode *pHead, const int M);

//ð������
void BubbleSort(PNode pHead);

//���õ�����--����ָ��
void ReverseSlist(PNode *pHead);

//ͷ�巨���õ�����
PNode ReverseSlistOP(PNode pHead);

//�ϲ�������������
PNode MergeSlist(PNode pHead1, PNode pHead2);

//�����м�ڵ㣬ֻ����һ������
PNode FindMiddleNode(PNode pHead);

//���ҵ�����k���ڵ㣬ֻ����һ������
PNode FindLastKNode(PNode pHead, int k);

//ɾ��������k���ڵ㣬ֻ����һ������
PNode DeleteLastKNode(PNode pHead, int k);

//�жϵ������Ƿ��ཻ����������
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

//�����������ཻ����
PNode GetCrossNode(PNode pHead1, PNode pHead2);

//�ж������Ƿ����
PNode IsCircle(PNode pHead);

//�󻷵ĳ���
int GetCircleLen(PNode pHead);

//�󻷵���ڵ�
PNode GetEnterNode(PNode pHead, PNode pMeetNode);

//�ж������Ƿ��ཻ��������ܴ���
int IsCrossWithCircle(PNode pHead1, PNode pHead2);

//��������ĸ���
pComPlexListNode CopyCoplexList(pComPlexListNode pHead);
void SListPrintComplex(pComPlexListNode pHead);






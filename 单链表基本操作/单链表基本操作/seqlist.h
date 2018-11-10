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
////////////////基本操作////////////////////////
///////////////////////////////////////////////
//链表初始化
void SListInit(PNode* pHead);

//获得节点
PNode BuySListNode(DataType data);

//链表尾插
void SListPushBack(PNode* pHead, DataType data);

//链表尾删
void SListPopBack(PNode* pHead);

//链表头插
void SListPushFront(PNode* pHead, DataType data);

//链表头删
void SListPopFront(PNode* pHead);

//查找值为data的节点，返回该节点在链表中的位置
PNode SListFind(PNode pHead, DataType data);

//在链表pos位置后插入节点
void SListInsert(PNode* pHead, PNode pos, DataType data);

//删除链表pos位置的节点
void SListErase(PNode* pHead, PNode pos);

//销毁链表
void SListDestory(PNode* pHead);

//将链表中的节点清空
void SListClear(PNode* pHead);

//求链表中节点的个数
int SListSize(PNode pHead); 

//获取单链表中最后一个节点的位置
PNode SListBack(PNode pHead);

//打印单链表
void SListPrint(PNode pHead);

////////////////////////////////////////////////
////////////////面试题//////////////////////////
///////////////////////////////////////////////

//从尾到头打印单链表
void PrintListFromTail(PNode pHead);

//删除非尾节点
void DeleteNotTailNode(PNode pos);

//在pos前面插入节点
void InsertPosFront(PNode pos, DataType data);

//约瑟夫环
void JosephCircle(PNode *pHead, const int M);

//冒泡排序
void BubbleSort(PNode pHead);

//逆置单链表--三个指针
void ReverseSlist(PNode *pHead);

//头插法逆置单链表
PNode ReverseSlistOP(PNode pHead);

//合并两个有序链表
PNode MergeSlist(PNode pHead1, PNode pHead2);

//查找中间节点，只遍历一次链表
PNode FindMiddleNode(PNode pHead);

//查找倒数第k个节点，只遍历一次链表
PNode FindLastKNode(PNode pHead, int k);

//删除倒数第k个节点，只遍历一次链表
PNode DeleteLastKNode(PNode pHead, int k);

//判断单链表是否相交，链表不带环
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2);

//不带环链表相交交点
PNode GetCrossNode(PNode pHead1, PNode pHead2);

//判断链表是否带环
PNode IsCircle(PNode pHead);

//求环的长度
int GetCircleLen(PNode pHead);

//求环的入口点
PNode GetEnterNode(PNode pHead, PNode pMeetNode);

//判断链表是否相交，链表可能带环
int IsCrossWithCircle(PNode pHead1, PNode pHead2);

//复杂链表的复制
pComPlexListNode CopyCoplexList(pComPlexListNode pHead);
void SListPrintComplex(pComPlexListNode pHead);






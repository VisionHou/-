#include"seqlist.h"

/*typedef int DataType;
typedef struct Node
{
	struct Node* _pNext;
	DataType data;
}Node,*PNode;
*/

////////////////////////////////////////////////
////////////////基本操作////////////////////////
///////////////////////////////////////////////
void SListInit(PNode* pHead)
{
	assert(pHead);
	*pHead = NULL;
}

PNode BuySListNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (pNewNode == NULL)
	{
		//申请失败
		return NULL;
	}
	else
	{
		pNewNode->data = data;
		pNewNode->_pNext = NULL;
	}
	return pNewNode;
}

void SListPushBack(PNode* pHead, DataType data)
{
	PNode pCur = NULL;
	PNode pNewNode = NULL;
	assert(pHead);
	pCur = *pHead;
	pNewNode = BuySListNode(data);
	if (pNewNode == NULL)
		return;
	//空链表
	if (*pHead == NULL)
	{
		*pHead = pNewNode;
		return;
	}
	//非空链表
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	pCur->_pNext = pNewNode;

}

void SListPopBack(PNode* pHead)
{
	assert(pHead);
	//空链表
	if (*pHead == NULL)
	{
		return;
	}
	//非空链表
	else
	{
		PNode pCur = *pHead;
		//只有一个节点
		if (pCur->_pNext==NULL)
		{
			free(pCur);
			*pHead = NULL; 
		}
		else
		{
			//多个节点
			while (pCur->_pNext->_pNext)
			{
				pCur = pCur->_pNext;
			}
			free(pCur->_pNext);
			pCur->_pNext = NULL;
		}
	}

}

void SListPushFront(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	pNewNode = BuySListNode(data);
	if (pNewNode == NULL)
		return;
	//空 非空

	pNewNode->_pNext = *pHead;
	*pHead = pNewNode;
}

void SListPopFront(PNode* pHead)
{
	PNode pDel = NULL;
	assert(pHead);
	if (*pHead == NULL)
		return;

	pDel = *pHead;
	*pHead = pDel->_pNext;
	free(pDel);
}

PNode SListFind(PNode pHead, DataType data)
{
	PNode pCur = pHead;
	while (pCur)
	{
		if (pCur->data == data)
		{
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}

void SListInsert(PNode* pHead, PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);
	if (*pHead == NULL || pos == NULL)
		return;

	pNewNode = BuySListNode(data);
	if (pNewNode == NULL)
		return;

	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErase(PNode* pHead, PNode pos)
{
	assert(pHead);
	PNode pCur = *pHead;
	if (*pHead == NULL || pos == NULL)
		return;
	if (pos == *pHead)
		SListPopFront(&pos);

	else
	{
		while (pCur->_pNext != pos)
		{
			pCur = pCur->_pNext;
		}

		pCur->_pNext =pos->_pNext;
		free(pos);
	}
}

void SListDestory(PNode* pHead)
{
	SListClear(&pHead);
}

void SListClear(PNode* pHead)
{
	PNode pDel = NULL;
	assert(pHead);

	while (*pHead)
	{
		pDel = *pHead;
		*pHead = pDel->_pNext;
		free(pDel);
	}
}

int SListSize(PNode pHead)
{
	assert(pHead);
	int count = 0;
	PNode pCur = pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
PNode SListBack(PNode pHead)
{
	assert(pHead);
	PNode pCur = pHead;
	while (pCur->_pNext)
		pCur = pCur->_pNext;

	return pCur;
}

void SListPrint(PNode pHead)
{
	
	if (pHead == NULL)
	{
		printf("链表为空\n");
	}
	else
	{
		PNode pCur = pHead;
		while (pCur)
		{
			printf("%d---->", pCur->data);
			pCur = pCur->_pNext;
		}
		printf("NULL\n");
	}
}

////////////////////////////////////////////////
////////////////面试题//////////////////////////
///////////////////////////////////////////////

void PrintListFromTail(PNode pHead)
{
	PNode pCur = pHead;

	if (pCur)
	{
		PrintListFromTail(pCur->_pNext);
		printf("%d---->", pCur->data);
	}
}

void DeleteNotTailNode(PNode pos)
{
	PNode pDel = NULL;

	while (pos == NULL || pos->_pNext == NULL)
		return;

	//替换法删除
	pDel = pos->_pNext;
	pos->data = pDel->data;
	pos->_pNext = pDel->_pNext;
	free(pDel);
}

void InsertPosFront(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	//先在后面插入再交换值
	pNewNode = BuySListNode(pos->data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	pos->data = data;

}

void JosephCircle(PNode *pHead, const int M)
//或者返回PNode
{
	PNode pCur = NULL;
	assert(pHead);
	
	pCur = *pHead;
	while(pCur->_pNext!=pCur)
	{   //报数
		int count = M;
		while (--count)
			pCur = pCur->_pNext;
		//删除节点
		PNode pDel = pCur->_pNext;
		pCur->data = pDel->data;
		pCur->_pNext = pDel->_pNext;
		free(pDel);
	}
	//pHead有可能已经被删除
	*pHead = pCur;
	//return pHead;
}

void BubbleSort(PNode pHead)
{
	PNode pPreNode = NULL;
	PNode pCur = NULL;
	PNode End = NULL;

	if (pHead == NULL || pHead->_pNext == NULL)
		return;

	//冒泡次数
	while(pHead!=End)
	{
		int change = 0;
		pPreNode = pHead;
		pCur = pPreNode->_pNext;
		while (pCur != End)
		{   //冒泡方法
			if (pPreNode->data > pCur->data)
			{
				int tmp = pPreNode->data;
				pPreNode->data = pCur->data;
				pCur->data = tmp;
				change = 1;
			}
			pPreNode = pCur;
			pCur = pCur->_pNext;
		}
		if (change == 0)
			return;
			End = pPreNode;
	}

}

//三个指针逆置
void ReverseSlist(PNode *pHead)
{
	PNode pPre = NULL;
	PNode pCur = NULL;
	PNode pNext = NULL;

	if (*pHead == NULL || (*pHead)->_pNext == NULL)
		return;

	pCur = *pHead;
	pNext = pCur->_pNext;
	while (pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	
	*pHead = pPre;
}

//头插法逆置
PNode ReverseSlistOP(PNode pHead)
{
	PNode pCur = NULL;
	PNode pNewNode = NULL;
	PNode pNext = NULL;

	if (pHead == NULL || pHead->_pNext == NULL)
		return NULL;

	pCur = pHead;
	while (pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pNewNode;
		pNewNode = pCur;
		pCur = pNext;
    }
	return pNewNode;
}


PNode MergeSlist(PNode pHead1, PNode pHead2)
{
	PNode pNewNode = NULL;
	PNode Tail = NULL;
	PNode PL1 = pHead1;
	PNode PL2 = pHead2;

	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	//两个链表都不为空
	  //先给pNewNode赋值
	if (pHead1->data < pHead2->data)
	{
		pNewNode = PL1;
		PL1 = PL1->_pNext;
	}
	else
	{
		pNewNode = PL2;
		PL2 = PL2->_pNext;
	}
	
	Tail = pNewNode;
	//尾插法排序
	while (PL1&&PL2)
	{
		if (PL1->data < PL2->data)
		{
			Tail->_pNext = PL1;
			PL1 = PL1->_pNext;
		}
		else 
		{
			Tail->_pNext = PL2;
			PL2 = PL2->_pNext;
		}
		Tail = Tail->_pNext;
	}

	if (PL1)
		Tail->_pNext = PL1;
	else
		Tail->_pNext = PL2;

	return pNewNode;
}

PNode FindMiddleNode(PNode pHead)
{
	//快慢指针
	//快的走两步，慢的走一步
	PNode Fast = pHead;
	PNode Slow = pHead;
	while (Fast && Fast->_pNext)//偶数个&&奇数个
	{
		Fast = Fast->_pNext->_pNext;
		Slow = Slow->_pNext;
	}
	return Slow;
}

PNode FindLastKNode(PNode pHead, int k)
{
	//先找第三个节点，再向后平移
	PNode Fast = pHead;
	PNode Slow = pHead;
	if (pHead == NULL || k < 0)
		return NULL;

	while (k--)//走k步
	{
		//	while (--k)//走k-1步
		if (Fast == NULL)
			return NULL;//k大于节点个数
		Fast = Fast->_pNext;
	}
	//两个同时向后走
	while (Fast)
	{
		//while (Fast->_pNext)
		Slow = Slow->_pNext;
		Fast = Fast->_pNext;
	}
	return Slow;
}
PNode DeleteLastKNode(PNode pHead, int k)
{
	//找节点
	PNode Fast = pHead;
	PNode Slow = pHead;
	PNode pPre = pHead;

	if (pHead == NULL || k < 0)
		return NULL;

	while (k--)//走k步
	{
		if (Fast == NULL)
			return NULL;//k大于节点个数
		Fast = Fast->_pNext;
	}
	  //两个同时向后走
	while (Fast)
	{
		if(Fast->_pNext!=NULL)
		pPre = pPre->_pNext;//保存前一个节点

		Slow = Slow->_pNext;
		Fast = Fast->_pNext;
	}
	//删节点
	  //头节点
	if (Slow == pHead)
	{
		pHead = Slow->_pNext;
		SListPopFront(&Slow);
		return pHead;
	}
	  //非头节点
	pPre->_pNext = Slow->_pNext;
	free(Slow);
	return pHead;
}

int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)
{
	PNode pTail1 = pHead1;
	PNode pTail2  = pHead2;
	if (pHead1 == NULL || pHead2 == NULL)
		return 0;

	//找两个链表最后一个节点
	while (pTail1->_pNext)
		pTail1 = pTail1->_pNext;
	while (pTail2->_pNext)
		pTail2 = pTail2->_pNext;

	//判断两个链表的最后一个节点是否相等
	return pTail1 == pTail2;
}

PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int size1 = 0;
	int size2 = 0;
	int gap = 0;
	if (!IsCrossWithoutCircle(pHead1, pHead2))
		return 0;

	//相交
	//求两个链表节点个数
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;
	while(pCur1)
	{
		size1++;
		pCur1 = pCur1->_pNext;
	}
	while (pCur2)
	{
		size2++;
		pCur2 = pCur2->_pNext;
	}
	 pCur1 = pHead1;
	 pCur2 = pHead2;
	gap = size1 - size2;
	//长的先走gap步
	if (gap > 0)
	{
		while (gap--)
			pCur1 = pCur1->_pNext;
	}
	else
	{
		while (gap++)
		{
			pCur2 = pCur2->_pNext;
		}
	}
	//两个指针同时向后走
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;

	}
	return pCur1;
}

PNode IsCircle(PNode pHead)
{
	//快慢指针
	//快的走两步，慢的走一步
	PNode pFast = pHead;
	PNode pSlow = pHead;
	while (pFast&&pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
		if (pSlow == pFast)
			return pSlow;
	}
	return NULL;
}

int GetCircleLen(PNode pHead)
{
	PNode pMeetNode = IsCircle(pHead);
	if (pMeetNode == NULL)
		return 0;
	
		int count = 0;
		PNode pCur = pMeetNode;
		while (pCur != pMeetNode)
		{
			count++;
			pCur = pCur->_pNext;
		}
	
	return count;
}

PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	  //一个从头走，一个从相遇点走，一定会相遇
	PNode PH = pHead;
	PNode PM = pMeetNode;
	if (pHead == NULL || pMeetNode == NULL)//链表不存在或不带环
		return NULL;
		while (PH != PM)
	{
		PH = PH->_pNext;
		PM = PM->_pNext;
	}
	return PH;
}

int IsCrossWithCircle(PNode pHead1, PNode pHead2)
{
	PNode pMeetNode1 = NULL;
	PNode pMeetNode2 = NULL;

	if (pHead1 == NULL || pHead2 == NULL)
		return 0;//不相交
	pMeetNode1 = IsCircle(pHead1);
	pMeetNode2 = IsCircle(pHead2);

	//两个都不带环
	if (pMeetNode1 == NULL && pMeetNode2 == NULL)
	{
		PNode pCur1 = pHead1;
		PNode pCur2 = pHead2;
		while (pCur1)
			pCur1 = pCur1->_pNext;
		while (pCur2)
			pCur2 = pCur2->_pNext;
		if (pCur1 == pCur2)
			return 1;//不带环相交
	}

	//两个链表均带环
	if (pMeetNode1&&pMeetNode2)
	{
		PNode pCur = pMeetNode2;
		while (pCur != pMeetNode1)
		{
			pCur = pCur->_pNext;
		}
		return 2;//带环相交
	}
	return 0;//不相交
}

pComPlexListNode CopyCoplexList(pComPlexListNode pHead)
{
		pComPlexListNode pOld = pHead;
		pComPlexListNode pNew = NULL;
		pComPlexListNode pNewHead = NULL;
		if (pHead == NULL)
			return NULL;

		//在原链表每个节点后插入值相同的元素
		while (pOld)
		{
			pNew = (ComPlexListNode*)malloc(sizeof(ComPlexListNode));
			if (pNew == NULL)
				return NULL;
			pNew->data = pOld->data;
			pNew->_pNext = NULL;
			pNew->_pRandom = NULL;

			pNew->_pNext = pOld->_pNext;
			pOld->_pNext = pNew;
			pOld = pNew->_pNext;
		}

		//给新插入节点的随机指针域赋值
		pOld = pHead;
		while (pOld)
		{
			pNew = pOld->_pNext;
			if (pOld->_pRandom == NULL)
			{
				pNew->_pRandom = NULL;
				pOld = pNew->_pNext;
			}
			else
			{
				pNew->_pRandom = pOld->_pRandom->_pNext;
				pOld = pNew->_pNext;
			}
		}

		//将插入的新节点从表中拆下来
		pOld = pHead;
		pNewHead = pOld->_pNext;
		while (pOld->_pNext)
		{
			pNew = pOld->_pNext;
			pOld->_pNext = pNew->_pNext;
			pOld = pNew;
		}
		return pNewHead;
}
void SListPrintComplex(pComPlexListNode pHead)
{

	if (pHead == NULL)
	{
		printf("链表为空\n");
	}
	else
	{
		pComPlexListNode pCur = pHead;
		while (pCur)
		{
			printf("%d---->", pCur->data);
			pCur = pCur->_pNext;
		}
		printf("NULL\n");
	}
}
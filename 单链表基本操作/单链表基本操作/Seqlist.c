#include"seqlist.h"

/*typedef int DataType;
typedef struct Node
{
	struct Node* _pNext;
	DataType data;
}Node,*PNode;
*/

////////////////////////////////////////////////
////////////////��������////////////////////////
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
		//����ʧ��
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
	//������
	if (*pHead == NULL)
	{
		*pHead = pNewNode;
		return;
	}
	//�ǿ�����
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	pCur->_pNext = pNewNode;

}

void SListPopBack(PNode* pHead)
{
	assert(pHead);
	//������
	if (*pHead == NULL)
	{
		return;
	}
	//�ǿ�����
	else
	{
		PNode pCur = *pHead;
		//ֻ��һ���ڵ�
		if (pCur->_pNext==NULL)
		{
			free(pCur);
			*pHead = NULL; 
		}
		else
		{
			//����ڵ�
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
	//�� �ǿ�

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
		printf("����Ϊ��\n");
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
////////////////������//////////////////////////
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

	//�滻��ɾ��
	pDel = pos->_pNext;
	pos->data = pDel->data;
	pos->_pNext = pDel->_pNext;
	free(pDel);
}

void InsertPosFront(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	//���ں�������ٽ���ֵ
	pNewNode = BuySListNode(pos->data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	pos->data = data;

}

void JosephCircle(PNode *pHead, const int M)
//���߷���PNode
{
	PNode pCur = NULL;
	assert(pHead);
	
	pCur = *pHead;
	while(pCur->_pNext!=pCur)
	{   //����
		int count = M;
		while (--count)
			pCur = pCur->_pNext;
		//ɾ���ڵ�
		PNode pDel = pCur->_pNext;
		pCur->data = pDel->data;
		pCur->_pNext = pDel->_pNext;
		free(pDel);
	}
	//pHead�п����Ѿ���ɾ��
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

	//ð�ݴ���
	while(pHead!=End)
	{
		int change = 0;
		pPreNode = pHead;
		pCur = pPreNode->_pNext;
		while (pCur != End)
		{   //ð�ݷ���
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

//����ָ������
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

//ͷ�巨����
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

	//����������Ϊ��
	  //�ȸ�pNewNode��ֵ
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
	//β�巨����
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
	//����ָ��
	//�����������������һ��
	PNode Fast = pHead;
	PNode Slow = pHead;
	while (Fast && Fast->_pNext)//ż����&&������
	{
		Fast = Fast->_pNext->_pNext;
		Slow = Slow->_pNext;
	}
	return Slow;
}

PNode FindLastKNode(PNode pHead, int k)
{
	//���ҵ������ڵ㣬�����ƽ��
	PNode Fast = pHead;
	PNode Slow = pHead;
	if (pHead == NULL || k < 0)
		return NULL;

	while (k--)//��k��
	{
		//	while (--k)//��k-1��
		if (Fast == NULL)
			return NULL;//k���ڽڵ����
		Fast = Fast->_pNext;
	}
	//����ͬʱ�����
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
	//�ҽڵ�
	PNode Fast = pHead;
	PNode Slow = pHead;
	PNode pPre = pHead;

	if (pHead == NULL || k < 0)
		return NULL;

	while (k--)//��k��
	{
		if (Fast == NULL)
			return NULL;//k���ڽڵ����
		Fast = Fast->_pNext;
	}
	  //����ͬʱ�����
	while (Fast)
	{
		if(Fast->_pNext!=NULL)
		pPre = pPre->_pNext;//����ǰһ���ڵ�

		Slow = Slow->_pNext;
		Fast = Fast->_pNext;
	}
	//ɾ�ڵ�
	  //ͷ�ڵ�
	if (Slow == pHead)
	{
		pHead = Slow->_pNext;
		SListPopFront(&Slow);
		return pHead;
	}
	  //��ͷ�ڵ�
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

	//�������������һ���ڵ�
	while (pTail1->_pNext)
		pTail1 = pTail1->_pNext;
	while (pTail2->_pNext)
		pTail2 = pTail2->_pNext;

	//�ж�������������һ���ڵ��Ƿ����
	return pTail1 == pTail2;
}

PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int size1 = 0;
	int size2 = 0;
	int gap = 0;
	if (!IsCrossWithoutCircle(pHead1, pHead2))
		return 0;

	//�ཻ
	//����������ڵ����
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
	//��������gap��
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
	//����ָ��ͬʱ�����
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->_pNext;
		pCur2 = pCur2->_pNext;

	}
	return pCur1;
}

PNode IsCircle(PNode pHead)
{
	//����ָ��
	//�����������������һ��
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
	  //һ����ͷ�ߣ�һ�����������ߣ�һ��������
	PNode PH = pHead;
	PNode PM = pMeetNode;
	if (pHead == NULL || pMeetNode == NULL)//�������ڻ򲻴���
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
		return 0;//���ཻ
	pMeetNode1 = IsCircle(pHead1);
	pMeetNode2 = IsCircle(pHead2);

	//������������
	if (pMeetNode1 == NULL && pMeetNode2 == NULL)
	{
		PNode pCur1 = pHead1;
		PNode pCur2 = pHead2;
		while (pCur1)
			pCur1 = pCur1->_pNext;
		while (pCur2)
			pCur2 = pCur2->_pNext;
		if (pCur1 == pCur2)
			return 1;//�������ཻ
	}

	//�������������
	if (pMeetNode1&&pMeetNode2)
	{
		PNode pCur = pMeetNode2;
		while (pCur != pMeetNode1)
		{
			pCur = pCur->_pNext;
		}
		return 2;//�����ཻ
	}
	return 0;//���ཻ
}

pComPlexListNode CopyCoplexList(pComPlexListNode pHead)
{
		pComPlexListNode pOld = pHead;
		pComPlexListNode pNew = NULL;
		pComPlexListNode pNewHead = NULL;
		if (pHead == NULL)
			return NULL;

		//��ԭ����ÿ���ڵ�����ֵ��ͬ��Ԫ��
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

		//���²���ڵ�����ָ����ֵ
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

		//��������½ڵ�ӱ��в�����
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
		printf("����Ϊ��\n");
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
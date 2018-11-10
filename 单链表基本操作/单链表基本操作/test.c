#include"seqlist.h"
#include<windows.h>

/*typedef int DataType;
typedef struct Node
{
	struct Node* _pNext;
	DataType data;
}Node,*PNode;
*/

//PushBack/PopBack
void Test1()
{
	PNode pHead;
	SListInit(&pHead);
	SListPrint(pHead);
	SListPushBack(&pHead, 1);
	SListPrint(pHead);

	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPrint(pHead);

	SListPopBack(&pHead);
	SListPrint(pHead);
	SListPopBack(&pHead);
	SListPopBack(&pHead);
	SListPopBack(&pHead);
	SListPopBack(&pHead);
	SListPrint(pHead);

}

//PushFront/PopFrot
void Test2()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushFront(&pHead, 1);
	SListPrint(pHead);

	SListPushFront(&pHead, 2);
	SListPushFront(&pHead, 3);
	SListPushFront(&pHead, 4);
	SListPushFront(&pHead, 5);
	SListPrint(pHead);

	SListPopFront(&pHead);
	SListPrint(pHead);
	SListPopFront(&pHead);
	SListPopFront(&pHead);
	SListPopFront(&pHead);
	SListPopFront(&pHead);
	SListPrint(pHead);

}

//SListInsert/SListErase
void Test3()
{
	PNode pHead;
	PNode pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPrint(pHead);

	pos = SListFind(pHead, 3);
	SListInsert(&pHead, pos, 6);
	SListPrint(pHead);

	SListErase(&pHead, pos);
	SListPrint(pHead);
}

//SListClear/SListDestroy/SListSize/SListBack
void Test4()
{
	PNode pHead;
	PNode pBack;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPrint(pHead);
	
	//SListClear(&pHead);
	//SListPrint(pHead);
	//SListDestory(&pHead);

	int size = SListSize(pHead);
	printf("�����нڵ�����ǣ�%d\n", size);

	pBack = SListBack(pHead);
	printf("���������һ���ڵ��ǣ�%d\n", pBack->data);
}

//PrintFromTail
void Test5()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintListFromTail(pHead);
}

//DeleteNotTailNode
void Test6()
{
	PNode pHead,pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPrint(pHead);
	pos = SListFind(pHead, 4);
	DeleteNotTailNode(pos);
	SListPrint(pHead);
}

//InsetPosFront
void Test7()
{
	PNode pHead, pos;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPrint(pHead);
	pos = SListFind(pHead, 4);
	if (pos)
		InsertPosFront(pos, 9);
	SListPrint(pHead);

}

//JosephCircle
void Test8()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	SListPrint(pHead);
	//����Լɪ��
	SListBack(pHead)->_pNext = pHead;
	JosephCircle(&pHead, 3);

	//�⻷
	pHead->_pNext = NULL;
	SListPrint(pHead);

}

//BubbleSort
void Test9()
{
	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 1);
	SListPrint(pHead);
	BubbleSort(pHead);
	SListPrint(pHead);

}

//reverse
void Test10()
{

	PNode pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPrint(pHead);
	ReverseSlist(&pHead);
	SListPrint(pHead);
	pHead= ReverseSlistOP(pHead);
	SListPrint(pHead);

}

//Merge
void Test11()
{
	PNode pHead1;
	PNode pHead2;
	PNode pHead;
	SListInit(&pHead1);
	SListInit(&pHead2);
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);
	SListPushBack(&pHead1, 9);
	SListPrint(pHead1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 8);
	SListPushBack(&pHead2, 10);
	SListPrint(pHead2);

    pHead =	MergeSlist(pHead1, pHead2);
	SListPrint(pHead);
}

//FindMiddleNode/FindLastKNode/DeleteLastKNode
void Test12()
{
	PNode pHead;
	PNode pCur;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	SListPrint(pHead);
	pCur = FindMiddleNode(pHead);
	printf("�м�ڵ��ǣ�%d\n", pCur->data);
	pCur = FindLastKNode(pHead, 2);
	printf("������2���ڵ��ǣ�%d\n", pCur->data);
	DeleteLastKNode(pHead, 2);
	SListPrint(pHead);


}

//IsCrossWithoutCircle/GetCrossNode
void Test13()
{
	PNode pHead1, pHead2, pCross;
	SListInit(&pHead1);
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	SListInit(&pHead2);
	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 7);
	SListPushBack(&pHead2, 8);
	SListPushBack(&pHead2, 9);
	SListPushBack(&pHead2, 0);

	SListBack(pHead1)->_pNext = SListFind(pHead2, 7);
	if (IsCrossWithoutCircle(pHead1, pHead2))
	{
		printf("���������ཻ\n");
		pCross = GetCrossNode(pHead1, pHead2);
		printf("������%d\n", pCross->data);
	}
	else
		printf("���������ཻ\n");

	SListPrint(pHead1);
	SListPrint(pHead2);

}

//CopyComPlexList
void Test14()
{
	ComPlexListNode node1, node2, node3, node4;
	pComPlexListNode pHead;
	node1.data = 1;
	node1._pNext = &node2;
	node1._pRandom = &node3;
	node2.data = 2;
	node2._pNext = &node3;
	node2._pRandom = &node1;
	node3.data = 3;
	node3._pNext = &node4;
	node3._pRandom = &node3;
	node4.data = 4;
	node4._pNext = NULL;
	node4._pRandom = NULL;

	pHead = CopyCoplexList(&node1);
	SListPrintComplex(pHead);

}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	////////////////////////////////////////////////
   ////////////////������//////////////////////////
   ///////////////////////////////////////////////

	//Test5();//��β��ͷ��ӡ
	//Test6();//ɾ����β�ڵ�
	//Test7();//��ǰ�����
	//Test8();//Լɪ��
	//Test9();//ð������
	//Test10();//����
	//Test11();//�ϲ�������������
	//Test12();//�����м�ڵ� �ҵ�����k���ڵ� ɾ��������k���ڵ�
	//Test13();//�ཻ����
	Test14();//���Ƹ�������
	system("pause");
	return 0;
}
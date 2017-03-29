#include <stdio.h>  //기본 linkedlist
#include <stdlib.h>
#include <string.h>

typedef struct LinkedListNodeType {
	int data;
	struct LinkedListNodeType *pLink;
} LinkedListNode;

typedef struct LinkedListType {
	int             currentCount;
	LinkedListNode  headerNode;
} LinkedList;

LinkedList *createLinkedList() {
	LinkedList *pReturn = (LinkedList *)malloc(sizeof(LinkedList));
	memset(pReturn, 0, sizeof(LinkedList));
	return pReturn;
}

int getLinkedListData(LinkedList* pList, int position) {
	int i = 0;

	LinkedListNode *pCurrentNode = &(pList->headerNode);
	for (i = 0; i <= position; i++) {
		pCurrentNode = pCurrentNode->pLink;
	}

	return pCurrentNode->data;
}

int addLinkedListData(LinkedList* pList, int position, int data) {
	int i = 0;

	LinkedListNode *pNewNode = NULL;
	LinkedListNode *pPreNode = NULL;

	pNewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	pNewNode->data = data;

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; i++) {
		pPreNode = pPreNode->pLink;
	}

	pNewNode->pLink = pPreNode->pLink;
	pPreNode->pLink = pNewNode;
	pList->currentCount++;

	return 0;
}

int removeLinkedListData(LinkedList* pList, int position) {
	int i = 0;
	LinkedListNode *pDelNode = NULL;
	LinkedListNode *pPreNode = NULL;

	pPreNode = &(pList->headerNode);
	for (i = 0; i < position; i++) {
		pPreNode = pPreNode->pLink;
	}

	pDelNode = pPreNode->pLink;
	pPreNode->pLink = pDelNode->pLink;
	free(pDelNode);
	pList->currentCount--;
	return 0;
}

void deleteLinkedList(LinkedList* pList) {
	LinkedListNode *pDelNode = NULL;
	LinkedListNode *pPreNode = pList->headerNode.pLink;
	while (pPreNode != NULL) {
		pDelNode = pPreNode;
		pPreNode = pPreNode->pLink;

		free(pDelNode);
	}

	free(pList);
}

int getLinkedListLength(LinkedList* pList) {
	if (NULL != pList) {
		return pList->currentCount;
	}
	return 0;
}



int main() {

	LinkedList *pList = NULL;

	int n;
	int m;

	int i = 0;
	int j = 0;
	int count = 0;

	pList = createLinkedList();

	scanf_s("%d %d", &n, &m );

	if (1 > n || 5000 < n) {  //범위 제한 1<=m ,n<=5000
		exit(1);
	}
	if (1 > m || 5000 < m) {
		exit(1);
	}
	for (i = 0; i <n; i++) {

		addLinkedListData(pList,i,i+1);

	}




	printf("<");

	for (count = 0; count < n; count++) {

		for (i = 0; i < m - 1; i++) {
			addLinkedListData(pList, getLinkedListLength(pList), getLinkedListData(pList, i));
		}


		for (j = 0; j < m - 1; j++) {
			removeLinkedListData(pList, 0);  // 0 번째가 지워지면 다시 0번으로 초기화
		}


		printf("%d", getLinkedListData(pList, 0));

		removeLinkedListData(pList, 0);
		
	}

	deleteLinkedList(pList);
	
	printf(">");




	return 0;
}
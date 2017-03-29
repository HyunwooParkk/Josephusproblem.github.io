#include <stdio.h>  //±âº» linkedlist
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


int getListLength(LinkedList *pList) {
	return pList->currentCount;
}

#include<stdio.h>



int main() {

	LinkedList *pList = NULL;

	int n;
	int m;

	int i = 0;
	int j = 0;
	int count = 0;

	pList = createLinkedList();

	scanf_s("%d %d", &n, &m );

	for (i = 0; i < n; i++) {

		addLinkedListData(pList,i,i+1);

	}

	printf("<");

	for (count = 0; count <= n; count++) {

		for (i = 1; i < m; i++) {
			addLinkedListData(pList, getLinkedListLength(pList) , getLinkedListData(pList,i));
		}


		for (j = 1; j < m ; j++) {
			removeLinkedListData(pList, j);
		}


		printf("%d", getLinkedListData(pList, 1));
		removeLinkedListData(pList, 1);

		
	}

	deleteLinkedList(pList);
	
	printf(">");




	return 0;
}
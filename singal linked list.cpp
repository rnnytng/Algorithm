#include<stdio.h>
#include<stdlib.h>
typedef struct num {
	int data;
	char name [20];
	struct num* next; 
}num,*nnum;
void initlist(nnum &head) {
	head = (num*)malloc(sizeof(num));
	if (head == NULL) {
		printf("����");
	}
	head->next = NULL;
}
//β�巨
void rearinsertlist(nnum& head) {
	int x = 0; 
	num* p =NULL;
	num* s = head;//s βָ��
	while(1){
		scanf_s("%d", &x);
		if (x < 0) {
			break;
		}
		p = (num*)malloc(sizeof(num));
		p->data = x;
		scanf_s("%s", &p->name, 20);
		s->next = p;
		s = p;
	}
}
//ͷ�巨
void frontinsertlist(nnum& head) {
	int x = 0;
	num* s = head;
	while (1) {
		scanf_s("%d", &x);
		if (x < 0) {
			break;
		}
		s = (num*)malloc(sizeof(num));
		s->data = x;
		scanf_s("%s", &s->name, 20);
		s->next = head->next;
		head->next = s;
	}
}
//��λɾ������
bool deletelist(nnum& head, int i) {
	if (i < 1) {
		return false;
	}
	num* p;
	p = head;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL) {
		return false;
	}
	num* q = p->next;
	p->next = q->next;
	free(q);
}
//��λ�������
bool addlist(nnum& head, int i) {
	if (i < 1) {
		return false;
	}
	num* p;
	p = head;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	int x=0;
	printf("������������:");
	scanf_s("%d", &x);
	num* q = (num*)malloc(sizeof(num));
	q->data = x;
	scanf_s("%s", &q->name, 20);
	q->next = p->next;
	p->next = q;
}
void printlist(nnum&head) {
	num* p = head->next;
	while (p != NULL) {
		printf("%d  %s\n", p->data,p->name); 
		p = p->next;
	}
}


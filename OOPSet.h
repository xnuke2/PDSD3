#pragma once
#include <iostream>
#include <string>
using std::string;

struct Node {
	int value;
	Node* next;
};

class SetClass {
	Node* firstNode;

	//�������� ������� ���������
	SetClass();
	
	//�������� ������ �� ���������?
	bool setisEmpty();

	//�������� �� ������� �������� � ���������
	bool setContains(int numToFind);

	//���������� �������� � ������ ���������
	void setAddFirst(int num);

	//�������� ���������� ���������
	SetClass(int length, int min, int max, string type);

	//�������� ���������
	int powerOfSet();

	//����� ��������� ���������	
	string printSet(char separator);

	//�������� ���������
	~SetClass();

	//������������ A-B
	bool subSet(SetClass a);

	//��������� ���� ��������
	bool equalitySet(SetClass a);

	//����������� ���� ��������
	Node* CombiningSets(Node* a);

	//����������� ���� ��������
	Node* intersectionOfSets(Node* a);

	//�������� ���� �������� a-b
	Node* subtraction(Node* a);

	//������������ �������� ���� ��������
	Node* simmetricSubtraction(Node* a);
};
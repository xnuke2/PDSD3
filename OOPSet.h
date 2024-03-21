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

	//создание пустого множества
	SetClass();
	
	//проверка пустое ли множество?
	bool setisEmpty();

	//проверка на наличие элемента в множестве
	bool setContains(int numToFind);

	//добавление элемента в начало множества
	void setAddFirst(int num);

	//создание случайного множества
	SetClass(int length, int min, int max, string type);

	//мощность множества
	int powerOfSet();

	//вывод элементов множества	
	string printSet(char separator);

	//удаление множества
	~SetClass();

	//подмножество A-B
	bool subSet(SetClass a);

	//равенство двух множеств
	bool equalitySet(SetClass a);

	//объединение двух множеств
	Node* CombiningSets(Node* a);

	//пересечение двух множеств
	Node* intersectionOfSets(Node* a);

	//разность двух множеств a-b
	Node* subtraction(Node* a);

	//симметричная разность двух множеств
	Node* simmetricSubtraction(Node* a);
};
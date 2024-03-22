#pragma once
#include <iostream>
#include <string>
using std::string;



class SetClass {

private: struct Node {
		int value;
		Node* next;
	};
	Node* firstNode;
public:
	//создание пустого множества
	SetClass();
	
	//проверка пустое ли множество?
	bool setisEmpty();

	//проверка на наличие элемента в множестве
	bool setContains(int numToFind);

	//добавление элемента в начало множества
	void setAddFirst(int num);

	//создание случайного множества
	static SetClass* createRandomSet(int length, int min, int max, string type);

	//мощность множества
	int powerOfSet();

	//вывод элементов множества	
	string printSet(char separator);

	//удаление множества
	~SetClass();

	//подмножество A-B
	bool subSet(SetClass* a);

	//равенство двух множеств
	bool equalitySet(SetClass* a);

	//объединение двух множеств
	SetClass* CombiningSets(SetClass* a);

	//пересечение двух множеств
	SetClass* intersectionOfSets(SetClass* a);

	//разность двух множеств a-b
	SetClass* subtraction(SetClass* a);

	//симметричная разность двух множеств
	SetClass* simmetricSubtraction(SetClass* a);
};
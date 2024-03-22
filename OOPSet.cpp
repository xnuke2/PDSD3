#include "OOPSet.h"

//создание пустого множества
SetClass::SetClass() {
    firstNode = nullptr;
}

//проверка пустое ли множество?
bool SetClass::setisEmpty()
{
    return (firstNode == nullptr);
}

//проверка на наличие элемента в множестве
bool SetClass::setContains(int numToFind)
{
    if (setisEmpty()) {
        return false;
    }
    Node* tmp = firstNode;
    while (tmp != nullptr)
    {
        if (tmp->value == numToFind) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

//добавление элемента в начало множества
void SetClass::setAddFirst(int num)
{
    if (setContains(num)) {
        return;
    }
    Node* newStart = new Node;
    newStart->value = num;
    newStart->next = firstNode;
    firstNode = newStart;
}

SetClass* SetClass::createRandomSet(int length, int min, int max, string type)
{
    SetClass* rezult = new SetClass();
    if (length <= 0 || max - min < length) {
        return nullptr;
    }
    if (type == "b") {
        for (int i = 0; i < length; i++) {
            int newNum = rand() % (max - min + 1) + min;
            while (rezult->setContains(newNum) || newNum % 10 <= 3) {
                newNum = rand() % (max - min + 1) + min;
            }
            rezult->setAddFirst(newNum);
        }
    }
    if (type == "a") {
        for (int i = 0; i < length; i++) {
            int newNum = rand() % (max - min + 1) + min;
            while (rezult->setContains(newNum) || newNum % 10 >= 8) {
                newNum = rand() % (max - min + 1) + min;
            }
            rezult->setAddFirst(newNum);
        }
    }
    return rezult;
}

int SetClass::powerOfSet()
{
    Node* tmp = firstNode;
    int length = 0;
    while (tmp != nullptr)
    {
        length++;
        tmp = tmp->next;
    }
    return length;
}

string SetClass::printSet(char separator)
{
    string rezult = "";
    if (setisEmpty()) {
        return rezult;
    }
    Node* tmp = firstNode;
    while (tmp != nullptr) {
        rezult = rezult + std::to_string(tmp->value);
        if (tmp->next != nullptr) {
            rezult = rezult + separator;
        }
        tmp = tmp->next;
    }
    return rezult;
}

SetClass::~SetClass()
{
    if (setisEmpty()) {
        return;
    }
    Node* tmp = firstNode;
    Node* tmpLast;
    while (tmp) {
        tmpLast = tmp;
        tmp = tmp->next;
        delete tmpLast;
    }
    firstNode = nullptr;
}

bool SetClass::subSet(SetClass* a)
{
    if (setisEmpty()) return true;
    if (a->setisEmpty()) return false;
    int sizea = powerOfSet();
    if (sizea > a->powerOfSet()) return false;
    int check = 0;
    Node* tmpa = firstNode;
    while (tmpa != nullptr) {
        if (!a->setContains(tmpa->value))return false;
        tmpa = tmpa->next;
    }
    return true;
}

bool SetClass::equalitySet(SetClass* a)
{
    return (subSet(a) && a->subSet(this));
}

SetClass* SetClass::CombiningSets(SetClass* a)
{
    if (this->setisEmpty() || a->setisEmpty()) return nullptr;
    Node* tmp = this->firstNode;
    SetClass* rezult = new SetClass();
    while (tmp != nullptr)
    {
        rezult->setAddFirst(tmp->value);
        tmp = tmp->next;
    }
    tmp = a->firstNode;
    while (tmp != nullptr)
    {
        rezult->setAddFirst(tmp->value);
        tmp = tmp->next;
    }
    return rezult;
}

SetClass* SetClass::intersectionOfSets(SetClass* a)
{
    if (this->setisEmpty() || a->setisEmpty()) return nullptr;
    SetClass* rezult = new SetClass();
    Node* tmpa = this->firstNode;
    while (tmpa != nullptr)
    {
        if (a->setContains( tmpa->value)) rezult->setAddFirst( tmpa->value);
        tmpa = tmpa->next;
    }
    return rezult;
}

SetClass* SetClass::subtraction(SetClass* a)
{
    if (this->setisEmpty() || a->setisEmpty()) return nullptr;
    SetClass* rezult = new SetClass();
    Node* tmpa = this->firstNode;
    while (tmpa != nullptr)
    {
        if (!a->setContains(tmpa->value)) rezult->setAddFirst(tmpa->value);
        tmpa = tmpa->next;
    }
    return rezult;
}

SetClass* SetClass::simmetricSubtraction(SetClass* a)
{
    return this->CombiningSets(a)->subtraction(this->intersectionOfSets(a));
}

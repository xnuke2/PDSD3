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

SetClass::SetClass(int length, int min, int max, string type)
{
    firstNode = nullptr;
    if (length <= 0 || max - min < length) {
        return;
    }
    if (type == "b") {
        for (int i = 0; i < length; i++) {
            int newNum = rand() % (max - min + 1) + min;
            while (setContains(newNum) || newNum % 10 <= 3) {
                newNum = rand() % (max - min + 1) + min;
            }
            setAddFirst(newNum);
        }
    }
    if (type == "a") {
        for (int i = 0; i < length; i++) {
            int newNum = rand() % (max - min + 1) + min;
            while (setContains(newNum) || newNum % 10 >= 8) {
                newNum = rand() % (max - min + 1) + min;
            }
            setAddFirst(newNum);
        }
    }
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

bool SetClass::subSet(SetClass a)
{
    if (setisEmpty()) return true;
    if (a.setisEmpty()) return false;
    int sizea = powerOfSet();
    if (sizea > a.powerOfSet()) return false;
    int check = 0;
    Node* tmpa = firstNode;
    while (tmpa != NULL) {
        if (!a.setContains(tmpa->value))return false;
        tmpa = tmpa->next;
    }
    return true;
}

bool SetClass::equalitySet(SetClass a)
{
    return (subSet(a) && a.subSet(this));
}

Node* SetClass::CombiningSets(Node* a)
{
    return nullptr;
}

Node* SetClass::intersectionOfSets(Node* a)
{
    return nullptr;
}

Node* SetClass::subtraction(Node* a)
{
    return nullptr;
}

Node* SetClass::simmetricSubtraction(Node* a)
{
    return nullptr;
}

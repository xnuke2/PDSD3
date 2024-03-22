
#include <iostream>
#include "OOPSet.h"

using std::cout;
using std::endl;
using std::to_string;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");

    cout << "Хмыренков 19 вариант" << endl;
    SetClass* A = SetClass::createRandomSet(rand() % (9 - 6 + 1) + 6, 10, 25, "a");
    SetClass* B = SetClass::createRandomSet(rand() % (9 - 6 + 1) + 6, 10, 26, "b");
    cout << "Множества A и B созданы" << endl;
    cout << "Вывод множества A: " + A->printSet(',') << endl;
    cout << "Мощность множество A: " + std::to_string(A->powerOfSet()) << std::endl;
    cout << "Вывод множества B: " + B->printSet(',') << endl;
    cout << "Мощность множество B: " + std::to_string(B->powerOfSet()) << std::endl;
    cout << "Множество A является подмножеством B: " + to_string(A->subSet( B)) << endl;
    cout << "Множество A является подмножеством A: " + to_string(A->subSet( A)) << endl;
    cout << "Множество A равно подмножеству B: " + to_string(A->equalitySet( B)) << endl;
    cout << "Множество A равно подмножеству A: " + to_string(A->equalitySet( A)) << endl;
    SetClass* C = A->CombiningSets(B);
    cout << "Объединение двух множеств: " + C->printSet( ',') << endl;
    cout << "Мощность объединения множеств: " + std::to_string(C->powerOfSet()) << std::endl;
    SetClass* D = A->intersectionOfSets(B);
    cout << "Пересечение двух множеств: " + D->printSet( ',') << endl;
    cout << "Мощность пересечения множеств: " + std::to_string(D->powerOfSet()) << std::endl;
    SetClass* E = A->subtraction( B);
    SetClass* F = B->subtraction( A);
    cout << "Разность A-B: " + E->printSet( ',') << endl;
    cout << "Мощность разности A-B: " + std::to_string(E->powerOfSet()) << std::endl;
    cout << "Разность B-A: " + F->printSet( ',') << endl;
    cout << "Мощность разности B-A: " + std::to_string(F->powerOfSet()) << std::endl;
    SetClass* G = A->simmetricSubtraction( B);
    cout << "Симметричная разность множеств: " + G->printSet( ',') << endl;
    cout << "Мощность cимметричная разности: " + std::to_string(G->powerOfSet()) << std::endl;

}

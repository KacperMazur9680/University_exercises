#include <iostream>
#include "Set.h"

int main()
{
    Set<int> A;

    A.add(1);
    A.add(2);
    A.add(3);
    A.add(2);

    cout << "A = ";
    A.displaySet();

    cout << "Czy zbior A zawiera wartosc 3? " << (A.contains(3) ? "zawiera" : "nie zawiera") << endl << endl;

    Set<int> B;

    B.add(1);
    B.add(2);
    B.add(4);

    cout << "B = ";
    B.displaySet();

    cout << "Czy zbior B zawiera wartosc 3? " << (B.contains(3) ? "zawiera" : "nie zawiera") << endl << endl;

    Set<int> F = A - B;
    cout << "A - B = ";
    F.displaySet();
    cout << endl;

    Set<int> D = A.unionSet(B);
    cout << "Laczenie zbiorow A i B = ";
    D.displaySet();
    cout << endl;

    Set<int> E = A.intersectionSet(B);
    cout << "Czesc wspolna zbiorow A i B = ";
    E.displaySet();
    cout << endl;

    cout << "Rownosc zbiorow A i B:  ";
    cout << "A " << ((A == B) ? "" : "!") << "= B" << endl;
}



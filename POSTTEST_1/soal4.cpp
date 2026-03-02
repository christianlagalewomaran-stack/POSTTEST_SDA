#include <iostream>
using namespace std;

void tukar(int* a, int* b){
int smntr = *a;
*a = *b;
*b = smntr;
}

int main(){
    int nilaiA;
    int nilaiB;
    cout << "masukkan nilai A: ";
    cin >> nilaiA;
    cout << "masukkan nilai B: ";
    cin >> nilaiB;
    cout << "nilai sebelum ditukar" << endl;
    cout << "nilai A: " << nilaiA << "\n" << "nilai B: " << nilaiB << endl;

    cout << endl;
    cout << "nilai sesudah ditukar" << endl;
    tukar(&nilaiA, &nilaiB);
    cout << "nilai A: " << nilaiA << "\n" << "nilai B: " << nilaiB << endl;

    return 0;
}
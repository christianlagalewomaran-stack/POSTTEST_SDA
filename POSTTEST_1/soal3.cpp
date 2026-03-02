#include <iostream>
using namespace std;

void balik(int* arr, int n){
    int* awal = arr;
    int* akhir = arr+n-1;
    while (awal < akhir){
        int smntr = *awal;
        *awal = *akhir;
        *akhir = smntr;
        awal++;
        akhir--;
    }

}

int main(){
int prima[7] = {2, 3, 5, 7, 11, 13, 17};
cout << "bilangan prima sebelum dibalik adalah sebagai berikut: " << endl;
for (int i = 0; i<7; i++){
    cout << "nilai: "<< prima[i] << ", alamat: " << &prima[i] << endl;

}
cout << endl;
balik(prima, 7);
cout << "bilangan prima sesudah dibalik adalah sebagai berikut" << endl;
for (int i =0; i<7; i++){
    cout << "nilai: "<< prima[i] << ", alamat: " << &prima[i] << endl;
}

}
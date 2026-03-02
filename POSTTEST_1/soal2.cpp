#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string NIM;
    float ipk;
};

int main(){
    mahasiswa mhs[5];
    for (int i = 0; i<5; i++){
    cout << "mahasiswa ke-" << i+1 << endl;
    cout << "Input nama mahasiswa: ";
    getline (cin, mhs[i].nama);
    cout << "input NIM mahasiswa: ";
    getline (cin, mhs[i].NIM);
    cout << "input ipk mahasiswa: ";
    cin >> mhs[i].ipk;
    cin.ignore();
    }

    float tertinggi = mhs[0].ipk;
    for (int i = 0; i<5; i++){
        if (mhs[i].ipk > tertinggi){
            tertinggi = mhs[i].ipk;
        }
    }

    for (int i = 0; i < 5; i++){
        if (mhs[i].ipk == tertinggi){
            cout << "Nama: " << mhs[i].nama << endl;
            cout << "NIM: " << mhs[i].NIM << endl;
            cout << "IPK: " << mhs[i].ipk << endl;
        }
    }
    return 0;
}
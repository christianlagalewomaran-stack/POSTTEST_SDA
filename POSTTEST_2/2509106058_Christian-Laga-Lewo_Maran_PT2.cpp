#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Kereta {
    int noKereta;
    string nama;
    string asal;
    string tujuan;
    float harga;
};

void swapKereta(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "\nJadwal Kereta\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->noKereta << " | "
            << (arr + i)->nama << " | "
            << (arr + i)->asal << " -> "
            << (arr + i)->tujuan << " | Rp"
            << (arr + i)->harga << endl;
    }
}

void tambah(Kereta *&arr, int &n) {
    Kereta *baru = new Kereta[n + 1];

    for (int i = 0; i < n; i++) {
        *(baru + i) = *(arr + i);
    }

    cout << "\nInput Data Kereta Baru\n";
    cout << "No Kereta: ";
    cin >> (baru + n)->noKereta;
    cin.ignore();

    cout << "Nama: ";
    getline(cin, (baru + n)->nama);

    cout << "Asal: ";
    getline(cin, (baru + n)->asal);

    cout << "Tujuan: ";
    getline(cin, (baru + n)->tujuan);

    cout << "Harga: ";
    cin >> (baru + n)->harga;

    delete[] arr;
    arr = baru;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool found = false;

    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Data tidak ditemukan\n";
    }
}

int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    cout << "\nProses Jump Search:\n";

    while ((arr + min(step, n) - 1)->noKereta < key) {
        cout << "Loncat ke index " << step << endl;
        prev = step;
        step += sqrt(n);

        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step, n); i++) {
        cout << "Cek index " << i << endl;
        if ((arr + i)->noKereta == key) {
            return i;
        }
    }

    return -1;
}

void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Kereta L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);

    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama <= R[j].nama) {
            *(arr + k) = L[i];
            i++;
        } else {
            *(arr + k) = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = L[i];
        i++; k++;
    }

    while (j < n2) {
        *(arr + k) = R[j];
        j++; k++;
    }
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }

        swapKereta(arr + i, arr + minIdx);
    }
}

int main() {
    int n = 3;

    Kereta *arr = new Kereta[n]{
        {1,"Argo","Jakarta","Surabaya",300000},
        {2,"Taksaka","Jakarta","Jogja",250000},
        {3,"Matarmaja","Malang","Jakarta",200000}
    };

    int pilih;

    do {
        cout << "\n MENU \n";
        cout << "1. Tampil Jadwal\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Rute (Linear)\n";
        cout << "4. Cari No Kereta (Jump)\n";
        cout << "5. Sort Nama (Merge)\n";
        cout << "6. Sort Harga (Selection)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            tampil(arr, n);
        }
        else if (pilih == 2) {
            tambah(arr, n);
        }
        else if (pilih == 3) {
            string asal, tujuan;
            cin.ignore();
            cout << "Asal: "; getline(cin, asal);
            cout << "Tujuan: "; getline(cin, tujuan);
            linearSearch(arr, n, asal, tujuan);
        }
        else if (pilih == 4) {
            int key;
            cout << "No Kereta: ";
            cin >> key;
            int hasil = jumpSearch(arr, n, key);

            if (hasil != -1)
                cout << "Ditemukan: " << (arr + hasil)->nama << endl;
            else
                cout << "Tidak ditemukan\n";
        }
        else if (pilih == 5) {
            mergeSort(arr, 0, n - 1);
            cout << "Berhasil diurutkan berdasarkan nama\n";
        }
        else if (pilih == 6) {
            selectionSort(arr, n);
            cout << "Berhasil diurutkan berdasarkan harga\n";
        }

    } while (pilih != 0);

    delete[] arr;
    return 0;
}
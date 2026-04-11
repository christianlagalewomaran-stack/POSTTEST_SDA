#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MAX 10

struct Kereta {
    int noKereta;
    string nama;
    string asal;
    string tujuan;
    float harga;
};

struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
};

struct Queue {
    Tiket data[MAX];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

bool isFullQ(Queue q) {
    return q.rear == MAX - 1;
}

bool isEmptyQ(Queue q) {
    return q.front == -1;
}

void tampilRute(Kereta *arr, int n) {
    cout << "\nDaftar Rute:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". "
            << (arr+i)->asal << " -> "
            << (arr+i)->tujuan << " ("
            << (arr+i)->nama << ")\n";
    }
}

void enqueue(Queue &q, Kereta *arr, int n) {
    if (isFullQ(q)) {
        cout << "Antrian penuh!\n";
        return;
    }

    int pilihRute;
    string nama;

    cin.ignore();
    cout << "Nama Penumpang: ";
    getline(cin, nama);

    tampilRute(arr, n);
    cout << "Pilih rute (nomor): ";
    cin >> pilihRute;

    if (pilihRute < 1 || pilihRute > n) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    if (q.front == -1) q.front = 0;
    q.rear++;

    q.data[q.rear].namaPenumpang = nama;
    q.data[q.rear].asal = (arr + pilihRute - 1)->asal;
    q.data[q.rear].tujuan = (arr + pilihRute - 1)->tujuan;

    cout << "Berhasil masuk antrian!\n";
}

void dequeue(Queue &q, Tiket &hasil) {
    if (isEmptyQ(q)) {
        cout << "Antrian kosong!\n";
        return;
    }

    hasil = q.data[q.front];

    for (int i = 0; i < q.rear; i++) {
        *(q.data + i) = *(q.data + i + 1);
    }

    q.rear--;

    if (q.rear < 0) q.front = -1;
}

void tampilQueue(Queue q) {
    if (isEmptyQ(q)) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\nAntrian:\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << (q.data+i)->namaPenumpang << " | "
            << (q.data+i)->asal << " -> "
            << (q.data+i)->tujuan << endl;
    }
}

void peekQueue(Queue q) {
    if (!isEmptyQ(q))
        cout << "Depan: " << q.data[q.front].namaPenumpang << endl;
}

struct Stack {
    Tiket data[MAX];
    int top;
};

void initStack(Stack &s) {
    s.top = -1;
}

bool isFullS(Stack s) {
    return s.top == MAX - 1;
}

bool isEmptyS(Stack s) {
    return s.top == -1;
}

void push(Stack &s, Tiket x) {
    if (isFullS(s)) {
        cout << "Riwayat penuh!\n";
        return;
    }

    s.top++;
    s.data[s.top] = x;
}

void pop(Stack &s) {
    if (isEmptyS(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }

    cout << "Hapus: " << s.data[s.top].namaPenumpang << endl;
    s.top--;
}

void peekStack(Stack s) {
    if (!isEmptyS(s))
        cout << "Terakhir: " << s.data[s.top].namaPenumpang << endl;
}

void tampilStack(Stack s) {
    if (isEmptyS(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\nRiwayat:\n";
    for (int i = 0; i <= s.top; i++) {
        cout << (s.data+i)->namaPenumpang << " | "
            << (s.data+i)->asal << " -> "
            << (s.data+i)->tujuan << endl;
    }
}

void swapKereta(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    cout << "\nJadwal Kereta\n";
    for (int i = 0; i < n; i++) {
        cout << (arr+i)->noKereta << " | "
            << (arr+i)->nama << " | "
            << (arr+i)->asal << " -> "
            << (arr+i)->tujuan << " | Rp"
            << (arr+i)->harga << endl;
    }
}

void tambah(Kereta *&arr, int &n) {
    Kereta *baru = new Kereta[n + 1];

    for (int i = 0; i < n; i++) {
        *(baru+i) = *(arr+i);
    }

    cout << "\nInput Data Kereta Baru\n";
    cout << "No: "; cin >> (baru+n)->noKereta;
    cin.ignore();
    cout << "Nama: "; getline(cin, (baru+n)->nama);
    cout << "Asal: "; getline(cin, (baru+n)->asal);
    cout << "Tujuan: "; getline(cin, (baru+n)->tujuan);
    cout << "Harga: "; cin >> (baru+n)->harga;

    delete[] arr;
    arr = baru;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((arr+i)->asal == asal && (arr+i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr+i)->nama << endl;
            found = true;
        }
    }
    if (!found) cout << "Tidak ditemukan\n";
}

int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    cout << "\nProses Jump Search:\n";

    while ((arr + min(step,n) - 1)->noKereta < key) {
        cout << "Loncat ke " << step << endl;
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step,n); i++) {
        cout << "Cek index " << i << endl;
        if ((arr+i)->noKereta == key)
            return i;
    }

    return -1;
}

void merge(Kereta *arr, int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;

    Kereta L[50], R[50];

    for (int i = 0; i < n1; i++) L[i] = *(arr+l+i);
    for (int j = 0; j < n2; j++) R[j] = *(arr+m+1+j);

    int i=0,j=0,k=l;

    while (i<n1 && j<n2) {
        if (L[i].nama <= R[j].nama) *(arr+k)=L[i], i++;
        else *(arr+k)=R[j], j++;
        k++;
    }

    while (i<n1) *(arr+k)=L[i], i++, k++;
    while (j<n2) *(arr+k)=R[j], j++, k++;
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l<r) {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min=i;
        for (int j = i+1; j < n; j++) {
            if ((arr+j)->harga < (arr+min)->harga)
                min=j;
        }
        swapKereta(arr+i, arr+min);
    }
}

int main() {
    int n = 5;

    Kereta *arr = new Kereta[n]{
        {1,"Argo","jakarta","surabaya",300000},
        {2,"Taksaka","jakarta","jogja",250000},
        {3,"Matarmaja","malang","jakarta",200000},
        {4,"Gajayana","malang","jogja",350000},
        {5,"Lodaya","bandung","solo",220000}
    };

    Queue q;
    Stack s;
    initQueue(q);
    initStack(s);

    int pilih;

    do {
        cout << "\nMENU\n";
        cout << "1. Tampil Jadwal\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari No Kereta\n";
        cout << "5. Sort Nama\n";
        cout << "6. Sort Harga\n";
        cout << "7. Tambah Antrian\n";
        cout << "8. Proses Antrian\n";
        cout << "9. Tampil Antrian\n";
        cout << "10. Tampil Riwayat\n";
        cout << "11. Peek\n";
        cout << "12. Hapus Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tampil(arr,n);
        else if (pilih == 2) tambah(arr,n);
        else if (pilih == 3) {
            string a,t;
            cin.ignore();
            cout << "Asal: "; getline(cin,a);
            cout << "Tujuan: "; getline(cin,t);
            linearSearch(arr,n,a,t);
        }
        else if (pilih == 4) {
            int key;
            cout << "No: "; cin >> key;
            int h = jumpSearch(arr,n,key);
            if (h!=-1) cout << "Ditemukan: " << (arr+h)->nama << endl;
            else cout << "Tidak ditemukan\n";
        }
        else if (pilih == 5) {
            mergeSort(arr,0,n-1);
            cout << "Urut nama\n";
        }
        else if (pilih == 6) {
            selectionSort(arr,n);
            cout << "Urut harga\n";
        }
        else if (pilih == 7) enqueue(q,arr,n);
        else if (pilih == 8) {
            Tiket t;
            dequeue(q,t);
            cout << "Diproses: " << t.namaPenumpang << endl;
            push(s,t);
        }
        else if (pilih == 9) tampilQueue(q);
        else if (pilih == 10) tampilStack(s);
        else if (pilih == 11) {
            peekQueue(q);
            peekStack(s);
        }
        else if (pilih == 12) pop(s);

    } while (pilih != 0);

    delete[] arr;
}
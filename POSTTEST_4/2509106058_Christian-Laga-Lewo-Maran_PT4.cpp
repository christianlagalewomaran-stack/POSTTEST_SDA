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

struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
};

struct Node {
    Tiket data;
    Node* next;
};

struct Queue {
    Node *front, *rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = nullptr;
}

bool isEmptyQ(Queue q) {
    return q.front == nullptr;
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
    Node* baru = new Node;

    cin.ignore();
    cout << "Nama Penumpang: ";
    getline(cin, baru->data.namaPenumpang);

    tampilRute(arr, n);
    int pilih;
    cout << "Pilih rute: ";
    cin >> pilih;

    if (pilih < 1 || pilih > n) {
        cout << "Pilihan tidak valid!\n";
        delete baru;
        return;
    }

    baru->data.asal = (arr+pilih-1)->asal;
    baru->data.tujuan = (arr+pilih-1)->tujuan;
    baru->next = nullptr;

    if (isEmptyQ(q)) {
        q.front = q.rear = baru;
    } else {
        q.rear->next = baru;
        q.rear = baru;
    }

    cout << "Berhasil masuk antrian!\n";
}

void dequeue(Queue &q, Tiket &hasil) {
    if (isEmptyQ(q)) {
        cout << "Antrian kosong!\n";
        return;
    }

    Node* hapus = q.front;
    hasil = hapus->data;

    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;

    delete hapus;
}

void tampilQueue(Queue q) {
    if (isEmptyQ(q)) {
        cout << "Antrian kosong\n";
        return;
    }

    Node* bantu = q.front;
    cout << "\nAntrian:\n";
    while (bantu != nullptr) {
        cout << bantu->data.namaPenumpang << " | "
            << bantu->data.asal << " -> "
            << bantu->data.tujuan << endl;
        bantu = bantu->next;
    }
}

void peekQueue(Queue q) {
    if (isEmptyQ(q)) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Depan: " << q.front->data.namaPenumpang << endl;
}

struct Stack {
    Node* top;
};

void initStack(Stack &s) {
    s.top = nullptr;
}

bool isEmptyS(Stack s) {
    return s.top == nullptr;
}

void push(Stack &s, Tiket x) {
    Node* baru = new Node;
    baru->data = x;
    baru->next = s.top;
    s.top = baru;
}

void pop(Stack &s) {
    if (isEmptyS(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }

    Node* hapus = s.top;
    cout << "Hapus: " << hapus->data.namaPenumpang << endl;

    s.top = s.top->next;
    delete hapus;
}

void peekStack(Stack s) {
    if (isEmptyS(s)) {
        cout << "Riwayat kosong!\n";
        return;
    }
    cout << "Terakhir: " << s.top->data.namaPenumpang << endl;
}

void tampilStack(Stack s) {
    if (isEmptyS(s)) {
        cout << "Riwayat kosong\n";
        return;
    }

    Node* bantu = s.top;
    cout << "\nRiwayat:\n";
    while (bantu != nullptr) {
        cout << bantu->data.namaPenumpang << " | "
            << bantu->data.asal << " -> "
            << bantu->data.tujuan << endl;
        bantu = bantu->next;
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

    for (int i = 0; i < n; i++) *(baru+i) = *(arr+i);

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

    while ((arr + min(step,n) - 1)->noKereta < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < min(step,n); i++) {
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
            if(t.namaPenumpang != "")
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
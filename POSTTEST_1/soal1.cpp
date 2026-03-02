#include <iostream>
using namespace std;

void findmin(int fib[], int n){
    int minimum = fib[0];
    for(int i = 1; i < n; i++){
        if(fib[i] < minimum){
            minimum = fib[i];
        }
    }
    cout << "elemen minimum pada array adalah: " << minimum << endl;
    for(int i = 0; i < n; i++){
        if(fib[i] == minimum){
            cout << "berada di indeks ke-" << i << endl;
        }
    }
    cout << endl;
}

int main(){
    int fibonacci[8] = {1,1,2,3,5,8,13,21};
    int n = 8;
    findmin(fibonacci, n);
    return 0;
}

/*
TABEL ANALISIS:
-------------------------------------------------------
| Pseudocode           | Cost | Tmin      | Tmax      |
-------------------------------------------------------
| procedure FindMin    | C1   | 1         | 1         |
| min ← A[0]           | C2   | 1         | 1         |
| for i ← 1 to n - 1   | C3   | n         | n         |
| if A[i] < min        | C4   | n-1       | n-1       |
| min ← A[i]           | C5   | 0         | n-1       |
| end if               | C6   | n-1       | n-1       |
| end for              | C7   | n         | n         |
| return min           | C8   | 1         | 1         |
| end procedure        | C9   | 1         | 1         |
-------------------------------------------------------
| Total waktu (Tn)     |      | O(n)      | O(n)      |
-------------------------------------------------------

Penjelasan tentang best case dan worst case dari pseudocode:

1. Kondisi ketika Base Case (Tmin):
- Terjadi saat A[0] sudah berupa nilai minimum
- Kondisi if A[i] < min selalu FALSE
- Operasi min ← A[i] (C5) tidak pernah dieksekusi atau terjadi 0 kali

Rumus untuk kondisi Tmin(n):
Tmin(n) = C1 + C2 + n*C3 + (n-1)*C4 + 0*C5 + (n-1)*C6 + n*C7 + C8 + C9
Tmin(n) = n(C3 + C4 + C6 + C7) + (C1 + C2 - C4 - C6 + C7 + C8 + C9)
Tmin(n) = an + b  (persamaan linear)

Kompleksitas Best Casenya adalah: O(n)

2. Kondisi ketika worst case (Tmax):
- Terjadi saat array terurut menurun (descending)
- Kondisi if A[i] < min selalu TRUE
- Operasi min ← A[i] (C5) dieksekusi sebanyak n-1 kali

Rumus untuk kondisi Tmax(n):
Tmax(n) = C1 + C2 + n*C3 + (n-1)*C4 + (n-1)*C5 + (n-1)*C6 + n*C7 + C8 + C9
Tmax(n) = n(C3 + C4 + C5 + C6 + C7) + (C1 + C2 - C4 - C5 - C6 + C7 + C8 + C9)
Tmax(n) = cn + d  (persamaan linear)

Kompleksitas Worst Casenya adalah: O(n)

Jadi Algoritma FindMin memiliki kompleksitas waktu O(n) untuk best case dan worst case

*\
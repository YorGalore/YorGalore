#include <iostream>
using namespace std;

/*
 * Soal 1 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika untuk menangani perintah "DATANG" dan "LAYANI".
 * - Gunakan struktur data yang sesuai untuk menyimpan antrian pasien.
 * - Implementasi tidak boleh menggunakan standard library (STL) seperti vector, queue, atau
 *   lainnya.
 * */

int main() {
  int n;
  cin >> n;

  while (n--) {
    string action;
    cin >> action;

    if (action == "DATANG") {
      char type;
      string name;
      cin >> type >> name;
      // TODO: Implementasikan logika untuk menangani pasien yang datang
    } else if (action == "LAYANI") {
      // TODO: Implementasikan logika untuk melayani pasien
    } else {
      cout << "Perintah tidak valid!\n";
      n++;
    }
  }
}

/*
 * Input:
 * 6
 * DATANG N Alice
 * DATANG E Bob
 * DATANG N David
 * LAYANI
 * DATANG E Charlie
 * LAYANI
 * */


#include <iostream>
using namespace std;

const int MAX = 100; // maksimal pasien (disesuaikan)
string queueE[MAX], queueN[MAX]; // dua antrian: emergency dan normal
int frontE = 0, rearE = 0;
int frontN = 0, rearN = 0;

void enqueue(char type, string name) {
  if (type == 'E') {
    if (rearE < MAX) {
      queueE[rearE++] = name;
    }
  } else if (type == 'N') {
    if (rearN < MAX) {
      queueN[rearN++] = name;
    }
  }
}

void dequeue() {
  if (frontE < rearE) {
    cout << queueE[frontE++] << endl;
  } else if (frontN < rearN) {
    cout << queueN[frontN++] << endl;
  } else {
    cout << "Tidak ada pasien\n";
  }
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    string action;
    cin >> action;

    if (action == "DATANG") {
      char type;
      string name;
      cin >> type >> name;
      enqueue(type, name);
    } else if (action == "LAYANI") {
      dequeue();
    } else {
      cout << "Perintah tidak valid!\n";
      n++; // ulangi perintah
    }
  }

  return 0;
}

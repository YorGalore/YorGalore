#include <iostream>
#include <vector>
using namespace std;

/*
 * Soal 5 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika untuk memproses kode yang diberikan.
 * - Gunakan struktur data yang sesuai untuk menyelesaikan masalah ini.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Mengeluarkan validitas kode yang diberikan dengan memastikan jumlah kurung buka dan tutup sama.
 *   (50 poin)
 * - Mengeluarkan hasil pencarian substring. (50 poin)
 * */

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<string> code(n);
  for (int i = 0; i < n; i++) getline(cin, code[i]);

  // TODO: Implementasikan logika untuk mengecek validitas kode
  // TODO: Implementasikan logika untuk mencari substring
}

/*
 * Input 1:
 * 6
 * (defun calculate-gst (price)
 *   (let ((gst-rate 0.1))
 *     (if (> price 0)
 *         (* price gst-rate)
 *         0)))
 * (calculate-gst 100)
 * gst-rate
 *
 * Input 2:
 * 3
 * (defun faktorial (n)
 *   (if (<= n 1) 1
 *       (* n (faktorial (- n 1)))
 * fact
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<string> code(n);
  for (int i = 0; i < n; i++) getline(cin, code[i]);

  string keyword;
  getline(cin, keyword); // membaca substring yang akan dicari

  // Validasi jumlah kurung
  int openParen = 0, closeParen = 0;
  for (const string& line : code) {
    for (char c : line) {
      if (c == '(') openParen++;
      else if (c == ')') closeParen++;
    }
  }

  if (openParen == closeParen)
    cout << "VALID" << endl;
  else
    cout << "TIDAK VALID" << endl;

  // Pencarian substring
  bool found = false;
  for (const string& line : code) {
    if (line.find(keyword) != string::npos) {
      cout << "Ditemukan: " << line << endl;
      found = true;
      break; // hanya cari baris pertama yang cocok
    }
  }

  if (!found) {
    cout << "Tidak ditemukan" << endl;
  }

  return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Soal 10 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika untuk menangani perintah "WRITE", "UNDO", "REDO", "PRINT", dan "FIND".
 * - Gunakan struktur data yang sesuai untuk menyimpan teks yang ditulis dan riwayat perubahan.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Berhasil mengimplementasikan "UNDO" dan "REDO" dengan benar. (50 poin)
 * - Mengeluarkan teks yang benar saat perintah "PRINT" dipanggil. (10 poin)
 * - Mengeluarkan hasil yang benar saat perintah "FIND" dipanggil. (40 poin)
 * */

int main() {
  int n;
  cin >> n;

  while (n--) {
    string action;
    cin >> action;

    // TODO: Implementasikan logika untuk menangani perintah "WRITE", "UNDO", "REDO", "PRINT", dan
    // "FIND".
    if (action == "WRITE") {
      string text;
      cin.ignore();
      getline(cin, text);

    } else if (action == "UNDO") {

    } else if (action == "REDO") {

    } else if (action == "PRINT") {

    } else if (action == "FIND") {

    } else {
      cout << "Perintah tidak valid!\n";
      n++;
    }
  }
}

/*
 * Input:
 * 8
 * WRITE This is a DNA sequence:
 * WRITE ATGCGTACGATGCATGC
 * FIND ATGCATG
 * UNDO
 * FIND ATGCATG
 * PRINT
 * REDO
 * PRINT
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> history; // semua perintah WRITE
  int current = 0;        // jumlah teks aktif saat ini

  while (n--) {
    string action;
    cin >> action;

    if (action == "WRITE") {
      string text;
      cin.ignore();
      getline(cin, text);

      // buang redo history jika kita sedang di tengah
      if (current < history.size()) {
        history.resize(current);
      }

      history.push_back(text);
      current++;

    } else if (action == "UNDO") {
      if (current > 0) current--;

    } else if (action == "REDO") {
      if (current < history.size()) current++;

    } else if (action == "PRINT") {
      for (int i = 0; i < current; ++i) {
        cout << history[i] << endl;
      }

    } else if (action == "FIND") {
      string pattern;
      cin >> pattern;
      string combined;
      for (int i = 0; i < current; ++i) {
        combined += history[i];
        if (i != current - 1) combined += '\n';
      }

      // cari jumlah kemunculan pattern dalam combined
      int count = 0;
      size_t pos = combined.find(pattern);
      while (pos != string::npos) {
        count++;
        pos = combined.find(pattern, pos + 1);
      }

      cout << count << endl;

    } else {
      cout << "Perintah tidak valid!\n";
      n++;
    }
  }

  return 0;
}

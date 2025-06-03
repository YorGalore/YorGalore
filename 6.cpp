#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*
 * Soal 6 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika untuk menambahkan dan menghapus kata dari struktur data yang sesuai.
 * - Gunakan struktur data yang sesuai untuk menyelesaikan masalah ini.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Implementasi logika penambahan dan penghapusan kata. (50 poin)
 * - Keluaran hasil deteksi email, apakah SPAM atau bukan. (50 poin)
 * */

int main() {
  int n;
  cin >> n;

  while (n--) {
    string action, word;
    cin >> action >> word;

    // TODO: Implementasikan logika untuk menambahkan atau menghapus kata
    if (action == "TAMBAH") {

    } else if (action == "HAPUS") {

    } else {
      cout << "Perintah tidak dikenal!\n";
      n++;
    }
  }

  // TODO: Implementasikan logika untuk mendeteksi apakah kata tersebut SPAM atau bukan
}

/*
 * Input:
 * 5
 * TAMBAH diskon
 * TAMBAH penipuan
 * HAPUS diskon
 * TAMBAH gratis
 * TAMBAH terbatas
 * 2
 * Jangan lewatkan penawaran terbatas ini!
 * Berikut kami lampirkan detail dokumen:
 */


#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<string> spamWords;

  while (n--) {
    string action, word;
    cin >> action >> word;

    if (action == "TAMBAH") {
      spamWords.push_back(word);
    } else if (action == "HAPUS") {
      for (auto it = spamWords.begin(); it != spamWords.end(); ++it) {
        if (*it == word) {
          spamWords.erase(it);
          break;
        }
      }
    } else {
      cout << "Perintah tidak dikenal!\n";
      n++; // kompensasi agar jumlah input tetap
    }
  }

  int m;
  cin >> m;
  cin.ignore(); // untuk mengabaikan newline setelah angka m

  while (m--) {
    string sentence;
    getline(cin, sentence);

    bool isSpam = false;
    for (const string& word : spamWords) {
      if (sentence.find(word) != string::npos) {
        isSpam = true;
        break;
      }
    }

    cout << (isSpam ? "SPAM" : "AMAN") << endl;
  }
}


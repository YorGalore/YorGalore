#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
 * Soal 9 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika untuk mengecek tingkat sensitivitas sebuah unggahan.
 * - Gunakan struktur data yang sesuai untuk menyimpan kata-kata yang perlu diperiksa.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Mengeluarkan tingkat sensitivitas unggahan berdasarkan kata-kata yang ada. (90 poin)
 * - Mengeluarkan kalimat setelah kata-kata sensitif disensor. (Opsional, 10 poin)
 * */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
using namespace std;

int getPriority(const string& str) {
  if (str == "TINGGI") return 3;
  else if (str == "MEDIUM") return 2;
  else if (str == "RENDAH") return 1;
  else {
    cout << "Invalid priority string: " << str << "\n";
    throw invalid_argument("Invalid priority string");
  }
}

string getPriorityString(int priority) {
  switch (priority) {
    case 3: return "TINGGI";
    case 2: return "MEDIUM";
    case 1: return "RENDAH";
    default: return "TIDAK SENSITIF";
  }
}

// Fungsi untuk ubah semua huruf menjadi lowercase
string toLower(const string& str) {
  string res = str;
  transform(res.begin(), res.end(), res.begin(), ::tolower);
  return res;
}

// Fungsi untuk hapus tanda baca di akhir kata
string stripPunctuation(const string& word) {
  if (!word.empty() && ispunct(word.back())) {
    return word.substr(0, word.size() - 1);
  }
  return word;
}

int main() {
  int n;
  cin >> n;

  vector<pair<string, int>> sensitiveWords(n);
  for (int i = 0; i < n; i++) {
    string word, level;
    cin >> word >> level;
    sensitiveWords[i] = {toLower(word), getPriority(level)};
  }

  int m;
  cin >> m;
  cin.ignore(); // Untuk konsumsi newline setelah angka

  for (int i = 0; i < m; i++) {
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    int maxPriority = 0;

    // Untuk versi sensor opsional
    vector<string> outputWords;

    while (iss >> word) {
      string originalWord = word;
      string cleaned = toLower(stripPunctuation(word));
      bool found = false;

      for (const auto& p : sensitiveWords) {
        if (cleaned == p.first) {
          maxPriority = max(maxPriority, p.second);
          found = true;
          break;
        }
      }

      if (found)
        outputWords.push_back("[SENSOR]");
      else
        outputWords.push_back(originalWord);
    }

    cout << "TINGKAT SENSITIVITAS: " << getPriorityString(maxPriority) << "\n";
    // Opsional 10 poin: Tampilkan kalimat setelah disensor
    for (int j = 0; j < outputWords.size(); ++j) {
      cout << outputWords[j];
      if (j < outputWords.size() - 1) cout << " ";
    }
    cout << "\n";
  }
}

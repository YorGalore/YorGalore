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
    default: return "UNKNOWN";
  }
}

int main() {
  int n;
  cin >> n;

  vector<pair<string, string>> words(n);
  for (int i = 0; i < n; i++) cin >> words[i].first >> words[i].second;

  // TODO: Implementasikan logika untuk mengecek tingkat sensitivitas unggahan
}

/*
 * Input:
 * 3
 * bomber MEDIUM
 * suicide TINGGI
 * dumb RENDAH
 * 3
 * What a wonderful world! /s
 * He is just young, dumb, and broke.
 * The suicide bomber planned a devastating attack on the city square.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int getPriority(const string& str) {
  if (str == "TINGGI") return 3;
  else if (str == "MEDIUM") return 2;
  else if (str == "RENDAH") return 1;
  else throw invalid_argument("Invalid priority string");
}

string getPriorityString(int priority) {
  switch (priority) {
    case 3: return "TINGGI";
    case 2: return "MEDIUM";
    case 1: return "RENDAH";
    default: return "UNKNOWN";
  }
}

// Helper function to lowercase a string
string toLower(string s) {
  for (char& c : s) c = tolower(c);
  return s;
}

// Replace all occurrences of a word with asterisks
string censorWord(const string& text, const string& word) {
  string censored = text;
  string lowerText = toLower(text);
  string lowerWord = toLower(word);
  size_t pos = lowerText.find(lowerWord);

  while (pos != string::npos) {
    for (size_t i = 0; i < word.length(); ++i) {
      if (pos + i < censored.length())
        censored[pos + i] = '*';
    }
    pos = lowerText.find(lowerWord, pos + 1);
  }

  return censored;
}

int main() {
  int n;
  cin >> n;

  vector<pair<string, string>> words(n); // {word, priority}
  for (int i = 0; i < n; i++) cin >> words[i].first >> words[i].second;

  int m;
  cin >> m;
  cin.ignore();

  for (int i = 0; i < m; i++) {
    string line;
    getline(cin, line);

    int maxPriority = 0;
    string censoredLine = line;

    for (const auto& [badWord, priorityStr] : words) {
      string lowerLine = toLower(line);
      string lowerWord = toLower(badWord);
      if (lowerLine.find(lowerWord) != string::npos) {
        maxPriority = max(maxPriority, getPriority(priorityStr));
        censoredLine = censorWord(censoredLine, badWord);
      }
    }

    cout << getPriorityString(maxPriority) << endl;
    cout << censoredLine << endl;
  }

  return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Soal 11 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika untuk menympan data buku di dalam AVL Tree.
 * - Implementasikan logika untuk mencari buku berdasarkan judul, penulis, atau tahun terbit.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Berhasil mengimplementasikan AVL Tree untuk menyimpan data buku. (50 poin)
 * - Berhasil mengimplementasikan pencarian buku berdasarkan judul, penulis, atau tahun terbit.
 *   (50 poin)
 */

struct Node {
  string title;
  string author;
  int year;

  Node* left;
  Node* right;
  Node(string t, string a, int y) : title(t), author(a), year(y), left(NULL), right(NULL) {}
};

int main() {
  int n;
  cin >> n;

  while (n--) {
    string title, author;
    int year;
    cin.ignore();
    getline(cin, title);
    getline(cin, author);
    cin >> year;

    // TODO: Implementasikan logika untuk menyimpan data buku di dalam AVL Tree
  }

  int m;
  cin >> m;
  while (m--) {
    string type;
    cin >> type;

    if (type == "TAHUN") {
      int year;
      cin >> year;
      // TODO: Implementasikan logika untuk mencari buku berdasarkan tahun terbit
    } else {
      string pattern;
      cin.ignore();
      getline(cin, pattern);
      // TODO: Implementasikan logika untuk mencari buku berdasarkan judul atau penulis
    }

    // TODO: Implementasikan logika untuk menampilkan hasil pencarian
  }
}

/*
 * Input:
 * 6
 * The Great Gatsby
 * F. Scott Fitzgerald
 * 1925
 * To Kill a Mockingbird
 * Harper Lee
 * 1960
 * Pride and Prejudice
 * Jane Austen
 * 1813
 * Harry Potter and the Chamber of Secrets
 * J.K. Rowling
 * 1998
 * The Catcher in the Rye
 * J.D. Salinger
 * 1951
 * Harry Potter and the Sorcerer's Stone
 * J.K. Rowling
 * 1997
 * 3
 * JUDUL Harry Potter
 * PENULIS J.
 * TAHUN 1999
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
  string title;
  string author;
  int year;
  int height;
  Node* left;
  Node* right;

  Node(string t, string a, int y)
      : title(t), author(a), year(y), height(1), left(NULL), right(NULL) {}
};

int height(Node* node) {
  return node ? node->height : 0;
}

int getBalance(Node* node) {
  return node ? height(node->left) - height(node->right) : 0;
}

void updateHeight(Node* node) {
  node->height = 1 + max(height(node->left), height(node->right));
}

Node* rotateRight(Node* y) {
  Node* x = y->left;
  Node* T2 = x->right;

  x->right = y;
  y->left = T2;

  updateHeight(y);
  updateHeight(x);

  return x;
}

Node* rotateLeft(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;

  y->left = x;
  x->right = T2;

  updateHeight(x);
  updateHeight(y);

  return y;
}

Node* insert(Node* node, string title, string author, int year) {
  if (!node)
    return new Node(title, author, year);

  if (title < node->title)
    node->left = insert(node->left, title, author, year);
  else
    node->right = insert(node->right, title, author, year);

  updateHeight(node);
  int balance = getBalance(node);

  // LL
  if (balance > 1 && title < node->left->title)
    return rotateRight(node);

  // RR
  if (balance < -1 && title > node->right->title)
    return rotateLeft(node);

  // LR
  if (balance > 1 && title > node->left->title) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }

  // RL
  if (balance < -1 && title < node->right->title) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }

  return node;
}

void searchByYear(Node* root, int year, vector<Node*>& results) {
  if (!root) return;
  if (root->year == year) results.push_back(root);
  searchByYear(root->left, year, results);
  searchByYear(root->right, year, results);
}

void searchByPattern(Node* root, const string& pattern, bool searchTitle, vector<Node*>& results) {
  if (!root) return;
  if ((searchTitle && root->title.find(pattern) != string::npos) ||
      (!searchTitle && root->author.find(pattern) != string::npos)) {
    results.push_back(root);
  }
  searchByPattern(root->left, pattern, searchTitle, results);
  searchByPattern(root->right, pattern, searchTitle, results);
}

void printResults(const vector<Node*>& results) {
  if (results.empty()) {
    cout << "BUKU TIDAK DITEMUKAN\n";
  } else {
    for (const auto& node : results) {
      cout << node->title << "\n" << node->author << "\n" << node->year << "\n";
    }
  }
}

int main() {
  int n;
  cin >> n;

  Node* root = nullptr;

  while (n--) {
    string title, author;
    int year;
    cin.ignore();
    getline(cin, title);
    getline(cin, author);
    cin >> year;

    root = insert(root, title, author, year);
  }

  int m;
  cin >> m;
  while (m--) {
    string type;
    cin >> type;

    vector<Node*> results;

    if (type == "TAHUN") {
      int year;
      cin >> year;
      searchByYear(root, year, results);
    } else {
      string pattern;
      cin.ignore();
      getline(cin, pattern);
      searchByPattern(root, pattern, type == "JUDUL", results);
    }

    printResults(results);
  }

  return 0;
}

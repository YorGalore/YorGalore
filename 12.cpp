#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

/*
 * Soal 12 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika mendapatkan biaya minimal untuk menghubungkan semua kantor
 * - Gunakan struktur data yang sesuai untuk merepresentasikan hubungan antar kantor.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Mengeluarkan biaya minimal untuk menghubungkan semua kantor. (45 poin)
 * - Mengeluarkan rute yang dilalui. (Opsional, 5 poin)
 * - Mengeluarkan biaya minimal setelah penambahan jaringan baru. (45 poin)
 * - Mengeluarkan rute yang dilalui setelah penambahan jaringan baru. (Opsional, 5 poin)
 * */

int main() {
  int n, m;
  cin >> n >> m;

  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;

    // TODO: Implementasikan logika untuk menyimpan hubungan antar kantor
  }

  // TODO: Cari biaya minimal untuk menghubungkan semua kantor

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> u >> v >> w;

    // TODO: Tambahkan ke daftar jaringan yang sudah ada.
  }

  // TODO: Cari biaya minimal untuk menghubungkan semua kantor setelah penambahan jaringan baru.
}

/*
 * Input:
 * 5 6
 * 1 2 5
 * 1 3 5
 * 1 4 5
 * 1 5 5
 * 3 4 8
 * 4 5 8
 * 2
 * 2 3 2
 * 3 5 3
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Edge {
  int u, v, w;
  bool operator<(const Edge &other) const {
    return w < other.w;
  }
};

struct DSU {
  vector<int> parent;
  DSU(int n) {
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }

  bool unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false;
    parent[py] = px;
    return true;
  }
};

int kruskal(int n, vector<Edge> &edges) {
  sort(edges.begin(), edges.end());
  DSU dsu(n);
  int totalCost = 0;
  for (const Edge &e : edges) {
    if (dsu.unite(e.u, e.v)) {
      totalCost += e.w;
    }
  }
  return totalCost;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges;
  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  int initialCost = kruskal(n, edges);
  cout << "Biaya minimal awal: " << initialCost << endl;

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  int updatedCost = kruskal(n, edges);
  cout << "Biaya minimal setelah penambahan jaringan baru: " << updatedCost << endl;
}

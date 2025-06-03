#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 * Soal 4 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika mendapatkan degree antara orang A dan B.
 * - Gunakan struktur data yang sesuai untuk merepersentasikan hubungan antar orang.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Mengeluarkan degree terpendek antara 2 orang A dan B. (90 poin)
 * - Mengeluarkan jalur terpendek yang menghubungkan kedua orang tersebut, jika ada. (Opsional, 10
 * poin)
 * */

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;

    // TODO: Implementasikan penyimpanan koneksi antar orang
  }

  // TODO: Implementasikan logika untuk mencari degree minimal antara orang A dan B
}

/*
 * Input:
 * 5 4
 * 1 2
 * 2 3
 * 2 4
 * 4 5
 * 1 5
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  // Representasi graph: adjacency list
  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected graph
  }

  int A, B;
  cin >> A >> B;

  // BFS untuk mencari degree
  vector<int> dist(n + 1, -1);      // Menyimpan jarak dari A
  vector<int> parent(n + 1, -1);    // Menyimpan parent untuk jalur terpendek (opsional)

  queue<int> q;
  q.push(A);
  dist[A] = 0;

  while (!q.empty()) {
    int curr = q.front(); q.pop();
    for (int neighbor : adj[curr]) {
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[curr] + 1;
        parent[neighbor] = curr;
        q.push(neighbor);
      }
    }
  }

  if (dist[B] == -1) {
    cout << "TIDAK TERHUBUNG\n";
  } else {
    cout << "DEGREE: " << dist[B] << "\n";

    // Opsional: menampilkan jalur terpendek dari A ke B
    vector<int> path;
    for (int v = B; v != -1; v = parent[v]) {
      path.push_back(v);
    }
    reverse(path.begin(), path.end());
    cout << "JALUR: ";
    for (int i = 0; i < path.size(); ++i) {
      cout << path[i];
      if (i != path.size() - 1) cout << " -> ";
    }
    cout << "\n";
  }
}

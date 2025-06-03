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

  vector<vector<int>> graph(n + 1); // asumsi node 1-based

  // Membangun graf dari m edge
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u); // tidak berarah
  }

  int A, B;
  cin >> A >> B;

  vector<int> dist(n + 1, -1); // -1 artinya belum dikunjungi
  vector<int> parent(n + 1, -1); // untuk pelacakan jalur
  queue<int> q;

  dist[A] = 0;
  q.push(A);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int neighbor : graph[curr]) {
      if (dist[neighbor] == -1) {
        dist[neighbor] = dist[curr] + 1;
        parent[neighbor] = curr;
        q.push(neighbor);
      }
    }
  }

  if (dist[B] == -1) {
    cout << "Tidak ada jalur dari " << A << " ke " << B << endl;
  } else {
    cout << "Degree terpendek dari " << A << " ke " << B << ": " << dist[B] << endl;

    // Optional: Menampilkan jalur terpendek
    vector<int> path;
    for (int at = B; at != -1; at = parent[at]) {
      path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "Jalur: ";
    for (int p : path) cout << p << " ";
    cout << endl;
  }

  return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 * Soal 8 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika mendapatkan rute dengan waktu tercepat.
 * - Gunakan struktur data yang sesuai untuk merepresentasikan hubungan antar kota.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Mengeluarkan waktu terbaik dari kota awal (A) ke kota tujuan (B). (45 poin)
 * - Mengeluarkan rute yang dilalui. (Opsional, 5 poin)
 * - Mengeluarkan waktu terbaik dari kota B ke A setelah insiden terjadi. (45 poin)
 * - Mengeluarkan rute yang dilalui setelah insiden. (Opsional, 5 poin)
 * */

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int u, v, t;
    cin >> u >> v >> t;

    // TODO: Implementasikan logika untuk menyimpan informasi kota dan rute
  }

  // TODO: Implementasikan logika untuk mencari rute tercepat dari kota awal ke kota tujuan

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int u, v, t;
    cin >> u >> v >> t;

    // TODO: Implementasikan logika untuk memperbarui weight rute setelah insiden
  }

  // TODO: Implementasikan logika untuk mencari rute tercepat dari kota tujuan ke kota awal setelah
  // insiden
}

/*
 * Input:
 * 5 6
 * 1 2 4
 * 1 3 2
 * 2 3 5
 * 2 4 3
 * 3 4 4
 * 4 5 1
 * 1 5
 * 3
 * 1 2 6
 * 3 1 9
 * 3 4 8
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dijkstra(int start, int end, const vector<vector<pair<int, int>>>& adj, vector<int>& path) {
  int n = adj.size();
  vector<int> dist(n, 1e9);
  vector<int> prev(n, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int cost = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (cost > dist[u]) continue;

    for (auto [v, w] : adj[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        prev[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  path.clear();
  if (dist[end] == 1e9) return -1;

  for (int at = end; at != -1; at = prev[at]) {
    path.push_back(at);
  }
  reverse(path.begin(), path.end());

  return dist[end];
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing

  for (int i = 0; i < m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    adj[u].push_back({v, t});
  }

  int A, B;
  cin >> A >> B;

  vector<int> path1;
  int waktu1 = dijkstra(A, B, adj, path1);
  cout << waktu1 << endl;
  // Optional: cetak rute
  for (int kota : path1) cout << kota << " ";
  cout << endl;

  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int u, v, t;
    // Update edge jika ditemukan
    bool updated = false;
    for (auto& p : adj[u]) {
      if (p.first == v) {
        p.second = t;
        updated = true;
        break;
      }
    }
    // Jika edge belum ada, tambahkan
    if (!updated) {
      adj[u].push_back({v, t});
    }
  }

  vector<int> path2;
  int waktu2 = dijkstra(B, A, adj, path2);
  cout << waktu2 << endl;
  for (int kota : path2) cout << kota << " ";
  cout << endl;

  return 0;
}

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 * Soal 3 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika mendapatkan rute dengan waktu tercepat.
 * - Gunakan struktur data yang sesuai untuk merepresentasikan hubungan antar kota.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Mengeluarkan waktu terbaik dari kota awal ke kota tujuan. (90 poin)
 * - Mengeluarkan rute yang dilalui. (Opsional, 10 poin)
 * */

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int p, q, s, v;
    cin >> p >> q >> s >> v;

    // TODO: Implementasikan logika untuk menyimpan informasi kota dan rute
  }

  // TODO: Implementasikan logika untuk mencari rute tercepat dari kota awal ke kota tujuan
}

/*
 * Input:
 * 5 5
 * 1 2 100 20
 * 1 3 60 30
 * 3 4 40 40
 * 2 4 80 40
 * 4 5 90 30
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

  vector<vector<pair<int, double>>> graph(m + 1); // kota dari 1 sampai m

  for (int i = 0; i < n; i++) {
    int p, q, s, v;
    cin >> p >> q >> s >> v;

    double time = (double)s / v; // waktu tempuh
    graph[p].push_back({q, time});
    graph[q].push_back({p, time}); // asumsi bidirectional
  }

  int start, end;
  cin >> start >> end;

  // Dijkstra
  vector<double> dist(m + 1, 1e9);
  vector<int> parent(m + 1, -1);
  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    auto [currTime, u] = pq.top(); pq.pop();

    if (currTime > dist[u]) continue;

    for (auto [v, t] : graph[u]) {
      if (dist[v] > dist[u] + t) {
        dist[v] = dist[u] + t;
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  if (dist[end] == 1e9) {
    cout << "Tidak ada rute dari " << start << " ke " << end << endl;
  } else {
    cout << "Waktu tercepat: " << dist[end] << endl;

    // Opsional: tampilkan rute
    vector<int> path;
    for (int at = end; at != -1; at = parent[at]) {
      path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << "Rute: ";
    for (int kota : path) cout << kota << " ";
    cout << endl;
  }

  return 0;
}

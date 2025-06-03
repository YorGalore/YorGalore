#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;


 * Soal 2 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika mendapatkan biaya minimal untuk menghubungkan semua kantor
 * - Gunakan struktur data yang sesuai untuk merepresentasikan hubungan antar kantor.
 * - Implementasi hanya boleh menggunakan STL yang didefinisikan di atas.
 *
 * KRITERIA PENILAIAN:
 * - Mengeluarkan biaya minimal untuk menghubungkan semua kantor. (90 poin)
 * - Mengeluarkan rute yang dilalui. (Opsional, 10 poin)
 * */

/*int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    // TODO: Implementasikan penyimpanan hubungan antar kantor
  }

  // TODO: Implementasikan logika untuk menghitung biaya minimal
}

/*
 * Input:
 * 4 5
 * 1 2 4
 * 1 3 2
 * 2 3 5
 * 2 4 3
 * 3 4 4
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Struktur untuk menyimpan setiap edge
struct Edge {
    int u, v, weight;
    
    // Operator untuk urutkan berdasarkan bobot
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Fungsi untuk mencari root dari sebuah elemen dalam Union-Find
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

// Fungsi untuk menggabungkan dua komponen
void unionSet(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    
    // Membaca edge
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Urutkan semua edge berdasarkan bobot
    sort(edges.begin(), edges.end());

    int parent[n + 1], rank[n + 1];
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstWeight = 0;
    vector<Edge> mstEdges;

    // Proses Kruskal's Algorithm untuk membangun MST
    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        if (find(parent, u) != find(parent, v)) {
            unionSet(parent, rank, u, v);
            mstWeight += w;
            mstEdges.push_back(edge);
        }
    }

    // Output hasil biaya minimal
    cout << "Biaya minimal: " << mstWeight << endl;

    // Opsional: Tampilkan rute yang dilalui (edges dalam MST)
    cout << "Rute yang dilalui: ";
    for (const Edge& edge : mstEdges) {
        cout << "(" << edge.u << " - " << edge.v << ") ";
    }
    cout << endl;

    return 0;
}*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Struktur data untuk menyimpan informasi edge
struct Edge {
    int u, v, w;
};

// Fungsi perbandingan untuk sorting edge berdasarkan biaya (w)
bool compareEdge(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

// Fungsi find dengan path compression
int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Fungsi union untuk menggabungkan dua set
void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = find(parent, u);
    v = find(parent, v);
    if (u == v) return;
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // Urutkan edge berdasarkan biaya
    sort(edges.begin(), edges.end(), compareEdge);

    // Inisialisasi union-find
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int mst_cost = 0;
    vector<Edge> mst_edges; // menyimpan edge yang masuk ke MST (opsional)

    // Proses algoritma Kruskal
    for (const auto &e : edges) {
        if (find(parent, e.u) != find(parent, e.v)) {
            unionSets(parent, rank, e.u, e.v);
            mst_cost += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "Biaya minimal untuk menghubungkan semua kantor: " << mst_cost << endl;
    
    // Output jalur yang dilalui (opsional)
    cout << "Rute yang dilalui:" << endl;
    for (const auto &e : mst_edges) {
        cout << e.u << " - " << e.v << " dengan biaya " << e.w << endl;
    }

    return 0;
}

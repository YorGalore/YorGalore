#include <iostream>
using namespace std;

/*
 * Soal 7 Responsi
 * Nama: [Nama Anda]
 * NIM: [NIM Anda]
 *
 * CATATAN:
 * - Implementasikan logika untuk menangani perintah "DATANG" dan "LAYANI".
 * - Gunakan struktur data yang sesuai untuk menyimpan antrian pasien.
 * - Implementasi tidak boleh menggunakan standard library (STL) seperti vector, queue, atau
 *   lainnya.
 * */

int main() {
  int n;
  cin >> n;

  while (n--) {
    string action;
    cin >> action;

    if (action == "DATANG") {
      char type;
      string name;
      cin >> type >> name;
      // TODO: Implementasikan logika untuk menangani pasien yang datang
    } else if (action == "LAYANI") {
      // TODO: Implementasikan logika untuk melayani pasien
    } else {
      cout << "Perintah tidak valid!\n";
      n++;
    }
  }
}

/*
 * Input:
 * 8
 * DATANG Alice 1200
 * DATANG Bob -1
 * DATANG Charlie 1130
 * LAYANI
 * DATANG David -1
 * LAYANI
 * LAYANI
 * LAYANI
 */


#include <iostream>
using namespace std;

struct Node {
  string name;
  int time;  // -1 untuk emergency
  Node* next;
};

Node* emergencyHead = nullptr;
Node* regularHead = nullptr;

void insertEmergency(string name) {
  Node* newNode = new Node{name, -1, nullptr};
  if (!emergencyHead) {
    emergencyHead = newNode;
  } else {
    Node* temp = emergencyHead;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
  }
}

void insertRegular(string name, int time) {
  Node* newNode = new Node{name, time, nullptr};
  if (!regularHead || time < regularHead->time) {
    newNode->next = regularHead;
    regularHead = newNode;
  } else {
    Node* temp = regularHead;
    while (temp->next && temp->next->time <= time) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void layani() {
  if (emergencyHead) {
    cout << emergencyHead->name << endl;
    Node* temp = emergencyHead;
    emergencyHead = emergencyHead->next;
    delete temp;
  } else if (regularHead) {
    cout << regularHead->name << endl;
    Node* temp = regularHead;
    regularHead = regularHead->next;
    delete temp;
  } else {
    cout << "Tidak ada pasien\n";
  }
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    string action;
    cin >> action;

    if (action == "DATANG") {
      string name;
      int time;
      cin >> name >> time;
      if (time == -1)
        insertEmergency(name);
      else
        insertRegular(name, time);
    } else if (action == "LAYANI") {
      layani();
    } else {
      cout << "Perintah tidak valid!\n";
      n++;
    }
  }

  return 0;
}

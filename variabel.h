#ifndef VARIABEL_H
#define VARIABEL_H

#include <string>
#include <vector>

using namespace std;

struct DataAset {
    string idAset;
    string namaAset;
    string kategori;
    int stok;
    int stokAwal; // Untuk menyimpan stok awal
};

struct DataPeminjaman {
    string idPinjam;
    string nim;
    string nama;
    string idAset;
    int jumlah;
    int durasi;
    string tglPinjam;
    string tglKembali;
};

// Deklarasi variabel global
extern vector<DataAset> aset;
extern vector<DataPeminjaman> pinjam;

// Deklarasi fungsi & prosedur
void TampilkanMenu();
void lihatAset();
void pinjamAset();
void kembaliAset();
void cekPeminjaman();
void cekSisaStokAset();
void sortAsetByNama();
void sortAsetByStok();
int cariAsetByID(string idAset);
int cariPeminjamanByID(string idPinjam);
string hitungTglKembali(const string& tglPinjam, int durasi);
void tambahStokAset(int idx, int jumlah);
void kurangStokAset(int idx, int jumlah);
void hapusPeminjaman(int idx);
bool validasiNIM(string nim);
string tanggalHariIni();
string generateIDPinjam();

#endif
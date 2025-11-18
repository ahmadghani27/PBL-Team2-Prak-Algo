#ifndef VARIABEL_H
#define VARIABEL_H

#include <string>
#include <vector>

struct DataAset {
    std::string idAset;
    std::string namaAset;
    std::string kategori;
    int stok;
    int stokAwal; // Untuk menyimpan stok awal
};

struct DataPeminjaman {
    std::string idPinjam;
    std::string nim;
    std::string nama;
    std::string idAset;
    int jumlah;
    int durasi;
    std::string tglPinjam;
    std::string tglKembali;
};

// Deklarasi variabel global
extern std::vector<DataAset> aset;
extern std::vector<DataPeminjaman> pinjam;

// Deklarasi fungsi & prosedur
void TampilkanMenu();
void lihatAset();
void pinjamAset();
void kembaliAset();
void cekPeminjaman();
void cekSisaStokAset();
void sortAsetByNama();
void sortAsetByStok();
int cariAsetByID(std::string idAset);
int cariPeminjamanByID(std::string idPinjam);
std::string hitungTglKembali(std::string tglPinjam, int durasi);
void tambahStokAset(int idx, int jumlah);
void kurangStokAset(int idx, int jumlah);
void hapusPeminjaman(int idx);
bool validasiNIM(std::string nim);
std::string tanggalHariIni();
std::string generateIDPinjam();

#endif
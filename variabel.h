#ifndef VARIABEL_H
#define VARIABEL_H

// File variabel.h berisi deklarasi variabel global

#include <string>
#include <vector>
#include <ctime>

struct DataAset {
    std::string idAset;
    std::string namaAset;
    std::string kategori;
    int stok;
};

struct DataPeminjaman {
    std::string idPinjam;
    std::string nim;
    std::string nama;
    std::string idAset;
    int jumlah;
    int durasi;
    std::time_t tglPinjam;
    std::time_t tglKembali;
};

// Deklarasi variabel global
extern std::vector<DataAset> aset;
extern std::vector<DataPeminjaman> pinjam;

// Deklarasi fungsi
void TampilkanMenu();
void lihatAset();
void pinjamAset();
void kembaliAset();
void cekPeminjaman();
void cekSisaStokAset();
int cariAsetByID(std::string idAset);
int cariPeminjamanByID(std::string idPinjam);
std::time_t hitungTglKembali(std::time_t tglPinjam, int durasi);
void tambahStokAset(int idx, int jumlah);
void kurangStokAset(int idx, int jumlah);
void hapusPeminjaman(int idx);
void sortAsetByNama();
void sortAsetByStok();
bool validasiNIM(std::string nim);
std::string generateIDPinjam();
std::time_t tanggalHariIni();

#endif
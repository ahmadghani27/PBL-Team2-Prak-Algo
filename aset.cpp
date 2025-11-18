#include "variabel.h" // megnambil variabel dari variabel.h
#include <iostream>
#include <algorithm>
#include <iomanip>

// Definisi variabel global
std::vector<DataAset> aset = {
    {"A001", "Arduino Uno", "Mikrokontroler", 15},
    {"A002", "Sensor Suhu", "Sensor", 8},
    {"A003", "ESP32", "Mikrokontroler", 10},
    {"A004", "LCD 16x2", "Display", 5}
};

std::vector<DataPeminjaman> pinjam;

void lihatAset() {
    if (aset.size() > 0) {
        std::cout << "\n===== DAFTAR ASET LABORATORIUM =====\n";
        std::cout << std::left << std::setw(8) << "ID" 
                  << std::setw(20) << "Nama Aset" 
                  << std::setw(15) << "Kategori" 
                  << std::setw(8) << "Stok" << std::endl;
        std::cout << "----------------------------------------\n";
        
        for (const auto& a : aset) {
            std::cout << std::setw(8) << a.idAset 
                      << std::setw(20) << a.namaAset 
                      << std::setw(15) << a.kategori 
                      << std::setw(8) << a.stok << std::endl;
        }

        int submenu;
        do {
            std::cout << "\n=== OPSI TAMPILAN ===\n";
            std::cout << "1. Urutkan berdasarkan Nama (A-Z)\n";
            std::cout << "2. Urutkan berdasarkan Stok (Terbanyak)\n";
            std::cout << "3. Kembali ke Menu Utama\n";
            std::cout << "Pilihan: ";
            std::cin >> submenu;

            if (submenu == 1) {
                sortAsetByNama();
                break;
            } else if (submenu == 2) {
                sortAsetByStok();
                break;
            } else if (submenu == 3) {
                return;
            } else {
                std::cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (true);
    } else {
        std::cout << "Data aset kosong\n";
    }
}

void sortAsetByNama() {
    std::sort(aset.begin(), aset.end(), [](const DataAset& a, const DataAset& b) {
        return a.namaAset < b.namaAset;
    });
    std::cout << "Data aset berhasil diurutkan berdasarkan nama!\n";
    lihatAset();
}

void sortAsetByStok() {
    std::sort(aset.begin(), aset.end(), [](const DataAset& a, const DataAset& b) {
        return a.stok > b.stok;
    });
    std::cout << "Data aset berhasil diurutkan berdasarkan stok!\n";
    lihatAset();
}

int cariAsetByID(std::string idAset) {
    for (size_t i = 0; i < aset.size(); i++) {
        if (aset[i].idAset == idAset) {
            return i;
        }
    }
    return -1;
}

void tambahStokAset(int idx, int jumlah) {
    aset[idx].stok += jumlah;
}

void kurangStokAset(int idx, int jumlah) {
    if (jumlah <= aset[idx].stok) {
        aset[idx].stok -= jumlah;
    } else {
        std::cout << "Kesalahan: Stok aset tidak cukup.\n";
    }
}
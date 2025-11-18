#include "variabel.h" 
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ctime>

void pinjamAset() {
    std::string idAset, nim, nama;
    int jumlah, durasi;
    int asetIdx;

    while (true) {
        std::cout << "Masukkan ID Aset (ketik 'BATAL' untuk kembali): ";
        std::cin >> idAset;

        if (idAset == "BATAL") return;

        asetIdx = cariAsetByID(idAset);
        if (asetIdx != -1) {
            break;
        } else {
            std::cout << "Aset tidak ditemukan. Coba lagi.\n";
        }
    }

    while (true) {
        std::cout << "Masukkan NIM (ketik 'BATAL' untuk kembali): ";
        std::cin >> nim;
        if (nim == "BATAL") return;

        if (validasiNIM(nim)) {
            break;
        } else {
            std::cout << "NIM tidak valid\n";
        }
    }

    std::cout << "Masukkan Nama: ";
    std::cin.ignore();
    std::getline(std::cin, nama);

    while (true) {
        std::cout << "Masukkan jumlah (ketik 'BATAL' untuk kembali): ";
        std::cin >> jumlah;
        if (jumlah == 0) {
            std::string batal;
            std::cin >> batal;
            if (batal == "BATAL") return;
        }

        if (jumlah <= 0 || jumlah > aset[asetIdx].stok) {
            std::cout << "Jumlah tidak valid atau stok tidak cukup\n";
        } else {
            break;
        }
    }

    std::cout << "Masukkan durasi (hari): ";
    std::cin >> durasi;

    std::time_t tglPinjam = tanggalHariIni();
    std::time_t tglKembali = hitungTglKembali(tglPinjam, durasi);
    std::string idPinjam = generateIDPinjam();

    kurangStokAset(asetIdx, jumlah);

    DataPeminjaman dataBaru;
    dataBaru.idPinjam = idPinjam;
    dataBaru.nim = nim;
    dataBaru.nama = nama;
    dataBaru.idAset = idAset;
    dataBaru.jumlah = jumlah;
    dataBaru.durasi = durasi;
    dataBaru.tglPinjam = tglPinjam;
    dataBaru.tglKembali = tglKembali;

    pinjam.push_back(dataBaru);

    std::cout << "\nPEMINJAMAN BERHASIL!\n";
    std::cout << "ID Peminjaman: " << idPinjam << std::endl;
    std::cout << "Peminjam: " << nama << " (" << nim << ")\n";
    std::cout << "Aset: " << aset[asetIdx].namaAset << " (" << idAset << ") x" << jumlah << std::endl;
    std::cout << "Durasi: " << durasi << " Hari\n";
    std::cout << "Stok tersisa: " << aset[asetIdx].stok << " unit\n";
}

void kembaliAset() {
    std::string idPinjam, kondisi;
    int peminjamanIdx;

    while (true) {
        std::cout << "Masukkan ID pinjam (ketik 'BATAL' untuk kembali): ";
        std::cin >> idPinjam;

        if (idPinjam == "BATAL") return;

        peminjamanIdx = cariPeminjamanByID(idPinjam);
        if (peminjamanIdx != -1) {
            break;
        } else {
            std::cout << "Data tidak ditemukan\n";
        }
    }

    while (true) {
        std::cout << "Masukkan kondisi (Baik/Rusak/Hilang) (ketik 'BATAL' untuk kembali): ";
        std::cin >> kondisi;

        if (kondisi == "BATAL") return;

        if (kondisi == "Baik") {
            std::string idAset = pinjam[peminjamanIdx].idAset;
            int jumlah = pinjam[peminjamanIdx].jumlah;
            int asetIdx = cariAsetByID(idAset);

            tambahStokAset(asetIdx, jumlah);

            std::cout << "\nPENGEMBALIAN BERHASIL!\n";
            std::cout << "Aset: " << aset[asetIdx].namaAset << " (" << idAset << ") x" << jumlah << std::endl;
            std::cout << "Kondisi: Baik\n";
            std::cout << "Stok updated: " << aset[asetIdx].stok << " unit\n";

            hapusPeminjaman(peminjamanIdx);
            return;
        } else if (kondisi == "Rusak" || kondisi == "Hilang") {
            std::cout << "Barang tidak bisa dikembalikan, harap ganti dengan barang yang sesuai dengan kondisi semula\n";
            return;
        } else {
            std::cout << "Kondisi tidak sesuai\n";
        }
    }
}

void cekPeminjaman() {
    std::string idPinjam;
    int peminjamanIdx;

    while (true) {
        std::cout << "Masukkan ID Peminjaman (ketik 'BATAL' untuk kembali): ";
        std::cin >> idPinjam;

        if (idPinjam == "BATAL") return;

        peminjamanIdx = cariPeminjamanByID(idPinjam);
        if (peminjamanIdx != -1) {
            break;
        } else {
            std::cout << "Data tidak ditemukan, coba lagi\n";
        }
    }

    int asetIdx = cariAsetByID(pinjam[peminjamanIdx].idAset);

    std::cout << "\nSTATUS PEMINJAMAN:\n";
    std::cout << "ID: " << pinjam[peminjamanIdx].idPinjam << " | Status: Active\n";
    std::cout << "Peminjam: " << pinjam[peminjamanIdx].nama << " (" << pinjam[peminjamanIdx].nim << ")\n";
    std::cout << "Aset: " << aset[asetIdx].namaAset << " (" << pinjam[peminjamanIdx].idAset << ") x" << pinjam[peminjamanIdx].jumlah << std::endl;
    std::cout << "Durasi: " << pinjam[peminjamanIdx].durasi << " Hari\n";
    
    // Format tanggal
    std::tm* tglPinjam = std::localtime(&pinjam[peminjamanIdx].tglPinjam);
    std::tm* tglKembali = std::localtime(&pinjam[peminjamanIdx].tglKembali);
    
    std::cout << "Tgl Pinjam: " << std::put_time(tglPinjam, "%d/%m/%Y") << std::endl;
    std::cout << "Batas Kembali: " << std::put_time(tglKembali, "%d/%m/%Y") << std::endl;
}

void cekSisaStokAset() {
    std::string idAset;
    int asetIdx;

    while (true) {
        std::cout << "Masukkan ID Aset (ketik 'BATAL' untuk kembali): ";
        std::cin >> idAset;

        if (idAset == "BATAL") return;

        asetIdx = cariAsetByID(idAset);
        if (asetIdx != -1) {
            break;
        } else {
            std::cout << "Aset tidak ditemukan, coba lagi\n";
        }
    }

    int stokDipinjam = 0;
    for (const auto& p : pinjam) {
        if (p.idAset == idAset) {
            stokDipinjam += p.jumlah;
        }
    }

    int totalStok = aset[asetIdx].stok + stokDipinjam;

    std::cout << "\n===== MONITORING STOK =====\n";
    std::cout << "ID Aset       : " << aset[asetIdx].idAset << std::endl;
    std::cout << "Nama Aset     : " << aset[asetIdx].namaAset << std::endl;
    std::cout << "Total Aset    : " << totalStok << std::endl;
    std::cout << "Tersedia      : " << aset[asetIdx].stok << std::endl;
    std::cout << "Dipinjam      : " << stokDipinjam << std::endl;

    if (aset[asetIdx].stok == 0) {
        std::cout << "PERINGATAN: Stok aset habis!\n";
    }
}

int cariPeminjamanByID(std::string idPinjam) {
    for (size_t i = 0; i < pinjam.size(); i++) {
        if (pinjam[i].idPinjam == idPinjam) {
            return i;
        }
    }
    return -1;
}

void hapusPeminjaman(int idx) {
    if (pinjam.empty()) {
        std::cout << "Tidak ada data peminjaman.\n";
        return;
    }

    if (idx < 0 || idx >= (int)pinjam.size()) {
        std::cout << "Data peminjaman tidak ditemukan.\n";
        return;
    }

    pinjam.erase(pinjam.begin() + idx);
    std::cout << "Data peminjaman berhasil dihapus.\n";
}

std::time_t hitungTglKembali(std::time_t tglPinjam, int durasi) {
    return tglPinjam + (durasi * 24 * 60 * 60); // durasi dalam detik
}

bool validasiNIM(std::string nim) {
    for (char c : nim) {
        if (!isdigit(c)) return false;
    }
    return true;
}

std::string generateIDPinjam() {
    static int counter = 1;
    return "PJM" + std::to_string(counter++);
}

std::time_t tanggalHariIni() {
    return std::time(nullptr);
}
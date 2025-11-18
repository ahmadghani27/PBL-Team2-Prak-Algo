<<<<<<< HEAD
#include <iostream>
#include <vector>
=======
#include "variabel.h" 
#include <iostream>
>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ctime>
<<<<<<< HEAD
#include "variabel.h"
#include <chrono>

using namespace std;

int cariPeminjamanByID(string idPinjam) {
    int left = 0;
    int right = pinjam.size() - 1;
    while (left <= right) {}
    {
        int mid = left + (right - left) / 2;
        const std::string& midId = pinjam[mid].idPinjam;
        if(midId == idPinjam) {
            return mid;
        }
        else if(midId < idPinjam) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Tidak ditemukan
}

string hitungTglKembali(const std::string& tglPinjam, int durasi) {
    using namespace std::chrono;

    int year = std::stoi(tglPinjam.substr(0, 4));
    int month = std::stoi(tglPinjam.substr(5, 2));
    int day = std::stoi(tglPinjam.substr(8, 2));

    year_month_day start = year / month / day;

    sys_days tp = sys_days(start) + days(durasi);

    year_month_day out = year_month_day(tp);

    std::ostringstream os;
    os << int(out.year()) << "-"
       << std::setw(2) << std::setfill('0') << unsigned(out.month()) << "-"
       << std::setw(2) << std::setfill('0') << unsigned(out.day());

    return os.str();
}

void hapusPeminjaman(int idx) {
    if (pinjam.empty()) {
        cout << "Tidak ada data peminjaman." << endl;
        return;
    }
    
    if (idx < 0 || idx >= pinjam.size()) {
        cout << "Data peminjaman tidak ditemukan." << endl;
        return;
    }
    
    pinjam.erase(pinjam.begin() + idx);
    cout << "Data peminjaman berhasil dihapus." << endl;
}

bool validasiNIM(string nim) {
    if (nim.length() < 8 || nim.length() > 15) return false;
    
    for (char c : nim) {
        if (!isdigit(c)) return false;
    }
    return true;
}

string tanggalHariIni() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    stringstream ss;
    ss << (1900 + ltm->tm_year) << "-"
       << (1 + ltm->tm_mon < 10 ? "0" : "") << (1 + ltm->tm_mon) << "-"
       << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday;
    return ss.str();
}

string generateIDPinjam() {
    static int counter = 1;
    stringstream ss;
    ss << "P" << setw(4) << setfill('0') << counter++;
    return ss.str();
}

void pinjamAset() {
    string idAset, nim, nama, idPinjam;
    int jumlah, durasi, asetIdx;
    
    while (true) {
        cout << "Masukkan ID Aset (ketik 'BATAL' untuk kembali): ";
        cin >> idAset;
        
        if (idAset == "BATAL") return;
        
=======

void pinjamAset() {
    std::string idAset, nim, nama;
    int jumlah, durasi;
    int asetIdx;

    while (true) {
        std::cout << "Masukkan ID Aset (ketik 'BATAL' untuk kembali): ";
        std::cin >> idAset;

        if (idAset == "BATAL") return;

>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
        asetIdx = cariAsetByID(idAset);
        if (asetIdx != -1) {
            break;
        } else {
<<<<<<< HEAD
            cout << "Aset tidak ditemukan. Coba lagi." << endl;
        }
    }
    
    while (true) {
        cout << "Masukkan NIM (ketik 'BATAL' untuk kembali): ";
        cin >> nim;
        
        if (nim == "BATAL") return;
        
        if (validasiNIM(nim)) {
            break;
        } else {
            cout << "NIM tidak valid" << endl;
        }
    }
    
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, nama);
    
    while (true) {
        cout << "Masukkan jumlah (ketik 'BATAL' untuk kembali): ";
        cin >> jumlah;
        
        if (jumlah == -1) {
            return;
        }
        
        if (jumlah <= 0 || jumlah > aset[asetIdx].stok) {
            cout << "Jumlah tidak valid atau stok tidak cukup" << endl;
=======
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
>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
        } else {
            break;
        }
    }
<<<<<<< HEAD
    
    cout << "Masukkan durasi (hari): ";
    cin >> durasi;
    
    string tglPinjam = tanggalHariIni();
    string tglKembali = hitungTglKembali(tglPinjam, durasi);
    idPinjam = generateIDPinjam();
    
    kurangStokAset(asetIdx, jumlah);
    
=======

    std::cout << "Masukkan durasi (hari): ";
    std::cin >> durasi;

    std::time_t tglPinjam = tanggalHariIni();
    std::time_t tglKembali = hitungTglKembali(tglPinjam, durasi);
    std::string idPinjam = generateIDPinjam();

    kurangStokAset(asetIdx, jumlah);

>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
    DataPeminjaman dataBaru;
    dataBaru.idPinjam = idPinjam;
    dataBaru.nim = nim;
    dataBaru.nama = nama;
    dataBaru.idAset = idAset;
    dataBaru.jumlah = jumlah;
    dataBaru.durasi = durasi;
    dataBaru.tglPinjam = tglPinjam;
    dataBaru.tglKembali = tglKembali;
<<<<<<< HEAD
    
    pinjam.push_back(dataBaru);
    
    cout << "Peminjaman berhasil dicatat. ID Peminjaman: " << idPinjam << endl;
}

void kembaliAset() {
    string idPinjam, kondisi;
    int peminjamanIdx, asetIdx, jumlah;
    
    while (true) {
        cout << "Masukkan ID pinjam (ketik 'BATAL' untuk kembali): ";
        cin >> idPinjam;
        
        if (idPinjam == "BATAL") return;
        
=======

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

>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
        peminjamanIdx = cariPeminjamanByID(idPinjam);
        if (peminjamanIdx != -1) {
            break;
        } else {
<<<<<<< HEAD
            cout << "Data tidak ditemukan" << endl;
        }
    }
    
    while (true) {
        cout << "Masukkan kondisi (Baik/Rusak/Hilang) (ketik 'BATAL' untuk kembali): ";
        cin >> kondisi;
        
        if (kondisi == "BATAL") return;
        
        if (kondisi == "Baik") {
            string idAset = pinjam[peminjamanIdx].idAset;
            jumlah = pinjam[peminjamanIdx].jumlah;
            asetIdx = cariAsetByID(idAset);
            
            tambahStokAset(asetIdx, jumlah);
            cout << "Pengembalian berhasil dicatat." << endl;
            
            hapusPeminjaman(peminjamanIdx);
            return;
        } else if (kondisi == "Rusak" || kondisi == "Hilang") {
            cout << "Barang tidak bisa dikembalikan, harap ganti dengan barang yang sesuai dengan kondisi semula" << endl;
            return;
        } else {
            cout << "Kondisi tidak sesuai" << endl;
=======
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
>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
        }
    }
}

void cekPeminjaman() {
<<<<<<< HEAD
    string idPinjam;
    int peminjamanIdx, asetIdx;
    
    while (true) {
        cout << "Masukkan ID Peminjaman (ketik 'BATAL' untuk kembali): ";
        cin >> idPinjam;
        
        if (idPinjam == "BATAL") return;
        
=======
    std::string idPinjam;
    int peminjamanIdx;

    while (true) {
        std::cout << "Masukkan ID Peminjaman (ketik 'BATAL' untuk kembali): ";
        std::cin >> idPinjam;

        if (idPinjam == "BATAL") return;

>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
        peminjamanIdx = cariPeminjamanByID(idPinjam);
        if (peminjamanIdx != -1) {
            break;
        } else {
<<<<<<< HEAD
            cout << "Data tidak ditemukan, coba lagi" << endl;
        }
    }
    
    asetIdx = cariAsetByID(pinjam[peminjamanIdx].idAset);
    
    cout << "\n=== STATUS PEMINJAMAN ===" << endl;
    cout << "ID: " << pinjam[peminjamanIdx].idPinjam << endl;
    cout << "NIM: " << pinjam[peminjamanIdx].nim << endl;
    cout << "Nama: " << pinjam[peminjamanIdx].nama << endl;
    cout << "Aset: " << pinjam[peminjamanIdx].idAset << endl;
    cout << "Nama Barang: " << aset[asetIdx].namaAset << endl;
    cout << "Jumlah: " << pinjam[peminjamanIdx].jumlah << endl;
    cout << "Durasi: " << pinjam[peminjamanIdx].durasi << " hari" << endl;
    cout << "Tanggal Pinjam: " << pinjam[peminjamanIdx].tglPinjam << endl;
    cout << "Tanggal Kembali: " << pinjam[peminjamanIdx].tglKembali << endl;
}

void cekSisaStokAset() {
    string idAset;
    int asetIdx;
    
    while (true) {
        cout << "Masukkan ID Aset (ketik 'BATAL' untuk kembali): ";
        cin >> idAset;
        
        if (idAset == "BATAL") return;
        
=======
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

>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
        asetIdx = cariAsetByID(idAset);
        if (asetIdx != -1) {
            break;
        } else {
<<<<<<< HEAD
            cout << "Aset tidak ditemukan, coba lagi" << endl;
        }
    }
    
=======
            std::cout << "Aset tidak ditemukan, coba lagi\n";
        }
    }

>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
    int stokDipinjam = 0;
    for (const auto& p : pinjam) {
        if (p.idAset == idAset) {
            stokDipinjam += p.jumlah;
        }
    }
<<<<<<< HEAD
    
    int totalStok = aset[asetIdx].stok + stokDipinjam;
    
    cout << "\n===== MONITORING STOK =====" << endl;
    cout << "ID Aset       : " << aset[asetIdx].idAset << endl;
    cout << "Nama Aset     : " << aset[asetIdx].namaAset << endl;
    cout << "Total Aset    : " << totalStok << endl;
    cout << "Tersedia      : " << aset[asetIdx].stok << endl;
    cout << "Dipinjam      : " << stokDipinjam << endl;
    
    if (aset[asetIdx].stok == 0) {
        cout << "PERINGATAN: Stok aset habis!" << endl;
    }
=======

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
>>>>>>> d10d3ab92f814818b1beab49f7316eb7368f54c1
}
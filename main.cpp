#include "variabel.h" // mengambil variabel dari file variabel.h
#include <iostream>

void TampilkanMenu() {
    int menu;
    
    while (true) {
        std::cout << "\n===== SISTEM PEMINJAMAN ASET LABORATORIUM =====\n";
        std::cout << "1. Lihat Data Aset\n";
        std::cout << "2. Peminjaman Aset\n";
        std::cout << "3. Pengembalian Aset\n";
        std::cout << "4. Cek Status Peminjaman\n";
        std::cout << "5. Cek Stok Aset\n";
        std::cout << "6. Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> menu;

        if (menu == 1) {
            lihatAset();
        } else if (menu == 2) {
            pinjamAset();
        } else if (menu == 3) {
            kembaliAset();
        } else if (menu == 4) {
            cekPeminjaman();
        } else if (menu == 5) {
            cekSisaStokAset();
        } else if (menu == 6) {
            std::cout << "Terima kasih telah menggunakan sistem!\n";
            break;
        } else {
            std::cout << "Pilihan tidak valid! Silakan masukkan angka 1-6.\n";
        }
    }
}

int main() {
    TampilkanMenu();
    return 0;
}
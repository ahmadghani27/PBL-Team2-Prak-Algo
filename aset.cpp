#include "variabel.h" // megnambil variabel dari variabel.h
#include <iostream>
#include <algorithm>
#include <iomanip>

// Definisi variabel global
std::vector<DataAset> aset = {
    {"A001", "Arduino Uno", "Mikrokontroler", 15},
    {"A002", "Sensor Suhu", "Sensor", 8},
    {"A003", "ESP32", "Mikrokontroler", 10},
    {"A004", "LCD 16x2", "Display", 5},
    {"A005", "Breadboard", "Aksesoris", 20, 20},
    {"A006", "Servo SG90", "Aktuator", 12, 12},
    {"A007", "Kabel Jumper", "Aksesoris", 50, 50},
    {"A008", "Multimeter", "Alat Ukur", 3, 3}};

bool sortedByID = true;
void lihatAset()
{
    // IF aset.length > 0 THEN
    if (!aset.empty())
    {
        // FOR i = 1 UNTIL aset.length PRINT...
        std::cout << "\n===== DAFTAR ASET LABORATORIUM =====\n";
        std::cout << std::left << std::setw(8) << "ID"
                  << std::setw(20) << "Nama Aset"
                  << std::setw(15) << "Kategori"
                  << std::setw(8) << "Stok" << std::endl;
        std::cout << "----------------------------------------\n";

        for (const auto &a : aset)
        {
            std::cout << std::setw(8) << a.idAset
                      << std::setw(20) << a.namaAset
                      << std::setw(15) << a.kategori
                      << std::setw(8) << a.stok << std::endl;
        }

        int submenu;
        do
        {
            std::cout << "\n=== OPSI TAMPILAN ===\n";
            std::cout << "1. Urutkan berdasarkan Nama (A-Z)\n";
            std::cout << "2. Urutkan berdasarkan Stok (Terbanyak)\n";
            std::cout << "3. Kembali ke Menu Utama\n";
            std::cout << "Pilihan: ";
            std::cin >> submenu;

            if (submenu == 1)
            {
                sortAsetByNama();
                break;
            }
            else if (submenu == 2)
            {
                sortAsetByStok();
                break;
            }
            else if (submenu == 3)
            {
                return;
            }
            else
            {
                std::cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (submenu < 1 || submenu > 3);
    }
    else
    {
        std::cout << "Data aset kosong\n";
    }
}

void sortAsetByNama()
{
    for (size_t i = 1; i < aset.size(); i++)
    {
        DataAset key = aset[i];
        int j = i - 1;

        while (j >= 0 && aset[j].namaAset > key.namaAset)
        {
            aset[j + 1] = aset[j];
            j--;
        }
        aset[j + 1] = key;
    }

    std::cout << "Data aset berhasil diurutkan berdasarkan nama (Insertion Sort)!\n";
    sortedByID = false;
    lihatAset();
}

void sortAsetByStok()
{
    for (size_t i = 1; i < aset.size(); i++)
    {
        DataAset key = aset[i];
        int j = i - 1;

        while (j >= 0 && aset[j].stok < key.stok) // descending
        {
            aset[j + 1] = aset[j];
            j--;
        }
        aset[j + 1] = key;
    }

    std::cout << "Data aset berhasil diurutkan berdasarkan stok (Insertion Sort)!\n";
    sortedByID = false;
    lihatAset();
}

int cariAsetByID(std::string idAset)
{
    if (!sortedByID) // sort by id terlebih dahulu untuk binary sort
    {
        for (size_t i = 1; i < aset.size(); i++)
        {
            DataAset key = aset[i];
            int j = i - 1;

            while (j >= 0 && aset[j].idAset > key.idAset)
            {
                aset[j + 1] = aset[j];
                j--;
            }
            aset[j + 1] = key;
        }
        sortedByID = true;
    }

    int left = 0;
    int right = aset.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (aset[mid].idAset == idAset)
        {
            return mid;
        }
        else if (aset[mid].idAset < idAset)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1; // tidak ditemukan
}

void tambahStokAset(int idx, int jumlah)
{
    aset[idx].stok += jumlah;
}

void kurangStokAset(int idx, int jumlah)
{
    if (jumlah <= aset[idx].stok)
    {
        aset[idx].stok -= jumlah;
    }
    else
    {
        std::cout << "Kesalahan: Stok aset tidak cukup.\n";
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <string>
#include "variabel.h"

using namespace std;
vector<DataPeminjaman> pinjam;

int cariPeminjamanByID(const string idPinjam)
{
    int left = 0;
    int right = pinjam.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        const string &midId = pinjam[mid].idPinjam;
        if (midId == idPinjam)
        {
            return mid;
        }
        else if (midId < idPinjam)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Tidak ditemukan
}

string hitungTglKembali(const string &tglPinjam, int durasi)
{
    tm mytm = {};
    mytm.tm_year = stoi(tglPinjam.substr(0, 4)) - 1900;
    mytm.tm_mon = stoi(tglPinjam.substr(5, 2)) - 1;
    mytm.tm_mday = stoi(tglPinjam.substr(8, 2));

    // Convert tm → time_t
    time_t tt = mktime(&mytm);

    // Tambahkan hari
    tt += durasi * 24 * 3600;

    // Convert kembali
    tm *out = localtime(&tt);

    ostringstream os;
    os << (out->tm_year + 1900) << "-"
       << setw(2) << setfill('0') << (out->tm_mon + 1) << "-"
       << setw(2) << setfill('0') << out->tm_mday;

    return os.str();
}

void hapusPeminjaman(int idx)
{
    if (pinjam.empty())
    {
        cout << "Tidak ada data peminjaman." << endl;
        return;
    }

    if (idx < 0 || idx >= pinjam.size())
    {
        cout << "Data peminjaman tidak ditemukan." << endl;
        return;
    }

    pinjam.erase(pinjam.begin() + idx);
    cout << "Data peminjaman berhasil dihapus." << endl;
}

bool validasiNIM(string nim)
{
    if (nim.length() < 8 || nim.length() > 15)
        return false;

    for (char c : nim)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

string tanggalHariIni()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << (1900 + ltm->tm_year) << "-"
       << (1 + ltm->tm_mon < 10 ? "0" : "") << (1 + ltm->tm_mon) << "-"
       << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday;
    return ss.str();
}

string generateIDPinjam()
{
    static int counter = 1;
    stringstream ss;
    ss << "P" << setw(4) << setfill('0') << counter++;
    return ss.str();
}

void pinjamAset()
{
    string idAset, nim, nama, idPinjam;
    int jumlah, durasi, asetIdx;

    cout << "(ketik 'BATAL' untuk kembali)" << endl;
    while (true)
    {
        cout << "Masukkan ID Aset : ";
        cin >> idAset;

        if (idAset == "BATAL")
            return;

        asetIdx = cariAsetByID(idAset);
        if (asetIdx != -1)
        {
            cout << "Aset :" << aset[asetIdx].namaAset << endl;
            break;
        }
        else
        {
            cout << "Aset tidak ditemukan. Coba lagi." << endl;
        }
    }

    while (true)
    {
        cout << "Masukkan NIM : ";
        cin >> nim;

        if (nim == "BATAL")
            return;

        if (validasiNIM(nim))
        {
            break;
        }
        else
        {
            cout << "NIM tidak valid" << endl;
        }
    }

    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, nama);

    while (true)
    {
        cout << "Masukkan jumlah : ";
        cin >> jumlah;

        if (jumlah == -1)
        {
            return;
        }

        if (jumlah <= 0 || jumlah > aset[asetIdx].stok)
        {
            cout << "Jumlah tidak valid atau stok tidak cukup" << endl;
        }
        else
        {
            break;
        }
    }

    cout << "Masukkan durasi (hari): ";
    cin >> durasi;

    string tglPinjam = tanggalHariIni();
    string tglKembali = hitungTglKembali(tglPinjam, durasi);
    idPinjam = generateIDPinjam();

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

    cout << "Peminjaman berhasil dicatat. ID Peminjaman: " << idPinjam << endl;
}

void kembaliAset()
{
    string idPinjam, kondisi;
    int peminjamanIdx, asetIdx, jumlah;

    while (true)
    {
        cout << "Masukkan ID pinjam (ketik 'BATAL' untuk kembali): ";
        cin >> idPinjam;

        if (idPinjam == "BATAL")
            return;

        peminjamanIdx = cariPeminjamanByID(idPinjam);
        if (peminjamanIdx != -1)
        {
            break;
        }
        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }

    while (true)
    {
        cout << "Masukkan kondisi (Baik/Rusak/Hilang) (ketik 'BATAL' untuk kembali): ";
        cin >> kondisi;

        if (kondisi == "BATAL")
            return;

        if (kondisi == "Baik")
        {
            string idAset = pinjam[peminjamanIdx].idAset;
            jumlah = pinjam[peminjamanIdx].jumlah;
            asetIdx = cariAsetByID(idAset);

            tambahStokAset(asetIdx, jumlah);
            cout << "Pengembalian berhasil dicatat." << endl;

            hapusPeminjaman(peminjamanIdx);
            return;
        }
        else if (kondisi == "Rusak" || kondisi == "Hilang")
        {
            cout << "Barang tidak bisa dikembalikan, harap ganti dengan barang yang sesuai dengan kondisi semula" << endl;
            return;
        }
        else
        {
            cout << "Kondisi tidak sesuai" << endl;
        }
    }
}

void cekPeminjaman()
{
    string idPinjam;
    int peminjamanIdx, asetIdx;

    while (true)
    {
        cout << "Masukkan ID Peminjaman (ketik 'BATAL' untuk kembali): ";
        cin >> idPinjam;

        if (idPinjam == "BATAL")
            return;

        peminjamanIdx = cariPeminjamanByID(idPinjam);
        if (peminjamanIdx != -1)
        {
            break;
        }
        else
        {
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

void cekSisaStokAset()
{
    string idAset;
    int asetIdx;

    while (true)
    {
        cout << "Masukkan ID Aset (ketik 'BATAL' untuk kembali): ";
        cin >> idAset;

        if (idAset == "BATAL")
            return;

        asetIdx = cariAsetByID(idAset);
        if (asetIdx != -1)
        {
            break;
        }
        else
        {
            cout << "Aset tidak ditemukan, coba lagi" << endl;
        }
    }

    int stokDipinjam = 0;
    for (const auto &p : pinjam)
    {
        if (p.idAset == idAset)
        {
            stokDipinjam += p.jumlah;
        }
    }

    int totalStok = aset[asetIdx].stok + stokDipinjam;

    cout << "\n===== MONITORING STOK =====" << endl;
    cout << "ID Aset       : " << aset[asetIdx].idAset << endl;
    cout << "Nama Aset     : " << aset[asetIdx].namaAset << endl;
    cout << "Total Aset    : " << totalStok << endl;
    cout << "Tersedia      : " << aset[asetIdx].stok << endl;
    cout << "Dipinjam      : " << stokDipinjam << endl;

    if (aset[asetIdx].stok == 0)
    {
        cout << "PERINGATAN: Stok aset habis!" << endl;
    }
}
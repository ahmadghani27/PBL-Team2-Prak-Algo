# 🧰 Sistem Peminjaman dan Pengembalian Aset Laboratorium Mikrokontroler

## 📘 Deskripsi Proyek
Sistem ini dirancang untuk membantu proses **pencatatan aktivitas peminjaman dan pengembalian aset di laboratorium mikrokontroler**.  
Sebelumnya, proses dilakukan secara manual menggunakan kertas sehingga sering terjadi kesalahan data dan kesulitan dalam pelacakan aset.  
Program ini dibuat untuk mempermudah laboran dan mahasiswa dalam melakukan transaksi peminjaman dengan **validasi otomatis** dan **pembaruan stok real-time**.

---

## 🧩 Fitur Utama
- **Manajemen Aset**
  - Menampilkan daftar aset dan stok yang tersedia.
  - Sorting aset berdasarkan **nama** atau **jumlah stok**.
- **Peminjaman**
  - Input data peminjam (NIM, Nama, ID Aset, Jumlah).
  - Validasi input & stok sebelum transaksi.
- **Pengembalian**
  - Proses pengembalian aset berdasarkan ID peminjaman.
  - Stok otomatis bertambah kembali.
- **Pencarian Cepat**
  - Cari data aset atau peminjaman dengan **Binary Search**.
- **Monitoring**
  - Mengecek status peminjaman dan sisa stok aset secara langsung.

---

## 🧠 Algoritma yang Digunakan
| Jenis | Algoritma | Tujuan |
|-------|------------|--------|
| Sorting | **Insertion Sort** | Mengurutkan aset berdasarkan nama atau stok |
| Searching | **Binary Search** | Mencari aset atau peminjaman berdasarkan ID |
| Struktur Data | **Array 2D** | Menyimpan data aset dan transaksi |

Kompleksitas:
- Insertion Sort → O(n²)
- Binary Search → O(log n)

---

## 📋 Struktur Menu
[1] Lihat Aset <br>
[2] Peminjaman <br>
[3] Pengembalian <br>
[4] Cek Peminjaman <br>
[5] Cek Sisa Stok Aset <br>
[6] Keluar

---

## 📥 Contoh Input dan Output

### ✅ Peminjaman Normal
**Input:**
NIM : 24051130000
Nama : Orang
ID Aset : 2
Jumlah : 3

makefile
Copy code
**Output:**
Peminjaman berhasil!
Sisa stok aset: 7

### ⚠️ Kasus Edge (stok tidak cukup)
**Input:**
ID Aset : 2
Jumlah : 15

makefile
Copy code
**Output:**
Gagal! Jumlah peminjaman melebihi stok tersedia.

---


## ⚙️ Sub-program Utama

| Fungsi | Deskripsi |
|--------|------------|
| `tampilkanMenu()` | Menampilkan daftar menu utama |
| `lihatAset()` | Menampilkan semua data aset |
| `pinjamAset()` | Proses peminjaman dan pengurangan stok |
| `kembaliAset()` | Proses pengembalian dan penambahan stok |
| `sortAsetByNama(arr)` | Mengurutkan aset berdasarkan nama (A–Z) |
| `sortAsetByStok(arr)` | Mengurutkan aset berdasarkan stok tersisa |
| `cariAsetByID(idAset)` | Mencari data aset dengan Binary Search |
| `cariPeminjamanByID(idPinjam)` | Mencari data peminjaman dengan Binary Search |
| `validasiNIM(nim)` | Memastikan format dan panjang NIM benar |
| `validasiJumlah(jumlah)` | Mengecek jumlah aset valid dan tidak negatif |
| `validasiID(id, tipe)` | Memastikan ID aset/peminjaman valid |
| `updateStok(idAset, perubahan)` | Menambah atau mengurangi stok sesuai transaksi |
| `cekPeminjaman(idPinjam)` | Menampilkan detail peminjaman |
| `cekSisaStokAset(idAset)` | Menampilkan stok tersisa dari aset tertentu |

---

## 🧪 Rencana Pengujian

| Jenis Uji | Deskripsi | Hasil yang Diharapkan |
|------------|------------|-----------------------|
| Normal | Peminjaman valid | Data tersimpan dan stok berkurang |
| Edge | Jumlah > stok | Pesan error dan stok tidak berubah |
| Edge | ID aset tidak valid | Pesan “Aset tidak ditemukan” |
| Normal | Pengembalian valid | Stok bertambah sesuai jumlah dikembalikan |
| Edge | ID peminjaman salah | Pesan “Peminjaman tidak ditemukan” |

---

## 🧾 Catatan Akhir
Proyek ini dikembangkan untuk memenuhi tugas akhir mata kuliah **Praktikum Basis Data**, dengan fokus pada penerapan **algoritma dasar (sort/search)** dan **pemodelan sistem informasi berbasis array 2D**.  
Sistem ini masih dapat dikembangkan lebih lanjut menggunakan **database SQLite atau MySQL** agar dapat digunakan secara nyata di lingkungan laboratorium.

---

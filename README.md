# 💻 Sistem Peminjaman dan Pengembalian Aset Laboratorium Mikrokontroler

Proyek ini adalah implementasi sistem berbasis **CLI (Command Line Interface)** untuk mendigitalisasi dan mengelola aktivitas peminjaman/pengembalian aset, berfokus pada **validasi stok otomatis** dan **pelacakan real-time** di lingkungan **Laboratorium Mikrokontroler**.

Sistem dikembangkan untuk membantu **Laboran** dalam mencegah kesalahan data, keterlambatan pelacakan, dan ketidaksesuaian antara data sistem dan ketersediaan fisik aset.

---

## 🌟 Fitur Utama

| **Fitur** | **Deskripsi** |
|------------|----------------|
| **Validasi Stok Otomatis** | Sistem mencegah peminjaman melebihi stok yang tersedia (over-borrow) dan memperbarui stok secara akurat setelah transaksi. |
| **Pelacakan Kondisi Aset** | Penambahan stok saat pengembalian hanya dilakukan jika aset dikembalikan dalam kondisi *Baik*. |
| **Pencarian & Sorting Cepat** | Menyediakan berbagai tampilan data aset (berdasarkan waktu input, nama, atau stok) menggunakan algoritma efisien. |
| **Monitoring Status** | Menyediakan informasi stok aset terkini dan status peminjaman (aktif/riwayat) untuk pelacakan aset yang efisien. |

---

## ⚙️ Desain & Algoritma Inti

Proyek ini dibangun menggunakan **struktur data dan algoritma fundamental** untuk menjaga efisiensi tinggi dengan nilai proses **$O(\log n)$** dan **$O(n)$**.

| **Komponen** | **Pilihan** | **Justifikasi Efisiensi** |
|---------------|--------------|-----------------------------|
| **Struktur Data** | Array 2D | Struktur sederhana, akses langsung, cocok untuk data skala kecil-menengah (Lab). |
| **Pencarian Data** | Binary Search | Kompleksitas $O(\log n)$, jauh lebih cepat daripada pencarian linear untuk data terurut. |
| **Pengurutan** | Insertion Sort | Stabil dan efisien ($O(n)$ terbaik) untuk data kecil hingga menengah. |
| **Kontrol Alur** | Perulangan & Percabangan | Digunakan untuk navigasi menu, validasi input, dan logika transaksi (stok, kondisi). |

---

## 🛠️ Rencana Modular Utama

Modul-modul utama dirancang dengan fokus pada **efisiensi pemrosesan data**, di mana fungsi pengubah data utama menggunakan mekanisme **Pass by Reference (ByRef)**.

| **Prosedur/Fungsi** | **Contoh Parameter Passing** | **Tujuan** |
|----------------------|-------------------------------|-------------|
| `pinjamAset()` | ByRef untuk Array Aset | Mencatat transaksi baru dan mengurangi stok aset. |
| `kembaliAset()` | ByRef untuk Array Aset | Mencatat pengembalian, validasi kondisi, dan memperbarui stok. |
| `cariAsetByID()` | ByRef untuk Array Aset | Mengambil data aset berdasarkan ID menggunakan Binary Search. |
| `sortAsetByNama()` | ByRef untuk Array Aset | Mengurutkan daftar aset untuk tampilan dan pencarian. |
| `cekSisaStokAset()` | ByRef untuk Array Aset | Mengembalikan jumlah stok tersedia terkini. |

---

## 🧪 Rencana Pengujian Awal

| **Jenis Uji** | **Deskripsi** | **Hasil yang Diharapkan** |
|----------------|----------------|-----------------------------|
| **Normal (Sort)** | Urutkan aset dengan Insertion Sort berdasarkan nama. | Data aset diurutkan secara Alfabetis (A–Z). |
| **Edge (Sort)** | Urutkan daftar aset kosong. | Tidak terjadi error, menampilkan pesan *"Data aset kosong"*. |
| **Normal (Search)** | Cari ID aset valid menggunakan Binary Search. | Mengembalikan data aset lengkap. |
| **Edge (Search)** | Cari ID aset tidak valid (Y100). | Pesan *"Aset tidak ditemukan"*. |
| **Edge (Transaksi)** | Peminjaman melebihi stok tersedia (A001, 16 unit). | ❌ *GAGAL:* Pesan *"Jumlah melebihi stok"*. |
| **Edge (Transaksi)** | Pengembalian dengan ID Peminjaman tidak valid (PJM999). | ❌ *GAGAL:* Pesan *"ID Peminjaman tidak ditemukan"*. |

---

## 🚀 Cara Menjalankan

### 1️⃣ Clone Repositori
```
git clone https://github.com/ahmadghani27/PBL-Team2-Prak-Algo.git
```
### 2️⃣ Kompilasi dan Eksekusi
(Instruksi dijalankan sesuai bahasa pemrograman yang digunakan, misalnya C/C++ atau Python.)

# Contoh jika menggunakan C/C++
gcc main.c -o sistem
./sistem

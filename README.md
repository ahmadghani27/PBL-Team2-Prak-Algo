# 🧰 Sistem Peminjaman & Pengembalian Aset Laboratorium Mikrokontroler  
### ⚡ Monitoring Real-Time & Validasi Stok Otomatis  

---

## 📘 Deskripsi  
Pencatatan aset laboratorium yang masih manual sering menimbulkan kesalahan data dan kehilangan aset.  
Sistem ini dibuat untuk membantu **laboran dan mahasiswa** dalam proses **peminjaman, pengembalian, dan pelacakan aset** secara **digital dan otomatis**.  

Fitur utama:
- Monitoring status aset **real-time**  
- Validasi stok otomatis  
- Pengembalian aset berdasarkan kondisi  
- Sorting & pencarian cepat dengan algoritma efisien  

---

## ⚙️ Fitur Sistem  
✅ **Manajemen Aset:** lihat, urutkan, dan cari aset berdasarkan ID, nama, atau stok.  
✅ **Peminjaman:** stok otomatis berkurang setelah transaksi.  
✅ **Pengembalian:** stok bertambah jika aset baik, tetap jika rusak/hilang.  
✅ **Monitoring:** cek status peminjaman & stok terkini secara langsung.  

---

## 🧠 Desain Algoritma  
| Komponen | Metode | Keterangan |
|-----------|---------|-------------|
| Penyimpanan Data | Array 2D | Simulasi tabel data aset & peminjaman |
| Pengurutan | Insertion Sort | Urutkan aset berdasarkan nama/stok |
| Pencarian | Binary Search | Cari data aset/peminjaman dengan cepat |
| Kontrol Program | Perulangan & Percabangan | Navigasi menu & validasi input |

---

## 🧩 Struktur Modular Utama
**Prosedur:**  
`pinjamAset()` • `kembaliAset()` • `sortAsetByNama()` • `sortAsetByStok()`  

**Fungsi:**  
`cariAsetByID()` • `cariPeminjamanByID()` • `cekPeminjaman()` • `cekSisaStokAset()`  

Ada lagi beberapa pelengkap
---

## 💻 Contoh I/O  
**Peminjaman Aset (`pinjamAset`)**  
- Input: `A001, 1` → ✅ *Peminjaman berhasil. Stok berkurang.*  
- Input: `A001, 16` → ❌ *Gagal: Melebihi stok.*  

**Pengembalian Aset (`kembaliAset`)**  
- Input: `PJM001, "baik"` → ✅ *Stok bertambah.*  
- Input: `PJM002, "rusak"` → ⚠️ *Stok tidak bertambah.*  

**Cek Stok (`cekSisaStokAset`)**  
- Input: `A001` → *13 unit tersedia*  
- Input: `Y100` → ❌ *ID tidak ditemukan*  

---

## 🧪 Rencana Pengujian  
| Jenis | Deskripsi | Hasil yang Diharapkan |
|--------|------------|-----------------------|
| Normal | Urutkan aset (nama) | Aset terurut A–Z |
| Normal | Urutkan aset (stok) | Aset terurut stok tertinggi |
| Edge | Daftar aset kosong | Pesan “Data aset kosong” |
| Normal | Cari aset valid | Data lengkap tampil |
| Edge | Cari aset tidak valid | Pesan “Aset tidak ditemukan” |
| Normal | Peminjaman valid | Data tersimpan & stok berkurang |
| Edge | Jumlah > stok | Pesan gagal, stok tetap |
| Normal | Pengembalian valid | Stok bertambah |
| Edge | ID peminjaman salah | Pesan “Peminjaman tidak ditemukan” |

---

## 🧾 Catatan Akhir  
Proyek ini dikembangkan untuk **Praktikum Basis Data** dengan penerapan **Array 2D, Sorting, dan Searching**.  
Sistem ini dapat dikembangkan lebih lanjut menggunakan **SQLite/MySQL** agar siap digunakan di laboratorium nyata.

# LIHAT ASET
- Pilih 1 (Urutkan berdasarkan alfabet nama aset)
> ``` Daftar di atas diurutkan berdasarkan Nama Aset (A-Z).```
- Pilih 2 (Urutkan berdasarkan stok aset terbanyak)
> ``` Daftar di atas diurutkan berdasarkan Stok (terbanyak ke terkecil).```

- Normal
> Urutkan aset dengan Insertion Sort by nama <br>
> ```Data aset diurutkan A–Z sesuai nama```
- Normal
> Urutkan aset dengan Insertion Sort by stok <br>
> ```Data aset diurutkan stok terbanyak–terendah```

# PEMINJAMAN
- input
```
NIM: 24051130000
Nama: Budi Santoso
ID_Aset: A001
Jumlah: 2
Durasi: 2 Hari
```
- output
```
PEMINJAMAN BERHASIL!
ID Peminjaman: PJM001
Peminjam: Budi Santoso (24051130000)
Aset: Arduino Uno (A001) x2
Durasi: 2 Hari
Stok tersisa: 13 unit 
```

# PENGEMBALIAN
- input
```ID_Peminjaman: PJM001
Kondisi_Aset: baik
```
- output
```PENGEMBALIAN BERHASIL!
Aset: Arduino Uno (A001) x2
Kondisi: Baik
Stok updated: 15 unit
```

# STATUS PEMINJAMAN
- input
```ID_Peminjaman: PJM001```
- output
```STATUS PEMINJAMAN:
ID: PJM001 | Status: Active
Peminjam: Budi Santoso (24051130000)
Aset: Arduino Uno (A001) x2
Durasi: 2 Hari
Tgl Pinjam : tgl pinjam (02/08/2025)
Batas Kembali : tgl pinjam+ 2 Hari
```

- Normal
x Cari data peminjaman valid dengan Binary Search
>``` Menampilkan detail peminjaman```
- Edge
x Cari data peminjaman tidak ditemukan
>``` Pesan “Peminjaman tidak ditemukan”```

# STOK ASET
- input
```ID_Aset: A001```
- output
```STOK ASET:
Arduino Uno (A001): 13 unit tersedia
Total: 15 unit | Dipinjam: 2 unit
```
- Normal
> Cari ID aset valid menggunakan Binary Search <br>
> ```Mengembalikan data aset lengkap```
- Edge
> Cari ID aset tidak valid dengan Binary Search <br>
> ```Pesan “Aset tidak ditemukan”```

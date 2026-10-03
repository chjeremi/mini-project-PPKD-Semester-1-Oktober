# Mini Project: Simulator ATM Sederhana (C++)

Program ini adalah simulator Anjungan Tunai Mandiri (ATM) berbasis konsol (CLI) yang dibuat menggunakan bahasa pemrograman C++. Program ini mendukung otentikasi login PIN, pengecekan saldo, penarikan tunai, penyetoran tunai, serta transfer antar rekening.

---

## 📌 Fitur Utama

1. **Sistem Login & Keamanan PIN**
   * Verifikasi akun berdasarkan nomor PIN.
   * Pembatasan percobaan login hingga **3 kali** sebelum akun diblokir sementara.
2. **Cek Saldo (`cekSaldo`)**
   * Menampilkan nama pemilik akun beserta sisa saldo saat ini secara presisi.
3. **Tarik Tunai (`tarikTunai`)**
   * Pengambilan uang dari saldo akun.
   * Memvalidasi batas saldo dan memastikan nominal penarikan lebih besar dari 0.
4. **Setor Tunai (`setorTunai`)**
   * Penambahan saldo ke akun yang sedang aktif.
5. **Transfer Antar Rekening (`transfer`)**
   * Pengiriman uang ke akun lain yang terdaftar dalam sistem.
   * Validasi agar pengguna tidak dapat melakukan transfer ke akun milik sendiri.
6. **Penanganan Error / Validasi Input (`bersihkanInput`)**
   * Mengantisipasi input *non-numeric* (huruf/simbol) agar program tidak bermasalah (*infinite loop*).

---

## 👥 Data Akun Default (Testing)

Program disimulasikan dengan 3 data akun bawaan sebagai berikut:

| Nama Pemilik   | PIN   | Saldo Awal (Rp) |
| :------------- | :---: | :-------------- |
| Budi Santoso   | `1111` | Rp 1.000.000    |
| Siti Aminah    | `2222` | Rp 2.500.000    |
| Andi Wijaya    | `3333` | Rp 500.000      |

---

## 🚀 Cara Menjalankan Program

### Persyaratan System
* C++ Compiler (`g++`, `clang`, atau MinGW)

### Langkah Kompilasi dan Eksekusi

1. **Clone repository ini**
   ```bash
   git clone https://github.com/USERNAME_ANDA/NAMA_REPOSITORY.git
   cd NAMA_REPOSITORY
   ```

2. **Kompilasi kode program**
   ```bash
   g++ -o simulator_atm main.cpp
   ```

3. **Jalankan program**
   * **Linux / macOS:**
     ```bash
     ./simulator_atm
     ```
   * **Windows:**
     ```bash
     simulator_atm.exe
     ```

---

## 💻 Contoh Penggunaan Program

```text
=====================================
   SELAMAT DATANG DI SIMULATOR ATM   
=====================================

Masukkan PIN Anda: 1111

[LOGIN BERHASIL] Selamat datang, Budi Santoso!

=========== MENU ATM ===========
1. Cek Saldo
2. Tarik Tunai
3. Setor Tunai
4. Transfer
5. Keluar
================================
Pilih menu (1-5): 1

===== INFORMASI SALDO =====
Nama Pemilik : Budi Santoso
Sisa Saldo   : Rp 1000000.00
```

---

## 🛠️ Struktur Kode & Algoritma

* `verifikasiPIN()`: Memeriksa input PIN dengan array `pinAkun[]`.
* `bersihkanInput()`: Membersihkan buffer `cin` menggunakan `cin.clear()` dan `cin.ignore()`.
* `main()`: Mengatur alur login utama serta perulangan menu (`while` & `switch-case`).
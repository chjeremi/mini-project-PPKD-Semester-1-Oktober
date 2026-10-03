#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int JUMLAH_AKUN = 3;

string namaAkun[JUMLAH_AKUN]  = {"Budi Santoso", "Siti Aminah", "Andi Wijaya"};
string pinAkun[JUMLAH_AKUN]   = {"1111", "2222", "3333"};
double saldoAkun[JUMLAH_AKUN] = {1000000.0, 2500000.0, 500000.0};

void bersihkanInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool verifikasiPIN(string inputPIN, int &indexLogin) {
    int i = 0;
    while (i < JUMLAH_AKUN) {
        if (inputPIN == pinAkun[i]) {
            indexLogin = i;
            return true;
        }
        i++;
    }
    return false;
}

void cekSaldo(int index) {
    cout << "\n===== INFORMASI SALDO =====" << endl;
    cout << "Nama Pemilik : " << namaAkun[index] << endl;
    cout << fixed << setprecision(2);
    cout << "Sisa Saldo   : Rp " << saldoAkun[index] << endl;
}

void tarikTunai(int index) {
    double nominal;

    cout << "\n===== TARIK TUNAI =====" << endl;
    cout << "Masukkan nominal penarikan: Rp ";

    if (!(cin >> nominal)) {
        bersihkanInput();
        cout << "[GAGAL] Input tidak valid! Harap masukkan angka." << endl;
        return;
    }

    if (nominal <= 0) {
        cout << "[GAGAL] Nominal harus lebih dari 0." << endl;
    } else if (nominal > saldoAkun[index]) {
        cout << "[GAGAL] Saldo tidak mencukupi!" << endl;
    } else {
        saldoAkun[index] -= nominal;
        cout << fixed << setprecision(2);
        cout << "[SUKSES] Penarikan sebesar Rp " << nominal << " berhasil." << endl;
        cout << "Sisa saldo Anda: Rp " << saldoAkun[index] << endl;
    }
}

void setorTunai(int index) {
    double nominal;

    cout << "\n===== SETOR TUNAI =====" << endl;
    cout << "Masukkan nominal setoran: Rp ";

    if (!(cin >> nominal)) {
        bersihkanInput();
        cout << "[GAGAL] Input tidak valid! Harap masukkan angka." << endl;
        return;
    }

    if (nominal <= 0) {
        cout << "[GAGAL] Nominal setoran harus lebih dari 0." << endl;
    } else {
        saldoAkun[index] += nominal;
        cout << fixed << setprecision(2);
        cout << "[SUKSES] Setoran sebesar Rp " << nominal << " berhasil." << endl;
        cout << "Saldo Anda sekarang: Rp " << saldoAkun[index] << endl;
    }
}

void transfer(int indexPengirim) {
    int nomorTujuan;
    double nominal;

    cout << "\n===== TRANSFER =====" << endl;

    cout << "Daftar akun yang tersedia:" << endl;
    for (int i = 0; i < JUMLAH_AKUN; i++) {
        cout << "  " << (i + 1) << ". " << namaAkun[i] << endl;
    }

    cout << "Masukkan nomor akun tujuan (1-" << JUMLAH_AKUN << "): ";
    if (!(cin >> nomorTujuan)) {
        bersihkanInput();
        cout << "[GAGAL] Input tidak valid! Harap masukkan angka." << endl;
        return;
    }

    int indexTujuan = nomorTujuan - 1;

    if (indexTujuan < 0 || indexTujuan >= JUMLAH_AKUN) {
        cout << "[GAGAL] Akun tujuan tidak ditemukan!" << endl;
        return;
    }

    if (indexTujuan == indexPengirim) {
        cout << "[GAGAL] Tidak dapat transfer ke akun sendiri!" << endl;
        return;
    }

    cout << "Masukkan nominal transfer: Rp ";
    if (!(cin >> nominal)) {
        bersihkanInput();
        cout << "[GAGAL] Input tidak valid! Harap masukkan angka." << endl;
        return;
    }

    if (nominal <= 0) {
        cout << "[GAGAL] Nominal transfer harus lebih dari 0." << endl;
    } else if (nominal > saldoAkun[indexPengirim]) {
        cout << "[GAGAL] Saldo tidak mencukupi untuk transfer!" << endl;
    } else {
        saldoAkun[indexPengirim] -= nominal;
        saldoAkun[indexTujuan]   += nominal;
        cout << fixed << setprecision(2);
        cout << "[SUKSES] Transfer Rp " << nominal << " ke "
             << namaAkun[indexTujuan] << " berhasil." << endl;
        cout << "Sisa saldo Anda: Rp " << saldoAkun[indexPengirim] << endl;
    }
}

int main() {
    const int MAKS_PERCOBAAN = 3;
    int percobaan = 0;
    int indexLogin = -1;
    bool loginBerhasil = false;
    string inputPIN;

    cout << "=====================================" << endl;
    cout << "   SELAMAT DATANG DI SIMULATOR ATM   " << endl;
    cout << "=====================================" << endl;

    while (percobaan < MAKS_PERCOBAAN && !loginBerhasil) {
        cout << "\nMasukkan PIN Anda: ";
        cin >> inputPIN;

        if (verifikasiPIN(inputPIN, indexLogin)) {
            loginBerhasil = true;
            cout << "\n[LOGIN BERHASIL] Selamat datang, "
                 << namaAkun[indexLogin] << "!" << endl;
        } else {
            percobaan++;
            int sisa = MAKS_PERCOBAAN - percobaan;
            cout << "[PIN SALAH] ";
            if (sisa > 0) {
                cout << "Sisa kesempatan: " << sisa << " kali." << endl;
            } else {
                cout << "Kesempatan habis." << endl;
            }
        }
    }

    if (!loginBerhasil) {
        cout << "\nAkun diblokir sementara. Silakan hubungi bank." << endl;
        return 0;
    }

    int pilihan = 0;

    while (pilihan != 5) {
        cout << "\n=========== MENU ATM ===========" << endl;
        cout << "1. Cek Saldo" << endl;
        cout << "2. Tarik Tunai" << endl;
        cout << "3. Setor Tunai" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Keluar" << endl;
        cout << "================================" << endl;
        cout << "Pilih menu (1-5): ";

        if (!(cin >> pilihan)) {
            bersihkanInput();
            pilihan = 0;
            cout << "[ERROR] Input harus berupa angka!" << endl;
            continue;  
        }

        switch (pilihan) {
            case 1:
                cekSaldo(indexLogin);
                break;
            case 2:
                tarikTunai(indexLogin);
                break;
            case 3:
                setorTunai(indexLogin);
                break;
            case 4:
                transfer(indexLogin);
                break;
            case 5:
                cout << "\nTerima kasih telah menggunakan ATM kami, "
                     << namaAkun[indexLogin] << "." << endl;
                cout << "Sampai jumpa!" << endl;
                break;
            default:
                cout << "[ERROR] Pilihan tidak valid! Pilih 1-5." << endl;
                break;
        }
    }

    return 0;
}

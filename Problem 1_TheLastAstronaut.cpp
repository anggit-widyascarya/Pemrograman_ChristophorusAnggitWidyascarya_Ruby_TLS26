#include <iostream>

int main() {
    int n, k;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai K: ";
    std::cin >> k;

    // Mendeklarasikan array untuk merepresentasikan astronot
    int astronauts[1000];
    for (int i = 0; i < n; i++) {
        astronauts[i] = i + 1;
    }

    int remaining = n;
    int current_idx = 0;

    std::cout << "Urutan eliminasi:\n";
    // Loop berjalan selama jumlah astronot tersisa lebih dari 1
    while (remaining > 1) {
        current_idx = (current_idx + (k - 1)) % remaining;
        int eliminated = astronauts[current_idx];
        
        std::cout << eliminated << " ";

        // Logika percabangan penentuan nilai K selanjutnya
        if (eliminated % 2 == 0) {
            k = k + 2;
        } else {
            k = k - 1;
        }

        if (k < 2) {
            k = 2;
        }

        // Menggeser nilai dalam array untuk menutupi posisi yang kosong
        for (int i = current_idx; i < remaining - 1; i++) {
            astronauts[i] = astronauts[i + 1];
        }
        remaining--;
    }

    std::cout << "\nAstronot terakhir yang bertahan: " << astronauts[0] << std::endl;
    return 0;
}
#include <iostream>

// User-defined function untuk menghitung panjang array karakter karena fungsi pustaka (library function) tidak diizinkan
int getStringLength(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char msg[1000];
    std::cout << "Masukkan pesan rahasia: ";
    std::cin >> msg;

    int len = getStringLength(msg);
    char encrypted[1000];

    // Proses perulangan menggeser huruf menggunakan for
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            encrypted[i] = msg[i];
        } else {
            int prev_val = msg[i - 1] - 'A' + 1;
            int curr_val = msg[i] - 'A' + 1;
            int new_val = curr_val + prev_val;

            // Logika if untuk karakter melampaui Z
            if (new_val > 26) {
                new_val = new_val % 26;
                if (new_val == 0) {
                    new_val = 26;
                }
            }
            encrypted[i] = (new_val - 1) + 'A';
        }
    }
    encrypted[len] = '\0';

    std::cout << "Pesan sandi: " << encrypted << std::endl;
    return 0;
}
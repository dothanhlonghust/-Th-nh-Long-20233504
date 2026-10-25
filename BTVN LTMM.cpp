#include <iostream>

using namespace std;

int phep_xor(int a, int b) {
    return a ^ b;
}

int nhan_voi_x(int g, int field) {
    if (field == 4) {
        int bit_cao_nhat = (g >> 3) & 1;
        int ket_qua = (g << 1) & 0x0F;
        if (bit_cao_nhat == 1) {
            ket_qua = phep_xor(ket_qua, 0x03);
        }
        return ket_qua;
    } else {
        int bit_cao_nhat = (g >> 7) & 1;
        int ket_qua = (g << 1) & 0xFF;
        if (bit_cao_nhat == 1) {
            ket_qua = phep_xor(ket_qua, 0x1B);
        }
        return ket_qua;
    }
}

int phep_nhan(int f, int g, int field) {
    int ket_qua = 0;
    int temp = g;

    for (int i = 0; i < field; i++) {
        int bit = (f >> i) & 1;
        if (bit == 1) {
            ket_qua = phep_xor(ket_qua, temp);
        }
        temp = nhan_voi_x(temp, field);
    }

    return ket_qua;
}

int main() {
    int a4 = 8;
    int b4 = 4;
    int kq4 = phep_nhan(a4, b4, 4);
    cout << "GF(2^4): " << kq4 << endl;

    int a8 = 0x57;
    int b8 = 0x83;
    int kq8 = phep_nhan(a8, b8, 8);
    cout << "GF(2^8): 0x" << hex << uppercase << kq8 << endl;

    return 0;
}

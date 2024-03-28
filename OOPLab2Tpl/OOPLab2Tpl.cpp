#include <iostream>
#include <clocale>
using namespace std;

int taskOne() {

    int a, b, c, d;
    int result;
    float check_res;
    cout << " Calculation of expressions using bitwise operations  \n";
    cout << "Enter A:";
    cin >> a;
    cout << "Enter B:";
    cin >> b;
    cout << "Enter C:";
    cin >> c;
    cout << "Enter D:";
    cin >> d;
    result = ((((a << 4) + a) + ((c << 3) + (c << 4) + (c << 5) + (c << 8))) >> 5) - ((b << 7) - (b << 3)) + ((d << 7) - d);
    cout << "Result:" << result << endl;
    check_res = ((a * 17 + c * 312) / 32) - b * 120 + d * 127;
    printf("Check result: %0.5f", check_res);
    return 0;
}

void shifr(char S[128], unsigned short Rez[128]) {
    unsigned char c;
    unsigned short r, t, b;
    short j;
    for (short i = 0; i < 128; i++) {
        r = 0;
        c = S[i];
        r = r | i;
        t = c;
        r = r | (t << 7);
        t = 1;
        b = 0;
        for (j = 0; j < 16; j++) {
            if (r & t) {
                if (b == 0) {
                    b = 1;
                }
                else {
                    b = 0;
                }
            }
            t <<= 1;
        }
        r |= b << 15;
        Rez[i] = r;
    }
}

void deshifr(unsigned short Rez[128], char S[128]) {
    unsigned short r;
    unsigned char c;
    for (short i = 0; i < 127; i++) {
        r = Rez[i];
        r = r >> 7;
        c = r;
        S[i] = c;
    }
    S[127] = '\0'; // Додавання завершального нуль-символу, щоб вказати кінець рядка.
}

int call() {
    cout << "Vvedit text dlya shifruvannya:" << endl;
    char S[129];
    unsigned short Rez[129];
    cin.get(S, 128);
    int n;
    n = strlen(S);
    for (short i1 = n; i1 < 128; i1++) S[i1] = '\0';
    shifr(S, Rez);
    for (short i = 0; i < 128; i++) {
        cout << hex << Rez[i];
    }
    cout << endl;
    deshifr(Rez, S);
    cout << S << endl;
    return 0;
}

int main() {
    int t;
    cout << "Choose task 1 or 2:" << endl;
    cin >> t;
    if (t == 1) {
        cout << "You choose task one:" << endl;
        taskOne();
        break;
    }
    if (t == 2) {
        call();
        break;
    }
    else {
        cout << "You choose wrong task. Choose 1 or 2!" << endl;
    }
    return 0;
}
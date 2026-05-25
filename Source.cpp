#include <iostream>

using namespace std;

const int N = 30;

struct Player {
    char* login = nullptr;
    char* password = nullptr;
    int level = 0;
    float money = 0;
};

void show(const Player& pl) {
    cout << "Login: " << pl.login
        << " | Password: " << pl.password
        << " | Level: " << pl.level
        << " | Money: " << pl.money << endl;
}

int main() {
    const char* PATH = "player.bin";
    const char* MODE = "ab+";

    Player bogdan;
    char l[N], p[N];
    cout << "Enter login: ";
    cin >> l;
    cout << "Enter password: ";
    cin >> p;
    cout << "Enter level: ";
    cin >> bogdan.level;
    bogdan.money = 100;

    bogdan.login = new char[strlen(l) + 1];
    strcpy_s(bogdan.login, strlen(l) + 1, l);
    bogdan.password = new char[strlen(p) + 1];
    strcpy_s(bogdan.password, strlen(p) + 1, p);

    FILE* f;
    if (fopen_s(&f, PATH, MODE) == 0) {
        fwrite(&bogdan, sizeof(Player), 1, f);

        int sizeLogin = strlen(bogdan.login) + 1;
        fwrite(&sizeLogin, sizeof(int), 1, f);
        fwrite(bogdan.login, sizeLogin, 1, f);

        int sizePwd = strlen(bogdan.password) + 1;
        fwrite(&sizePwd, sizeof(int), 1, f);
        fwrite(bogdan.password, sizePwd, 1, f);

        fseek(f, 0, SEEK_SET);
        while (!feof(f)) {
            Player pl;
            int sL, sP;
            if (fread(&pl, sizeof(Player), 1, f) > 0) {
                if (fread(&sL, sizeof(int), 1, f) > 0) {
                    char* loginBuf = new char[sL];
                    fread(loginBuf, sL, 1, f);
                    pl.login = new char[sL];
                    strcpy_s(pl.login, sL, loginBuf);
                    delete[] loginBuf;
                }
                if (fread(&sP, sizeof(int), 1, f) > 0) {
                    char* pwdBuf = new char[sP];
                    fread(pwdBuf, sP, 1, f);
                    pl.password = new char[sP];
                    strcpy_s(pl.password, sP, pwdBuf);
                    delete[] pwdBuf;
                }
                show(pl);
                delete[] pl.login;
                delete[] pl.password;
            }
        }
        fclose(f);
    }

    delete[] bogdan.login;
    delete[] bogdan.password;
    return 0;
}

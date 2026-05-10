#include <iostream>
using namespace std;

int main() {
    const char* PATH_TO_FILE = "test.txt";
    const char* MODE = "a"; //"w" - write, "a" - append, "r" - read
    FILE* file;
    int code = fopen_s(&file, PATH_TO_FILE, MODE); // відкрити файл
    unsigned int num = 0;
    char ch;
    do {
        cout << "Enter char (q - quit) = ";
        ch = getchar();
        if (ch >= '0' && ch <= '9') {
            num++;
        }

        if (ch == 'q') {
            break;
        }
        fputc(ch, file);
        cin.ignore();

    } while (true);
    cout << "Digits entered = " << num << endl;

    if (code == 0) { //SUCCES
        fclose(file); // закрити файл

        // Тепер відкриваємо файл для читання
        FILE* readFile;
        fopen_s(&readFile, PATH_TO_FILE, "r");
        if (readFile) {
            unsigned int digits = 0, upper = 0, lower = 0;
            char c;
            while ((c = fgetc(readFile)) != EOF) {
                if (c >= '0' && c <= '9') digits++;
                else if (c >= 'A' && c <= 'Z') upper++;
                else if (c >= 'a' && c <= 'z') lower++;
            }
            fclose(readFile);

            cout << "In file:\n";
            cout << "Digits = " << digits << endl;
            cout << "Uppercase letters = " << upper << endl;
            cout << "Lowercase letters = " << lower << endl;
        }
    }
    else { //ERROR
        cout << code;
    }

    return 0;
}

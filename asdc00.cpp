#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Record {
    string name;
    int number1;
    string color;
    int number2;
    string material;

    // Конструктор по умолчанию
    Record() : name(""), number1(0), color(""), number2(0), material("") {}

    // Конструктор копирования
    Record(const Record& other) : name(other.name), number1(other.number1), color(other.color), number2(other.number2), material(other.material) {}

    // Оператор (метод) копирования (=, clone)
    Record& operator=(const Record& other) {
        if (this != &other) {
            name = other.name;
            number1 = other.number1;
            color = other.color;
            number2 = other.number2;
            material = other.material;
        }
        return *this;
    }

    // Оператор (метод) сравнения (==, equal)
    bool operator==(const Record& other) const {
        return name == other.name && number1 == other.number1 && color == other.color && number2 == other.number2 && material == other.material;
    }

    // Оператор (метод) чтения из потока
    friend istream& operator>>(istream& is, Record& record) {
        is >> record.name >> record.number1 >> record.color >> record.number2 >> record.material;
        return is;
    }

    // Оператор (метод) записи в поток
    friend ostream& operator<<(ostream& os, const Record& record) {
        os << record.name << " " << record.number1 << " " << record.color << " " << record.number2 << " " << record.material << endl;
        return os;
    }
};

const int MAX_SIZE = 100;

int main() {
    Record records[MAX_SIZE];
    int size = 0;

    // Чтение из файла
    ifstream file("mebeli1.txt");
    if (!file) {
        cerr << "Error: could not open file" << endl;
        return 1;
    }

    while (size < MAX_SIZE && file >> records[size]) {
        ++size;
    }

    file.close();

    // Вывод на экран
    for (int i = 0; i < size; ++i) {
        cout << records[i];
    }

    return 0;
}
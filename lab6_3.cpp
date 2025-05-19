#include <iostream>
#include <string>

using namespace std;

class Student {
protected:
    string name;
    string university;
    int year;
public:
    Student(string n = "", string uni = "", int y = 0)
        : name(n), university(uni), year(y) {}

    virtual ~Student() {}

    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);
};


istream& operator>>(istream& in, Student& s) {
    cout << "Ім'я студента: ";
    getline(in >> ws, s.name);
    cout << "Університет: ";
    getline(in >> ws, s.university);
    cout << "Курс: ";
    in >> s.year;
    return in;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << "Студент: " << s.name << "\n"
        << "Університет: " << s.university << "\n"
        << "Курс: " << s.year << endl;
    return out;
}


class Parent {
protected:
    string childName;
    int numChildren;
public:
    Parent(string child = "", int num = 0)
        : childName(child), numChildren(num) {}

    virtual ~Parent() {}

    friend istream& operator>>(istream& in, Parent& p);
    friend ostream& operator<<(ostream& out, const Parent& p);
};


istream& operator>>(istream& in, Parent& p) {
    cout << "Ім'я дитини: ";
    getline(in >> ws, p.childName);
    cout << "Кількість дітей: ";
    in >> p.numChildren;
    return in;
}

ostream& operator<<(ostream& out, const Parent& p) {
    out << "Ім'я дитини: " << p.childName << "\n"
        << "Кількість дітей: " << p.numChildren << endl;
    return out;
}


class StudentParent : public Student, public Parent {
private:
    string status;
public:
    StudentParent(string n = "", string uni = "", int y = 0,
                  string child = "", int num = 0,
                  string stat = "Студент-Батько")
        : Student(n, uni, y), Parent(child, num), status(stat) {}

    virtual ~StudentParent() {}

    void display() const {
        cout << "\n=== Інформація про об'єкт StudentParent ===" << endl;
        cout << static_cast<const Student&>(*this);
        cout << static_cast<const Parent&>(*this);
        cout << "Статус: " << status << endl;
    }
};

int main() {
    StudentParent sp("Іван Петренко", "КНУ", 3, "Марійка", 2);
    sp.display();

    cout << "\nСтворимо нового студента-батька вручну:\n";
    StudentParent sp2;
    cin >> static_cast<Student&>(sp2);
    cin >> static_cast<Parent&>(sp2);
    sp2.display();

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Класс для сущности Имя
class Name {
public:
    string lastName;    // Фамилия
    string firstName;   // Личное имя
    string middleName;  // Отчество

    // Конструктор только с личным именем
    Name(string first) : firstName(first), lastName(""), middleName("") {}

    // Конструктор с личным именем и фамилией
    Name(string first, string last) : firstName(first), lastName(last), middleName("") {}

    // Конструктор с личным именем, фамилией и отчеством
    Name(string first, string last, string middle) : firstName(first), lastName(last), middleName(middle) {}

    // Функция для вывода имени в строковом формате
    string toString() const {
        string result;
        if (!lastName.empty()) {
            result += lastName + " ";
        }
        if (!firstName.empty()) {
            result += firstName + " ";
        }
        if (!middleName.empty()) {
            result += middleName;
        }
        return result;
    }

    // Функция для печати
    void print() const {
        cout << toString();
    }
};

// Класс для сущности Отдел
class Department {
private:
    vector<class Employee*> employees; // Хранит сотрудников отдела

public:
    string name;
    string head;

    // Конструктор с параметрами
    Department(string name, string head) : name(name), head(head) {}

    // Метод для добавления сотрудника в отдел
    void addEmployee(class Employee* employee);

    // Метод для получения списка всех сотрудников
    void listEmployees() const;
};

// Определение класса Employee
class Employee {
public:
    string name;
    Department* department;

    // Конструктор с параметрами
    Employee(string name, Department* department) : name(name), department(department) {
        department->addEmployee(this); // Добавляем сотрудника в отдел
    }

    // Метод для получения списка сотрудников этого отдела
    void listDepartmentEmployees() const {
        department->listEmployees();
    }

    // Функция для текстового представления
    string toString() const {
        return name + (department->head == name ? 
            " — начальник отдела " + department->name : 
            " работает в отделе " + department->name + ", начальник которого " + department->head);
    }

    // Функция для печати
    void print() const {
        cout << toString() << endl;
    }
};

// Реализация метода addEmployee для класса Department
void Department::addEmployee(Employee* employee) {
    employees.push_back(employee);
}

// Реализация метода listEmployees для класса Department
void Department::listEmployees() const {
    cout << "Сотрудники отдела " << name << ":" << endl;
    for (const auto& employee : employees) {
        cout << employee->name << endl;
    }
}

// Класс для сущности Человек
class Person {
public:
    string name;
    int height;

    // Конструктор с параметрами
    Person(string name, int height) : name(name), height(height) {}

    // Функция для текстового представления
    string toString() const {
        return name + ", рост: " + to_string(height);
    }

    // Функция для печати
    void print() const {
        cout << toString() << endl;
    }
};

// Класс для сущности Пистолет
class Pistol {
private:
    int bullets; // Количество патронов

public:
    // Конструктор с указанием количества патронов
    Pistol(int initialBullets) : bullets(initialBullets) {}

    // Конструктор без указания, по умолчанию 5 патронов
    Pistol() : bullets(5) {}

    // Метод для стрельбы
    void shoot() {
        if (bullets > 0) {
            cout << "Бах!" << endl;
            bullets--;
        } else {
            cout << "Клац!" << endl;
        }
    }

    // Получить количество оставшихся патронов
    int getBullets() const {
        return bullets;
    }
};

int main() {
    // Создание имен с различными параметрами
    Name cleopatra("Клеопатра");
    Name pushkin("Александр", "Пушкин", "Сергеевич");
    Name mayakovsky("Владимир", "Маяковский");
    Name bonifatevich("Христофор", "Бонифатьевич");

    // Вывод имен
    cout << "Созданные имена:" << endl;
    cout << "Имя 1: ";
    cleopatra.print();
    cout << endl;
    cout << "Имя 2: ";
    pushkin.print();
    cout << endl;
    cout << "Имя 3: ";
    mayakovsky.print();
    cout << endl;
    cout << "Имя 4: ";
    bonifatevich.print();
    cout << endl;

    // Создание предопределенных людей
    Person person1("Клеопатра", 152);
    Person person2("Пушкин", 167);
    Person person3("Владимир", 189);

    // Вывод людей
    cout << "\nСписок людей:" << endl;
    person1.print();
    person2.print();
    person3.print();

    // Создаем отдел IT и назначаем начальником Козлова
    string departmentName = "IT";
    string departmentHead = "Козлов";

    Department itDepartment(departmentName, departmentHead);

    // Создаем сотрудников
    Employee petrov("Петров", &itDepartment);
    Employee kozlov(departmentHead, &itDepartment); // Козлов будет начальником
    Employee sidorov("Сидоров", &itDepartment);

    // Выводим текстовое представление сотрудников
    cout << "\nСписок сотрудников:" << endl;
    petrov.print();
    kozlov.print();
    sidorov.print();

    // Получение списка всех сотрудников отдела IT с помощью ссылки на сотрудника
    cout << endl;
    petrov.listDepartmentEmployees();

    // Создание пистолета с 3 патронами
    Pistol pistol(3);

    // Стрельба из пистолета пять раз
    cout << "\nСтрельба из пистолета:" << endl;
    for (int i = 0; i < 5; i++) {
        pistol.shoot();
    }

    return 0;
}



#include <iostream>
#include <vector>
#include <iterator>
#include <string>

class Person {
protected: // Родитель для всех остальных классов
	std::string name;
	int age;
public:
	Person(std::string name, int age) {
		this->name = name;
		this->age = age;  //this - это указатель на объект классаБ который позволяет при одинаковых именах вызывать именно эту переменную
	}
	virtual void ShowData() = 0; // Функция которая относится также к другим классам
	
};

class Student : public Person {// 
private:
	std::vector<int>_marks;
public:
	Student(std::string name, int age, std::vector<int>&marks) : Person(name, age){	
		_marks = marks;
	}
	void ShowData() override { // Помогает понять что функция не новая, а из класса родителя
		std::cout << "Name: " << name << '\n';
		std::cout << "Age: " << age << '\n';
		std::cout << "Marks: ";
		for (const auto& it : _marks)
			std::cout << it << ", ";
		std::cout << std::endl;
	}

};

class Professor : public Person {
private:
	std::string _degree;
public:
	Professor(std::string name, int age, std::string degree) : Person(name, age) { 
		_degree = degree;
	}
	void ShowData() override {
		std::cout << "Name: " << name << '\n';
		std::cout << "Age: " << age << '\n';
		std::cout << "Degree: " << _degree << '\n';
	}

};
//	Наследование - когда у класса родителя берут его поля


int main() {
	setlocale(LC_ALL, "Ru");
	std::vector<int>marks = { 12, 5, 6, 4, 8, 12 };
	Student student1("John", 20, marks);
	Professor professor("Alex", 65, "Math doctor");
	student1.ShowData();
	std::cout << '\n';
	professor.ShowData();





	return 0;
}
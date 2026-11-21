#include <iostream>
using namespace std;

void copyText(char* to, const char* from) {
	int i = 0;
	while (from[i] != '\0') {
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';
}

bool sameText(const char* a, const char* b) {
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] != b[i]) return false;
		i++;
	}
	return a[i] == b[i];
}

class Book {
private:
	char author[100];
	char title[100];
	char publisher[100];
	int year;
	int quantity;
	int pages;

public:
	explicit Book(const char* author, const char* title, const char* publisher, int year, int quantity, int pages) {
		copyText(this->author, author);
		copyText(this->title, title);
		copyText(this->publisher, publisher);
		this->year = year;
		this->quantity = quantity;
		this->pages = pages;
	}

	const char* getAuthor() const {
		return author;
	}
	const char* getPublisher() const {
		return publisher;
	}
	int getYear() const {
		return year;
	}

	void print() const {
		cout << author << " | " << title << " | " << publisher << " | year: "
			<< year << " | quantity: " << quantity << " | pages: " << pages << endl;
	}
};


class Worker {
private:
	char fullName[100];
	char position[100];
	int startYear;
	int salary;

public:
	explicit Worker(const char* fullName, const char* position, int startYear, int salary) {
		copyText(this->fullName, fullName);
		copyText(this->position, position);
		this->startYear = startYear;
		this->salary = salary;
	}

	const char* getPosition() const {
		return position;
	}
	int getStartYear() const {
		return startYear;
	}
	int getSalary() const {
		return salary;
	}

	void print() const {
		cout << fullName << " | " << position << " | since " << startYear
			<< " | salary: " << salary << endl;
	}
};



int main()
{
	/* Task 1 

	const int SIZE = 5;
	Book books[SIZE] = {
		Book("Rowling", "Harry Potter", "Bloomsbury", 1997, 7, 320),
		Book("Jeff Kinney", "Diary of a Wimpy Kid", "Amulet Books", 2007, 21, 221),
		Book("J. R. R. Tolkien", "The Hobbit", "George Allen & Unwin", 1937, 1, 310),
		Book("Robert Louis Stevenson", "Treasure Island", "Cassell and Company", 1883, 1, 292),
		Book("J. K. Rowling", "The Christmas Pig", "Little, Brown", 2021, 1, 288)
	};

	cout << "All books:" << endl;
	for (int i = 0; i < SIZE; i++) {
		books[i].print();
	}

	char author[100];
	char publisher[100];
	int year;

	cout << "\nEnter author: ";
	cin.getline(author, 100);
	cout << "Books by " << author << ":" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (sameText(books[i].getAuthor(), author)) books[i].print();
	}

	cout << "\nEnter publisher: ";
	cin.getline(publisher, 100);
	cout << "Books by publisher " << publisher << ":" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (sameText(books[i].getPublisher(), publisher)) books[i].print();
	}

	cout << "\nEnter year: ";
	cin >> year;
	cout << "Books after " << year << ":" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (books[i].getYear() > year) books[i].print();
	}

	return 0;
	*/


	/* Task 2 */

	const int CURRENT_YEAR = 2026;
	const int SIZE = 5;
	Worker workers[SIZE] = {
		Worker("Marcus Thorne", "Administator", 2018, 4000),
		Worker("Liam O'Connor", "Tester", 2025, 1800),
		Worker("Mike Johnson", "Programmer", 2020, 2300),
		Worker("Amara Diallo", "Junior", 2026, 1900),
		Worker("Tom Takahashi", "Assistant", 2024, 1300)
	};

	cout << "All workers:" << endl;
	for (int i = 0; i < SIZE; i++) {
		workers[i].print();
	}

	int years;
	int salary;
	char position[100];

	cout << "\nEnter number of years: ";
	cin >> years;
	cout << "Workers with more than " << years << " years of experience:" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (CURRENT_YEAR - workers[i].getStartYear() > years) workers[i].print();
	}

	cout << "\nEnter salary: ";
	cin >> salary;
	cout << "Workers with salary more than " << salary << ":" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (workers[i].getSalary() > salary) workers[i].print();
	}

	cin.ignore();
	cout << "\nEnter position: ";
	cin.getline(position, 100);
	cout << "Workers with position " << position << ":" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (sameText(workers[i].getPosition(), position)) workers[i].print();
	}

	return 0;
}

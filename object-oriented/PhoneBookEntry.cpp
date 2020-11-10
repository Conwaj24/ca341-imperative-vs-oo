#pragma once
#include <string>
#include <iostream>

using namespace std;

class PhoneBookEntry {
	public:
		string name;
		string address;
		int number;

		PhoneBookEntry(string name, string address, int number) {
			this->name=name;
			this->address=address;
			this->number=number;
		}

		void display() {
			cout << name << endl
			<< address << endl
			<< number << endl;
		}
};

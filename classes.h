#ifndef branch_H2
#define branch_H2
#include <iostream>
#include <string>
#include <vector>
#include "cl_base.h"
class cl_2 :public cl_base {

public:
	cl_2(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор
	void signal_m(string path) { cout << endl << "Signal from " << path; };
	void handler_m(string path, string message) { cout << endl << "Signal to " << path << " Text:" << message << " (class: 2)";; }
};
class cl_3 :public cl_base {

public:
	cl_3(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор
	void signal_m(string path) { cout << endl << "Signal from " << path; };
	void handler_m(string path, string message) { cout << endl << "Signal to " << path << " Text:" << message << " (class: 3)"; }
};
class cl_4 :public cl_base {

public:
	cl_4(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор
	void signal_m(string path) { cout << endl << "Signal from " << path; };
	void handler_m(string path, string message) { cout << endl << "Signal to " << path << " Text:" << message << " (class: 4)"; }
};
class cl_5 :public cl_base {
public:
	cl_5(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор
	void signal_m(string path) { cout << endl << "Signal from " << path; };
	void handler_m(string path, string message) { cout << endl << "Signal to " << path << " Text:" << message << " (class: 5)"; }
};
class cl_6 :public cl_base {
public:
	cl_6(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор
	void signal_m(string path) { cout << endl << "Signal from " << path; };
	void handler_m(string path, string message) { cout << endl << "Signal to " << path << " Text:" << message << " (class: 6)"; }
};




#endif
#ifndef CL_BASE
#define CL_BASE
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(& signal_f )                // Макроопределение препроцессора
#define HANDLER_D( handler_f )(TYPE_HANDLER)( & handler_f )
class cl_base;
typedef void (cl_base ::* TYPE_SIGNAL) (string&);
typedef void (cl_base ::* TYPE_HANDLER) (string);       // Создание псевдонима для типа данных сигнала и обработчика
class cl_base {
private:
	string obj_name; // Имя объекта
	cl_base* p_head; // Указатель на головной объект
	int value = 1; // Поле состояния объекта
	int num_of_class = 1; // Поля для хранения номера класса объекта
	vector<cl_base*> childes; // Вектор наследников
	struct connection_strct {
		TYPE_SIGNAL pointer_signal;
		cl_base* obj_pointer;			// Структура связи
		TYPE_HANDLER pointer_handler;
	};
	vector <connection_strct*> connections; // Вектор связей 

public:


	void set_connection(TYPE_SIGNAL pointer_signal, cl_base* obj_pointer, TYPE_HANDLER ponter_handler); // Метод установки связи
	void emit_connection(TYPE_SIGNAL pointer_signal, string& command); // Метод для выдачи сигнала 
	void deleteTheConnection(TYPE_SIGNAL pointer_signal, cl_base* obj_pointer, TYPE_HANDLER pointer_handler); // Метод для удаления связи
	void set_all(); // Метод для установки готовности для всех объектов
	string get_path_of_obj(); // Метод получения абсолютного пути к объекту
	int getObjectNum();  // Метод получения номера класса текущего объекта 
	void setObjectNum(int num) { this->num_of_class = num; } // Сеттер номера класса
	virtual void signal_m(string path) { }; // Виртуальный метод-сигнал для выдачи сигнала
	virtual void handler_m(string path, string message) { }; // Виртуальный метод-обработчик для обработки поступающего сигнала
	void connect(cl_base* ob1, cl_base* ob2); // Метод установки связи между ob1 и ob2 с использованием set_connection (происходит учитывание номера класса)
	void deletec(cl_base* ob1, cl_base* ob2); // Метод для удаления связи между ob1 и ob2 с использованием deleteTheConnection (происходит учитывание номера класса)
	void emit(string message);
	cl_base* get_object_by_name2(string name,int i);
	void change_state(int value);

	cl_base(cl_base* p_head, string name = "root"); // Параметризированный конструктор
	void set_name(string name); // Сеттер имени объекта
	string get_name(); // Геттер имени объекта
	void print_tree(int num_of_tabs); // Метод для вывода дерева иерархии
	void set_p(cl_base* ptr); // Метод установки указателя на родителя
	cl_base* get_phead() { return this->p_head; }; // Метод для получения указателя на г.объект


	cl_base* get_object_by_name(string name); //Метод для определения указателя на объект по имени
	void Status_setter(string name_r); // Метод для формирования дерева готовности 
	void Print_status(int num_of_tabs);	// Метод для вывода дерева готовности
	int get_value() { return this->value; } // Геттер значения готовности
	void set_value(int value) { this->value = value; } // Сеттер значения готовности

	static cl_base* root; // Поле для хранения объекта root 
	cl_base* get_path(string name); // Метод для проверки координаты и получения указателя на родителя
	void get_by_path(); // Метод, реализующий работу функций find/set
	cl_base* koord_abs_relat(string name_of_p);
};
#endif 



















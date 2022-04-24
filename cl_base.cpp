#include "cl_base.h"
#include <iomanip>
cl_base* cl_base::root;
cl_base::cl_base(cl_base* p_head, string name) {
	this->obj_name = name; // Присваивание имени объекту
	if (p_head) { // Если не nullptr
		this->p_head = p_head;
		set_p(p_head);
	}
}
void cl_base::set_p(cl_base* ptr) {
	int size = p_head->childes.size(); // Размер массива наследников текущего гол.объекта
	for (int i = 0; i < size; i++) // Проход по всем потомкам родительского объекта и удаление объекта, который перестал подчиняться родительскому
	{
		if (p_head->childes[i] == this)
		{
			p_head->childes.erase(p_head->childes.begin() + i);
			break;
		}
	}
	p_head->childes.push_back(this); //Добавление указателя на текущий объект
	this->p_head = p_head;
}
cl_base* cl_base::get_object_by_name(string name) //Метод поиска объекта по имени
{
	if (this->childes.size() == 0 && this->get_name() != name) {
		return nullptr;// Если это крайний элемент, который не подходит
	}
	if (this->get_name() == name) // Если имя текущего объекта совпадает с требуемым
		return this;
	for (int i = 0; i < this->childes.size(); i++)
		if (this->childes[i]->get_object_by_name(name) != nullptr) // Поиск среди дочерних
			return this->childes[i]->get_object_by_name(name);
	return nullptr;
}
void cl_base::set_name(string name) {
	this->obj_name = name; // Установка имени объекта
}
string cl_base::get_name() {
	return obj_name; // Возврат имени объекта
}

void cl_base::print_tree(int num_of_tabs) {
	string tabulaion = string(num_of_tabs * 4, ' '); // Определение отступа

	for (int i = 0; i < this->childes.size(); i++) {
		cout << endl << tabulaion << this->childes[i]->get_name();   //Вывод имени
		if (this->childes[i]->childes.size() != 0) {
			this->childes[i]->print_tree(num_of_tabs + 1); // Рекурсивный вызов функции для наследников
		}
	}
}

void cl_base::Status_setter(string name_r) {
	string name;
	int temp;
	while (cin >> name >> temp) {
		cl_base* obj = get_object_by_name(name);
		if (name_r == name)
			obj->set_value(temp); // Установка значения для головного объекта
		else {
			if (obj->get_phead() != nullptr) {
				if (obj->get_phead()->get_value() == 0) // Если объект выше по иерархии не активирован-установка 0
					obj->set_value(0);
				else
					obj->set_value(temp); // Иначе установка заданного значения 
			}
		}
	}
}
void cl_base::Print_status(int num_of_tabs) {
	string tabulaion = string(num_of_tabs * 4, ' '); //Определение отступа
	for (int i = 0; i < this->childes.size(); i++)
	{
		if (this->childes[i]->get_value() == 0) {
			cout << endl << tabulaion << this->childes[i]->get_name() << " is not ready"; //Если состояние равно 0
		}
		else {
			cout << endl << tabulaion << this->childes[i]->get_name() << " is ready";//Если состояние отлично от 0
		}
		if (this->childes[i]->childes.size() != 0)
		{
			this->childes[i]->Print_status(num_of_tabs + 1); //Рекурсивный вызов для наследников
		}
	}
}


void cl_base::get_by_path() {

	string command, path;
	cl_base* current = this, * object = nullptr;
	cin >> command;
	while (command != "END") {
		cin >> path;
		if (path=="/")
			object=cl_base::root;
		else
			object = current->get_path(path);
		string temp_path = path;
		if (command == "FIND") {
			if (object)
				cout << endl << temp_path << "     Object name: " << object->get_name();
			else
				cout << endl << temp_path << "     Object is not found";
		}
		else if (command == "SET") {
			if (object) {
				current = object;
				cout << endl << "Object is set: " << current->get_name();

			}
			else
				cout << endl << "Object is not found: " << current->get_name() << " " << path;

		}
		cin >> command;
	}
}
cl_base* cl_base::get_path(string name_of_p) {
	cl_base* parent = nullptr;
	int index;
	cl_base* current = this;
	string name_of_p2;
	if (name_of_p[0] == '/') {
		if (name_of_p.length() == 1) {
			parent = cl_base::root;
		}	
		else if (name_of_p[1] == '/') {
			parent = (cl_base::root)->get_object_by_name(name_of_p.substr(2, name_of_p.length() - 1));
		}
		else 
			parent = cl_base::root->koord_abs_relat(name_of_p);
		}
	else if (name_of_p == ".") {
		parent = current;
	}
	else {
		parent = current->koord_abs_relat('/' + name_of_p);
	}
	return parent;
}
cl_base* cl_base::koord_abs_relat(string name_of_p) {
	cl_base* current = this;
	int index;
	string name_of_p2;
	cl_base* parent=nullptr;
	name_of_p.erase(0, 1);
	while (name_of_p.length() != 0) {
		index = name_of_p.find("/");
		index = -1 ? index : name_of_p.length();
		name_of_p2 = name_of_p.substr(0, index);
		name_of_p.erase(0, name_of_p2.length() + 1);
		cl_base* head = current->get_object_by_name(name_of_p2);
		current = head;
		if (current == nullptr) return nullptr;
		if (current->get_object_by_name(name_of_p2) == nullptr) {
			parent = nullptr;
		}
		else
			parent = current->get_object_by_name(name_of_p2);

	}
	return parent;
}
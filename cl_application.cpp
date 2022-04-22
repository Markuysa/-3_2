#include "cl_application.h"
#include "cl_branch.h"
#include "classes.h"
void application::build_Tree() {
	string name_of_p, name_of_ch,name_temp; // Вводимые имена 
	int temp;
	cin >> name_of_p;
	this->set_name(name_of_p);
	cl_base* head = this, * br = nullptr; // Создание головного объекта
	cin >> name_of_p;
	cl_base* parent=nullptr;
	while (name_of_p != "endtree") {
		string name_of_p2;	
		name_temp = name_of_p;
		if (name_of_p.length() == 1 && name_of_p == "/") {
			name_of_p2 = this->get_name();							//Если путь состоит из одного слеша, то родитель - root
			parent = get_object_by_name(name_of_p2);
		}
		else{
			parent = get_path(name_of_p);
		}
		cin >> name_of_ch >> temp;
		if (parent != nullptr) {
			switch (temp)
			{
			case 2:
				br = new cl_2(parent, name_of_ch);
				break;
			case 3:
				br = new cl_3(parent, name_of_ch);
				break;
			case 4:
				br = new cl_4(parent, name_of_ch);  //Определение заданного номера класса
				break;
			case 5:
				br = new cl_5(parent, name_of_ch);
				break;
			case 6:
				br = new cl_6(parent, name_of_ch);
				break;
			}
			cin >> name_of_p;
		}
		else {
			cout << "Object tree" << endl;
			this->print_tree(1);
			cout << "The head object " << name_temp << " is not found" << endl;
			break;
		}

	}

}
int application::executeApp() {
	cout << "Object tree\n" << this->get_name() << endl;
	this->print_tree(1); // Вызов метода для вывода дерева иерархии
	this->get_by_path();
	return 0;

}
cl_base* cl_base::get_path(string name_of_p) {
	int index;
	string name_of_p2;
	cl_base* parent;
	name_of_p.erase(0, 1);
	index = name_of_p.find("/");
	index = -1 ? index : name_of_p.length();    // Отделение первого имени пути
	name_of_p2 = name_of_p.substr(0, index);
	cl_base* head = get_object_by_name(name_of_p2);
	if (head == nullptr) {
		parent = nullptr;   // Если первое имя в пути не найдено 
	}
	else { parent = head; }
	name_of_p.erase(0, name_of_p2.length() + 1);
	if (parent) {							// Если первое имя пути найдено, то выполнить проверку на все остальные
		while (name_of_p.length() != 0) {
			index = name_of_p.find("/");
			index = -1 ? index : name_of_p.length();
			name_of_p2 = name_of_p.substr(0, index);
			name_of_p.erase(0, name_of_p2.length() + 1);
			if (head->get_object_by_name(name_of_p2) == nullptr) {
				parent = nullptr;
				break;
			}
			else
				parent = head->get_object_by_name(name_of_p2);
		}
	}
	return parent;
}


























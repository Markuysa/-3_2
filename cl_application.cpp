#include "cl_application.h"
#include "cl_branch.h"
#include "classes.h"

bool application::build_Tree() {
	string name_of_p, name_of_ch, name_temp; // Вводимые имена 
	int temp;
	cin >> name_of_p;
	this->set_name(name_of_p);
	cl_base::root = this;
	cin >> name_of_p;
	cl_base* parent = nullptr, * br = nullptr;
	while (name_of_p != "endtree") {
		parent = get_path(name_of_p);
		string name_of_p2;
		name_temp = name_of_p;
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
			cout << "Object tree";
			this->print_tree(1);
			cout << endl << "The head object " << name_temp << " is not found";
			return false;
		}

	}
	return true;
}
int application::executeApp(bool checker) {
	cout << "Object tree\n" << this->get_name();
	if (checker) {
		this->print_tree(1); // Вызов метода для вывода дерева иерархии
		this->get_by_path();
	}
	return 0;

}




































































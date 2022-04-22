#ifndef CL_application
#define CL_application
#include "cl_base.h"
#include <iostream>
#include <string>
#include <vector>
class application : public cl_base {
public:
	application(cl_base* root) : cl_base(root) { };
	void build_Tree(); // Метод построения дерева иерархии
	int executeApp(); // Метод запуска алгоритма программы
};
#endif

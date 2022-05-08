#ifndef CL_application
#define CL_application
#include "cl_base.h"
#include <iostream>
#include <string>
#include <vector>
class application : public cl_base {
public:
	application(cl_base* root) : cl_base(root) { };
	bool build_Tree(); // Метод построения дерева иерархии
	void build_connections();
	int executeApp(bool checker); // Метод запуска алгоритма программы
};
#endif

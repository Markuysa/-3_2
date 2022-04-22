#ifndef branch_H
#define branch_H
#include <iostream>
#include <string>
#include <vector>
#include "cl_base.h"
class cl_branch :public cl_base {

public:

	cl_branch(cl_base* root, string name) :cl_base(root, name) {}; // Наследованный от базового класса параметризированный коснструктор
};
#endif
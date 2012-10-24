#ifndef TEST_H
#define TEST_H
#include "Logic.h"
using namespace DS14;
class test : public logic
{
public:
	test():logic(){};
	void test_init(int i);
	int test_update(DS14::PlayerCommand * AIcommand, int test_number);
};


#endif
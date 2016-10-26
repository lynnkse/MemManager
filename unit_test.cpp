#include "mu_test.h"
#include "MemPage_t.h"
#include "MemPool_t.h"
#include "MemManager_t.h"
#include <iostream>

using namespace std;

UNIT(page_simple)
	MemPage_t page;
	ASSERT_THAT(!page.IsFull());
	ASSERT_THAT(page.IsEmpty());
	ASSERT_THAT(page.GetActualSize() == 0);
	ASSERT_THAT(page.GetCapacity() == 6);
	ASSERT_THAT(page.GetPos() == 0);
END_UNIT

UNIT(insert_int)
	MemPage_t page;
	int num = 7;
	ASSERT_THAT(page.MemWrite(&num, sizeof(int)) == sizeof(int));
	ASSERT_THAT(page.GetPos() == 4);
	ASSERT_THAT(page.GetActualSize() == sizeof(int));
	ASSERT_THAT(!page.IsFull());
	ASSERT_THAT(!page.IsEmpty());	
END_UNIT

UNIT(insert_two_ints)
	MemPage_t page;
	int num1 = 7, num2 = 8;
	ASSERT_THAT(page.MemWrite(&num1, sizeof(int)) == sizeof(int));
	ASSERT_THAT(page.MemWrite(&num2, sizeof(int)) == 2);
	ASSERT_THAT(page.GetActualSize() == page.GetCapacity());
	ASSERT_THAT(page.GetPos() == 6);
	ASSERT_THAT(page.IsFull());
	ASSERT_THAT(!page.IsEmpty());	
END_UNIT

UNIT(write_and_read_int)
	MemPage_t page;
	int num = 7, res;
	ASSERT_THAT(page.MemWrite(&num, sizeof(int)) == sizeof(int));
	cout << "New pos:" << page.GetPos() << endl;
	page.MemRead(&res, sizeof(int));
	ASSERT_THAT(res != 7);
	page.SetPos(0);
	page.MemRead(&res, sizeof(int));
	cout << "Pos after read:" << page.GetPos() << endl;
	cout << "Read:" << res << endl;
	ASSERT_THAT(res == 7);
END_UNIT

UNIT(write_and_read_int_on_set_pos)
	MemPage_t page;
	int num = 7;//, res;
	ASSERT_THAT(page.MemWrite(&num, sizeof(int)) == sizeof(int));
	ASSERT_THAT(page.MemWrite(&num, sizeof(int)) == 2);
	//ASSERT_THAT(page.MemWrite(&num, sizeof(int), 2) == sizeof(int));
	cout << page.MemWrite(&num, sizeof(int), 2) << endl;
END_UNIT

TEST_SUITE(Memory manager tests)
	TEST(page_simple)
	TEST(insert_int)
	TEST(insert_two_ints)
	TEST(write_and_read_int)
	TEST(write_and_read_int_on_set_pos)
END_SUITE





























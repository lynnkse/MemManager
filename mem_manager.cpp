#include "MemPage_t.h"
#include "MemManager_t.h"
#include "MemPool_t.h"
#include <iostream>

using namespace std;

int Run();

int main()
{
	Run();
	
	return 0;
}

int Run()
{
	int choice = 1;
	int num;
	MemPool_t pool;
	MemManager_t& manager = pool;
	
	while(choice)
	{
		cout << "Choose option:" << endl << "1. Set position" << endl
										 << "2. Write int" << endl
										 << "3. Read int" << endl
										 << endl << endl;
		cin >> choice;
	
		switch(choice)
		{
			case 1:
				size_t pos;
				cout << "Enter position..." << endl;
				cin >> pos;
				cout << (manager.SetPos(pos) == MemManager_t::MEM_SUCCESS ? "Possition set" : "Failure!") << endl;
				break;
			case 2:
				cout << "Enter integer..." << endl;
				cin >> num;
				if(manager.MemWrite(&num, sizeof(int)) != sizeof(int))
				{
					cout << "Error occured!" << endl;
				}
				else
				{
					cout << "Done!" << endl;
				}	
				break;
			case 3:		
				if(manager.MemRead((void*) &num, sizeof(int)) != sizeof(int))
				{
					cout << "Error occured!" << endl;
				}
				else
				{
					cout << "Integer read: " << num << endl;
				}
			case 0:
				break;
		}
	}
	
	return 0;
}

#include <vector>
#include "MemPage_t.h"

using namespace std;

class MemPool_t : public MemManager_t
{
	public:
		MemPool_t();
		~MemPool_t();
		virtual size_t MemWrite(void* _data, size_t _dataSize, size_t _pos) = 0;
		virtual size_t MemWrite(void* _data, size_t _dataSize);
		virtual size_t MemRead(void** _data, size_t _dataSize, size_t _pos);
		virtual size_t MemRead(void** _data, size_t _dataSize);
		void SetDefaultPageSize();
	private:
		MemPool_t(MemPool_t& _memPool);
		void operator=(MemPool_t& _memPool);
		
		size_t m_defaultPageSize;
		vector<MemPage_t> m_pages;
};

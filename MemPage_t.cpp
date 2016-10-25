#define DEFAULT_PAGE_SIZE 6

size_t MemPage_t::m_defaultPageSize = DEFAULT_PAGE_SIZE;

MemPage_t::MemPage_t(): m_capacity(m_defaultPageSize)
{
	m_data = new char[m_capacity];
}

MemPage_t::MemPage_t(size_t _pageSize): m_capacity(_pageSize)
{
	m_data = new char[m_capacity];
}

MemPage_t::~MemPage_t()
{
	delete[] m_data;
}

size_t MemPage_t::MemWrite(void* _data, size_t _dataSize, size_t _pos)
{
	size_t numOfBytesToWrite = m_capacity - (GetPos() + 1);
	numOfBytesToWrite < _dataSize ? numOfBytesToWrite : _dataSize; 
	size_t newActualSize = (GetActualSize() + numOfBytesToWrite <= m_capacity ? GetActualSize() + numOfBytesToWrite : m_capacity);
	
	memcpy(m_data + _pos, _data, numOfBytesToWrite);
	
	SetActualSize(newActualSize);
	SetPos(GetPos() + numOfBytesToWrite);
	
	return numOfBytesToWrite;
}

size_t MemPage_t::MemWrite(void* _data, size_t _dataSize)
{
	MemWrite(_data, _dataSize, GetPos());
}

size_t MemRead(void** _data, size_t _dataSize, size_t _pos)
{
	size_t numOfBytesToRead = m_capacity - (GetPos() + 1);
	numOfBytesToRead < _dataSize ? numOfBytesToRead : _dataSize; 
	
	memcpy();
}









































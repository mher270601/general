#ifndef __UNIQUE__ID__GENERATOR__IMPL__CPP__
#define __UNIQUE__ID__GENERATOR__IMPL__CPP__

UniqueIdGenerator::UniqueIdGenerator(){ // Ctor

}
size_t UniqueIdGenerator::m_counter{0};
	
size_t UniqueIdGenerator::GenerateId(){
	return m_counter++;
}

#endif // __UNIQUE__ID__GENERATOR__IMPL__CPP__

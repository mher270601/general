#ifndef __IOBJECT__IMPL__CPP__
#define __IOBJECT__IMPL__CPP__

#include <string>

namespace PowerPoint{

	IObject::IObject(const std::string& objectName) : ASimpleObject(objectName){
	}

	//inline std::string IObject::getName() const noexcept{
	//	return m_name;
	//}

        void IObject::MoveRight(const size_t plusX){
		m_data.m_coords.x += plusX;
	}
        
	void IObject::MoveLeft(const size_t minusX){
		m_data.m_coords.x -= minusX;
	}
        
	void IObject::MoveTop(const size_t plusY){
		m_data.m_coords.y += plusY;
	}
        
	void IObject::MoveBottom(const size_t minusY){
		m_data.m_coords.y -= minusY;
	}

	//inline size_t IObject::GetIdentifier() const noexcept{
	//	return m_Identifier;
	//}

} // napespace __IOBJECT__IMPL__CPP__

#endif // __IOBJECT__IMPL__CPP__

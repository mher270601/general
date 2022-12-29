#ifndef __IOBJECT__HPP__
#define __IOBJECT__HPP__

#include "IObservable.hpp"

class IObject : public IObservable<IObject>{
public:
	virtual std::string Name() const noexcept = 0;
protected:
	virtual ~IObject() = default;
};
#endif // __IOBJECT__HPP__

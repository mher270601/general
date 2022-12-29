#ifndef __PRICE__HPP__
#define __PRICE__HPP__

struct Price{
	size_t price{0};
	Price(size_t _price) : price(_price) {}
	Price() = default;
	Price(const Price& rhs){
		price = rhs.price;
	}
};

#endif // __PRICE__HPP__

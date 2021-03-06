#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include "visitor.hpp"
class Rand : public Base {
    public:
	Rand() : Base() {   }
	virtual double evaluate() { 
	    val = rand() % 100;
	    return val; 
	}
	virtual std::string stringify() { return std::to_string(val);}
	virtual int number_of_children() { return 0; }
	virtual Base* get_child(int i) { return nullptr; }
	virtual void accept(Visitor* visitor, int index) {
		visitor->visit_rand(this);
	}

    private:
	double val;
};

#endif //__RAND_HPP__

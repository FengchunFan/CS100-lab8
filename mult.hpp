#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    public:
	Mult(Base* lhs, Base* rhs) : Base() { 
	    leftVal = lhs;
	    rightVal = rhs;
	}
	virtual double evaluate() {
	    return (leftVal->evaluate()) * (rightVal->evaluate()); 
	}
	virtual std::string stringify() {
	    return ("(" + leftVal->stringify() + "*" + rightVal->stringify() + ")"); 
	}

        virtual int number_of_children() {
               int num = 0;
               if(leftVal!= nullptr)
                        ++num;
                if(rightVal!= nullptr)
                        ++num;
                return num;
        }

        virtual Base* get_child(int i) {
                if(i < number_of_children()){
                        if(i == 0){
                                return leftVal;
                        }
                        if(i == 1){
                                return rightVal;
                        }
                }

        }


    private:
	Base* leftVal = nullptr;
	Base* rightVal = nullptr;

};

#endif // __MULT_HPP__

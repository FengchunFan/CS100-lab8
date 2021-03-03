#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    public:
        Div(Base* lhs, Base* rhs) : Base() {
            leftVal = lhs;
            rightVal = rhs;
        }
        virtual double evaluate() {
	    if(rightVal->evaluate() != 0) {
                return (leftVal->evaluate()) / (rightVal->evaluate());
	    }
	    else {
		return -1;
	    }
        }
        virtual std::string stringify() {
            return ("(" + leftVal->stringify() + "/" + rightVal->stringify() + ")");
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

#endif //__DIV_HPP__

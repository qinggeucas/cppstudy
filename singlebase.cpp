#include<iostream>
using namespace std;

class Base {
	public: virtual void func1();
	public: virtual void func2();
	public: void setB(int);
    protected : int b;
 //   private : int i;
    protected : char i;
};

void Base::func1() {
	if(this == NULL) {
		cout << "this == NULL" << endl;
	}else{
		cout << this << endl;
	}
	cout << "----------- " << this->b<<endl;
	cout<<"Base::func1()"<<endl;
}

void Base::func2() {
	if(this == NULL) {
		cout << "this == NULL" << endl;
	}else{
		cout << this << endl;
	}
	cout<<"Base::func2()"<<endl;
}

void Base::setB(int cur) {
    this->b = cur;
}

class Derive : public Base {
	public: virtual void func1();
	public: virtual void func3();
    public: void func4();
};

void Derive::func1() {
	if(this == NULL) {
		cout << "this == NULL" << endl;
	}else{
		cout << this << endl;
	}
	cout << "*********** " << this->b<<endl;
	cout<<"Derive::func1()"<<endl;
}

void Derive::func3() {
	if(this == NULL) {
		cout << "this == NULL" << endl;
	}else{
		cout << this << endl;
	}
	cout<<"Derive::func3()"<<endl;
}

void Derive::func4() {
	if(this == NULL) {
		cout << "this == NULL" << endl;
	}else{
		cout << this << endl;
	}
    cout<<"Derive::func4()"<<endl;
}

typedef void (*FUNC)(Base*);

void PrintVF(long* slot, int num, Base* b) {
	cout << "start..." << endl;
    if(slot == NULL) {
		return;
	}	
	//for (long i = 0; slot[i] != 0; ++i) {
	for (long i = 0; i < num; ++i) {
		FUNC f = (FUNC)slot[i];
		f(b);
	}
	cout << "end..." << endl;
}

int main() {
	cout << "size of int: " << sizeof(int) <<endl;
	cout << "size of char: " << sizeof(char) <<endl;
	cout << "size of int*: " << sizeof(int*) <<endl;
	cout << "size of long: " << sizeof(long) <<endl;
    Base *b = new Base();	
    Base *tb = new Base();	
	b->setB(10101);
	Derive *d = new Derive();
	d->setB(20202);
    long *vb = (long*)(*(long*)b);
	cout << "the addr of b : " << (long*)b << endl;
	cout << "the addr of b vfptr : " <<(*(long*)b) << endl;
	cout << "the addr of tb : " << (long*)tb << endl;
	cout << "the addr of tb vfptr : " <<(*(long*)tb) << endl;
	cout << "the addr of d : " << (long*)d << endl;
	cout << "the addr of d vfptr : " <<(*(long*)d) << endl;
	PrintVF(vb, 2, b);
	long *vd = (long*)(*(long*)d);
	PrintVF(vd, 3, b);

    long *longHead = (long*)b;
	cout << *longHead << endl;
	longHead++;
	cout << *longHead << endl;

	cout << "size of Base:" << sizeof(Base) <<endl;
	cout << "size of Derive:" << sizeof(Derive) <<endl;

	cout << "pointer size:" << sizeof(void*) <<endl;

	return 1;
}

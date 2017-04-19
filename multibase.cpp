#include<iostream>
using namespace std;

class Base1 {
	public: virtual void func1();
	public: virtual void func2();
    protected : int b;
};

void Base1::func1() {
	cout<<"Base1::func1()"<<endl;
}

void Base1::func2() {
	cout<<"Base1::func2()"<<endl;
}

class Base2 {
	public: virtual void func1();
	public: virtual void func2();
    protected : int b2;
};

void Base2::func1() {
	cout<<"Base2::func1()"<<endl;
}

void Base2::func2() {
	cout<<"Base2::func2()"<<endl;
}

class Derive : public Base1, public Base2 {
	public: virtual void func1();
	public: virtual void func3();
    public: void func4();
};

void Derive::func1() {
	cout<<"Derive::func1()"<<endl;
}

void Derive::func3() {
	cout<<"Derive::func3()"<<endl;
}

void Derive::func4() {
    cout<<"Derive::func4()"<<endl;
}

typedef void (*FUNC)();

void PrintVF(long* slot, int num) {
	cout << "start..." << endl;
    if(slot == NULL) {
		return;
	}	
	//for (long i = 0; slot[i] != 0; ++i) {
	for (long i = 0; i < num; ++i) {
		FUNC f = (FUNC)slot[i];
		f();
	}
	cout << "end..." << endl;
}

int main() {
	Derive *d = new Derive();
	// base1 
    long* b1vfstart = (long*)(*(long*)d);
	PrintVF(b1vfstart, 3);

	// base2
    long* b2vfstart = (long*)(*((long*)((Base2*)d)));
	PrintVF(b2vfstart, 2);

    long *b2 = (long*)((Base2*)d);
	long *b22 = (long*)((char*)d + sizeof(Base1));
	long *b23 = (long*)d + sizeof(Base1)/sizeof(long);
    cout << b2 <<endl; 	
    cout << b22 <<endl; 	
    cout << b23 <<endl; 	
	return 1;
}

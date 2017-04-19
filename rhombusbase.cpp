#include<iostream>
using namespace std;

class Base {
	public: virtual void func1();
	public: virtual void func2();
	public: virtual void func5();
    protected : int b;
};

void Base::func1() {
	cout<<"Base::func1()"<<endl;
}

void Base::func2() {
	cout<<"Base::func2()"<<endl;
}

void Base::func5() {
	cout<<"Base::func5()"<<endl;
}

class Base1 : public virtual Base {
	public: virtual void func1();
	public: virtual void func2();
	public: virtual void func7();
    protected : int b;
};

void Base1::func1() {
	cout<<"Base1::func1()"<<endl;
}

void Base1::func2() {
	cout<<"Base1::func2()"<<endl;
}

void Base1::func7() {
	cout<<"Base1::func7()"<<endl;
}

class Base2 : public virtual Base {
	public: virtual void func1();
	public: virtual void func2();
	public: virtual void func6();
    protected : int b2;
};

void Base2::func1() {
	cout<<"Base2::func1()"<<endl;
}

void Base2::func2() {
	cout<<"Base2::func2()"<<endl;
}

void Base2::func6() {
	cout<<"Base2::func6()"<<endl;
}

class Derive : public Base1, public Base2 {
	public: virtual void func1();
	public: virtual void func2();
	public: virtual void func3();
    public: void func4();
};

void Derive::func1() {
	cout<<"Derive::func1()"<<endl;
}

void Derive::func2() {
	cout<<"Derive::func2()"<<endl;
}

void Derive::func3() {
	cout<<"Derive::func3()"<<endl;
}

void Derive::func4() {
    cout<<"Derive::func4()"<<endl;
}

typedef void (*FUNC)();

void PrintVF(long* slot, int num) {
		cout << "-----------------------------" << slot << endl;
	cout << "start..." << endl;
    if(slot == NULL) {
		return;
	}	
	//for (long i = 0; slot[i] != 0; ++i) {
	for (int i = 0; i < num; ++i) {
		FUNC f = (FUNC)slot[i];
		f();
	}

	/*
	for (int i = 1; i <= bnum; i++) {
		cout << slot[-1 * i] << endl;
	}
	*/

	cout << "end..." << endl;
}

int main() {
	Derive *d = new Derive();
    long *vptrSlot0 = (long*)(*((long*)d));
	PrintVF(vptrSlot0, 4);

	if (d == (Base1*)d) {
		cout << "addr equal!!!" << endl;
	}else{
		cout << "addr not equal!!!" << endl;
	}

	cout << ((long*)(Base1*)d) << endl;
	cout << vptrSlot0 << endl;

	if (((long*)(Base1*)d) == vptrSlot0) {
		cout << "equal!!!" << endl;
	}else {
		cout << "not equal!!!" << endl;
	}

	cout << "d    : " << d << endl;
	cout << "base1: " << (Base1*)d << endl;
	cout << "base2: " << (Base2*)d << endl;
	cout << "base : " << (Base*)d << endl;

	cout << "size of Derive: " << sizeof(Derive) << endl;
	cout << "size of Base1: " << sizeof(Base1) << endl;
	cout << "size of Base2: " << sizeof(Base2) << endl;
	cout << "size of Base: " << sizeof(Base) << endl;

    long* dhead = (long*)d;
	long* base1Head = (long*)((char*)(dhead)+sizeof(long));
	cout << "d     Head: " << dhead<<endl;
	cout << "base  Head: " << (Base*)d << endl;
	cout << "base1 Head: " << (Base1*)d << endl;
//	cout << "base1 Head: " << base1Head << endl;
	long* base2Head = base1Head + sizeof(Base1)/sizeof(long);
	cout << "base2 Head: " << (Base2*)d << endl;
//	cout << "base2 Head: " << base2Head << endl;
    PrintVF((long*)(*((long*)(Base1*)d)), 4);
    PrintVF((long*)(*((long*)(Base2*)d)), 3);
    PrintVF((long*)(*((long*)(Base*)d)), 3);

	return 1;
}

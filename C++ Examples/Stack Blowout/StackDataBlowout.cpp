#include <iostream>

struct B
{
	char b[1021186];
};

struct X
{
	char x[0x10000];
};

struct S
{
	char s;
};

struct A
{
	char a[1];
};

void PassByLoopValue(X x1)
{
	x1.x[0] = 'E';
}

void PassByLoopRefNew(X & x)
{
	x = *new X();
}

void PassBySafeDeleteRefNew(X & x)
{
	x.x[0] = 'H';
	X *ptr = new X();
	ptr->x[0] = 'N';
	x.x[0] = (*ptr).x[0];
	x.x[0] = ptr->x[0];
	delete ptr;
}

void PassByLoopPtrNew(X * x)
{
	x = new X();
}

void PassByValue(X x1, X x2, X x3, X x4, X x5, X x6, X x7, X x8, X x9, X x10, X x11, X x12, X x13, X x14, X x15, X x16)
{
	x1.x[0] = 'V';
	x5.x[0] = 'A';
	x10.x[0] = 'L';
}

void PassByReference(X &x1, X &x2, X &x3, X &x4, X &x5, X &x6, X &x7, X &x8, X &x9, X &x10, X &x11, X &x12, X &x13, X &x14, X &x15, X &x16)
{
	x1.x[0] = 'V';
	x5.x[0] = 'A';
	x10.x[0] = 'L';
}

void PassByPointer(X *x1, X *x2, X *x3, X *x4, X *x5, X *x6, X *x7, X *x8, X *x9, X *x10, X *x11, X *x12, X *x13, X *x14, X *x15, X *x16)
{
	x1->x[0] = 'V';
	x5->x[0] = 'A';
	x10->x[0] = 'L';
}

void Pass8_ByValue(X x1, X x2, X x3, X x4, X x5, X x6, X x7, X x8)
{
	x1.x[0] = '!';
}

void SendPassBy8(X x)
{
	Pass8_ByValue(x, x, x, x, x, x, x, x);
}

void VoidRecursiveByValue(X x, int count)
{
	if (--count > 0)
		VoidRecursiveByValue(x, count);
	return;
}

void VoidRecursiveByReference(const X &x, int count)
{
	if (--count > 0)
		VoidRecursiveByReference(x, count);
	return;
}

void VoidRecursiveByReference(A &a, int count)
{
	if (--count > 0)
		VoidRecursiveByReference(a, count);
	return;
}

void VoidRecursiveByReference(S &s, int count)
{
	if (--count > 0)
		VoidRecursiveByReference(s, count);
	return;
}

void VoidRecursiveByPointer(X *x, int count)
{
	if (--count > 0)
		VoidRecursiveByPointer(x, count);
	return;
}

void VoidRecursiveByArrayPointer(char * c, int count)
{
	if (--count > 0)
		VoidRecursiveByArrayPointer(c, count);
	return;
}

void VoidRecursiveByValueReference(char & c, int count)
{
	if (--count > 0)
		VoidRecursiveByValueReference(c, count);
	return;
}

void VoidRecursiveCounter(int count)
{
	//std::cout << "Hello Counter!" << std::endl;
	if (--count > 0)
		VoidRecursiveCounter(count);
}

void VoidRecursiveCounterRef(int & count)
{
	//std::cout << "Hello Counter!" << std::endl;
	if (--count > 0)
		VoidRecursiveCounter(count);
}

X& RecursiveRefReturnByRef(X & ref, int count)
{
	if (--count > 0)
		RecursiveRefReturnByRef(ref, count);
	return ref;
}

A RecursRef(A & ref, int count)
{
	if (--count > 0)
		RecursRef(ref, count);
	return ref;
}

static int VALUE;

void FullVoidRecursion()
{
	while (--VALUE > 0)
		FullVoidRecursion();
}

int main()
{
	X x;
	RecursiveRefReturnByRef(x, 3500);

	system("pause");
	return 0;
}
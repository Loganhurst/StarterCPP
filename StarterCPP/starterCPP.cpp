#include <iostream>
// starter CPP that can be used with VS
//  to make it work with an online compiler, copy out the stdafx.h

#include "stdafx.h"
#include <iostream>

using std::cout;
using std::endl;

class Book
{
public:
	Book();
	~Book();
private:
	std::string m_title;
	double m_id;
	bool m_out;
};
Book::Book()
{
	m_title = "";
	m_id = 0;
	m_out = false;
}
Book::~Book()
{
	cout << "Destructor" << endl;
	//delete[] Book;
}

int main()
{

	Book witcher();
	Book LOTR;
	Book Halo;

	Book books[10];

	return 0;
}
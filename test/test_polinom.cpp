#include "gtest.h"
#include "polinom.h"
#include "monom.h"
#include "list.h"
int i = -1;
int j = -1;
int k = -1;
int n = -1;
int l = -1;
// ����� ������� � ���������
TEST(list, insert_to_end) // ������� � �����
{
	monom a(12, 14);
	monom b(14, 43);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.reset();
	monom res(l.getcurrentdate());
	EXPECT_EQ(res,a);

}

TEST(list, can_create_list) // ����� ������� ����
{
	EXPECT_NO_THROW(list<monom> l);
}

TEST(list, delete_last_not_empty_list) // �������� �� ������� �����
{
	monom a(12, 14);
	monom b(14, 43);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.clear();
	EXPECT_EQ(l.IsEmpty(), 1);
}

TEST(list, can_check_is_empty) // �������� �� ������� �� ������� �����
{
	monom a(12, 14);
	monom b(14, 43);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	EXPECT_EQ(0, l.IsEmpty());
}

TEST(list, can_check_is_empty_if_empty) // �������� �� ������� ������� �����
{
	list<monom> l;
	EXPECT_EQ(1, l.IsEmpty());
}


TEST(list, operator_ravno_for_list) // �������� ���������  = 
{
	monom a(12, 14);
	monom b(14, 43);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	list<monom> z = l;
	EXPECT_EQ(z,l);
}

TEST(list, operator_ravno_for_list2)
{
	monom a(12, 14);
	monom b(14, 43);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	list<monom> z = l;
	if (l == z)
		EXPECT_EQ(l, z);
}

TEST(list, operator_ravno_for_list3)
{
	monom a(12, 14);
	monom b(14, 43);
	monom c(11, 123);
	monom d(12, 1232);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	list<monom> z = l;
	if (l == z)
		EXPECT_EQ(l, z);
}
//dellcurent
TEST(list, Dellcurent_first)
{
	monom a(12, 14);
	monom b(14, 43);
	monom c(11, 123);
	monom d(12, 1232);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.reset();
	l.Dellcurrent();
	EXPECT_EQ(l.getcurrentdate(), b);
}

TEST(list, Dellcurent_last)
{
	monom a(12, 14);
	monom b(14, 43);
	monom c(11, 123);
	monom d(12, 1232);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.getnext();
	l.Dellcurrent();
	EXPECT_EQ(l.getcurrentdate(), c);
}

TEST(list, Dellcurent_middle)
{
	monom a(12, 14);
	monom b(14, 43);
	monom c(11, 123);
	monom d(12, 1232);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.Dellcurrent();
	EXPECT_EQ(l.getcurrentdate(), b);
}

TEST(list, Dellcurent_first_must_empty)
{
	monom a(12, 14);
	list<monom> l;
	l.Insert_to_tail(a);
	l.reset();
	l.Dellcurrent();
	EXPECT_EQ(l.IsEmpty(),1);
}

TEST(list, can_get_currnextdata)
{
	monom a(12, 14);
	monom b(14, 43);
	monom c(11, 123);
	monom d(12, 1232);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	EXPECT_EQ(l.getcurrentnextdata(), d);

}

TEST(list, can_get_currdata)
{
	monom a(12, 14);
	monom b(14, 43);
	monom c(11, 123);
	monom d(12, 1232);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	EXPECT_EQ(l.getcurrentdate(), c);

}

TEST(list, can_getnext_node)
{
	monom a(12, 14);
	monom b(14, 43);
	monom c(11, 123);
	monom d(12, 1232);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.Insert_to_tail(c);
	l.Insert_to_tail(d);
	l.getnext();
	EXPECT_EQ(l.getcurrentdate(), d);

}





// ����� ��� ��������, �������������������

struct t //��������� ��� �������� �������� �������� � ���������� ������
{
	string s;
	monom lastmonom;

	t(string mys = "", monom f = monom(0,0))
	{
		s = mys;
		lastmonom = f;
	}
};

class parameterizedstringforPolinom : public ::testing::TestWithParam<t>
{
protected:
	struct t TESTcase;

public:
	parameterizedstringforPolinom() : TESTcase(GetParam())
	{
	}

	~parameterizedstringforPolinom() {}
};


struct t1 //��������� ��� �������� �������� �������� � ���������� ������
{
	string s;

	t1(string mys = "")
	{
		s = mys;
	}
};

class parameterizedstringforPolinom1 : public ::testing::TestWithParam<t1>
{
protected:
	struct t1 TESTcase;

public:
	parameterizedstringforPolinom1() : TESTcase(GetParam())
	{
	}

	~parameterizedstringforPolinom1() {}
};

TEST_P(parameterizedstringforPolinom1, can_throw_when_degree_normal)
{
	ASSERT_NO_THROW(Polinom a(GetParam().s));
}

TEST_P(parameterizedstringforPolinom1, can_oper_ravno)
{
	Polinom a(GetParam().s);
	Polinom b = a;
	EXPECT_EQ(b == a,1);
}
t1 myarray1[] = { t1("3+z^1+y+x") , t1("3+z+y^1"), t1("12.12+x+y+xyz"), t1("1+x^2+z^3+xyz^2"), t1("12+3xyz+x^2y^4"), t1("111+323xyz+23.32xyz+2.232+12x^9"), t1("1+x+y+x^2yz") };

INSTANTIATE_TEST_CASE_P(instantiation2,
	parameterizedstringforPolinom1,
	::testing::ValuesIn(myarray1));

class parameterizedstringforPolinom2 : public parameterizedstringforPolinom1 {};


TEST_P(parameterizedstringforPolinom2, can_throw_when_degree)
{
	ASSERT_ANY_THROW(Polinom a(GetParam().s));
}

t1 myarray2[] = { t1("3+z^10+y+x") , t1("3+z^12+y^1"), t1("12.12+x^12+y+xyz"), t1("1+x^2+z^31+xyz^2"), t1("12+3xyz+x^2y^41"), t1("111+323xyz+23.32xyz+2.232+12x^91"), t1("1+x+y^12+x^2yz") };
INSTANTIATE_TEST_CASE_P(instantiation3,
	parameterizedstringforPolinom2,
	::testing::ValuesIn(myarray2));

class parameterizedstringforPolinom3 : public parameterizedstringforPolinom1 {}; // ����� ��� �������� ��������

struct t2 //��������� ��� �������� �������� �������� � ���������� ������
{
	string s;

	t2(string mys = "")
	{
		s = mys;
	}
};

t2 myarray4[] = { t2("2+2x"), t2("22+2x+4x^2+2z^7") };

TEST_P(parameterizedstringforPolinom3, can_plus)
{
	Polinom a(GetParam().s);
	Polinom b(GetParam().s);
	Polinom c = a + b;
	Polinom z(myarray4[i+1].s);
	i++;
	EXPECT_EQ(z, c);
}

t1 myarray3[] = { t1("1+x"), t1("11+x+2x^2+z^7") };
INSTANTIATE_TEST_CASE_P(instantiation4,
	parameterizedstringforPolinom3,
	::testing::ValuesIn(myarray3));


class parameterizedstringforPolinom4 : public parameterizedstringforPolinom1 {}; // ����� ��� �������� ���������
t2 myarray6[] = { t2("0") , t2("0"), t2("1"), t2("12x^3-11x^4y+21.4xyz"), t2("-1")};
t2 arrayforminus [] = { t2("1+x+y"), t2("12+x^9+y^1+z^7"), t2("10+x+y+z"), t2("0"), t2("2+x+yx+z")};
TEST_P(parameterizedstringforPolinom4, can_minus)
{
	Polinom a(GetParam().s);
	Polinom b(arrayforminus[j + 1].s);
	Polinom c;
	c = a - b;
	Polinom z(myarray6[j + 1].s);
	j++;
	EXPECT_EQ(z, c);
}

t1 myarray5[] = { t1("1+x+y"), t1("x^9+y^1+z^7+12"), t1("11+x+y+z") , t1("12x^3-11x^4y+21.4xyz"), t1("1+x+yx+z") };
INSTANTIATE_TEST_CASE_P(instantiation5,
	parameterizedstringforPolinom4,
	::testing::ValuesIn(myarray5));

TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom a("1+x+y"));
}

TEST(Polinom, can_plus)
{
	Polinom a("1+x+y");
	Polinom b("1+x+x^3");
	ASSERT_NO_THROW(a+b);
}

TEST(Polinom, can_minus)
{
	ASSERT_NO_THROW(Polinom a("1+x+y"));
}

TEST(Polinom, too_big_degree)
{
	Polinom a("1+x+y");
	Polinom b("1+x^9+y");
	ASSERT_ANY_THROW(a*b);
}

class parameterizedstringforPolinom5 : public parameterizedstringforPolinom1 {}; // ����� ��� �������� ���������
t2 myarray7[] = { t2("1-x^2") , t2("1+2x+x^2"), t2("1-x^3"), t2("0"), t2("-1-x-xy-z"), t2("x^2-y^2"), t2("x^2-2xz+z^2"), t2("x^2+2zx+z^2") };
t2 arrayformultyply[] = { t2("1-x"), t2("1+x"), t2("1+x+x^2"), t2("0"), t2("-1") , t2("x-y"), t2("x-z"), t2("x+z") };
TEST_P(parameterizedstringforPolinom5, muityply_between_Polinoms)
{
	Polinom a(GetParam().s);
	Polinom b(arrayformultyply[k + 1].s);
	Polinom c;
	c = a *b;
	Polinom z(myarray7[k + 1].s);
	k++;
	EXPECT_EQ(z, c);
}

t1 myarray8[] = { t1("1+x"), t1("1+x"), t1("1-x") , t1("12x^3-11x^4y+21.4xyz"), t1("1+x+yx+z") , t1("x+y"), t1("x-z"), t1("x+z") };
INSTANTIATE_TEST_CASE_P(instantiation6,
	parameterizedstringforPolinom5,
	::testing::ValuesIn(myarray8));

class parameterizedstringforPolinom6 : public parameterizedstringforPolinom1 {}; // ����� ��� �������� ���������
t2 arrayonconst[] = { t2("1+x") , t2("-1-x"), t2("-2+2x"), t2("24x^3-22x^4y+42.8xyz"), t2("100+100x+100yx+100z"), t2("0.5x+0.5y") };
double arrayformultyply1[] = { 1, -1,-2,2,100, 0.5 };
TEST_P(parameterizedstringforPolinom6, muityply_between_Polinoms_right)
{
	Polinom a(GetParam().s);
	Polinom c;
	c = a * arrayformultyply1[n + 1];
	Polinom z(arrayonconst[n + 1].s);
	n++;
	EXPECT_EQ(z, c);
}

TEST_P(parameterizedstringforPolinom6, muityply_between_Polinoms_left)
{
	Polinom a(GetParam().s);
	Polinom c;
	c = arrayformultyply1[l + 1]*a;
	Polinom z(arrayonconst[l + 1].s);
	l++;
	EXPECT_EQ(z, c);
}

t1 myarray9[] = { t1("1+x"), t1("1+x"), t1("1-x") , t1("12x^3-11x^4y+21.4xyz"), t1("1+x+yx+z") , t1("x+y") };
INSTANTIATE_TEST_CASE_P(instantiation7,
	parameterizedstringforPolinom6,
	::testing::ValuesIn(myarray9));















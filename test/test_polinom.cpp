#include "gTEST.h"
#include "Polinom.h"
#include "monom.h"
#include "list.h"
int i = -1;
int j = -1;
// тесты мономов и полиномов
TEST(list, insert_to_end) // вставка в конец
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

TEST(list, can_create_list) // может создать лист
{
	EXPECT_NO_THROW(list<monom> l);
}

TEST(list, delete_last_not_empty_list) // Удаление не пустого листа
{
	monom a(12, 14);
	monom b(14, 43);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	l.clear();
	EXPECT_EQ(l.IsEmpty(), 1);
}

TEST(list, can_check_is_empty) // проверка на пустоту не пустого листа
{
	monom a(12, 14);
	monom b(14, 43);
	list<monom> l;
	l.Insert_to_tail(a);
	l.Insert_to_tail(b);
	EXPECT_EQ(0, l.IsEmpty());
}

TEST(list, can_check_is_empty_if_empty) // проверка на пустоту пустого листа
{
	list<monom> l;
	EXPECT_EQ(1, l.IsEmpty());
}


TEST(list, operator_ravno_for_list) // проверка оператора  = 
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
	monom c(11.2, 123);
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


// тесты для полинома, параметризированные

struct t //структура для проверки создания полинома и последнего монома
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


struct t1 //структура для проверки создания полинома и последнего монома
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

class parameterizedstringforPolinom3 : public parameterizedstringforPolinom1 {}; // класс для проверки сложения

struct t2 //структура для проверки создания полинома и последнего монома
{
	string s;

	t2(string mys = "")
	{
		s = mys;
	}
};

t2 myarray4[] = { t2("2+2x") };

TEST_P(parameterizedstringforPolinom3, can_plus)
{
	Polinom a(GetParam().s);
	Polinom b(GetParam().s);
	Polinom c = a + b;
	Polinom z(myarray4[i+1].s);
	i++;
	EXPECT_EQ(z, c);
}

t1 myarray3[] = { t1("1+x")  };
INSTANTIATE_TEST_CASE_P(instantiation4,
	parameterizedstringforPolinom3,
	::testing::ValuesIn(myarray3));


class parameterizedstringforPolinom4 : public parameterizedstringforPolinom1 {}; // класс для проверки вычитания
t2 myarray6[] = { t2("0") , t2("0")};
t2 arrayforminus [] = { t2("1+x+y"), t2("12+x^9+y^1+z^7")};
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

t1 myarray5[] = { t1("1+x+y"), t1("x^9+y^1+z^7+12") };
INSTANTIATE_TEST_CASE_P(instantiation5,
	parameterizedstringforPolinom4,
	::testing::ValuesIn(myarray5));

// тесты на проверку правильности полинома

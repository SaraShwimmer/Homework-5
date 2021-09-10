// Homework 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

//Задание 1

/*Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.*/
//template <class T>
//class Pair1
//{
//private:
//	T m_num1;
//	T m_num2;
//
//public:
//	Pair1(const T& num1, const T& num2)
//		: m_num1(num1), m_num2(num2)
//	{
//	}
//
//	T& first() { return m_num1; }
//	const T& first() const { return m_num1; }
//	T& second() { return m_num2; }
//	const T& second() const { return m_num2; }
//};
//
//int main()
//{
//
//	Pair1<int> p1(6, 9);
//	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
//
//	const Pair1<double> p2(3.4, 7.8);
//	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
//
//	return 0;
//}

//Задание 2

/*Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.*/

//template <class T, class U>
//class Pair
//{
//private:
//	T m_num1;
//	U m_num2;
//
//public:
//	Pair(const T& num1, const U& num2)
//		: m_num1(num1), m_num2(num2)
//	{
//	}
//
//	T& first() { return m_num1; }
//	const T& first() const { return m_num1; }
//	U& second() { return m_num2; }
//	const U& second() const { return m_num2; }
//};
//
//int main()
//{
//	Pair<int, double> p1(6, 7.8);
//	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
//
//	const Pair<double, int> p2(3.4, 5);
//	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
//
//	return 0;
//}

//Задание 3

/*Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, 
а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный 
класс Pair, в котором первый параметр — string, а второй — любого типа данных.*/

//template <class T, class U>
//class Pair
//{
//private:
//	T m_num1;
//	U m_num2;
//
//public:
//	Pair(const T& num1, const U& num2)
//		: m_num1(num1), m_num2(num2)
//	{
//	}
//
//	T& first() { return m_num1; }
//	const T& first() const { return m_num1; }
//	U& second() { return m_num2; }
//	const U& second() const { return m_num2; }
//};
//
//template <class U>
//class StringValuePair : public Pair<string, U>
//{
//public:
//	//Передача строки по константной ссылке(усвоено из одной из контрольных)
//	StringValuePair(const string& key, const U& value)
//		: Pair<string, U>(key, value)
//	{
//	}
//};
//
//int main()
//{
//	StringValuePair<int> svp("Amazing", 7);
//	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
//
//	return 0;
//}

//Задание 4

/*Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand 
наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет 
два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить 
поле name - имя игрока. Также добавить 3 метода:
IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
IsBoosted() - возвращает bool значение, есть ли у игрока перебор
Bust() - выводит на экран имя игрока и объявляет, что у него перебор.*/

class GenericPlayer : public Hand {

	friend ostream& operator<<(ostream os, const GenericPlayer& aGenericPlayer);
public: 
	GenericPlayer(const string& name = " ");
	virtual ~GenericPlayer();
	//Проверка будет ли игрок брать карты
	virtual bool IsHitting() const = 0;
	//Возвращает значение, если сумма очков больше 21 (перебор)
	bool IsBusted() const;
	//Объявление о переборе
	void Bust() const;
protected:
	string m_name;
};

GenericPlayer::GenericPlayer(const string& name) :
	m_name(name) {}
GenericPlayer::~GenericPlayer(){}
bool GenericPlayer::IsBusted() const {
	return (GetTotal() > 21);
}
void GenericPlayer::Bust() const {
	cout << m_name << " busts.\n";
}



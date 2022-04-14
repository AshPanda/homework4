/*
1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
• для удаления последнего элемента массива (аналог функции pop_back() в векторах)
• для удаления первого элемента массива (аналог pop_front() в векторах)
• для сортировки массива
• для вывода на экран элементов.

2. Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.
3. Реализовать класс Hand, который представляет собой коллекцию карт. 
В классе будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, а тип его элементов
должен быть - указатель на объекты класса Card). Также в классе Hand должно быть 3 метода:
• метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
• метод Clear, который очищает руку от карт
• метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).
*/

#include <iostream>
#include <vector>
#include <cassert>
//Task#1
//Container from lesson 4
class Container {
	int* data;
	int size;
	int capacity;
	int& operator[](int idx) {}

public:
	Container() : size(0), data(nullptr), capacity(0) { }
	Container(int _size) : size(_size) {
		if (_size == 0) {
			Container();
		}
		else if (_size < 0) {
			std::cout << "Bad thing happened" << std::endl;
			Container();
		}
		else {
			this->data = new int[_size];
			this->capacity = 0;
		}
	}
	virtual ~Container() {
		delete[] data;
	}
	void setData(int idx, int value) {
		assert(idx >= 0 && idx < size);
		this->data[idx] = value;
	}
	int getData(int idx) {
		assert(idx >= 0 && idx < size);

		return this->data[idx];
	}
	int capacity() {
		return this->capacity;
	}
	void resize(int newLength) {

		if (newLength == size) return;
		if (newLength <= 0) {

			return;
		}
		int* newData = new int[newLength];
		if (size > 0) {
			int elemToCopy = (newLength > size) ? size : newLength;
			for (int idx = 0; idx < elemToCopy; idx++) {

				newData[idx] = data[idx];
			}
		}
		delete[] data;
		data = newData;
		size = newLength;
	}
	void erase() {
		capacity = 0;
		for (int idx = 0; idx < size; idx++) {
			data[idx] = 0;
		}
	}
// homework
	int removeLast() {
		int temp = getData(size - 1);
		resize(size - 1);
		return temp;
	}
	int removeFirst() {
		int temp = getData(0);
		for (int i = 1; i < size; ++i)
			data[i - 1] = data[i];

		resize(size - 1);
		return temp;
	}
	void sortArray() {
		int temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = (size - 1); j > i; j--)
			{
				if (data[j - 1] > data[j])
				{temp = data[j - 1]; 
					data[j - 1] = data[j]; 
					data[j] = temp; }
			}
	}
	void printArray() {
		for (int i = 0; i < size; ++i)
			std::cout << data[i] << " " << std::endl;
	}
}

//Task#2 -
//Task#3

enum rank {
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10
};
enum suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};
class Card
{
public:

	Card(rank Rank, suit Suit) : Rank(Rank), Suit(Suit) {
		isFaceUp = true;
	}
	~Card() {}
	int GetValue() const {
		return Rank;
	}
	void Flip() {
		isFaceUp = !(isFaceUp);
	}

protected:
	rank Rank;
	suit Suit;
	bool isFaceUp;
};
class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Card* pCard) 
	{
		myCards.push_back(pCard);
	}
	void Clear() {
		std::vector<Card*>::iterator i = myCards.begin();
		for (i = myCards.begin(); i != myCards.begin(); ++i)
		{
			delete* i;
			*i = 0;
		}
		myCards.clear();
	}
	int GetValue() const {
		if (myCards.empty())
		{
			return 0;
		}
		if (myCards[0]->GetValue() == 0)
		{
			return 0;
		}
		int total = 0;
		std::vector<Card*>::const_iterator i;
		for (i = myCards.begin(); i != myCards.end(); ++i)
		{
			total += (*i)->GetValue();
		}
		bool isAce = false;
		for (i = myCards.begin(); i != myCards.end(); ++i)
		{
			if ((*i)->GetValue() == rank::ACE)
			{
				isAce = true;
			}
		}
		if (isAce && total <= 11)
		{
			total += 10;
		}
		return total;
	}
protected:
	std::vector<Card*> myCards;
};

Hand::Hand()
{
	myCards.reserve(5);
}

Hand::~Hand()
{
	Clear();
}

int main()
{
	return 0;
}

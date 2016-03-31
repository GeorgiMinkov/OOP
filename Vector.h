#ifndef VECTOR_H
#define VECTOR_H

const int initialCapacity = 64;
class Vector
{
private:
	int *container;
	size_t size;//current size of container
	size_t capacity;//all capacity of container
	void resize(size_t newCapacity);

public:
	Vector();
	Vector(size_t capacity, size_t size = 0);
	Vector(const Vector& otherVector); //copy constructor задължителен когато има динамична памет записва се с const и &
	~Vector();

	bool SetAt(int value, size_t index);
	int GetAt(size_t index) const;

	void PushBack(int element);
	void InsertAt(int element, size_t index);
	void DeleteAt(size_t index);

	bool isEmpty()const;
	size_t Size() const;

	void Sort(bool sortIncreasing = true);
	bool IsSorted() const;

	void Resize(size_t newCapacity);

};

#endif
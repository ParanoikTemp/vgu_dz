#pragma once

#include <ostream>
#include <sstream>
#include <string>

using std::string;
using std::ostringstream;
using std::ostream;
using std::distance;

template<typename T>
class FlexArray {
private:
	T *arr;
	int len = 0;

	/**
	 * Функция модуля
	 * @param x число, подставляемое в модуль
	 * @return Абсолютная величина числа
	 */
	inline int abs(int x) const;
public:
	/**
	* Итератор класса FlexArray
	*/
	class Iterator;

	/**
	 * Конструктор пустого массива
	 */
	FlexArray() = default;
	/**
	 * Конструктор массива заполненого одним и тем же значением
	 * @param length Длина массива
	 * @param number Значение, которым будет заполнен массив.
	 */
	FlexArray(int length, T value);
	/**
	 * Конструктор гибкого массива на основе динамического массива
	 * @param arr Указатель на динамический массив
	 * @param len Длина переданного массива
	 */
	FlexArray(T *arr, int length);
	/**
	 * Конструктор копирования
	 * @param other Объект класса FlexArray
	 */
	FlexArray(const FlexArray &other);
	/**
	 * Деструктор класса
	 */
	~FlexArray();

	/**
	 * Геттер длины массива
	 * @return Длина массива
	 */
	inline int length() const;

	/**
	 * Оператор получения элемента по индексу
	 * @param index Индекс элемента
	 * @return Элемент массива по переданному индексу
	 */
	T& operator[] (const int &index) const;
	/**
	 * Конструктор присваивания
	 * @param array Объект класса FlexArray
	 * @return Ссылку на себя
	 */
	FlexArray& operator= (const FlexArray &array);

	/**
	 * Функция добавления элемента на определенную позицию в массиве
	 * @param elem Добавляемый элемент
	 * @param index Индекс добавления элемента
	 */
	void pushToIndex(T elem, int index);
	/**
	 * Вставка нового элемента в конец массива
	 * @param elem Добавляемый элемент
	 */
	inline void append(T elem);

	/**
	 * Удаляет элемент по заданному индексу
	 * @param index Индекс удаляемого элемента
	 * @return Значение удаленного элемента
	 */
	T removeToIndex(int index);

	/**
	 * Удаляет элемент из массива
	 * @param elem Элемент
	 * @param count Количество удалений. Если -1, то удаляются все элементы
	 */
	void remove(T elem, int count = -1);
	/**
	 * Проводит замену одного элемента на другой
	 * @param elem Заменяемый элемент
	 * @param newElem Заместитель
	 * @param count Количество замен. Если -1, то заменяются все элементы
	 */
	void replace(T elem, T newElem, int count = -1);

	/**
	 * Вставляет часть одного массива в другой
	 * @param begin Итератор начала части массива
	 * @param end Итератор конца части массива
	 * @param index Индекс вставки (index >= 0)
	 */
	void insertElements(Iterator begin, Iterator end, int index);
	/**
	 * Удаляет группу элементов из массива
	 * @param begin Итератор начала группы
	 * @param end Итератор конца группы
	 */
	void removeElements(Iterator begin, Iterator end);
	/**
	 * Заменяет группу элементов на другую группу элементов
	 * @param begin Начало группы
	 * @param end конец группы
	 * @param index индекс вставки группы
	 */
	void replaceElements(Iterator begin, Iterator end, int index);

	/**
	 * Ищет первое вхождение элемента в массиве
	 * @param element Элемент, который ищется в массиве
	 * @return Индекс первого вхождения элемента
	 */
	int find(T element);
	/**
	 * Ищет первое вхождение группы элементов в массиве
	 * @param begin Итератор начала группы элементов
	 * @param end Итератор конца группы элементов
	 * @return Индекс первого вхождения группы
	 */
	int findElements(Iterator begin, Iterator end);

	/**
	 * Подсчитывает количество переданного элемента в массиве
	 * @param elem Считаемый элемент
	 * @return Количество элемента в массиве
	 */
	int count(T elem) const;
	/**
	 * Проверяет вхождение элемента в массив
	 * @param elem Проверяемый элемент
	 * @return True, если элемент есть в массиве
	 */
	bool include(T elem) const;

	/**
	 * Преобразует строку в строковый формат
	 * @return строка с визуализацией массива
	 */
	string toString() const;

	/**
	 * Создает итератор с указателем на начало массива
	 * @return Итератор на начале массива
	 */
	inline Iterator begin() { return Iterator(arr); }
	/**
	 * Создает итератор с указателем на конец массива
	 * @return Итератор на конце массива
	 */
	inline Iterator end() { return Iterator(arr + len); }

	class Iterator {
	private:
		T* cur;
	public:
		/**
		 * Конструктор итератора
		 * @param first указатель но то, куда будет указывать итератор
		 */
		Iterator(T* first) {
			cur = first;
		};
		/**
		 * Оператор Копирования
		 * @param other другой итератор
		 */
		Iterator(const Iterator &other) = default;
		/**
		 * Оператор присваивания
		 * @param other другой итератор
		 * @return ссылку на себя
		 */
		Iterator& operator=(const Iterator &other) = default;

		/**
		 * Оператор сложения
		 * @param n на сколько сдвинуть итератор
		 * @return Итератор через n элементов
		 */
		Iterator operator+(int n) const {
			T *cur2 = cur;
			for (int i = 0; i < n; ++i) ++cur2;
			return Iterator(cur2);
		}
		/**
		 * Оператор вычитания
		 * @param n на сколько назад сдвинуть итератор
		 * @return Итератор на n элементов назад
		 */
		Iterator operator-(int n) const {
			T *cur2 = cur;
			for (int i = 0; i < n; ++i) --cur2;
			return Iterator(cur2);
		}

		int operator-(const Iterator &other) const { return distance(cur, other.cur); }

		/**
		 * Оператор постинкремента. После операции итератор движется вперед на 1 шаг.
		 * @return Свою копию
		 */
		Iterator operator++(int) {
			Iterator i = *this;
			cur += 1;
			return i;
		}
		/**
		 * Оператор постдекремента. После операции итератор движется назад на 1 шаг.
		 * @return Свою копию
		 */
		Iterator operator--(int) {
			Iterator i = *this;
			cur -= 1;
			return i;
		}
		/**
		 * Оператор инкремента.
		 * @return Ссылку на свой же объект, сдвинутый на шаг вперед
		 */
		Iterator& operator++() {
			cur += 1;
			return *this;
		}
		/**
		 * Оператор инкремента.
		 * @return Ссылку на свой же объект, сдвинутый на шаг назад
		 */
		Iterator& operator--() {
			cur -= 1;
			return *this;
		}

		/**
		 * Оператор равенства
		 * @param other Другой итератор
		 * @return True, если итераторы равны
		 */
		bool operator==(const Iterator &other) const { return cur == other.cur; }
		/**
		 * Оператор неравенства
		 * @param other Другой итератор
		 * @return True, если итераторы не равны
		 */
		bool operator!=(const Iterator &other) const { return cur != other.cur; }

		/**
		 * Оператор разыменования
		 * @return
		 */
		T& operator*() { return *cur; }
	};

	template<typename Z>
	friend ostream& operator<<(ostream &stream, const FlexArray<Z> &array);
};

template<typename T>
int FlexArray<T>::findElements(Iterator begin, Iterator end) {
	for (int i = 0; i < len - abs(begin - end) + 1; ++i) {
		if (arr[i] == *begin) {
			bool flag = true;
			int k = 0;
			for (Iterator it = begin; it != end; ++it)
				if (arr[k++ + i] != *it) {
					flag = false;
					break;
				}
			if (flag) return i;
		}
	}
	return -1;
}

template<typename T>
int FlexArray<T>::find(T element) {
	for (int i = 0; i < len; ++i)
		if (arr[i] == element) return i;
	return -1;
}

template<typename T>
void FlexArray<T>::replaceElements(Iterator begin, Iterator end, int index) {
	int i = index;
	while (begin != end) arr[i++] = *begin++;
}

template<typename T>
void FlexArray<T>::removeElements(Iterator begin, Iterator end) {
	int newLen = abs(begin - end);
	T *newArr = new T[newLen];
	int k = 0;
	for (Iterator it = this->begin(); it != begin; ++it) newArr[k++] = *it;
	for (Iterator it = end; it != this->end(); ++it) newArr[k++] = *it;
	len = newLen;
	T *rem = arr;
	arr = newArr;
	delete[] rem;
}

template<typename T>
void FlexArray<T>::insertElements(Iterator begin, Iterator end, int index) {
	int newLen = abs(begin - end) + len;
	T *newArr = new T[newLen];
	for (int i = 0, k = 0; i < len; ++i) {
		if (k == index)
			while (begin != end) newArr[k++] = *(begin++);
		newArr[k++] = arr[i];
	}
	T *rem = arr;
	len = newLen;
	arr = newArr;
	delete[] rem;
}

template<typename T>
ostream& operator<<(ostream &stream, const FlexArray<T> &array) {
	stream << array.toString();
	return stream;
}

template<typename T>
void FlexArray<T>::replace(T elem, T newElem, int count) {
	int cnt = this->count(elem);
	if (cnt > 0 && count != 0) {
		if (count > 0 && count > cnt) count = cnt;
		if (count < 0) count = cnt;
		for (int i = 0, c = 0; i < len; ++i) {
			if (arr[i] == elem && c < count) {
				++c;
				arr[i] = newElem;
			}
		}
	}
}

template<typename T>
void FlexArray<T>::remove(T elem, int count) {
	int cnt = this->count(elem);
	if (cnt > 0 && count != 0) {
		if (count > 0 && count > cnt) count = cnt;
		if (count < 0) count = cnt;
		T *newArr = new T[len - count];
		for (int i = 0, c = 0, k = 0; i < len; ++i) {
			if (arr[i] != elem || c == count) newArr[k++] = arr[i];
			else ++c;
		}
		T *rem = arr;
		arr = newArr;
		len = len - count;
		delete[] rem;
	}
}

template<typename T>
bool FlexArray<T>::include(T elem) const {
	for (int i = 0; i < len; ++i)
		if (arr[i] == elem) return true;
	return false;
}

template<typename T>
int FlexArray<T>::count(T elem) const {
	int count = 0;
	for (int i = 0; i < len; ++i)
		if (arr[i] == elem) ++count;
	return count;
}

template<typename T>
T FlexArray<T>::removeToIndex(int index) {
	T *newArr = new T[len - 1], elem = arr[index];
	for (int i = 0, k = 0; i < len; ++i) {
		if (i != index) newArr[k++] = arr[i];
	}
	T *rem = arr;
	arr = newArr;
	len -= 1;
	delete[] rem;
	return elem;
}

template<typename T>
void FlexArray<T>::append(T elem) {
	pushToIndex(elem, -1);
}

template<typename T>
string FlexArray<T>::toString() const {
	ostringstream stream;
	stream << '[';
	for (int i = 0; i < len; ++i) {
		stream << arr[i];
		if (i != len - 1) stream << ", ";
	}
	stream << ']';
	return stream.str();
}

template<typename T>
int FlexArray<T>::abs(int x) const {
	if (x >= 0) return x;
	else return x * -1;
}

template<typename T>
FlexArray<T>::FlexArray(int length, T value) {
	len = length;
	arr = new T[len];
	for (int i = 0; i < len; ++i) arr[i] = value;
}

template<typename T>
void FlexArray<T>::pushToIndex(T elem, int index) {
	int newLen = len + (abs(index) > len ? abs(index) - len + (index > 0 ? 1 : 0) : 1);
	T* newArr = new T[newLen];
	int k = 0, i = 0;
	if (index < 0 && abs(index) > len) {
		if (abs(index) > len) newArr[k++] = elem;
		while (newLen - k > len) newArr[k++] = 0;
	}
	if (index < 0) index = len + index + 1;
	while (i < len + (index <= len ? 1 : 0)) {
		newArr[k++] = (k != index ? arr[i++] : elem);
	}
	if (index > 0 && index > len) {
		while (k != index) newArr[k++] = 0;
		newArr[k] = elem;
	}
	T *rem = arr;
	delete[] rem;
	arr = newArr;
	len = newLen;
}

template<typename T>
int FlexArray<T>::length() const {
	return len;
}

template<typename T>
FlexArray<T>::FlexArray(const FlexArray &other) {
	len = other.len;
	arr = new T[len];
	for (int i = 0; i < len; ++i) arr[i] = other[i];
}

template<typename T>
FlexArray<T> &FlexArray<T>::operator=(const FlexArray &array) {
	if (len > 0) {
		T *rem = arr;
		arr = nullptr;
		delete[] rem;
	}
	len = array.len;
	arr = new T[len];
	for (int i = 0; i < len; ++i) arr[i] = array[i];
	return *this;
}

template<typename T>
T& FlexArray<T>::operator[](const int &index) const {
	if (index >= 0) return arr[index];
	else return arr[len + index];
}

template<typename T>
FlexArray<T>::~FlexArray() {
	delete[] arr;
}

template<typename T>
FlexArray<T>::FlexArray(T *array, int length) {
	len = length;
	arr = new T[length];
	for (int i = 0; i < length; ++i) arr[i] = array[i];
}

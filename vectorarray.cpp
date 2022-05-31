#include <iostream>

class VectorArr {
	double* m_data{ nullptr };
	int m_size{ 0 };
	int m_capacity{ 0 };

public:
	VectorArr() {
		m_data = 0;
		m_size = 0;
		m_capacity = 0;
	}
	VectorArr(int capacity) :
		m_capacity(capacity) {
		m_size = 0;
		m_data = new double[capacity];
		for (int count = 0; count < m_capacity; count++)
			m_data[count] = 0;
	}
	VectorArr(const VectorArr& other) {
		resize(other.m_size);
		m_data = new double[m_capacity];

		for (int count = 0; count < m_size; count++)
			m_data[count] = other.m_data[count];
	}
	~VectorArr() {
		m_size = 0;
		m_capacity = 0;
		delete[] m_data;
	}

	void resize(int newSize) {
		if (m_capacity > newSize)
			m_size = newSize;

		else {
			m_capacity = (newSize + 1) * 2;
			double* temp = new double[m_capacity];
			for (int count = 0; count < m_capacity; count++) {
				if (count < m_size)
					temp[count] = m_data[count];
				else
					temp[count] = 0;
			}
			m_size = newSize;
			delete[] m_data;
			m_data = temp;
		}
	}

	void pushback(double value) {
		if (m_capacity < m_size + 1)
			resize(m_size + 1);
		else
			m_size++;
		m_data[m_size - 1] = value;
	}

	double popback() {
		double temp = m_data[m_size];
		m_size--;
		return temp;
	}

	double erase(int index) {
		double temp = m_data[index];
		for (int count = index; count < m_size - 1; count++)
			m_data[count] = m_data[count + 1];
		m_size--;
		return temp;
	}

	void insert(double value, int index) {
		resize(m_size + 1);
		for (int count = m_size - 1; count > index; count--)
			m_data[count] = m_data[count - 1];
		m_data[index] = value;
	}

	VectorArr& operator=(const VectorArr& other) {
		if (&other == this)
			return *this;
		delete[] m_data;
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_data = new double[m_capacity];
		for (int count = 0; count < m_size; count++)
			m_data[count] = other.m_data[count];

		return *this;
	}

	friend std::ostream& operator<< (std::ostream & out, const VectorArr& other) {
		out << "(";
		for (int count = 0; count < other.m_size; count++)
			out << other.m_data[count] << "  ";
		out << ")" << std::endl;
		return out;
	}

	int getsize() {
		return m_size;
	}

};

int main() {
	VectorArr vector(3);
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	vector.insert(5., 0);
	std::cout << vector;
	return 0;
}

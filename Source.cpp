//14	Двумерный массив(матрица) с элементами типа int.
//сравнения(> и < и == ),
//унарные арифметические(--);


#include<iostream>
#include<array>

class Matrix {
	int height;
	int width;
	int *members;
public:
	Matrix(Matrix& m) {
		height = m.height;
		width = m.width;
		members = new int[width * height];
		for (int i = 0; i < width * height; i++) members[i] = m.members[i];
	}
	
	Matrix(int height, int width) : height{ height }, width{ width } {
		members = new int[width * height];
		for (int i = 0; i < width * height; i++) members[i] = 0;
	}
	~Matrix() { 
		delete[] members;
		std::cout << "Destructor is called." << std::endl;
	}
	int & get_member(int x, int y) {
		int index = y * width + x;
		return members[index];
	}
	void show_matrix() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				std::cout << members[i*width+j] << " ";

			}
			std::cout << std::endl;
		}
	}
	bool operator>(const Matrix& m) {
		if ((height * width) > (m.height * m.width)) {
			return true;
		}
		else return false;
	}
	bool operator<(const Matrix& m) {
		if ((height * width) < (m.height * m.width)) {
			return true;
		}
		else return false;
	}
	bool operator==(const Matrix& m) {
		if ((height * width) == (m.height * m.width)) {
			for (int i = 0; i < (height * width); i++) {
				if (members[i] != m.members[i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
	friend const Matrix& operator--(Matrix& m, int);
};

const Matrix& operator--(Matrix& m, int) {
	for (int i = 0; i < (m.height * m.width); i++) {
		m.members[i]--;
	}
	return m;
}

int main() {
	Matrix matrix(3,4);
	Matrix second_matrix(5, 2);
	if (matrix < second_matrix) {
		std::cout << "First matrix less than second." << std::endl;
	}
	else std::cout << "Second matrix less than first." << std::endl;
	matrix.get_member(2, 1) = 5;
	Matrix third_matrix(matrix);
	if (matrix == third_matrix) {
		std::cout << "Matrices are equal." << std::endl;
	}
	else std::cout << "Matrices are not equal." << std::endl;
	second_matrix.show_matrix();
	second_matrix--;
	std::cout << "Decrementing second matrix." << std::endl;
	second_matrix.show_matrix();

}

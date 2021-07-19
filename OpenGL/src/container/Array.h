#pragma once
#include "common/Core.h"
#include "math/Lingal.h"

namespace OpenGL {
	using namespace Math;
	template<int dim, typename T>
	class ArrayND {

	};

	template<typename T>
	class ArrayND<2, T> {
	public:
		ArrayND() {}
		ArrayND(const Vec2i& res) : res(res) {}
		ArrayND(int row, int col) : data(row* col) {
			res[0] = row;
			res[1] = col;
		}
		ArrayND(const std::vector<T>& data, int row, int col) : data(data) {
			res[0] = row;
			res[1] = col;
		}
		const T& operator()(int x, int y) const {
			return data[x * res[1] + y];
		}
		T& operator()(int x, int y) {
			return data[x * res[1] + y];
		}

		const T* operator[](int i) const {
			return &data[0] + i * res[1];
		}
		T* operator[](int i) {
			return &data[0] + i * res[1];
		}
		const T& operator[](Vec2i i) const {
			return data[i.x * res[1] + i.y];
		}
		T& operator[](Vec2i i) {
			return data[i.x * res[1] + i.y];
		}
		const std::vector<T>& GetData() const {
			return data;
		}
	public:
		Vec2i res;
	private:
		std::vector<T> data;
	};

	template <typename T>
	using Array2D = ArrayND<2, T>;
}

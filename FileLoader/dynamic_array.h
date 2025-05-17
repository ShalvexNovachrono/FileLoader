#pragma once

/// <summary>
/// This will contain the class array
/// </summary>
namespace dynamic_array {
	template <typename T>
	class array {
	private:
		int Capacity = 0; // Size of Collection at the start
		int CollectionSize = 0; // Amount of items in the Collection
		T* Collection = nullptr; // This will create Pointer that points to something which is nothing

		void Resize() {
			Capacity = (Capacity == 0) ? 1: Capacity * 2; // Increases the capacity by 2x and
			// this save it from resizing the array too many time making it perform better with larger amount of data
			T* CollectionTemp = new T[Capacity]; // Make a temp array

			for (int i = 0; i < CollectionSize; i++) {
				CollectionTemp[i] = Collection[i];
			}

			delete[] Collection;
			Collection = CollectionTemp;
		}
	public:
		array() {
			Capacity = 1;
			Collection = new T[Capacity]; // This will initialise the pointer array
		}

		~array() {
			delete[] Collection;
		}

		void Append(T Value) {
			if (Capacity == CollectionSize) {
				Resize();
			}

			Collection[CollectionSize] = Value;

			CollectionSize++;
		}

		T Get(int Index) {
			if (Index > 0 && Index < CollectionSize) {
				return Collection[Index];
			}
			return T();
		}

		void Set(T Value, int Index) {
			if (Index > 0 && Index < CollectionSize) {
				Collection[Index] = Value;
			}
		}


		void Delete(int Index) {
			if (Index > 0 && Index < CollectionSize) {
				for (int i = Index; i < CollectionSize - 1; i++) {
					Collection[i] = CollectionSize[i + 1];
				}
				CollectionSize--;
			}
		}

		int Size() {
			return CollectionSize;
		}
	};

}


#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace nwacc {

	template <typename T>
	class self_adjusting_list {
	public:

		explicit self_adjusting_list(size_t initial_size = 14) : // constructor
			my_size{ 0 }, my_capacity{ initial_size + 2 }
		{
			this->data = new T[this->my_capacity];
		}



		self_adjusting_list(const self_adjusting_list& other) : // Copy constructor. 
			my_size{ other.my_size }, my_capacity{ other.my_capacity }, data{ nullptr }
		{
			this->data = new T[this->my_capacity];
			for (auto index = 0U; index < this->my_size; index++) {
				this->data[index] = other.data[index];
			} 
		}



		self_adjusting_list(self_adjusting_list&& other) : // Move constructor 
			my_size{ other.my_size }, my_capacity{ other.my_capacity }, data{ other.data }
		{
			other.data = nullptr;
			other.my_size = 0U;
			other.my_capacity = 0U;
		}



		self_adjusting_list& operator=(const self_adjusting_list& rhs)
		{
			auto copy = rhs;
			std::swap(*this, copy);
			return *this;
		}



		self_adjusting_list& operator=(self_adjusting_list&& rhs) // Move assignment operator
		{
			std::swap(this->my_size, rhs.my_size);
			std::swap(this->my_capacity, rhs.my_capacity);
			std::swap(this->data, rhs.data);
			return *this;
		}



		~self_adjusting_list() // destructor
		{
			delete[] this->data;
		}



		T& operator[](int index)
		{
			return this->data[index];
		}



		const T& operator[](int index) const
		{
			return this->data[index];
		}



		bool empty() const
		{
			return this->my_size == 0;
		}



		size_t size() const
		{
			return this->my_size;
		}

		size_t getlocation() const
		{
			return this->location;
		}

		std::string valuefound() const
		{
			std::string anwser = "";
			if (found == 1)
			{
				anwser = "yes";
				return anwser;
			}
			//else
			anwser = "no";
			return anwser;
			
		}



		void reserve(int new_capacity)
		{
			if (new_capacity < this->my_size) {
				return;
			}
			//else

			T* new_data = new T[new_capacity];
			for (auto index = 0U; index < this->my_size; index++) {
				new_data[index] = std::move(this->data[index]);
			}

			this->my_capacity = new_capacity;
			std::swap(this->data, new_data);
			delete[] new_data;
		}



		void push_back(const T& value)
		{
			if (this->my_size == this->my_capacity) {
				this->reserve((this->my_capacity * 3) / 2);
			} // else

			this->data[this->my_size++] = value;
		}



		void emplace_back(T&& value)
		{
			if (this->my_size == this->my_capacity) {
				this->reserve((this->my_capacity * 3) / 2);
			} // else

			this->data[this->my_size++] = std::move(value);
		}



		void pop_back()
		{
			if (this->empty()) {
				throw std::out_of_range("list is empty");
			} // else

			--this->my_size;
		}



		const T& back() const
		{
			if (this->empty()) {
				throw std::out_of_range("list is empty");
			} // else, we have some values, do_nothing();

			return this->data[this->my_size - 1];
		}



		typedef T* iterator; 
		typedef const T* const_iterator; 

		iterator begin() 
		{ 
			return &this->data[0U];
		}

		const_iterator begin() const
		{
			return &this->data[0U];
		}


		iterator end()
		{
			return &this->data[this->size()];
		}

		const_iterator end() const
		{
			return &this->data[this->size()];
		}





		void insert(const T& value) // insert operator
		{
			if (this->my_size == this->my_capacity) {
				this->reserve((this->my_capacity * 3) / 2);
			}

			T* new_data = new T[my_capacity];
			
			for (auto index = 1; index <= this->my_size; index++)
			{
				new_data[my_size-index+1] = std::move(this->data[my_size-index]);
			}

			std::swap(this->data, new_data);
			delete[] new_data;
			my_size++;

			this->data[this->my_size - my_size] = value; // insert new value at beginning
		}









		void find(const T& value) // insert operator
		{
			location = 0;

			T* new_data = new T[my_capacity];

			std::swap(this->data, new_data);//send values to new data to be checked

			size_t* target = 0;//iterator value holder

			auto check = 0U; // how many runs through loop (also gives found values location)
			

			for (auto i = 0U; i <= my_size - 1; i++)//find the first occurance of number being serched for
			{
				found = true;
				auto target = new_data[i];

				if (i == my_size - 1)//value not found and at end of array
				{
					found = false;
					std::swap(this->data, new_data);
					break;
				}
				

				if (target == value)
				{
					location = check;

					std::swap(this->data, new_data);
					delete[] new_data;
					new_data = new T[my_capacity];

					for (auto index = 1U; index <= location; index++)		// put correct values in new data up to indexed number
					{
						new_data[(location - index) + 1] = std::move(this->data[location - index]);
					}

					for (auto index = 1U; index <= my_size - 1 - location; index++)   // put correct values in new data after indexed  number
					{
						new_data[my_size - index] = std::move(this->data[my_size - index]);
					}

					std::swap(this->data, new_data);
					delete[] new_data;

					this->data[this->my_size - my_size] = value; // insert new value at beginning

					break;
				}
				check++;
			}
		}

		friend std::ostream& operator<<(std::ostream& out, const self_adjusting_list& list)
		{
			out << "Size " << list.my_size << std::endl;
			out << "Capacity " << list.my_capacity << std::endl;
			out << " location " << list.location << std::endl;
			
			for (auto index = 0U; index < list.my_size; index++) {
				out << list[index] << " ";
			}

			for (auto index = list.my_size; index < list.my_capacity; ++index) {
				out << "nil ";
			}

			out << std::endl;
			return out;
		}

	private:

		bool found;

		size_t location;

		size_t my_size;

		size_t my_capacity;

		T* data;
	};
}

#endif
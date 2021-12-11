#include <iostream>

#include "self_adjusting_list.h"

int main()
{
	nwacc::self_adjusting_list<int> list(1);


	list.push_back(67); // give some values to the array
	list.push_back(56);
	list.push_back(9);
	list.push_back(28);
	list.push_back(46);
	list.push_back(82);
	list.push_back(3);

	std::cout << "starting values are :" << std::endl; 
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	list.insert(2); // use insert function to set front value of array and push rest back
	std::cout << "list.insert(2); Expect to see 2 67 56 9 28 46 82 3" << std::endl; // 
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	list.insert(55); // use insert function to set front value of array and push rest back
	std::cout << "list.insert(2); Expect to see 55 2 67 56 9 28 46 82 3" << std::endl; // 
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	list.insert(97); // use insert function to set front value of array and push rest back
	std::cout << "list.insert(97); Expect to see  97 55 2 67 56 9 28 46 82 3" << std::endl; // 
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	list.find(9); // use find function to find first occurance of value
	std::cout << "was value 9 was found ? " << list.valuefound() << std::endl;
	std::cout << "the number 9 was at the location " << list.getlocation() << std::endl;
	std::cout << "list.find(9);  Expect to see 9 97 55 2 67 56 28 46 82 3" << std::endl;
	std::cout << "Output : ";
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}
	
	std::cout << std::endl;
	std::cout << std::endl;

	list.find(46); // use find function to find first occurance of value
	std::cout << "was the value 46 value was found ? " << list.valuefound() << std::endl;
	std::cout << "the number 46 was at the location " << list.getlocation() << std::endl;
	std::cout << "list.find(46);  Expect to see 46 9 97 55 2 67 56 28 82 3" << std::endl;
	std::cout << "Output : ";
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	

	std::cout << std::endl;
	std::cout << std::endl;


	list.find(82); // use find function to find first occurance of value
	std::cout << "was the value 82 was found ? " << list.valuefound() << std::endl;
	std::cout << "the number 82 was at the location " << list.getlocation() << std::endl;
	std::cout << "list.find(82);  Expect to see 82 46 9 97 55 2 67 56 28 3 " << std::endl;
	std::cout << "Output : ";
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;


	

	list.find(82); // use find function to find first occurance of value
	std::cout << "was the value 82 was found ? " << list.valuefound() << std::endl;
	std::cout << "the number 82 was at the location " << list.getlocation() << std::endl;
	std::cout << "list.find(82);  Expect to see 82 46 9 97 55 2 67 56 28 3 " << std::endl;
	std::cout << "Output : ";
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	list.find(22);
	std::cout << "can value 22 be found ? " << list.valuefound() << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "CHECKING THAT ALL ITERATORS STILL WORK" << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "For - Expect to see 82 46 9 97 55 2 67 56 28 3 " << std::endl;
	for (auto index = 0U; index < list.size(); index++) {
		std::cout << list[index] << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "For WITH iterators -Expect to see 82 46 9 97 55 2 67 56 28 3 " << std::endl;
	for (auto iterator = list.begin(); iterator != list.end(); iterator++) {
		std::cout << *iterator << " ";	 
	}
	
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "For each - Expect to see 82 46 9 97 55 2 67 56 28 3 " << std::endl;
	for (const auto& value : list) {
		std::cout << value << " ";
	}

	std::cout << std::endl;
	std::cout << std::endl;
	
	return 0;
}
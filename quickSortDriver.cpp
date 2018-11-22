//Megan Hodges
//quickSort Program 7: Implementing quicksort
//COSC 2436
//03/04/2018

#include <iostream>
#include <string>
#include "quickSort.cpp"
#include "insertionSort.cpp"

using namespace std;

int main()
{	
	const int PI_SIZE = 30;
	int piDigits[PI_SIZE] = { 1, 4, 1, 5, 9, 2, 6,
		5, 3, 5, 8, 9, 7, 9,
		3, 2, 3, 8, 4, 6, 2, 6,
		4, 3, 3, 8, 3, 2, 7, 9 };
	const int COUNTRY_SIZE = 50;
	string countries[COUNTRY_SIZE] = { "China", "India", "USA", "Indonesia", "Brazil",
		"Pakistan", "Nigeria", "Bangladesh", "Russia", "Mexico",
		"Japan", "Ethiopia", "Philippines", "Egypt", "Vietnam",
		"Germany", "Congo", "Iran", "Turkey", "Thailand",
		"UK", "France", "Italy", "Tanzania", "SouthAfrica",
		"Myanmar", "SouthKorea", "Colombia", "Kenya", "Spain",
		"Argentina", "Ukraine", "Uganda", "Algeria", "Sudan",
		"Iraq", "Poland", "Canada", "Morocco", "Afghanistan", "SaudiArabia", "Peru", 
		"Venezuela", "Uzbekistan", "Malaysia",
		"Angola", "Mozambique", "Nepal", "Ghana", "Yemen" };
	int first = 0;

	cout << "Unordered list of numbers: " << endl;
	display(piDigits, PI_SIZE);
	cin.get();

	cout << "There are " << PI_SIZE - first + 1 << " numbers in the array." << endl;
	cout << "Should be 30." << endl;

	cout << "Testing 30 ints with quickSort: " << endl;
	quickSort(piDigits, first, PI_SIZE - 1);
	display(piDigits, PI_SIZE);
	cout << "\n\nShould be: 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 5,"
		<< "5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 9, 9, 9, 9" << endl;
	cin.get();

	cout << "Unordered list of countries: " << endl;
	display(countries, COUNTRY_SIZE);
	cin.get();

	cout << "There are " << COUNTRY_SIZE - first + 1 << " strings in the array." << endl;
	cout << "Should be 50." << endl;

	cout << "Testing 50 countries with quickSort: " << endl;
	quickSort<string>(countries, first, COUNTRY_SIZE - 1);
	display<string>(countries, COUNTRY_SIZE);
	cin.get();

	cout << "\n\nShould be: Afghanistan, Algeria, Angola, Argentina, Bangladesh,"
		<< "Brazil, Canada, China, Colombia, Congo, Egypt, Ethiopia, France, "
		<< "Germany, Ghana, India, Indonesia, Iran, Iraq, Italy, Japan, Kenya, "
		<< "Malaysia, Mexico, Morocco, Mozambique, Myanmar, Nepal, Nigeria, "
		<< "Pakistan, Peru, Philippines, Poland, Russia, SaudiArabia, SouthAfrica, "
		<< "SouthKorea, Spain, Sudan, Tanzania, Thailand, Turkey, UK, USA, "
		<< "Uganda, Ukraine, Uzbekistan, Venezuela, Vietnam, Yemen" << endl;
	cin.get();
}
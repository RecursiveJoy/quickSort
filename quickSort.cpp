#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include "insertionSort.cpp"

//author Megan West
//Spring 2018

/** Swaps two elements in an array.
@pre	the Array has at least 1 item
@post	the two values c[a] and c[b] have switched places in the array.
@param	c is any array
@param	a is an index in array c
@param	b is an index in array c */
template <class ItemType>
void swap(ItemType c[], int a, int b)
{
	ItemType temp = c[a];
	c[a] = c[b];
	c[b] = temp;
}//end swap

 /** Arranges first, middle, last elements in ascending order.
 @pre	theArray has at least 3 items
 @post	if successful the first, middle, & last elements are sorted.
 @param	theArray is any array
 @param  first is the first item in the array
 @param	mid is the middle item in the array
 @param	last is the last item in the array */
template <class ItemType>
void sortFirstMiddleLast(ItemType theArray[], int first, int mid, int last)
{
	//if the first value is greater than the middle one, 
	//put them in order
	if (theArray[first] > theArray[mid])
		swap(theArray, first, mid);

	//if the middle is greater than the last, 
	//put them in order
	if (theArray[mid] > theArray[last])
		swap(theArray, mid, last);

	//finally if the first is greater than the middle
	//swap them.
	if (theArray[first] > theArray[mid])
		swap(theArray, first, mid);
}//end sortFirstMiddleLast

 /** Partitions an array into three sections using a median-of-three
 pivot selection.
 @pre theArray has at least 4 elements
 @post items less than pivot value are before pivot. Items greater than pivot
 value are after pivot.*/
template <class ItemType>
int partition(ItemType theArray[], int first, int last)
{
	//choose pivot & move it to end to get out of the way.
	int mid = first + (last - first) / 2;
	sortFirstMiddleLast(theArray, first, mid, last);
	//using last-1 because last is already sorted to the correct partition.
	swap(theArray, mid, last - 1);
	int pivotIndex = last - 1;
	ItemType pivotValue = theArray[pivotIndex];

	//begin comparing items in unsorted array with pivot
	int indexFromLeft = first + 1;
	int indexFromRight = last - 2;

	//"done" indicates we are done partitioning the array
	bool done = false;

	while (!done)
	{
		//locate first entry on left that >= pivot
		while (theArray[indexFromLeft] < pivotValue)
			indexFromLeft = indexFromLeft + 1;

		//locate first entry on right that <= pivot
		while (theArray[indexFromRight] > pivotValue)
			indexFromRight = indexFromRight - 1;

		//if indexFromLeft and indexFromRight are in wrong partitions
		//swap them
		if (indexFromLeft < indexFromRight)
		{
			swap(theArray, indexFromLeft, indexFromRight);
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;
		}//end if

		else
			done = true;
	}//end while

	 //put the pivot back in the center of the array.
	swap(theArray, pivotIndex, indexFromLeft);
	pivotIndex = indexFromLeft;

	return pivotIndex;
}//end partition

 /** Sorts an array into ascending order. Arrays of < 4 elements
 are sorted using insertionSort.
 @pre	theArray[first...last] is an array
 @post	theArray is sorted
 @param	theArray is an array
 @param	first is index of first element of the array
 @param	last is index of last element of the array*/
template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{
	const int MIN_SIZE = 4;

	//if array is smaller than min_size, insertion sort.
	if ((last - first + 1) < MIN_SIZE)
	{
		cout << "Calling insertionSort with size = " << last - first + 1
			<< endl;
		insertionSort(theArray, first, last);
	}//end if

	else
	{
		//create the partitions: S1 | Pivot | S2
		int pivotIndex = partition(theArray, first, last);

		cout << "Calling quicksort with left side = " << (pivotIndex - 1) - first + 1;
		cout << " and right side = " << last - (pivotIndex + 1) + 1 << endl;

		//sort subarrays S1 and S2
		quickSort(theArray, first, pivotIndex - 1);
		quickSort(theArray, pivotIndex + 1, last);
	}//end if
}// end quickSort

 /** Displays the array contents.*/
template <class ItemType>
void display(ItemType anArray[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		cout << anArray[i] << ", ";
	}//end for

	cout << anArray[size - 1] << endl;
}//end display

#endif

/****************************************************************************************************************************
Title          :   Sorter.cpp
Auhor          :   Nigel Ferrer
Modified By    :   Kelly Camacho
Description    :   implementation file of an integer array container class that 
                   contains implementations of some sorting algorithms
Dependencies   :   Sorter.cpp
****************************************************************************************************************************/

#include "Sorter.hpp"
using namespace std;

Sorter::Sorter(array_type type, size_t array_size, int *arr) : type_(type), SIZE_(array_size), values_(arr)
{
}

/***************************s* Selection Sort ****************************/
template <typename Comparator>
int Sorter::getPosOfMinOrMax(int arr[], int from, int to, const Comparator &comp)
{
    int min_or_max = from;
    for (int i = from + 1; i <= to; i++)
    {
        if (comp(arr[i], arr[min_or_max]))
        {
            min_or_max = i;
        }
    }
    return min_or_max;
}

template <typename Comparator>
int Sorter::selectionSort(int arr[], size_t size, const Comparator &comp)
{
    bool able_to_sort = size > 0;

    if (able_to_sort) {

        for (int first = 0; first < size - 1; first++){

            int index_ = getPosOfMinOrMax(arr, first, size - 1, comp);
            if (arr[index_] != arr[first]) {
                swap(arr[index_], arr[first]);
                selectionCount_++; //increase counter
            }   //end if
            
        }   // end for

    }   //end if

    return selectionCount_;
}   //end Selection Sort
/************************************************************************/


/**************************** Insertion Sort ****************************/
template <typename Comparator>
int Sorter::insertionSort(int arr[], size_t size, const Comparator &comp)
{
    for (int unsorted = 1; unsorted < size; unsorted++) {

        int current = unsorted; // currently being inserted
        while ((current > 0) && comp(arr[current], arr[current -1])) {

            if (arr[current] != arr[current - 1]) {
                swap(arr[current], arr[current - 1]); // swap 
                insertionCount_++; //increase counter
            }   //end if
            
            current--;
        }  // end while

    }    // end for

    return insertionCount_;
}   //end Insertion Sort
/************************************************************************/


// /****************************** Merge Sort ******************************/
template <typename Comparator>
void Sorter::merge(int arr[], int from, int mid, int to, const Comparator &comp)
{
    //Left Side Array
    int left_mid = mid - from + 1; //left size
    int Left[left_mid]; //array of right side  

    for (int i = 0; i < left_mid; i++) {
        Left[i] = arr[from + i];
    }   //end for


    //Right Side Array
    int right_mid = to - mid; //right size
    int Right[right_mid]; //array of right side

    for (int j = 0; j < right_mid; j++) {
        Right[j] = arr[mid + j + 1];
    }   //end for


    /************ Merge Together ************/
    
    int l_index_ = 0;
    int r_index_ = 0;
    int arr_index_ = from;

    while (l_index_ < left_mid && r_index_ < right_mid) {
        if (comp(Left[l_index_], Right[r_index_])) { //correct on left
            arr[arr_index_] = Left[l_index_];
            l_index_++;
        }   //end if
        else if (comp(Right[r_index_], Left[l_index_])) { //correct of right
            arr[arr_index_] = Right[r_index_];
            r_index_++;
        }   //end if

        arr_index_++;
        mergeCount_++;
    }   //end while


    //remaining in Left
    while (l_index_ < left_mid) {
        arr[arr_index_] = Left[l_index_];
        arr_index_++;
        l_index_++;
        mergeCount_++;
    }   //end if

    //remaining in Right
    while (r_index_ < right_mid) {
        arr[arr_index_] = Right[r_index_];
        arr_index_++;
        r_index_++;
        mergeCount_++;
    }   //end if

}   //end Merge

template <typename Comparator>
int Sorter::mergeSort(int arr[], int from, int to, const Comparator &comp)
{
    bool able_to_sort = to > from;
    if (able_to_sort) {
        int middle = (from + to)/2;

        mergeSort(arr, from, middle, comp); //left side
        mergeSort(arr, middle + 1, to, comp); //right size
        merge(arr, from, middle, to, comp);
    }   //end if
    
    return mergeCount_;
}   //end Merge Sort
// /************************************************************************/

void Sorter::runSorts(sort_order order)
{

    int selectionValues[SIZE_];
    int insertionValues[SIZE_];
    int mergeValues[SIZE_];

    if (type_ == RANDOM)
    {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = rand() % 100;
            insertionValues[i] = rand() % 100;
            mergeValues[i] = rand() % 100;
        }
    }

    else
    {
        for (int i = 0; i < SIZE_; i++)
        {
            selectionValues[i] = values_[i];
            insertionValues[i] = values_[i];
            mergeValues[i] = values_[i];
        }
    }

    // Selection Sort Display
    std::cout << "******** Selection Sort ********\nOriginal Array:\n";
    displayArr(selectionValues);
    if (order == INCREASING)
    {
        selectionSort(selectionValues, SIZE_, std::less<int>());
    }
    else
    {
        selectionSort(selectionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(selectionValues);
    std::cout << "\nNumber of swaps: " << selectionCount_ << "\n********************************\n\n";

    // Insertion Sort Display
    std::cout << "\n******** Insertion Sort ********\nOriginal Array:\n";
    displayArr(insertionValues);
    if (order == INCREASING)
    {
        insertionSort(insertionValues, SIZE_, std::less<int>());
    }
    else
    {
        insertionSort(insertionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(insertionValues);
    std::cout << "\nNumber of swaps: " << insertionCount_ << "\n********************************\n\n";

    // Merge Sort Display
    std::cout << "\n********** Merge Sort **********\nOriginal Array:\n";
    displayArr(mergeValues);
    if (order == INCREASING)
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::less<int>());
    }
    else
    {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(mergeValues);
    std::cout << "\nNumber of comparisons: " << mergeCount_ << "\n********************************\n\n";

}

void Sorter::displayArr(const int array[]) const
{
    for (size_t i = 0; i < SIZE_; i++)
    {
        std::cout << array[i];
        (i < SIZE_ - 1) ? (cout << " ") : (cout << "\n");
    }
}
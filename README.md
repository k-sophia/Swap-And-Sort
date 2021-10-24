# Swap-And-Sort

Implement four canonical sorting algorithms within the Sorter class. In order to successfully complete this project, you must understand the following 
sorting algorithms: Selection, Insertion, and Merge Sort.

## Implementation

Work incrementally! Work through the tasks sequentially (implement and test). Only move on to a task when you are positive that the previous one has 
been completed correctly. Remember that the names of function prototypes and member variables must exactly match those declared in the respective header 
file when implementing a class.

You are given ```Sorter.hpp``` and ```Sorter.cpp```.

___
Task 0   Getting Started
___

Please thoroughly read and experiment with the code base given to you in the Starter Code folder. Create a main file and figure out how to instantiate 
```Sorter``` objects. Read the ```unSorts()``` function to see how everything will come together once you have finished this project. You will only be 
able to test your project as you work if you understand how to use what has been given to you.

___
Task 1   There Is No Better Time Than Now To Sort…
___

Modify the ```Sorter``` class to implement the following sorting algorithms: Selection, Insertion, and Merge sort. For our purposes comparators are simple 
objects that evaluate to a boolean value.

For example, if we have ```comp <- std::less<int>()```, then ```comp(0, 1)``` will evaluate to true.

Please reread the implementation of ```getPosOfMinOrMax()``` to see how we use comparators.

*Hints*: use ```getPosOfMinOrMax()``` within ```selectionSort()```. You can make ```displayArr()``` a public function for testing purposes but please make 
it private once you move on to the following task.

___
Task 2   Tootsie Slide
___

Modify ```selectionSort()``` and ```insertionSort()``` to increment their respective private count variables when a swap has taken place. Also, modify 
```mergeSort()``` to increment its private count variable when a comparison between elements within the array it is processing is made. Once this has been 
completed ```runSorts()``` should not crash your test file and should give you some deterministic output.

Here is an example of what the output of ```runSorts()``` should look like if you finished all tasks correctly:

```
Sorter abc(RANDOM, 10);
def.runSorts(INCREASING);

******** Selection Sort ********
Original Array:
12 39 2 58 74 26 81 63 36 62

Sorted Array:
2 12 26 36 39 58 62 63 74 81

Number of swaps: 7
********************************


******** Insertion Sort ********
Original Array:
91 24 29 37 77 19 54 11 16 75

Sorted Array:
11 16 19 24 29 37 54 75 77 91

Number of swaps: 27
********************************


********** Merge Sort **********
Original Array:
37 9 75 60 1 78 89 88 6 73

Sorted Array:
1 6 9 37 60 73 75 78 88 89

Number of comparisons: 34
********************************
```

___
**Testing**

How to compile:

```
g++ Sorter.cpp <main file> -std=c++17
```

You must always implement and test you programs INCREMENTALLY!!! What does this mean? Implement and test one method at a time. **For each class**

* Implement one function/method and test it thoroughly (multiple test cases + edge cases if applicable).
* Implement the next function/method and test in the same fashion. 
  * **How do you do this?** Write your own main() function to test your classes. Choose the order in which you implement your methods so that you 
    can test incrementally: i.e. implement mutator functions before accessor functions. Sometimes functions depend on one another. If you need to 
    use a function you have not yet implemented, you can use stubs: a dummy implementation that always returns a single value for testing. Don’t 
    forget to go back and implement the stub!!! If you put the word STUB in a comment, some editors will make it more visible.














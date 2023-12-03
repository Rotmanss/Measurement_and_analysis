//#include <iostream>


//double calculateDerivative(double (*func)(double), double x, double h = 1e-5)
//{
//    return (func(x + h) - func(x - h)) / (2 * h);
//}


//int main() {
    
//    for (double i = 0; i < 1000000000; i++) {
//        double x = i * i;
        //std::cout << "The derivative of f(x) at x = " << x << ", f'(x) = " << calculateDerivative([](double x) { return x * x; }, x) << std::endl;
//    }

//    return 0;
//}


#include <iostream>
#include <vector>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

// Function to partition the vector
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform QuickSort
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a vector of 10,000 random numbers between 1 and 100
    vector<int> numbers;
    for (int i = 0; i < 1000000; i++) {
        numbers.push_back(rand() % 100 + 1);
    }

    // Display the unsorted vector (optional)
    // cout << "Unsorted Vector:" << endl;
    // for (int num : numbers) {
    //     cout << num << " ";
    // }
    // cout << endl;

    // Perform QuickSort on the vector
    quickSort(numbers, 0, numbers.size() - 1);

    cout << "Sorted Vector:" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


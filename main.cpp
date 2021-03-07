#include <iostream>
#include <vector>

void print(std::vector<int> data, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

int linearSearch(std::vector<int> data, int size, int value)
{
    int index = 0;      // Position during search of the data.
    int position = -1;  // Position of the value searched for (set when found and returned at end)
    bool found = false; // Flag (is set true when/if the value was found)
    while (index < size && !found)
    {
        if (data[index] == value) // If the value is found
        {
            found = true;     // Set the flag
            position = index; // Set the position of the found value
        }
        index++; // Go to the next element
    }
    return position; // Return the position, or -1
}

int binarySearch(std::vector<int> data, int size, int value)
{
    int first = 0,       // First element
        last = size - 1, // Last element
        middle,          // Mid of search
        position = -1;   // Position of the value searched for
    bool found = false;  // Flag (is set true when/if the value was found)
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint
        if (data[middle] == value)   // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (data[middle] > value)  // If the search value is in lower half
            last = middle - 1;
        else                            // If the search value is in upper half
            first = middle + 1; 
    }
    return position;
}

int main()
{
    std::string str = "Hello";
    str += " World";
    std::cout << str + "!\n";

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    print(numbers, numbers.size());

    int search = 4;
    int position = 0;

    //Linear search
    position = linearSearch(numbers, numbers.size(), search);
    std::cout << "LINEAR: Number " << search << " is found at position: " << position + 1 << std::endl;

    //Binary search
    position = binarySearch(numbers, numbers.size(), search);
    std::cout <<  "BINARY: Number " << search << " is found at position: " << position + 1 << std::endl;
}
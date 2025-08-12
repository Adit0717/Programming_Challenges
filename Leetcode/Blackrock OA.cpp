/*
1.
You are given a string representing a list of cities and their corresponding distances from a fixed starting point (distance 0).
Multiple entries are separated by semicolons (;). 
The entries may appear in random order, and the distances represent the total distance from the starting point to each city, not the distance between adjacent cities.

Input:
A single line of input containing the city and distance pairs in the format:
<City1>:<Distance1>; <City2>:<Distance2>; ... <CityN>:<DistanceN>

Output:
Print the relative distances between consecutive cities as space-separated integers.

Example:
INPUT - ABCD:1; TRYU:7; POIU:4; VBYU:2
OUTPUT - 1 1 2 3

NOTE - This is relatively easy compared to FAANG questions., but the only difference is Input and output handling.
Big Tech requires candidates to write functions directly without worrying about input and other things whereas this assessment wants us to
manage Input / Output and Error blocks.

Input needs to be parsed which was quite challenging; but the algo is straightforward and simple
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input); // read the full line

    std::vector<int> distances;

    std::stringstream ss(input);
    std::string segment;

    // Step 1: Split by ';'
    while (std::getline(ss, segment, ';')) {
        // Remove leading/trailing whitespace
        segment.erase(0, segment.find_first_not_of(" \t"));
        segment.erase(segment.find_last_not_of(" \t") + 1);

        // Find ':' to extract distance
        size_t colonPos = segment.find(':');
        if (colonPos != std::string::npos) {
            std::string distanceStr = segment.substr(colonPos + 1);
            int distance = std::stoi(distanceStr);
            distances.push_back(distance);
        }
    }

    // Step 2: Sort distances
    std::sort(distances.begin(), distances.end());

    // Step 3: Calculate and print relative distances
    int prev = 0;
    for (int d : distances) {
        std::cout << d - prev << " ";
        prev = d;
    }

    std::cout << std::endl;

    return 0;
}

/*
2.
You are given a single input string consisting of two lines, separated by a newline character (\n). 
Each line contains multiple words — which can be either random characters or numbers — separated by spaces.

Task:
Write an efficient algorithm to identify all the words that appear in both lines.

INPUT:
A single string

OUTPUT:
Print out all the common characters.

The solution should handle multiple occurrences of the same word gracefully (i.e., output unique common words only once).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string input;
    // Read the entire input (2 lines)
    getline(cin, input);

    /* Find the position of the newline '\n' separating the two lines
       But since input is read as one string, input itself contains 2 lines separated by \n,
       if the input is literally two lines separated by a newline, then
       usually cin will read one line at a time.
       So we need to read two lines separately instead.
    */
    
    string line1, line2;
    getline(cin, line1);  // Read 1st line
    getline(cin, line2);  // Read 2nd line
    
    unordered_set<string> set1;
    stringstream ss1(line1);
    string word;
    
    // Insert words from first line into set1
    while (ss1 >> word) {
        set1.insert(word);
    }
    
    unordered_set<string> common;
    stringstream ss2(line2);
    
    // Check words in 2nd line for commonality
    while (ss2 >> word) {
        if (set1.find(word) != set1.end()) {
            common.insert(word);  // Use set to avoid duplicates
        }
    }
    
    // Print common words
    for (const auto& w : common) {
        cout << w << " ";
    }
    cout << "\n";
    
    return 0;
}

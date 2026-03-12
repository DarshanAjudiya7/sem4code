#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

class MarksManager {
    vector<int> marks;
public:
    bool readMarksFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) return false;
        cout << "Reading of marks completed" << endl;
        int m;
        while (file >> m) marks.push_back(m);
        return true;
    }

    double calculateMean() const {
        if (marks.empty()) return 0;
        return (double)accumulate(marks.begin(), marks.end(), 0) / marks.size();
    }

    double calculateVariance(double mean) const {
        if (marks.empty()) return 0;
        double sum = 0;
        for (int m : marks) sum += (m - mean) * (m - mean);
        return sum / marks.size();
    }

    void printMarks() const {
        if (marks.empty()) { cout << "No marks available!" << endl; return; }
        cout << "Marks: ";
        for (int m : marks) cout << m << " ";
        cout << endl;
    }

    void displayResults() {
        double mean = calculateMean();
        double var = calculateVariance(mean);
        cout << "Mean: " << mean << endl;
        cout << "Variance: " << var << endl;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class KnapsackItem {
    int value;
    int weight;

public:
    KnapsackItem(int v, int w) : value(v), weight(w) {}

    int getValue() const {
        return value;
    }

    int getWeight() const {
        return weight;
    }

    double getValueToWeightRatio() const {
        if (weight == 0)
            return 0;
        return (double)value / weight;
    }

    void display() const {
        cout << "Value: " << value
             << ", Weight: " << weight
             << ", Value/Weight Ratio: "
             << getValueToWeightRatio() << endl;
    }
};

class KnapsackManager {
    vector<KnapsackItem> items;

public:
    void addItem(int value, int weight) {
        items.push_back(KnapsackItem(value, weight));
    }

    void sortItems() {
        sort(items.begin(), items.end(),
             [](const KnapsackItem& a, const KnapsackItem& b) {
                 return a.getValueToWeightRatio() >
                        b.getValueToWeightRatio();
             });
    }

    void displayItems() const {
        for (const auto& item : items)
            item.display();
    }
};

int main() {
    KnapsackManager manager;

    manager.addItem(60, 100);
    manager.addItem(10, 20);
    manager.addItem(120, 30);

    cout << "Items before sorting:" << endl;
    manager.displayItems();

    manager.sortItems();

    cout << "\nItems after sorting based on value/weight ratio:" << endl;
    manager.displayItems();

    return 0;
}
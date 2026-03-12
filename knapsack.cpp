#include<iostream>
#include<algorithm>
using namespace std;

// Structure to represent each warehouse item
struct Item {
    int profit;
    int weight;
};

Item items[1000];
int n;

// Sort items in decreasing order of profit/weight ratio
void sortItems() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((double)items[j].profit / items[j].weight <
                (double)items[j + 1].profit / items[j + 1].weight) {
                swap(items[j], items[j + 1]);
            }
        }
    }
}

void maximizeProfit(int capacity) {

    sortItems();

    double total_profit = 0;
    int total_weight = 0;

    cout << "\nItems selected for transportation:\n";

    for (int i = 0; i < n && capacity > 0; i++) {

        if (items[i].weight <= capacity) {
            cout << "Item " << i + 1 << " fully transported "
                 << "(Profit = " << items[i].profit
                 << ", Weight = " << items[i].weight << ")\n";

            capacity -= items[i].weight;
            total_weight += items[i].weight;
            total_profit += items[i].profit;
        }
        else {
            double fraction = (double)capacity / items[i].weight;

            cout << "Item " << i + 1 << " partially transported "
                 << "(Fraction = " << fraction << ")\n";

            total_profit += items[i].profit * fraction;
            total_weight += capacity;
            capacity = 0;
        }
    }

    cout << "\nTotal Weight Transported = " << total_weight << endl;
    cout << "Total Profit Earned = " << total_profit << endl;
}

int main() {

    cout << "Enter number of items in warehouse: ";
    cin >> n;

    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit >> items[i].weight;
    }

    int capacity;
    cout << "Enter maximum transportation weight limit: ";
    cin >> capacity;

    maximizeProfit(capacity);

    return 0;
}
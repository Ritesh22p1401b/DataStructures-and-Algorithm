#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& S, int target, vector<int>& subset, int index, int currentSum, bool& found) {
    if (currentSum == target) {
        found = true;
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    if (currentSum > target || index == S.size()) {
        return; // Backtrack
    }

    // Include S[index] in the subset
    subset.push_back(S[index]);
    backtrack(S, target, subset, index + 1, currentSum + S[index], found);
    
    // Exclude S[index] and backtrack
    subset.pop_back();
    backtrack(S, target, subset, index + 1, currentSum, found);
}

int main() {
    vector<int> S = {1, 2, 5, 6, 8};
    int target = 9;

    vector<int> subset;
    bool found = false;

    cout << "Subsets that sum to " << target << ":" << endl;
    backtrack(S, target, subset, 0, 0, found);

    if (!found) {
        cout << "No subset found with the given sum." << endl;
    }

    return 0;
}

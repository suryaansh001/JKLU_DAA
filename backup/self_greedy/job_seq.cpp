#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct job {
    int profit;
    int deadline;
};

bool sort_deadline(const job &a, const job &b) {
    return a.deadline < b.deadline;
}

void job_sequencing(vector<job> &jobs) {
    sort(jobs.begin(), jobs.end(), sort_deadline);

    cout << "Jobs sorted by deadline:" << endl;
    for (const auto &j : jobs) {
        cout << "Profit: " << j.profit << ", Deadline: " << j.deadline << endl;
    }

    vector<job> results;
    for (int i = 0; i < jobs.size(); i++) {
        bool found = false;
        for (int j = 0; j < results.size(); j++) {
            if (jobs[i].deadline == results[j].deadline) {
                found = true;
                if (jobs[i].profit > results[j].profit) {
                    results[j] = jobs[i];
                }
                break;
            }
        }
        if (!found) {
            results.push_back(jobs[i]);
        }
    }

    cout << "Selected jobs:" << endl;
    for (const auto &j : results) {
        cout << "Profit: " << j.profit << ", Deadline: " << j.deadline << endl;
    }
}

int main() {
    int size;
    cout << "Enter the number of jobs: ";
    cin >> size;

    vector<job> jobs(size);
    for (int j = 0; j < size; j++) {
        cout << "Enter the profit for job " << j + 1 << ": ";
        cin >> jobs[j].profit;
        cout << "Enter the deadline for job " << j + 1 << ": ";
        cin >> jobs[j].deadline;
    }

    job_sequencing(jobs);

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
//
// struct job {
//     int profit;
//     int deadline;
// };
//
// bool sort_deadline(const job &a, const job &b) {
//     return a.deadline < b.deadline;
// }
//
//
// void job_sequencing(vector<job> &jobs) {
//     sort(jobs.begin(), jobs.end(), sort_deadline);
//
//     cout << "Jobs sorted by deadline:" << endl;
//     for (const auto &j : jobs) {
//         cout << "Profit: " << j.profit << ", Deadline: " << j.deadline << endl;
//     }
//     vector<job> results(jobs.size());
//     for (int i=0;i<jobs.size();i++){
//         //checking if there are more than one entries of deadline ==1
//         results.push_back(max())
//
//     }
//
// }
//
// int main() {
//     int size;
//     cout << "Enter the number of jobs: ";
//     cin >> size;
//
//     vector<job> jobs(size);
//     for (int j = 0; j < size; j++) {
//         cout << "Enter the profit for job " << j + 1 << ": ";
//         cin >> jobs[j].profit;
//         cout << "Enter the deadline for job " << j + 1 << ": ";
//         cin >> jobs[j].deadline;
//     }
//
//     job_sequencing(jobs);
//
//     return 0;
// }
//

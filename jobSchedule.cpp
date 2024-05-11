#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    string id;
    int profit;
    int deadline;

    Job(string _id, int _profit, int _deadline) : id(_id), profit(_profit), deadline(_deadline) {}
};

// Comparator function to sort jobs in descending order of profit
bool compare(Job& a, Job& b) {
    return a.profit > b.profit;
}

vector<string> jobSequence(vector<Job>& jobs) {
    // Sort jobs in descending order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Create a list of available time slots
    vector<bool> slots(maxDeadline, false);

    // Create a list to store the scheduled jobs
    vector<string> schedule;

    // Iterate over the jobs and schedule them in the latest available time slot before the deadline
    for (auto job : jobs) {
        // Find the latest available time slot before the deadline
        for (int i = job.deadline - 1; i >= 0; --i) {
            if (!slots[i]) {
                slots[i] = true;
                schedule.push_back(job.id);
                break;
            }
        }
    }
    return schedule;
}

int main() {
    // Example input
    vector<Job> jobs = {{"J1", 3, 1}, {"J2", 5, 3}, {"J3", 20, 4}, {"J4", 18, 3}, {"J5", 0, 2}, {"J6", 6, 1},{"J7", 30, 2}};

    // Test the function
    vector<string> output = jobSequence(jobs);
    cout << "Scheduled Jobs: ";
    for (const string& job : output) {
        cout << job << " ";
    }
    cout << endl;

    return 0;
}
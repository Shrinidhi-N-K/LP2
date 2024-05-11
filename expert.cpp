#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<string> MENTAL_HEALTH_QUESTIONS = {
        "Have you been experiencing persistent feelings of sadness or hopelessness?",
        "Do you find it difficult to enjoy activities that you used to find pleasurable?",
        "Have you been experiencing changes in appetite or weight?",
        "Are you having trouble sleeping or sleeping too much?",
        "Do you have low energy or fatigue most days?",
        "Have you been feeling excessively guilty or worthless?",
        "Do you have difficulty concentrating or making decisions?",
        "Have you had thoughts of harming yourself or others?",
        "Do you feel anxious or on edge most of the time?",
        "Have you been experiencing panic attacks or sudden feelings of intense fear?",
        "Do you have intrusive thoughts or obsessions that are distressing?",
        "Have you been engaging in compulsive behaviors or rituals?",
        "Are you experiencing hallucinations or delusions?",
        "Have you been using substances (such as drugs or alcohol) to cope with your feelings?",
};

map<string, int> MENTAL_HEALTH_THRESHOLD = {
    {"Mild", 3},
    {"Moderate", 6},
    {"Severe", 9},
};

void mental_health_expert_system(vector<string> questions, map<string, int> threshold) {
    int score = 0;
    for (string question : questions) {
        cout << question << " (y/n)" << endl;
        string ans;
        getline(cin, ans);
        while (ans != "y" && ans != "n") {
            cout << "Invalid input! Please enter 'y' for Yes or 'n' for No." << endl;
            getline(cin, ans);
        }
        if (ans == "y") {
            score += 1;
        }
    }
    cout<<"\n\n";
    if (score >= threshold["Severe"]) {
        cout << "Based on your answers, it seems like you're experiencing severe mental health symptoms." << endl;
        cout << "Immediate intervention may be necessary. Please seek help from a mental health professional or visit the nearest mental health facility." << endl;
    } else if (score >= threshold["Moderate"]) {
        cout << "Based on your answers, it seems like you're experiencing moderate mental health symptoms." << endl;
        cout << "It's important to seek help from a mental health professional to address your symptoms." << endl;
    } else if (score >= threshold["Mild"]) {
        cout << "Based on your answers, it seems like you're experiencing mild mental health symptoms." << endl;
        cout << "Consider reaching out to a mental health professional for support and guidance." << endl;
    } else {
        cout << "Based on your answers, it seems like you're not experiencing significant mental health symptoms at this time." << endl;
        cout << "However, it's still important to prioritize self-care and seek help if you're struggling." << endl;
    }

    cout << "\nFor immediate assistance, you can contact:" << endl;
    cout << "- National Suicide Prevention Lifeline: 1-800-273-TALK (8255)" << endl;
    cout << "- Crisis Text Line: Text HOME to 741741" << endl;
    cout << "- Your local mental health services or emergency services" << endl;
}

int main() {
    cout << "\n\n\t\tWelcome To The Mental Health Expert System\n" << endl;
    cout << "\tNote: Please answer the following questions honestly.\n\n" << endl;
    mental_health_expert_system(MENTAL_HEALTH_QUESTIONS, MENTAL_HEALTH_THRESHOLD);

    return 0;
}
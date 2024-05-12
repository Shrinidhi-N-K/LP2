#include <iostream>
#include <string>
#include <map>

using namespace std;

class CustomerServiceChatbot {
private:
    map<string, map<string, string>> context; // Map to store context

public:
    CustomerServiceChatbot() {
        // Initialize context with default values
        context["camera"] = {{"size", "36 MP"}, {"price", "$500"}};
        context["screen"] = {{"size", "6.5 inches"}, {"price", "$200"}};
        context["sim"] = {{"size", "Nano-SIM"}, {"price", "$20"}};
        context["ram"] = {{"size", "8 GB"}, {"price", "$100"}};
        context["memory"] = {{"size", "128 GB"}, {"price", "$50"}};
        context["battery"] = {{"size", "4000 mAh"}, {"price", "$80"}};
        context["current_context"] = {{"context", "None"}}; // Initialize current context to None
    }

    void handleUserInput(const string& userInput) {
        // Check if user input contains a keyword from context
        for (const auto& pair : context) {
            if (userInput.find(pair.first) != string::npos) {
                // Update current context
                context["current_context"] = pair.second;

                // Provide response based on context
                cout << "Chatbot: ";
                 if (userInput == pair.first) { // Check if userInput is exactly equal to the keyword
                cout << "Size of " << pair.first << " is " << pair.second.at("size") << "." << endl;
                cout << "Price of " << pair.first << " is " << pair.second.at("price") << "." << endl;
            }
            else{
            if (userInput.find("size") != string::npos) {
                    cout << "Size of " << pair.first << " is " << pair.second.at("size") << "." << endl;
                }
                if (userInput.find("price") != string::npos) {
                    cout << "Price of " << pair.first << " is " << pair.second.at("price") << "." << endl;
                } 
                if(userInput.find("size") == string::npos && userInput.find("price") == string::npos){
                    cout << "I'm sorry, I didn't understand your query. Could you please rephrase?" << endl;
                }
            }
                return;
            }
        }

        // If no context matches, use previously stored context
        if (context["current_context"]["context"] != "None") {
            cout << "Chatbot: ";
            if (userInput.find("size") != string::npos) {
                cout << "Size of " << context["current_context"]["context"] << " is " 
                     << context["current_context"].at("size") << "." << endl;
            } else if (userInput.find("price") != string::npos) {
                cout << "Price of " << context["current_context"]["context"] << " is " 
                     << context["current_context"].at("price") << "." << endl; // Access price directly from the context
            } else {
                cout << "I'm sorry, I didn't understand your query. Could you please rephrase?" << endl;
            }
        } else {
            cout << "Chatbot: I'm sorry, I didn't understand your query. Could you please provide more context?" << endl;
        }
    }
};

int main() {
    CustomerServiceChatbot chatbot;

    cout << "Welcome to Customer Service Chatbot" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;

    string userInput;
    while (true) {
        cout << "User: ";
        getline(cin, userInput);

        if (userInput == "bye") {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        chatbot.handleUserInput(userInput);
    }

    return 0;
}

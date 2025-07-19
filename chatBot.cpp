#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), 
              [](unsigned char c){ return tolower(c); });
    return lowerStr;
}


string getAIResponse(const string& userInput) {
    string input = toLower(userInput);
    
    
    if (input.find("hello") != string::npos || input.find("hi") != string::npos) {
        return "Hello there! How can I help you today?";
    }
    else if (input.find("how are you") != string::npos) {
        return "I'm just a computer program, but I'm functioning well. Thanks for asking!";
    }
    else if (input.find("name") != string::npos) {
        return "I'm a simple AI chatbot. You can call me ChatBot.";
    }
    else if (input.find("bye") != string::npos || input.find("goodbye") != string::npos) {
        return "Goodbye! Have a nice day!";
    }
    else if (input.find("thank") != string::npos) {
        return "You're welcome!";
    }
    else {
        vector<string> defaults = {
            "Interesting. Tell me more.",
            "I see. Can you elaborate?",
            "I'm not sure I understand. Could you rephrase that?",
            "That's a good point. What else is on your mind?"
        };
        return defaults[rand() % defaults.size()];
    }
}

int main() {
    cout << "Simple AI Chatbot (type 'bye' to exit)\n";
    cout << "------------------------------------\n";
    
    string userInput;
    while (true) {
        cout << "You: ";
        getline(cin, userInput);
        
        if (toLower(userInput) == "bye") {
            cout << "AI: " << getAIResponse(userInput) << endl;
            break;
        }
        
        cout << "AI: " << getAIResponse(userInput) << endl;
    }
    
    return 0;
}
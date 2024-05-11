import random
import re

responses = {
    "greeting": ["Greetings! Welcome to our mobile repair center. How may I assist you today?", "Hello! What can I do for you regarding your mobile?", "Welcome! What's the issue with your phone?"],
    "farewell": ["Thanks for choosing our mobile repair services. Have a wonderful day!", "We prioritize your satisfaction. Goodbye!", "Feel free to ask if you have more questions. Goodbye and take care!"],
    "help": ["Of course, I'm here to assist. What problems are you encountering with your mobile?", "How may I aid you with your mobile repair? Please share the details.", "I'm here to provide the best solutions for your mobile issues. What do you need help with?"],
    "screen_cracked": ["A cracked screen is a common problem. We can replace the screen for you. Please bring your mobile to our center, and our technicians will handle it.", "Oh no! A cracked screen can be quite annoying. But don't worry, we offer screen replacement services. Visit our center, and we'll fix it for you."],
    "battery_problem": ["If you're having battery issues, we can replace your mobile's battery. Bring it to our center, and we'll make sure it gets fixed.", "Battery problems are quite frequent. We can replace your mobile's battery with a new one. Please visit our center for help."],
    "software_issue": ["Software issues can often be fixed by resetting your mobile or updating its software. We can help you with that. Please bring your phone to our center, and our technicians will assist you.", "Software problems can be tricky. We suggest trying a software reset or update. If the issue continues, our technicians can help you further. Just visit our center."],
    "water_damage": ["Water damage can be severe for mobiles. We recommend immediately turning off your device and bringing it to our center for professional repair. Please refrain from powering it on.", "Water damage needs immediate attention. Please switch off your mobile, remove any SIM cards or memory cards, and bring it to our center. Our experts will evaluate the damage and propose a suitable solution."],
    "default": ["I apologize, but I couldn't comprehend your request.", "Apologies, I didn't quite understand that. Could you please rephrase?", "I'm still learning. Can you provide more details?", "Sorry, your request is beyond my knowledgebase."],
    "welcome": ["You're welcome!", "Not a problem!", "Always here to help!"]
}

def respond_to_inquiry(inquiry):
    inquiry = inquiry.lower()
    if re.search(r"\b(?:hello|hi)\b", inquiry):
        return random.choice(responses["greeting"])
    elif re.search(r"\b(?:goodbye|bye)\b", inquiry):
        return random.choice(responses["farewell"])
    elif re.search(r"\b(?:help|support)\b", inquiry):
        return random.choice(responses["help"])
    elif re.search(r"\b(?:screen|cracked)\b", inquiry):
        return random.choice(responses["screen_cracked"])
    elif re.search(r"\b(?:battery|charge)\b", inquiry):
        return random.choice(responses["battery_problem"])
    elif re.search(r"\b(?:software|update|reset)\b", inquiry):
        return random.choice(responses["software_issue"])
    elif re.search(r"\b(?:water|damage)\b", inquiry):
        return random.choice(responses["water_damage"])
    elif re.search(r"\b(?:thank|thanks)\b", inquiry):
        return random.choice(responses["welcome"])
    else:
        return random.choice(responses["default"])

print("\n\nWelcome to the Customer Interaction Chatbot!")
print("Type 'exit' to end the conversation.\n")

while True:
    user_input = input("Customer: ")

    if user_input.lower() == "exit":
        break

    bot_response = respond_to_inquiry(user_input.lower())
    print("Chatbot: " + bot_response + "\n")

print("\nThank you for using the Customer Interaction Chatbot. Goodbye!")
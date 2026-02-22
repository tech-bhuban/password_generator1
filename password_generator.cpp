

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

class PasswordGenerator {
private:
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string digits = "0123456789";
    std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    
public:
    PasswordGenerator() { srand(time(0)); }
    
    std::string generate(int length, bool useUpper, bool useLower, 
                        bool useDigits, bool useSpecial) {
        std::string chars = "";
        std::string password = "";
        
        if(useUpper) chars += uppercase;
        if(useLower) chars += lowercase;
        if(useDigits) chars += digits;
        if(useSpecial) chars += special;
        
        if(chars.empty()) return "Error: No character types selected!";
        
        for(int i = 0; i < length; i++) {
            password += chars[rand() % chars.length()];
        }
        return password;
    }
    
    int checkStrength(const std::string& password) {
        int score = 0;
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        
        for(char c : password) {
            if(isupper(c)) hasUpper = true;
            else if(islower(c)) hasLower = true;
            else if(isdigit(c)) hasDigit = true;
            else hasSpecial = true;
        }
        
        if(password.length() >= 8) score++;
        if(hasUpper) score++;
        if(hasLower) score++;
        if(hasDigit) score++;
        if(hasSpecial) score++;
        
        return score;
    }
};

int main() {
    PasswordGenerator pg;
    std::string password = pg.generate(12, true, true, true, true);
    int strength = pg.checkStrength(password);
    
    std::cout << "Generated Password: " << password << "\n";
    std::cout << "Strength (1-5): " << strength << "/5\n";
    return 0;
}


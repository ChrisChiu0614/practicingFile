#include <iostream>
#include <cstdlib> // For system() function
#include <termios.h> // For terminal input

// Function to read a single character from terminal
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}

int main() {
    char choice;
    std::cout << "Press 'P' and choose an option (p: pwd, l: ls): ";
    choice = getch();
    std::cout << std::endl;

    if (choice == 'p' || choice == 'P') {
        // Execute pwd command
        system("pwd");
    } else if (choice == 'l' || choice == 'L') {
        // Execute ls command
        system("ls");
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}

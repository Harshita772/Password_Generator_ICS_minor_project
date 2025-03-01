# Random Password Generator

## Objectives

The main objective of this project is to help users to create strong passwords for their accounts. It aims to provide a simple interface for generating passwords and evaluating strong passwords for their account.

## Functionalities

- **Password Strength Calculation:**
This program can calculate the strength of a user's password based on several criteria such as length, presence of numbers, uppercase and lowercase letters, and special characters. 

- **Random Password Generation:**
This program can generate random passwords that meet all the necessary criteria for a strong password, with a 100% strength guarantee. 

- **User-Friendly Interface**
And also this program has a user-friendly interface that is menu-driven, making it easy for users to either enter their own passwords or generate random ones.

## Prerequisites

- **C Compiler:**
 A C compiler should be installed on your system (e.g., GCC).
- **Basic Command Line Knowledge:**
Basic Command Line Knowledge: Familiarity with using the command line interface.


3. **Follow On-Screen Instructions:**
   - The program will greet you and provide basic instructions.
   - It will enter your password when prompted, ensuring it meets the minimum criteria.
   - Choose from the menu options:
     - Option 1: Calculate the strength of your entered password.
     - Option 2: Generate a 100% strong random password.
     - Option 3: Exit the program.

4. **Interpret Results:**
   - The program will display the strength of your password as a percentage.
   - If you choose to generate a random password, it will be displayed on the screen.

5. **Exit the Program:**
   - Once you're done, select the option to exit the program.

## Working

The create_password function is a program to generate a strong random password of a specified length (len). This is achieved by utilizing arrays of characters representing different sets: digits (number), lowercase letters (lower), uppercase letters (upper), and special characters (charac). The function iterates through each set of characters and selects one character randomly, then adds it to the password array. This process will repeat until the desired length of the password is reached. After all characters are selected, the function shuffles the elements in the password array, so that randomness is ensured. Finally, it prints the generated password to the console, suggesting the user a 100% strong password. The randomness and variety of character sets used in this process contribute to the overall strength of the generated password.

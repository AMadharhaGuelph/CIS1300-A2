/************************madharhaAnkushA2.c**************
Student Name: Ankush Madharha     Email Id: amadharh@uoguelph.ca
Due Date: October 28th            Course Name: CIS 1300

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
1) I have read and understood the University policy on academic integrity. 
2) I have completed the Computing with Integrity Tutorial on Moodle; and 
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall

compiling:
gcc -std=c99 -Wall madharhaAnkushA2.c
Running: ./a.out
OR
gcc -std=c99 -Wall madharhaAnkushA2.c -o assn2
Running the Program: ./assn2
********************************************************/


/*
 readInput: Gets user input
 In: char str[MAX]
 Out: None
 Post: input is sotred in str
*/
void readInput(char str[MAX])
{
    // Get the user input using fgets
    fgets(str, MAX, stdin);

    // Remove the \n that gets added from fgets from the end of ths string
    str[strlen(str) - 1] = '\0';
}

/*
 findStats: Count the specials characters, uppercase, lowercase, and numbers in str
 In: char str[MAX], int *countSpecialChars, int *countUpperCase, int *countLowerCase, int *countNumbers
 Out: None
 Post: countSpecialChars, countUpperCase, countLowerCase, countNumbers store respective values depending on str
*/
void findStats(char str[MAX], int *countSpecialChars, int *countUpperCase, int *countLowerCase, int *countNumbers)
{
    // Initalize variables to 0
    *countSpecialChars = 0;
    *countUpperCase = 0;
    *countLowerCase = 0;
    *countNumbers = 0;

    // Goes through each character in str
    for (int i = 0; i < strlen(str); i++)
    {
        // Executes if current character is puncuation or a space
        if (ispunct(str[i]) || isspace(str[i]))
        {
            // Increment countSpecialChars by 1
            *countSpecialChars += 1;
        }
        // Executes if current character is uppercase
        else if (isupper(str[i]))
        {
            // Increment countUpperCase by 1
            *countUpperCase += 1;
        }
        // Executes is current character is lowercase
        else if (islower(str[i]))
        {
            // Increment countLowerCase by 1
            *countLowerCase += 1;
        }
        // Executes if character is none of the above (must be a number)
        else
        {
            // Increment countNumbers by 1
            *countNumbers += 1;
        }
    }
    printf("Special characters: %d\n", *countSpecialChars);
    printf("Upper characters: %d\n", *countUpperCase);
    printf("Lower characters: %d\n", *countLowerCase);
    printf("Number characters: %d\n", *countNumbers);
}

/*
 findTotalChancesGiven: Counts the unique digits in str (chances)
 In: char str[MAX]
 Out: int
 Post: Return amount of unique digits found in str, this is the chances the player gets
*/
int findTotalChancesGiven(char str[MAX])
{
    // Declare Variables
    int uniqueDigits[MAX];
    int uniqueDigitIndex;
    bool unique;

    // Initialize Variable 
    uniqueDigitIndex = 0;

    // Goes through each character in str
    for (int i = 0; i < strlen(str); i++)
    {
        // Executes if current character is a a digit
        if (isdigit(str[i]))
        {
            unique = true;
            // Goes through array containing unique digits
            for (int j = 0; j < uniqueDigitIndex; j++)
            {
                // Excutes if current digit in str is found in the unique digit array
                if (str[i] == uniqueDigits[j])
                {
                    // Set unique to false because the current digit in str is not unique
                    unique = false;
                }
            }
            // Executes if the current digit in str is unique (was not found in unique digit array)
            if (unique == true)
            {
                // Add the digit to the unique digits array, and increment the uniqueDigitIndex
                uniqueDigits[uniqueDigitIndex] = str[i];
                uniqueDigitIndex += 1;
            }
        }
    }
    // Returns uniqueDigitIndex, this is the amount of unique digits which is amount of chances 
    return uniqueDigitIndex;
}

/*
 extractDigits: Extracts the specific digits and amount of digits from str
 In: char str[MAX], int digitsInInputString[MAX]
 Out: int
 Post: Digits in str are stored in digitsInInputString, amount of digits in str is returned 
*/
int extractDigits(char str[MAX], int digitsInInputString[MAX])
{
    // Declare and Intialilze variable 
    int digitsInInputStringIndex;
    digitsInInputStringIndex = 0;

    // Goes throught the string str
    for (int i = 0; i < strlen(str); i++)
    {
        // Executes if current character in str is a digit
        if (isdigit(str[i]))
        {
            // Adds the digit to the digitsInInputString array, increments the index by 1
            digitsInInputString[digitsInInputStringIndex] = str[i] - '0';
            digitsInInputStringIndex += 1;
        }
    }
    // Returns digitsInInputStringIndex, the amount of digits in str
    return digitsInInputStringIndex;
}

/*
 checkPlayerMove: Checks to see if the player's input was correct
 In: int playersGuess, int digitsInInputString[MAX], int totalDigits
 Out: int
 Post: 1 will be returned if player input was correct, 0 is returned if player input was incorrect
*/
int checkPlayerMove(int playersGuess, int digitsInInputString[MAX], int totalDigits)
{
    // Goes through digitsInInputString array
    for (int i = 0; i < totalDigits; i++)
    {
        // Executes if current digit in digitsInInputString array is equal to players guess
        if (digitsInInputString[i] == playersGuess)
        {
            // Return 1 as the players guess was correct
            return 1;
        }
    }
    // Return 0 as the players guess was incorrect
    return 0;
}

/*
 updateDigits: updates the remainingDigits array
 In: int playersGuess, int remainingDigits[MAXD]
 Out: None
 Post: The digit in remainingDigits that is equal to players Guess will get replaced by -1
*/
void updateDigits(int playersGuess, int remainingDigits[MAXD])
{
    // Goes through remainingDigits array
    for (int i = 0; i < MAXD; i++)
    {
        // Executes if current digit in remainingDigits array is equal to players guess
        if (remainingDigits[i] == playersGuess)
        {
            // Replace current index of remainingDigits with -1
            remainingDigits[i] = -1;
        }
    }
}

/*
 displayDigits: Outputs the remaining digits
 In: int remainingDigits[MAXD]
 Out: None
 Post: The digits in remainingDigits array get outputted
*/
void displayDigits(int remainingDigits[MAXD])
{
    // Output prompt for user
    printf("Digits remaining are as follows - player picks one among these: ");
    // Goes through the remainingDigits array
    for (int i = 0; i < MAXD; i++)
    {
        // Executes if the current digit in remainingDigits is a -1
        if (remainingDigits[i] == -1)
        {
            // Output a space
            printf(" ");
        }
        // Executes if the current digit in remainingDigits is not a -1
        else
        {
            // Output the current digit
            printf("%d ", remainingDigits[i]);
        }
    }
}

/*
 displayXs: Outputs the X's (could be digits)
 In: char exes[MAX], int totalDigits
 Out: None
 Post: The exes array gets outputted
*/
void displayXs(char exes[MAX], int totalDigits)
{
    // Goes through the exes array
    for (int i = 0; i < totalDigits; i++)
    {
        // Prints the current character of the exes array
        printf("%c ", exes[i]);
    }
}

/*
 countXs: Counts the amount of X's in the array exes
 In: char exes[MAX], int totalDigits
 Out: int
 Post: Returns the amount of X's found in exes array
*/
int countXs(char exes[MAX], int totalDigits)
{
    // Declare and Initialize variable
    int xCounter;
    xCounter = 0;

    // Goes through the exes array
    for (int i = 0; i < totalDigits; i++)
    {
        // Executes if current character in exes array is X
        if (exes[i] == 'X')
        {
            // Increment the counter by 1
            xCounter += 1;
        }
    }
    // Return counter, this is the amount of X's
    return xCounter;
}
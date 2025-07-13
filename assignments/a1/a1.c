//
// Problem statement :
// 9.a. Decompose a given natural number in its prime factors.
//   b. Given a vector of numbers, find the longest contiguous subsequence such that any consecutive
//   elements contain the same digits.


#include <stdio.h>

void showMenu() {
    /*
     Shows the menu for the user to choose an option.
    */

    printf("\n");
    printf("MENU:\n");
    printf("1. Read a vector of numbers.\n");
    printf("2. Decompose a given natural number in its prime factors.\n");
    printf("3. Find the longest contiguous subsequence such that any consecutive elements contain the same digits.\n");
    printf("0. Exit.\n");
}

int readVector(int a[1001]) {
    /*
     Reads a vector from the user.
        a[1001] = the vector
        number = each number read
        length = the length of the vector
    */
    int number, length;

    printf("Number of elements in the vector: ");
    scanf("%d", &length);

    if (length == 0) {
        printf("Your vector is empty.\n");
    } else if (length < 0) {
        printf("Invalid input.\n");
    } else {
        printf("Enter the numbers: \n");
        for (int i = 0; i < length; i++) {
            scanf("%d", &number);
            a[i] = number;
        }

        printf("Your vector is: ");
        for (int i = 0; i < length; i++) {
            printf("%d ", a[i]);
        }
    }

    return length;
}

int readNumberToBeDecomposed() {
    int number;
    printf("Enter the number to be decomposed: ");
    scanf("%d", &number);
    return number;
}

int decompose(int primefactors[1001], int number) {
    int j = 0, n = 0;
    for (int i = 2; i <= number; i++) {
        if (number % i == 0) {
            primefactors[j] = i;
            j++;
            n++;
            while (number % i == 0) {
                number /= i;
            }
        }
    }
    return n;
}

void decomposePrimeFactors() {
    /*
    Decompose a given natural number in its prime factors.
        number = the number to be decomposed in its prime factors
    */
    int number, primefactors[1001], numFactors;
    number = readNumberToBeDecomposed();

    if (number < 0) {
        printf("Invalid input.\n");
    } else {
        numFactors = decompose(primefactors, number);
        printf("The prime factors are: ");
        for (int i = 0; i < numFactors; i++) {
            printf("%d ", primefactors[i]);
        }
    }
}

void initializeDigits(int digits[10], int number) {
    if (number == 0)
        digits[0] = 1;
    else {
        while (number != 0) {
            digits[number % 10]++;
            number = number / 10;
        }
    }
}

int checkDigits(int nr, int digits[10]) {
    int ok = 0;

    while (nr != 0 && ok == 0) {
        int c = nr % 10;
        if (digits[c] == 0)
            ok = 1;
        nr = nr / 10;
    }
    return ok;
}


void longestSubsequence(int a[1001], int length) {
    /*
    Given a vector of numbers, find the longest contiguous subsequence
    such that any consecutive elements contain the same digits.
        digits[10] = array which contains the digit and the number of appearances in the number
        currentSubseq = current subsequence
        currentLength = the length of the current subsequence
        longestSubseq = longest subsequence
        longestLength = the length of the longest subsequence
    */
    int digits[10] = {0};
    int currentSubseq[1001], longestSubseq[1001];
    int currentLength = 0, longestLength = 0;

    // Take the first element and put it in the current sequence
    currentSubseq[0] = a[0];
    currentLength++;

    // Initialize the digits vector for the first element in the vector
    initializeDigits(digits, currentSubseq[0]);

    int ok = 0; // ok = 0, the numbers have the same digits
                // ok = 1, the numbers have different digits

    for (int i = 1; i < length; i++) {
        int nr = a[i];
        ok = checkDigits(nr,digits);
        if (ok == 1) {

            // Check if the current seq is longer than the longest seq and update the longest seq if thats the case
            if (currentLength > longestLength) {
                longestLength = currentLength;
                for (int j = 0; j < currentLength; j++) {
                    longestSubseq[j] = currentSubseq[j];
                }
            }

            // Reinitialize the current subsequence and the digits
            currentSubseq[0] = a[i];
            currentLength = 1;

            for (int j = 0; j < 10; j++) {
                digits[j] = 0;
            }

            initializeDigits(digits, a[i]);
        } else {
            // Add to the current subsequence
            currentSubseq[currentLength++] = a[i];
        }
    }

    // Check in case the longest subsequence is at the end
    if (currentLength > longestLength) {
        longestLength = currentLength;
        for (int j = 0; j < currentLength; j++) {
            longestSubseq[j] = currentSubseq[j];
        }
    }

    printf("The longest contiguous subsequence is: ");
    for (int i = 0; i < longestLength; i++) {
        printf("%d ", longestSubseq[i]);
    }
    printf("\n");
}

int main() {
    /*
        option = the option the user chooses
        length = the vectors length
        a[1001] = the vector
     */

    int option, length = 0, a[1001];

    while (1) {
        showMenu();
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 0) {
            printf("Bye, bye!");
            return 0;
        }
        if (option == 1) {
            length = readVector(a);
        } else if (option == 2) {
            decomposePrimeFactors();
        } else if (option == 3) {
            if (length == 0)
                printf("The vector is empty.\n");
            else
                longestSubsequence(a, length);
        }
    }
}

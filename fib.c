#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
long long fib_r(int n);        // Recursive wrapper with memoization
long long fib_i(int n);

// Function definitions
long long *memo_r; // For recursive
long long *memo_i; // For iterative

// Recursive Fibonacci with memoization
long long fib_r(int n) {
    if (n == 0) {
        return 0;  // Handle base case n == 0
    }
    if (n == 1) {
        return 0;  // Fix: The first Fibonacci number is 0
    }
    if (n == 2) {
        return 1;  // Fix: The second Fibonacci number is 1
    }
    if (memo_r == NULL) {
        memo_r = (long long *)malloc((n + 1) * sizeof(long long));
        for (int i = 0; i <= n; i++) {
            memo_r[i] = -1;  // Initialize cache
        }
    }
    
    if (memo_r[n] != -1) {
        return memo_r[n];
    }
    
    memo_r[n] = fib_r(n - 1) + fib_r(n - 2);
    return memo_r[n];
}

// Iterative Fibonacci with memoization
long long fib_i(int n) {
    if (n == 0) return 0;  // Handle base case n == 0
    if (n == 1) return 0;  // Fix: The first Fibonacci number is 0
    if (n == 2) return 1;  // Fix: The second Fibonacci number is 1
    
    if (memo_i == NULL) {
        memo_i = (long long *)malloc((n + 1) * sizeof(long long));
        for (int i = 0; i <= n; i++) {
            memo_i[i] = -1;  // Initialize cache
        }
    }

    if (memo_i[n] != -1) {
        return memo_i[n];
    }

    long long a = 0, b = 1, next = 0;
    for (int i = 3; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
        memo_i[i] = next;  // Store in cache
    }
    return memo_i[n];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer> <r/i>\n", argv[0]);
        return 1;
    }

    // Initialize memo arrays
    memo_r = NULL;
    memo_i = NULL;

    // Get input number from command-line argument
    int input_number = atoi(argv[1]);

    long long fib;

    // Determine which Fibonacci function to use based on the second argument
    if (strcmp(argv[2], "r") == 0) {
        fib = fib_r(input_number);
    } else if (strcmp(argv[2], "i") == 0) {
        fib = fib_i(input_number);
    } else {
        printf("Second argument must be 'r' or 'i'\n");
        return 1;
    }
    
    printf("%lld\n", fib);  // Ensure to print with a newline

    free(memo_r);
    free(memo_i);

    return 0;
}

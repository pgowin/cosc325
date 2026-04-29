#include <stdio.h>

/*
 * C Imperative Paradigm Lab
 * Parts 1–4 are implemented in this file.
 *
 * Do NOT change function signatures.
 * 
 * Patrick
 */

/* ===== Part 2 ===== */
int sum_to(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

/* ===== Part 3 ===== */
double avg_1_to_n(int n) {
    return (double)sum_to(n) / n;
}

/* ===== Part 4 ===== */
void increment_bad(int x) {
    x++;
}

void increment(int *x) {
    (*x)++;
}

int main() {

    /* ===== Part 1 ===== */
    printf("--- Part 1: State and Sequence ---\n");

    int x = 2;
    x = x * 4;
    x = x + 3;
    printf("x=%d\n", x);
    // TODO: swap the last two assignments above and re-run
    // It completely changes the final value of x! Why? Because the order of operations matters when we are changing state.

    /* ===== Part 2 ===== */
    printf("\n--- Part 2: Control Flow ---\n");
    printf("sum_to(5) = %d (expected 15)\n", sum_to(5));
    printf("sum_to(1) = %d (expected 1)\n", sum_to(1));
    //lines 14-15 is where the control happens. The state is changed at line 16. 
    // Because Python is an interpreted language, it executes line by line. So the control flow is determined by the order of the lines of code. In this case, the for loop controls how many times the state is changed (how many times we add to sum). If we change the order of the lines, we can change the control flow and thus change the final result of sum_to.
    // This is different from Java because Java is a compiled language, so the control flow is determined by the structure of the code (e.g. loops, conditionals) rather than the order of the lines of code. In Java, we would have to use a loop or a recursive function to achieve the same result as sum_to.

    /* ===== Part 3 ===== */
    printf("\n--- Part 3: Functions as Procedures ---\n");
    printf("avg_1_to_n(5) = %.1f (expected 3.0)\n", avg_1_to_n(5));
    //C requires you to write this differently than Python and Java they convert the sum_to function to a double and then divide by n. In Python and Java, we can just divide the sum by n and it will automatically convert to a float/double if necessary. In C, we have to explicitly convert the sum to a double before dividing to get a floating-point result.



    /* ===== Part 4 ===== */
    printf("\n--- Part 4: Pass-by-Value vs Pointers ---\n");

    int a = 5;
    increment_bad(a);
    printf("after increment_bad: a=%d (expected 5)\n", a);
    // this one didnt increament because in C, when we pass a variable to a function, we are passing a copy of the variable (pass-by-value). So when we increment x in increment_bad, we are only incrementing the copy of a, not the original a. Therefore, the original a remains unchanged.
    increment(&a);
    printf("after increment:     a=%d (expected 6)\n", a);
    //this one did increment because in C, when we pass a pointer to a variable to a function, we are passing the address of the variable. So when we increment *x in increment, we are incrementing the value at the address of a, which is the original a. Therefore, the original a is changed.
    return 0;
}
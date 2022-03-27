#include <stdio.h>

int main(void) {
    float loan = 2500;
    float month_interest_rate = 1.03;
    int interest_rate = month_interest_rate * 100;
    interest_rate = interest_rate % 100;

    printf("Loan: %.2f$\n", loan);
    printf("Interest rate: %d %%/month\n", interest_rate);
    float interest_rate_per_month = loan * interest_rate / 100 + loan; // 1
    printf("To be paid in a month: %.2f\n", interest_rate_per_month);
    interest_rate_per_month = interest_rate_per_month * interest_rate / 100 + interest_rate_per_month; // 2
    interest_rate_per_month = interest_rate_per_month * interest_rate / 100 + interest_rate_per_month; // 3
    interest_rate_per_month = interest_rate_per_month * interest_rate / 100 + interest_rate_per_month; // 4
    interest_rate_per_month = interest_rate_per_month * interest_rate / 100 + interest_rate_per_month; // 5
    interest_rate_per_month = interest_rate_per_month * interest_rate / 100 + interest_rate_per_month; // 6
    printf("To be paid in 6 months: %.2f ", interest_rate_per_month);
    return 0;
}
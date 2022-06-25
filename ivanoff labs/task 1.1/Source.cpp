#include <stdio.h>
#include <math.h>

const float E = 2.71828;

float variant_1(float x, int n);
float variant_2(float x, int n);
float variant_3(float x, int n);
float variant_4(float x, int n);
float variant_5(float x, int n);
float variant_6(float x, int n);
float variant_7(float x, int n);
float variant_8(float x, int n);
float variant_9(float x, int n);
float variant_10(float x, int n);
float variant_11(float x, int n);
float variant_12(float x, int n);
float variant_13(float x, int n);
float variant_14(float x, int n);
float variant_15(float x, int n);
float variant_16(float x, int n);
float variant_17(float x, int n);
float variant_18(float x, int n);
float variant_19(float x, int n);
float variant_20(float x, int n);

int main(void) {
	printf("%f\n", variant_1(2, 10));
	printf("%f\n", variant_2(2, 10));
	printf("%f\n", variant_3(2, 10));
	printf("%f\n", variant_4(2, 10));
	printf("%f\n", variant_5(2, 10));
	printf("%f\n", variant_6(2, 10));
	printf("%f\n", variant_7(2, 10));
	printf("%f\n", variant_8(2, 10));
	printf("%f\n", variant_9(2, 10));
	printf("%f\n", variant_10(2, 10));
	printf("%f\n", variant_11(2, 10));
	printf("%f\n", variant_12(2, 10));
	printf("%f\n", variant_13(2, 10));
	printf("%f\n", variant_14(2, 10));
	printf("%f\n", variant_15(2, 10));
	printf("%f\n", variant_16(2, 10));
	printf("%f\n", variant_17(2, 10));
	printf("%f\n", variant_18(2, 10));
	printf("%f\n", variant_19(2, 10));
	printf("%f\n", variant_20(2, 10));

	return 0;
}

float variant_1(float x, int n) {
	float res = 0;
	if (n < 0) {
		return res;
	}
	if (x < 4) {
		for (int i = 1; i < n; i++) {
			res += pow(sin(0.5 * x - 2), i);
		}
		res = 0.25 * x + 14.0 * res;
		return res;
	} 
	if (x >= 4) {
		res = sqrt(x - 3.0);
		return res;
	}
	
}

float variant_2(float x, int n) {
	float res = 0;
	if (x <= 5) {
		for (int i = 1; i < n; i++) {
			res += cos(pow((0.2 * x - 1.0), i));
		}
		return res;
	}
	if (x > 5) {
		res = pow(1 / 3.0, 2.0 * x - 9.0) + 7.0;
	}
}

float variant_3(float x, int n) {
	float res = 0;
	if (x <= 20) {
		for (int i = 1; i < n; i++) {
			res *= sin(0.1 * x - 0.3 * i + 1.0);
		}
		res = x + 12 * res;
		return res;
	}
	if (x > 20) {
		 res = -pow(0.5 * x - 9, 1 / 3.0) + 2.0 * float(n) + 1.0;
		 return res;
	}
}

float variant_4(float x, int n) {
	float res = 0;
	if (x < 7) {
		for (int k = 1; k < n; k++) {
			res += pow(k, sin(x - 7.0));
		}
		res = 3.0 * x + res;
		return res;
	}
	if (x >= 7) {
		res = 23.0 - pow(2.0 * E, 7.0 - x);
		return res;
	}
}

float variant_5(float x, int n) {
	float res = 0;
	if (x <= 3) {
		for (int k = 1; k < n; k++) {
			res += k * cos(x - 3.0);
		}
		res = -x + res;
		return res;
	}
	if (x > 3) {
		res = 22 + pow (3.0 * E, 3.0 - x);
		return res;
	}
}

float variant_6(float x, int n) {
	float res = 0;
	if (x <= 3) {
		for (int k = 1; k < n; k++) {
			res += pow(sin(3.0 * x - 9.0), k);
			res = 2.0 * x + 0.5 + res;
			return res;
		}
	}
	if (x > 3) {
		res = pow(1.0 / 3.0, (x - 2.0) * (x - 2.0)) + 5.0;
		return res;
	}
}

float variant_7(float x, int n) {
	float res = 0;
	if (x < 6) {
		for (int k = 1; k < n; k++) {
			res += pow(7.0 - x, 1.0 / k);
		}
		return res;
	}
	if (x >= 6) {
		res = sin(0.5 * x - 3.0) + 8.0;
		return res;
	}
}

float variant_8(float x, int n) {
	float res = 0;
	if (x < 5) {
		for (int k = 1; k < n; k++) {
			res *= (pow(cos(x - 5.0), k) + 1.0);
		}
		res = 2 + res;
		return res;
	}
	if (x >= 5) {
		res = pow(x - 4.0, 1.0 / 5.0) + x + 60;
	}
}

float variant_9(float x, int n) {
	float res = 0;
	if (x <= 8) {
		for (int k = 1; k < n; k++) {
			res += pow(sin(x - 8.0), 2.0 * k);
		}
		res = 0.5 * x + 7 + res;
		return res;
	}
	if (x > 8) {
		res = 0.5 * sqrt(fabs(x - 12.0)) + 10.0;
		return res;
	}
}

float variant_10(float x, int n) {
	float res = 0;
	if (x <= 5) {
		for (int k = 1; k < n; k++) {
			pow(sin(0.5 * x - 2.5), k);
		}
		res = x + res;
		return res;
	}
	if (x > 5) {
		res = pow(x - 4.0, 1.0 / 3.0) / pow(E, x - 5.0) + 4;
		return res;
	}
}

float variant_11(float x, int n) {
	float res = 0;
	if (x < 3) {
		res = 3.0 * cos(x - 3.0) + 2.0 * x;
		return res;
	}
	if (x >= 3) {
		for (int k = 1; k < n; k++) {
			res += pow(E, -k * (x - 3.0));
		}
		return res;
	}
}

float variant_12(float x, int n) {
	float res = 0;
	if (x <= 5) {
		for (int k = 1; k < n; k++) {
			res += float(k) * pow(E, 0.2 * x - 1.0);
		}
		res = -0.2 * x + res;
		return res;
	}
	if (x > 5) {
		res = 5.0 * cos(0.6 * x - 3.0) + 15.0;
		return res;
	}
}

float variant_13(float x, int n) {
	float res = 0;
	if (x < 4) {
		for (int k = 1; k < n; k++) {
			res += pow((1.0 - x / 4.0), k);
		}
		res = 3.0 * x + 6.0 + res;
		return res;
	}
	if (x >= 4) {
		res = 4.0 * cos(x - 4.0) + 14;
		return res;
	}
}

float variant_14(float x, int n) {
	float res = 0;
	if (x < 5) {
		for (int k = 1; k < n; k++) {
			res += pow(k, x - 4.0);
		}
	}
	if (x >= 5) {
		res = cos(0.2 * x - 1.0) + x + 15.0;
		return res;
	}
}

float variant_15(float x, int n) {
	float res = 0;
	if (x <= 8) {
		for (int k = 1; k < n; k++) {
			res *= k + pow(E, 1.0 - 0.125 * x) - 1;
		}
		res = 10.0 + res;
		return res;
	}
	if (x > 8) {
		res = sin(0.5 * x - 4) + 138.0 - x;
		return res;
	}
}

float variant_16(float x, int n) {
	float res = 0;
	if (x <= 6) {
		for (int k = 1; k < n; k++) {
			res += sqrt(float(k * k) + 6.0 - x);
		}
		return res;
	}
	if (x > 6) {
		res = 27.0 + pow(E, 6.0 - x);
		return res;
	}
}

float variant_17(float x, int n) {
	float res = 0;
	if (x <= 8) {
		res = sqrt(9.0 - x) + 2.0 * x;
		return res;
	}
	if (x > 8) {
		for (int i = 1; i < n; i++) {
			res += sin(x / 4.0 - i);
		}
		res = 17.0 + 34.0 * res;
		return res;
	}
}

float variant_18(float x, int n) {
	float res = 0;
	if (x < 7) {
		res = pow(3.5 - 0.5 * x, E) + 20.0;
		return res;
	}
	if (x >= 7) {
		for (int k = 1; k < n; k++) {
			res += sqrt(k * k + x - 7.0);
		}
		return res;
	}
}

float variant_19(float x, int n) {
	float res = 0;
	if (x < 6) {
		for (int k = 1; k < n; k++) {
			res += pow(sin(x - 6.0), k);
		}
		res = 0.5 * x + 9.0 + res;
		return res;
	}
	if (x >= 6) {
		res = 0.5 * fabs(x - 10.0) + 10;
		return res;
	}
}

float variant_20(float x, int n) {
	float res = 0;
	if (x <= 11) {
		for (int k = 1; k < n; k++) {
			res += pow(cos(x - 11.0), k);
		}
		res = 3.0 + res;
		return res;
	}
	if (x > 11) {
		res = sqrt(x - 10.0) + 0.5 * x + 4.5;
		return res;
	}
}
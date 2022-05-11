#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

enum BMIResult {
	UNDERWEIGTH,
	NORMAL,
	OVERWEIGHT
};

BMIResult bmi(float weight, float heigt);

int main(void) {
	printf("%d",bmi(75, 1.8));
	return 0;
}

BMIResult bmi(float weight, float height) {
	float bmiScore = weight / (height * height);
	if (bmiScore >= 18.5 && bmiScore <= 25) {
		return NORMAL;
	} else if (bmiScore < 18.5) {
		return UNDERWEIGTH;
	} else if (bmiScore > 25) {
		return OVERWEIGHT;
	}
}
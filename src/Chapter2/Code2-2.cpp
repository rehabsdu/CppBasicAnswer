// Code 2-2

int add(int num1, int num2) {
	int sum = num1 ^ num2;
	int carry = (num1 & num2) << 1;
	while (carry != 0) {
		int a = sum;
		int b = carry;
		sum = a ^ b;
		carry = (a & b) << 1;
	}
	return sum;
}
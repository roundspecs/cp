#include <stdio.h>

int is_weight_possible(int *, int, int, int);

int main() {
  // input
  int length;
  int arr[20];
  scanf("%d", &length);
  for (int i = 0; i < length; i++)
    scanf("%d", &arr[i]);

  int sum = 0;
  for (int i = 0, temp; i < length; i++)
    sum += arr[i];
  int half_of_sum = sum / 2;

  int temp;
  for (int i = 0; i < length; ++i) {
    for (int j = i + 1; j < length; ++j) {
      if (arr[i] < arr[j]) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  int result = 0;
  while (half_of_sum >= arr[length - 1]) {
    if (is_weight_possible(arr, 0, length, half_of_sum) == 1) break;
    half_of_sum--;
  }
  printf("%d", sum - 2 * half_of_sum);
}

int is_weight_possible(int *arr, int start, int length, int sum) {
  sum -= arr[start];
  if (sum == 0) return 1;
  if (start == length) return 0;
  if (sum < 0 || is_weight_possible(arr, start + 1, length, sum) == 0)
    return is_weight_possible(arr, start + 1, length, sum + arr[start]);
  return 1;
}
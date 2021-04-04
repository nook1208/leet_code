#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000

int N;
int nums[MAX];
int sorted[MAX];

void merge(int left, int right, int* nums) {
    int mid = (left + right) / 2;
    int lidx = left, ridx = mid + 1;
    int i = left;

    for (; lidx <= mid && ridx <= right; i++)
        sorted[i] = (nums[lidx] <= nums[ridx]) ? nums[lidx++] : nums[ridx++];

    for (; lidx <= mid; i++, lidx++)
        sorted[i] = nums[lidx];

    for (; ridx <= right; i++, ridx++)
        sorted[i] = nums[ridx];

    for (int k = left; k <= right; k++)
        nums[k] = sorted[k];
}

void merge_sort(int left, int right, int* nums) {
    int mid = (left + right) / 2;

    if (left == right)
        return;

    merge_sort(left, mid, nums);
    merge_sort(mid + 1, right, nums);
    merge(left, right, nums);
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    merge_sort(0, N - 1, nums);

    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}

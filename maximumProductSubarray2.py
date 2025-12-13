from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        # Số lượng phần tử
        n = len(nums)

        # Kết quả ban đầu là phần tử đầu tiên
        res = nums[0]

        # prefix: tích từ trái sang phải
        # suffix: tích từ phải sang trái
        prefix = 0
        suffix = 0

        # Duyệt mảng 1 lần
        for i in range(n):

            # Nếu prefix == 0 thì nhân với 1 để bắt đầu lại
            # Nếu không thì tiếp tục nhân chuỗi cũ
            prefix = nums[i] * (prefix or 1)

            # suffix làm tương tự nhưng duyệt từ phải sang trái
            suffix = nums[n - 1 - i] * (suffix or 1)

            # Cập nhật kết quả lớn nhất
            res = max(res, prefix, suffix)

        return res


# -----------------------------
# PHẦN CHẠY THỬ TRONG VS CODE
# -----------------------------
if __name__ == "__main__":

    # Test mẫu
    nums = [2, 3, -2, 4]

    solution = Solution()
    result = solution.maxProduct(nums)

    print("Mảng:", nums)
    print("Tích lớn nhất của subarray:", result)

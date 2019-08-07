//
// Created by android on 19-8-7.
//
/*题目：
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *１　２　８　　９
 *２　４　９　　１２
 *４　７　１０　１３
 *６　８　１１　１５
 *
 * 首先选取数组中右上角的数字。如果该数字等于要查找的数字，查找过程结束；如果该数字大于要查找的数组，
 * 剔除这个数字所在的列；如果该数字小于要查找的数字，剔除这个数字所在的行。也就是说如果要查找的数字不在数组的右上角，
 * 则每一次都在数组的查找范围中剔除一行或者一列，这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空。
 * 运行时间：9ms占用内存：1596k
 * */
#include <vector>
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {

        int rows = array.size();
        int columns = array[0].size();
        if (!array.empty() && rows > 0 && columns > 0) {
            int row = 0;
            int col = columns - 1;
            while (row < rows && col >= 0) {
                if (array[row][col] == target) {
                    return true;
                } else if (array[row][col] > target) {
                    col--;
                } else {
                    row++;
                }

            }
            return false;

        } else {
            return false;
        }
    }

};

TEST(find,c2){
    int target = 13;//13,99分别测试
    vector<vector<int> >num =
            {{1,5,10,12,15},{2,8,12,15,17},{4,9,13,16,21},{9,14,18,20,24},{10,18,25,23,30} };

    EXPECT_EQ(true,(new Solution)->Find(target,num));
}
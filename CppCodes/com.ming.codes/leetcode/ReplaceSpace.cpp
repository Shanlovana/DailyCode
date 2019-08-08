//
// Created by android on 19-8-8.
//

/*题目：
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 *
 * 问题1：替换字符串，是在原来的字符串上做替换，还是新开辟一个字符串做替换！
 * 问题2：在当前字符串替换，怎么替换才更有效率。
 * 从前往后替换，后面的字符要不断往后移动，要多次移动，所以效率低下
 * 从后往前，先计算需要多少空间，然后从后往前移动，则每个字符只为移动一次，这样效率更高一点。
 *
 * 实现
 * 思路：从前向后记录‘ ’数目，从后向前替换‘ ’。 重点：从后向前替换的时候的技巧 例如：“we are lucky”
 * 0 1 2 3 4 5 6 7 8 9 10 11
 * w e a r e l u c k y
 * 可以得知count=2;//空格的个数。 所以在替换的时候7~11的字母要向后移动count×2个位置，
 * 3~5字母要向后移动（count-1）×2个位置。 所以得到 ：
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 * w e   a r e   l u c  k y
 * w e   a r a r e u c  k l u c k y
 *在替换的时候直接在空格处写入%20了
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
 * w e   a r e   l u c  k y
 * w e % 2 0 a r e % 2  0 l u c k y
 *
 * 运行时间：1 test from find (0 ms total)
 * */
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int replaceSpace(char *str, int length) {

        int spaceNum = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                spaceNum++;
            }
        }
        for (int j = length - 1; j >= 0; j--) {
            if (str[j] != ' ') {
                str[j + 2 * spaceNum] = str[j];
            } else {
                spaceNum--;//此处先减除，否则结果错误
                str[j + 2 * spaceNum] = '%';
                str[j + 2 * spaceNum + 1] = '2';
                str[j + 2 * spaceNum + 2] = '0';

            }
        }
        cout << "repalced str is :" << str << endl;
        return spaceNum;
    }
};

TEST(repalce, a1) {
    //本题目前提是预先分配了足够的长度，并且支持space进行扩容，否则程序不会运行成功。
    char buf[30] = {'w', 'e', ' ', 'a', 'r', 'e', ' ', 'l', 'u', 'c', 'k', 'y', '\0'};
    //看打印结果即可
    EXPECT_EQ(2, (new Solution)->replaceSpace(buf, 30));

}
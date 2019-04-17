# 剑指Offer的刷题笔记
所有代码都在[这里](https://github.com/jiangyuwei666/my-study-demo/tree/master/Algorithm/sword%20of%20offer)

* [1.二维数组中的查找](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/1.%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.py)
    ```
    二维数组，每一行从左往右增大，每一列从上往下增大，输入一个整数，判断数组中是否含有该整数。
    ```
    ![](https://images0.cnblogs.com/blog2015/381412/201508/172206497062111.png)
    从左下角或者右上角入手
    输入7返回Ture 输入5返回False
* [2.替换空格](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/2.%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC.py)

    ```
    请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，则输出“We%20are%20happy.”。　
    ```

    这个题用Python实现没什么难度。。。

    但是要如果用别的语言实现的时候要考虑长度问题，空格占一个，%20占3个。
* [3.从头到尾打印链表](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/3.%E4%BB%8E%E5%A4%B4%E5%88%B0%E5%B0%BE%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.py)
    ```
    输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
    ```
* [4.重建二叉树](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/5.%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91.py)

    ```
    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
    ```

    先通过前序遍历找到根节点(第一个)，再在中序遍历中将整个树分为左子树和右子树。再在前序遍历中找到左右子树，重复以上操作（递归）

* [5.用两个栈实现队列](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/6.%E7%94%A8%E4%B8%A4%E4%B8%AA%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.py)

    ```
    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
    ```

    两个栈，一个是stack1，另外一个是stack2，首先将所有元素push进stack1里，再以此pop到stack2中，这样再从stack2中pop的
    时候就可以就能实现先进先出的。这里要注意的是，pop的时候，如果stack2中没有元素了，这个时候才将stack1中的所有元素pop到
    stack2中，push的时候，直接push到stack1中就行

    python中利用list的append和pop方法就能实现栈的功能
* [6.旋转数组中的最小数字](https://github.com/jiangyuwei666/my-study-demo/blob/master/Algorithm/sword%20of%20offer/7.%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9C%80%E5%B0%8F%E7%9A%84%E6%95%B0%E5%AD%97.py)
    ```
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
    ```
* [7.斐波那契数列]()
* [8.跳台阶]()
    ```
    一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
    ```
* [9.变态跳台阶]()
    ```
    青蛙可以一次跳n级台阶
    ```
* [10.矩形覆盖]()
    ```
    我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
    ```
* [11.二进制中1的个数]()
    ```
    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
    ```
* [12.数值的整数次方]()
    ```
    给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
    ```
* [13.调整数组顺序使奇数位于偶数前面]()
    ```
    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
    ```
* [14.链表中倒数第k个结点]()
    ```
    输入一个链表，输出该链表中倒数第k个结点。
    ```
    ![](https://images2015.cnblogs.com/blog/936002/201604/936002-20160414184635848-1331750727.png)
* [15.反转链表]()
    ```
    输入一个链表，反转链表后，输出新链表的表头
    ```
* [16.合并两个排序的链表]()
    ```
    输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
    ```
* [16.树的子结构]()
    ```
    
    ```
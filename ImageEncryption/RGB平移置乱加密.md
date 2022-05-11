# RGB 平移置乱加密

## 思想

将图像的RGB三个分量分成三个图像矩阵，对每个分量矩阵按行列进行平移，最后合成。

## 加密算法伪代码

1. 输入图像Mat
2. 输入控制序列ck,ck==1,代表水平变换，ck==0，代表竖直变换

​		（1）i=0，while(ck非空)

​				① if ck[i] == 1 调用HORIZONTAL， i++

​				② if ck[i] == 0 调用VERTICAL， i++

3. 结束

---

HORIZONTAL 定义：

1. 输入图像Mat、初识偏移量initkey[r,g,b]、每次偏移后增加的偏移量deltakey[r,g,b]
2. $\Delta R = initkey[r]+deltakey[r]$、$\Delta G = initkey[g]+deltakey[g]$、$\Delta B = initkey[b]+deltakey[b]$
3. for RowC =  $y_0$ to RowC = $y_{max}$：（图像的一共$y_{max}$行，第一行为$y_0$）

​		（1）第RowC行的像素R分量的坐标水平移动$\Delta R$

​		（2）第RowC行的像素G分量的坐标水平移动$\Delta G$

​		（3）第RowC行的像素B分量的坐标水平移动$\Delta B$

​		（4）$\Delta R = \Delta R+deltakey[r]$

​		（5）$\Delta G = \Delta G+deltakey[g]$

​		（6）$\Delta B = \Delta B+deltakey[b]$

  4.结束

---

VERTICAL 定义：

1. 输入图像Mat、初识偏移量initkey[r,g,b]、每次偏移后增加的偏移量deltakey[r,g,b]
2. $\Delta R = initkey[r]+deltakey[r]$、$\Delta G = initkey[g]+deltakey[g]$、$\Delta B = initkey[b]+deltakey[b]$
3. for ColC =  $x_0$ to ColC = $x_{max}$：（图像的一共$x_{max}$列，第一行为$x_0$）

​		（1）第ColC行的像素R分量的坐标垂直移动$\Delta R$

​		（2）第ColC行的像素G分量的坐标垂直移动$\Delta G$

​		（3）第ColC行的像素B分量的坐标垂直移动$\Delta B$

​		（4）$\Delta R = \Delta R+deltakey[r]$

​		（5）$\Delta G = \Delta G+deltakey[g]$

​		（6）$\Delta B = \Delta B+deltakey[b]$

  4.结束

## 解密

控制序列ck需要逆序变换，加密中ck的角标从0~(ck.len-1)，解密需要遍历的角标为(ck.len-1) ~0。

坐标映射：

比如在加密时，原图为Mat,加密后的图片为Mat'，Mat的坐标（0,0）水平移动500个像素变换到Mat'的（0,500）。

那么在解密时，解密图为Mat''，Mat‘’的坐标（0,0）还需要水平移动500个像素到Mat'的（0,500）。




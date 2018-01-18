import cv2
import os
import numpy as np
import argparse
from PIL import Image
from PIL import ImageFilter


im = Image.open("testimg.JPG")

#img = cv2.imread('testimg.JPG', 0)
im = im.convert("L")
im.save(r't.JPG')
img = cv2.imread('t.JPG', 0)

sobelX = cv2.Sobel(img,cv2.CV_64F,1,0)#x方向的梯度
sobelY = cv2.Sobel(img,cv2.CV_64F,0,1)#y方向的梯度



sobelX = np.uint8(np.absolute(sobelX))#x方向梯度的绝对值
sobelY = np.uint8(np.absolute(sobelY))#y方向梯度的绝对值


sobelCombined = cv2.bitwise_or(sobelX,sobelY)#

median = cv2.medianBlur(img, 5)

blur = cv2.GaussianBlur(img,(5,5),0)
cv2.imshow("blur",blur)


lines = cv2.HoughLines(blur,4,np.pi/180,118) #这里对最后一个参数使用了经验型的值

result = img.copy()

for line in lines[0]:
    rho = line[0] #第一个元素是距离rho
    theta= line[1] #第二个元素是角度theta
    print(rho)
    print(theta)
    if(theta < (np.pi/4. )) or (theta > (3.*np.pi/4.0)): #垂直直线
                #该直线与第一行的交点
        pt1 = (int(rho/np.cos(theta)),0)
        #该直线与最后一行的焦点
        pt2 = (int((rho-result.shape[0]*np.sin(theta))/np.cos(theta)),result.shape[0])
        #绘制一条白线
        cv2.line( result, pt1, pt2, (255))
    else: #水平直线
        # 该直线与第一列的交点
        pt1 = (0,int(rho/np.sin(theta)))
        #该直线与最后一列的交点
        pt2 = (result.shape[1], int((rho-result.shape[1]*np.cos(theta))/np.sin(theta)))
        #绘制一条直线
        cv2.line(result, pt1, pt2, (255), 1)

cv2.imshow("result", result)

#cv2.imshow('Result', result)

#cv2.imshow("Sobel Combined", sobelCombined)


cv2.waitKey(0)
cv2.destroyAllWindows()
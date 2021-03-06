import cv2
import os
import numpy as np
import argparse
from PIL import Image
from PIL import ImageFilter
from matplotlib import pyplot as plt

#im = Image.open("testimg.JPG")

#img = cv2.imread('testimg.JPG', 0)
#im = im.convert("L")
#im.save(r't.JPG')
origin = cv2.imread('origin.JPG', 0)
img_grey = cv2.imread('.JPG', 0)
img_inc = cv2.imread('incimg.jpg', 0)


blur = cv2.GaussianBlur(img_inc,(5,5),0)
#cv2.imshow("blur",blur)
cv2.imwrite('blur.jpg', blur)
edges = cv2.Canny(blur, 10, 100, apertureSize = 3)
#cv2.imshow("edges",edges)
cv2.imwrite('edge.jpg', edges)

lines = cv2.HoughLines(edges,3,np.pi/180,118) #这里对最后一个参数使用了经验型的值
result = img_grey.copy()

for i in range(0,7):
    for line in lines[i]:
        rho = line[0] #第一个元素是距离rho
        theta= line[1] #第二个元素是角度theta
        #print(rho)
        #print(theta)
        if(theta < (np.pi/4. )) or (theta > (3.*np.pi/4.0)): #垂直直线
                #该直线与第一行的交点
            pt1 = (int(rho/np.cos(theta)),0)
            #该直线与最后一行的焦点
            pt2 = (int((rho-result.shape[0]*np.sin(theta))/np.cos(theta)),result.shape[0])
            #绘制一条白线
            cv2.line( result, pt1, pt2, (255))
        else: #水平直线
            # 该直线与第一列的交点
            #pt1 = (0,int(rho/np.sin(theta)))
            #该直线与最后一列的交点
            #pt2 = (result.shape[1], int((rho-result.shape[1]*np.cos(theta))/np.sin(theta)))
            #绘制一条直线
            #cv2.line(result, pt1, pt2, (255), 1)
            pass

#cv2.imshow("result", result)
cv2.imwrite('result.jpg', result)
#cv2.imshow('Result', result)

#cv2.imshow("Sobel Combined", sobelCombined)
plt.subplot(151);plt.imshow(origin)
plt.subplot(152);plt.imshow(img_grey)

plt.subplot(153);plt.imshow(img_inc)
plt.subplot(154);plt.imshow(edges)
plt.subplot(155);plt.imshow(result)
plt.show()

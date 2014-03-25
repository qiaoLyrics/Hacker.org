# 解压了几次再file命令查询还是gzip压缩文件
# 猜测是压缩了N多遍的文件
# 就用下面的脚本搞了一下，最后解压出来的是一个文本

# Python通过文件头来判断文件的真实类型:  http://aminby.net/2013/07/python-file-header-recoginze-type-extension/
#                                        http://blog.csdn.net/shuifa2008/article/details/9333193

import struct  
import os
def typeList():  
    return {  
        "52617221": "EXT_RAR",  
        "504B0304": "EXT_ZIP",  
        "1F8B0800": "EXT_GZIP"}
def bytes2hex(bytes):  
    num = len(bytes)  
    hexstr = u""  
    for i in range(num):  
        t = u"%x" % bytes[i]  
        if len(t) % 2:  
            hexstr += u"0"  
        hexstr += t  
    return hexstr.upper()  
def filetype(filename):  
    binfile = open(filename, 'rb') 
    tl = typeList()  
    ftype = 'unknown'  
    for hcode in tl.keys():  
        numOfBytes = len(hcode) / 2 
        binfile.seek(0) 
        hbytes = struct.unpack_from("B"*numOfBytes, binfile.read(numOfBytes)) 
        f_hcode = bytes2hex(hbytes)  
        if f_hcode == hcode:  
            ftype = tl[hcode]
            break  
    binfile.close()  
    return ftype  
  
if __name__ == '__main__':  
    while True :
        if filetype("./doll") == "EXT_GZIP" :
            os.system("mv doll doll.gz && gunzip doll.gz")
        else : break




# Python通过文件头来判断文件的真实类型
#分类： python 工具 2013-07-15 16:03 552人阅读 评论(1) 收藏 举报
####  
## 文章：Python通过文件头来判断文件类型  
## 作者：http://aminby.net  
####  
#  
#import struct  
#  
## 支持文件类型  
## 用16进制字符串的目的是可以知道文件头是多少字节  
## 各种文件头的长度不一样，少半2字符，长则8字符  
#def typeList():  
#    return {  
#        "52617221": EXT_RAR,  
#        "504B0304": EXT_ZIP}  
#  
## 字节码转16进制字符串  
#def bytes2hex(bytes):  
#    num = len(bytes)  
#    hexstr = u""  
#    for i in range(num):  
#        t = u"%x" % bytes[i]  
#        if len(t) % 2:  
#            hexstr += u"0"  
#        hexstr += t  
#    return hexstr.upper()  
#  
## 获取文件类型  
#def filetype(filename):  
#    binfile = open(filename, 'rb') # 必需二制字读取  
#    tl = typeList()  
#    ftype = 'unknown'  
#    for hcode in tl.keys():  
#        numOfBytes = len(hcode) / 2 # 需要读多少字节  
#        binfile.seek(0) # 每次读取都要回到文件头，不然会一直往后读取  
#        hbytes = struct.unpack_from("B"*numOfBytes, binfile.read(numOfBytes)) # 一个 "B"表示一个字节  
#        f_hcode = bytes2hex(hbytes)  
#        if f_hcode == hcode:  
#            ftype = tl[hcode]  
#            break  
#    binfile.close()  
#    return ftype  
#  
#if __name__ == '__main__':  
#    print filetype(Your-file-path)  
#常见文件格式的文件头
#
#文件格式     文件头(十六进制)
#JPEG (jpg)   FFD8FF
#PNG (png)    89504E47
#GIF (gif)    47494638
#TIFF (tif)   49492A00
#Windows Bitmap (bmp)     424D
#CAD (dwg)    41433130
#Adobe Photoshop (psd)    38425053
#Rich Text Format (rtf)   7B5C727466
#XML (xml)    3C3F786D6C
#HTML (html)  68746D6C3E
#Email [thorough only] (eml)  44656C69766572792D646174653A
#Outlook Express (dbx)    CFAD12FEC5FD746F
#Outlook (pst)    2142444E
#MS Word/Excel (xls.or.doc)   D0CF11E0
#MS Access (mdb)  5374616E64617264204A
#WordPerfect (wpd)    FF575043
#Postscript (eps.or.ps)   252150532D41646F6265
#Adobe Acrobat (pdf)  255044462D312E
#Quicken (qdf)    AC9EBD8F
#Windows Password (pwl)   E3828596
#ZIP Archive (zip)    504B0304
#RAR Archive (rar)    52617221
#Wave (wav)   57415645
#AVI (avi)    41564920
#Real Audio (ram)     2E7261FD
#Real Media (rm)  2E524D46
#MPEG (mpg)   000001BA
#MPEG (mpg)   000001B3
#Quicktime (mov)  6D6F6F76
#Windows Media (asf)  3026B2758E66CF11
#MIDI (mid)   4D546864
#这种方法也可以在网络服务方法可以用来防止上传者来者修改扩展名来欺骗服务器干坏事。

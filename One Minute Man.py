# 24小时里只有一分钟会出现答案，那就每隔一段时间趴该页面下来
# 看看呗
import urllib.request
import time
while True :
    s = urllib.request.urlopen('http://www.hacker.org/challenge/misc/minuteman.php').read()
    if s != b'<html><body>\nback later' :
        print(s)
        break
    else : time.sleep(30)

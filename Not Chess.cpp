/* 
    考点：代码阅读/实现
          不会js，不了解escape()的话会折腾很久
          好题


    折腾了好久，因为不会js，所以只能用C++/Python翻译原程序，因为js里的escape折腾得比较久

    一开始想逆向一下算法，未果，再暴力枚举。
    研究一下js里的encodeIt()函数，会发现它是3个字母一组的，每组互不影响，所以直接C++翻译暴力枚举。


    因为之前忽略了js的escape()的影响，有两组没能翻译出来。鼓捣了好久，在网上搞到了C++的escape函数的实现，直接拿过来用。
    但还是有两组死活搞不出来，"ZW4l"和"JTIw"
    W3SchoolTIY是个好东西，在线测试js，在上面鼓捣了好一阵子之后我意识到，原串经过escape()后空格等字符会改变。
    试着输入空格‘ ’，hacker.org返回"JTIw"，haha~nice
    到这里就简单啦~在keyStr后面加上所有符号"~`!@#$%^&*()-_[];\"\',./<>? "，再跑一遍程序~出来了

    js_escape() 是C++实现js里的escape函数，网上复制别人的。虽说到最后可以不用这个函数，但中途用该函数实验了很多东西。
*/
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


string js_escape(string &str)               // C++ escappe
{
 setlocale(LC_CTYPE,"");
 wchar_t aa[1<<10];
 mbstowcs(aa,str.c_str(),str.size());
 wstring wcs(aa);
 str = "";
 for(int i=0;i<wcs.size();i++)
 {
  if(wcs[i]>0xff)
  {
   char tmp[5];
   sprintf(tmp,"%x",wcs[i]);
   str += "%u";
   str += tmp;
  }
  else
  {
            if( (wcs[i]>='a' && wcs[i]<='z') || (wcs[i]>='A' && wcs[i]<='Z') || ( wcs[i]>='0' && wcs[i]<='9' ) )
            {
       char tmp[2];
       sprintf(tmp,"%c",wcs[i]);
       str += tmp;
            }
            else
            {
                char tmp[3];
       sprintf(tmp,"%02x",wcs[i]);
       str += "%";
       str += tmp;
            }
  }
 }
 return str;
}


bool isdigit(char ch) { return '0' <= ch && ch <= '9'; }

string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=~`!@#$%^&*()-_[];\"\',./<>? ";
int main()
{
    int len = s.length();
    //s = js_escape(s);
    for(int i = 0; i < len; i++)
        for(int j = 0; j < len; j++)
            for(int k = 0; k < len; k++) {
                    string ans = "";
                    ans += s[i] ; ans += s[j] ; ans += s[k];
                    int enc1 = (int)(ans[0]) >> 2;
                    int enc2 = (((int)(ans[0]) & 3) << 4) | ((int)(ans[1]) >> 4);
                    int enc3 = (((int)(ans[1]) & 15) << 2) | ((int)(ans[2]) >> 6);
                    int enc4 = (int)(ans[2]) & 63;

                    ///if(!isdigit(ans[1])) enc3 = enc4 = 64;               //唬人的，没用
                    //else if (!isdigit(ans[2])) enc4 = 64;

                    string output = "";
                    output += s[enc1]; output += s[enc2]; output += s[enc3]; output += s[enc4];
                    if (output == "ZW4l") {             //分组枚举
                        cout << ans << endl;
                        return 0;
                    } 
                }
    return 0;
}

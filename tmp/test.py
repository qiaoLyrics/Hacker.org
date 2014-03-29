def pj(region):
    (w,h)=region.size
    t=[0,0,0,0]
    for i in range(2,w-2):
        for j in range(2,h-2):
            (r,g,b,a)=region.getpixel((i,j))
            t[0]+=r
            t[1]+=g
            t[2]+=b
            t[3]+=b
    t[0]=t[0]/float(w-4)/(h-4)
    t[1]=t[1]/float(w-4)/(h-4)
    t[2]=t[2]/float(w-4)/(h-4)
    t[3]=t[3]/float(w-4)/(h-4)
    # #print dir(region)
    # for i in range(w):
        # for j in range(h):
            # region.putpixel((i,j),(t[0],t[1],t[2],t[3]))
    return t



DECLARE INTEGER VikeyFind IN ViKey.DLL LONG @
DECLARE INTEGER VikeyGetHID IN ViKey.DLL INTEGER ,LONG @
DECLARE INTEGER VikeyGetLevel IN ViKey.DLL INTEGER ,INTEGER @


DECLARE INTEGER VikeyUserLogin IN ViKey.DLL INTEGER ,STRING
DECLARE INTEGER VikeyAdminLogin IN ViKey.DLL INTEGER ,STRING
DECLARE INTEGER VikeyLogoff IN ViKey.DLL INTEGER


DECLARE INTEGER VikeySetUserPassWordAttempt IN ViKey.DLL INTEGER
DECLARE INTEGER VikeySetAdminPassWordAttempt IN ViKey.DLL INTEGER

DECLARE INTEGER VikeyGetUserPassWordAttempt IN ViKey.DLL INTEGER, INTEGER @,INTEGER @
DECLARE INTEGER VikeyGetAdminPassWordAttempt IN ViKey.DLL INTEGER, INTEGER @,INTEGER @


DECLARE INTEGER VikeyResetPassword IN ViKey.DLL INTEGER, STRING, STRING 


DECLARE INTEGER VikeySetSoftIDString IN ViKey.DLL INTEGER, STRING 
DECLARE INTEGER VikeyGetSoftIDString IN ViKey.DLL INTEGER, STRING @

DECLARE INTEGER VikeyReadData IN ViKey.DLL INTEGER, INTEGER, INTEGER, STRING @
DECLARE INTEGER VikeyWriteData IN ViKey.DLL INTEGER, INTEGER, INTEGER, STRING


DECLARE INTEGER ViKeyRandom IN ViKey.DLL INTEGER, INTEGER@, INTEGER@, INTEGER@, INTEGER@
DECLARE INTEGER VikeyGetTime IN ViKey.DLL INTEGER, INTEGER@


DECLARE INTEGER wsprintf IN User32.DLL String @,string,LONG,LONG  


public DevicePath,ret,keycount,index
*这个用于判断系统中是否存在着加密锁。
index = 0
ret =VikeyFind (@keycount)
If ret<> 0 Then 
	=messagebox("未找到加密狗",0)
	return 
endif


*用于返回加密狗的ID号。
local HID
HID=0
ret = VikeyGetHID (index, @HID)
If ret <> 0 Then 
	=messagebox( "返回硬件ID错误",0)
	return
endif
local c_id
c_id=space(20)
wsprintf(@c_id,"%u",HID,HID)
=messagebox( "已成功返回锁的硬件ID号:"+c_id,0)


*写入字符串到加密锁中
local AdminPassWord
AdminPassWord= "00000000"
ret=VikeyAdminLogin (index,AdminPassWord)
if ret<>0then
	=messagebox ("管理员登陆失败",0)
	return 
endif
=messagebox( "管理员登陆成功",0)



*写入字符串到加密锁中
local mylen
local InString 
local addr
InString = "测试数据内容"
mylen=12
addr=0 &&要写入的地址为0
ret=VikeyWriteData (index,addr, mylen, InString)
if ret<>0then
	=messagebox ("写字符串错误",0)
	return 
endif
=messagebox( "写入成功。写入的字符串是："+InString ,0)


*从加密锁的储存器中读取字符串
local OutString
mylen=12 &&注意这里的6是长度，要与写入的字符串的长度相同
OutString=space(mylen)
ret=VikeyReadData (index,addr, mylen, @OutString)
If ret <> 0 Then 
	=messagebox( "读字符串错误",0)
	return
endif
=messagebox( "读字符串成功：" + OutString,0)

ret=VikeyLogoff (index)
=messagebox( "演示完毕。",0)




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
*��������ж�ϵͳ���Ƿ�����ż�������
index = 0
ret =VikeyFind (@keycount)
If ret<> 0 Then 
	=messagebox("δ�ҵ����ܹ�",0)
	return 
endif


*���ڷ��ؼ��ܹ���ID�š�
local HID
HID=0
ret = VikeyGetHID (index, @HID)
If ret <> 0 Then 
	=messagebox( "����Ӳ��ID����",0)
	return
endif
local c_id
c_id=space(20)
wsprintf(@c_id,"%u",HID,HID)
=messagebox( "�ѳɹ���������Ӳ��ID��:"+c_id,0)


*д���ַ�������������
local AdminPassWord
AdminPassWord= "00000000"
ret=VikeyAdminLogin (index,AdminPassWord)
if ret<>0then
	=messagebox ("����Ա��½ʧ��",0)
	return 
endif
=messagebox( "����Ա��½�ɹ�",0)



*д���ַ�������������
local mylen
local InString 
local addr
InString = "������������"
mylen=12
addr=0 &&Ҫд��ĵ�ַΪ0
ret=VikeyWriteData (index,addr, mylen, InString)
if ret<>0then
	=messagebox ("д�ַ�������",0)
	return 
endif
=messagebox( "д��ɹ���д����ַ����ǣ�"+InString ,0)


*�Ӽ������Ĵ������ж�ȡ�ַ���
local OutString
mylen=12 &&ע�������6�ǳ��ȣ�Ҫ��д����ַ����ĳ�����ͬ
OutString=space(mylen)
ret=VikeyReadData (index,addr, mylen, @OutString)
If ret <> 0 Then 
	=messagebox( "���ַ�������",0)
	return
endif
=messagebox( "���ַ����ɹ���" + OutString,0)

ret=VikeyLogoff (index)
=messagebox( "��ʾ��ϡ�",0)


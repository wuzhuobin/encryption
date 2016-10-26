<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>ViKey--API测试</title>
<link href="ViKeyTest.css" rel="stylesheet" type="text/css">
<embed id="ViKeyInterface"  type="application/npViKeyInterface-plugin" style="height: 0;width: 0; "> </embed>
<script language="JavaScript">
<!-- 
var ViKeyInterface;

function LoadViKeyInterface() 
{
	var ViKeyCount;
	try
	{
		 //创建ViKey加密狗控件
		if (document.implementation && document.implementation.createDocument && typeof XSLTProcessor != 'undefined') 
		{ 
			// chrome, firefox etc
			//alert("Google");
			ViKeyInterface= document.getElementById('ViKeyInterface');
		}
		else
		{
			//alert("IE");
			ViKeyInterface=new ActiveXObject("ViKeyActiveX.ViKeyInterface.1");
		}

		var ViKeyCount;
		ViKeyCount = ViKeyInterface.IVikeyFind();
	 }
			
	 catch(e)  
	 {  
		alert("没有安装ViKey加密狗网页控件, 请安装ViKey加密狗网页控件");
		return false;
	 }  

	return true;
}

window.onload = function() 
{
	LoadViKeyInterface();
}

function GetVersion()    //查找加密锁
{   
	var FM = window.document.ViKeyForm;
	var Version;

	Version = ViKeyInterface.IGetVersion();
	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="版本：" + Version;
	}
	else
	{
		FM.edtResult.value="失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();
	}
}

function ViKeyFind()    //查找加密锁
{   
	var FM = window.document.ViKeyForm;
	var ViKeyCount;

	ViKeyCount = ViKeyInterface.IVikeyFind();
	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="已找到ViKey加密锁数量：" + ViKeyCount;
	}
	else
	{
		FM.edtResult.value="查找失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();
	}
}

function ViKeyHID()   //获取硬件序列号
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	var ViKeyHID;

	ViKeyIndex = 0;
	ViKeyHID = ViKeyInterface.IVikeyGetHID(ViKeyIndex);
	
	if(ViKeyInterface.IViKeyGetError() == 0)	
	{
		FM.edtResult.value="获取硬件序列号成功,硬件 " + ViKeyHID;	
		FM.etdNTID.value = ViKeyHID;
	}
	else
	{
		FM.edtResult.value="获取硬件序列号失败 ERRORCODE：" + ViKeyInterface.IViKeyGetError()	
	}
}

function ViKeyUserLogon()   //以用户权限登录
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	ViKeyIndex = 0;

	ViKeyInterface.IVikeyUserLogin(ViKeyIndex, FM.UserPin2.value);
	
	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="用户登录成功";	
	}
	else
	{
		FM.edtResult.value="用户登录失败 ERRORCODE：" + ViKeyInterface.IViKeyGetError();	
	}
}

function ViKeyAdminLogon()   //以管理员权限登录
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	ViKeyIndex = 0;

	ViKeyInterface.IVikeyAdminLogin(ViKeyIndex, FM.AdminPin2.value);
	
	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="管理员登录成功";	
	}
	else
	{
		FM.edtResult.value="用户登录失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();	
	}
}

function ViKeySetSoftID()   //设置软件ID
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	ViKeyIndex = 0;

	ViKeyInterface.IVikeySetSoftIDString(ViKeyIndex, FM.EditSetSoftID.value);
	
	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="设置软件ID成功: " + FM.EditSetSoftID.value;
	}
	else
	{
		FM.edtResult.value="设置软件ID失败 ERRORCODE：" + ViKeyInterface.Result;	
	}
}

function ViKeyGetSoftID()   //获取软件ID
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	var ViKeySID;
	ViKeyIndex = 0;

	ViKeySID = ViKeyInterface.IVikeyGetSoftIDString(ViKeyIndex);

	FM.EditGetSoftID.value = ViKeySID;
	
	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="读取软件ID成功: " + 	FM.EditGetSoftID.value;
	}
	else
	{
		FM.edtResult.value="读取软件ID失败 ERRORCODE：" + ViKeyInterface.Result;	
	}
}

function ViKeyWriteData()   //写数据到ViKey
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	var Addr= 0;
	var Length = FM.EditWriteData.value.length*2;

	ViKeyIndex = 0;

	ViKeyInterface.IVikeyWriteData(ViKeyIndex, Addr, Length, FM.EditWriteData.value);

	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="写入数据成功: " + 	FM.EditWriteData.value;
	}
	else
	{
		FM.edtResult.value="写入数据失败 ERRORCODE："+ViKeyInterface.IViKeyGetError();	
	}
}

function ViKeyReadData()   //从ViKey中读取数据
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	var Addr = 0;
	var Length = 32;
	var buffer="";
	ViKeyIndex = 0;

	buffer = ViKeyInterface.IVikeyReadData(ViKeyIndex, Addr, Length);

	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="读取数据成功: " +  buffer;
		FM.EditReadData.value=buffer;
	}
	else
	{
		FM.edtResult.value="读取数据失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();	
	}
}

function ViKeySetMd5Key() //设置MD5的Key
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	ViKeyIndex = 0;
	
	ViKeyInterface.IVikeySetMD5Key(ViKeyIndex, FM.EditMD5Key.value);
	
	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="设置MD5Key成功";
	}
	else
	{
		FM.edtResult.value="设置MD5Key失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();	
	}
	
}

function VikeyHmacMD5()   //计算MD5值
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	var Length = 32;
	var buffer="";
	ViKeyIndex = 0;

	buffer = ViKeyInterface.IVikeyHmacMD5(ViKeyIndex, Length, FM.edtMD5Text.value);

	if(ViKeyInterface.IViKeyGetError() ==0)	
	{
		FM.edtResult.value="HMAC-MD5计算成功";
		FM.edtMD5Result.value=buffer;
	}
	else
	{
		FM.edtResult.value="HMAC-计算失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();	
	}
}
function Des3Encrypt()   //3Des加密
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	var buffer="";
	ViKeyIndex = 0;

	if( FM.edtDesEncrypt.value.length != 24)
	{	
		alert("加密长度必须为24个字符");
	}
	else
	{
		buffer = ViKeyInterface.IVikey3DesEncrypt(ViKeyIndex, FM.edtDesEncrypt.value);

		if(ViKeyInterface.IViKeyGetError() ==0)	
		{
			FM.edtResult.value="3DES加密成功";
			FM.edtDesEncrypt.value=buffer;
		}
		else
		{
			FM.edtResult.value="3DES加密失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();	
		}
	}
}

function Des3Decrypt()   //3Des解密
{
	var FM = window.document.ViKeyForm;
	var ViKeyIndex;
	var buffer="";
	ViKeyIndex = 0;
	if( FM.edtDesDecrypt.value.length != 48)
	{	
		alert("解密长度必须为48个16进制字符");
	}
	else
	{
		buffer = ViKeyInterface.IVikey3DesDecrypt(ViKeyIndex, FM.edtDesDecrypt.value);

		if(ViKeyInterface.IViKeyGetError() ==0)	
		{
			FM.edtResult.value="3DES解密成功";
			FM.edtDesDecrypt.value=buffer;
		}
		else
		{
			FM.edtResult.value="3DES解密失败 ERRORCODE："+ ViKeyInterface.IViKeyGetError();	
		}
	}
}

</script>
</head>
<body>
<div align="center">
              <span class="blue01">ViKey API测试</span>

</div>
            <form action="" name="ViKeyForm" id="ViKeyForm">
              <table width="510" border="1" align="center" bgcolor="#dfe7df">
     <tr>
      <td width="123">&nbsp;</td>
      <td>&nbsp;</td>
      <td><input name="btnGetVersion" type="button" class="ctbottom" id="btnGetVersion" value=" 控件版本" onClick="GetVersion();"></td>
    </tr>
     <tr>
      <td width="123">&nbsp;</td>
      <td>&nbsp;</td>
      <td><input name="btnFind" type="button" class="ctbottom" id="btnFind" value=" 查  找 " onClick="ViKeyFind();"></td>
    </tr>
    <tr>
      <td><div align="right"><span class="ctbody3">硬件序列号：</span></div></td>
      <td><input name="etdNTID" type="text" class="cttextboxt" id="etdNTID" size="35" maxlength="32"></td>
      <td><input name="btnNTID" type="button" class="ctbottom" id="btnNTID" value="获取HID" onClick="ViKeyHID();"></td>
    </tr>
    <tr>
      <td><div align="right" class="ctbody3">用户密码：</div></td>
      <td><input name="UserPin2" type="text" class="cttextboxt" id="UserPin2" value="11111111" size="35" maxlength="32"></td>
      <td><input name="btnUserPin2" type="button" class="ctbottom" id="btnUserPin2" value="用户登录" onClick="ViKeyUserLogon();"></td>
    </tr>
    <tr>
      <td><div align="right" class="ctbody3">管理员密码：</div></td>
      <td><input name="AdminPin2" type="text" class="cttextboxt" id="AdminPin2" value="00000000" size="35" maxlength="32"></td>
      <td><input name="btnAdminPin2" type="button" class="ctbottom" id="btnAdminPin2" value="管理员登录" onClick="ViKeyAdminLogon();"></td>
    </tr>
	 <tr>
      <td><div align="right" class="ctbody3">设置软件ID：</div></td>
      <td><input name="EditSetSoftID" type="text" class="cttextboxt" id="EditSetSoftID" value="12345678" size="35" maxlength="32"></td>
      <td><input name="btnSetSID" type="button" class="ctbottom" id="btnSetSID" value="设置SID" onClick="ViKeySetSoftID();"></td>
    </tr>
	 <tr>
      <td><div align="right" class="ctbody3">读取软件ID：</div></td>
      <td><input name="EditGetSoftID" type="text" class="cttextboxt" id="EditGetSoftID" value="" size="35" maxlength="32"></td>
      <td><input name="btnGetSID" type="button" class="ctbottom" id="btnGetSID" value="读取SID" onClick="ViKeyGetSoftID();"></td>
    </tr>
		 <tr>
      <td><div align="right" class="ctbody3">写入数据：</div></td>
      <td><input name="EditWriteData" type="text" class="cttextboxt" id="EditWriteData" value="abcdefg-ABCDEFG" size="35" maxlength="32"></td>
      <td><input name="btnSetData" type="button" class="ctbottom" id="btnSetData" value="写入数据" onClick="ViKeyWriteData();"></td>
    </tr>
	 <tr>
      <td><div align="right" class="ctbody3">读取数据：</div></td>
      <td><input name="EditReadData" type="text" class="cttextboxt" id="EditReadData" value="" size="35" maxlength="32"></td>
      <td><input name="btnGetData" type="button" class="ctbottom" id="btnGetData" value="读取数据" onClick="ViKeyReadData();"></td>
    </tr>
    <tr>
      <td><div align="right" class="ctbody3">MD5Key：</div></td>
      <td><input name="EditMD5Key" type="text" class="cttextboxt" id="edtMD5Key" value="1234ABCD1234abcdxxxxyyyy" size="35" maxlength="32"></td>
      <td><input name="btnSetMD5Key" type="button" class="ctbottom" id="btnSetMD5Key" value="设置MD5Key" onClick="ViKeySetMd5Key();"></td>
    </tr>
    <tr>
      <td><div align="right" class="ctbody3">输入内容</div></td>
      <td><input name="edtMD5Text" type="text" class="cttextboxt" id="edtMD5Text" value="FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF" size="35" maxlength="32"></td>
    </tr>    
	<tr>
      <td><div align="right" class="ctbody3">计算MD5值</div></td>
      <td><input name="edtMD5Result" type="text" class="cttextboxt" id="edtMD5Result" value="" size="35" maxlength="32"></td>
      <td><input name="btnMD5Value" type="button" class="ctbottom" id="btnHmacMD5" value="计算MD5值" onClick="VikeyHmacMD5();"></td>
    </tr> 
	<tr>
      <td><div align="right" class="ctbody3">3DES加密</div></td>
      <td><input name="edtDesEncrypt" type="text" class="cttextboxt" id="edtDesEncrypt" value="" size="35" maxlength="1024"></td>
      <td><input name="btnDesEncrypt" type="button" class="ctbottom" id="btnDesEncrypt" value="3DES加密" onClick="Des3Encrypt();"></td>
    </tr> 
	<tr>
      <td><div align="right" class="ctbody3">3DES解密</div></td>
      <td><input name="edtDesDecrypt" type="text" class="cttextboxt" id="edtDesDecrypt" value="" size="35" maxlength="1024"></td>
      <td><input name="btnDesDecrypt" type="button" class="ctbottom" id="btnDesDecrypt" value="3DES解密" onClick="Des3Decrypt();"></td>
    </tr>
    <tr>
      <td height="18">&nbsp;</td>
      <td>&nbsp;</td>
      <td>&nbsp;</td>
    </tr>
    <tr>
      <td>&nbsp;</td>
      <td>&nbsp;</td>
      <td>&nbsp;</td>
    </tr>
    <tr>
      <td><div align="right" class="ctbody3">操作结果：</div></td>
      <td><input name="edtResult" type="text" id="edtResult" size="35"></td>
      <td>&nbsp;</td>
    </tr>
	    <tr>
      <td height="18"><div align="right"><span class="ctbody3">操作说明：</span></div></td>
      <td colspan="2" class="ctbody3"><p>1.ViKey-API测试，必须安装ViKey网页控件才可使用<br>
        2.例子只是对锁进行基本信息设置与演示</p>        </td>
      </tr>

  </table>
</form>
            <table width="510" border="0" align="center" cellspacing="0">
              <tr>
                <td width="139"><div align="center"><span class="ctbody3"><span class="blue01 style1"><a href="ViKey网页控件.exe">点击安装ViKey加密狗网页控件</a></span></span></div></td>
               
              </tr>
            </table>
            <p align="center" class="ctbody3">Create by ViKeyMaster, 2013-5-17</p>
<div align="center" class="ctbody3"></div>

</body>
</html>

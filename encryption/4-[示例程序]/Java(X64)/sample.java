import ViKey.ViKeyJavaObj;

class sample
{
	public static void ViKeySample()
	{
		ViKeyJavaObj ViKeyObj = new ViKeyJavaObj();

		short	Index = 0;
		long	retval;
		int[]	dwCount=new int[1];
		int[]	HID= new int[1];
		short	Addr;
		short	Length;
		byte[]  buffer=new byte[1024];
		byte[]  UserPassWord	=new byte[10];
		byte[]  AdminPassWord	=new byte[10];
		byte[]  SoftIDString 	=new byte[10];

		// 查找加密狗
		retval = ViKeyObj.ViKeyFind(dwCount);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("系统中找到ViKey加密狗数量:"+dwCount[0]);
		}
		else
		{
			System.out.println("系统中没有找到ViKey加密狗");
			return;
		}

		Index = 0;
		//获取加密狗硬件ID
		retval = ViKeyObj.ViKeyGetHID(Index, HID);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("获取加密狗的硬件ID:"+HID[0]);
		}
		else
		{
			System.out.println("获取加密狗类型错误");
			return;
		}


		//用户登录加密狗

		UserPassWord[0] = 0x31;
		UserPassWord[1] = 0x31;
		UserPassWord[2] = 0x31;
		UserPassWord[3] = 0x31;
		UserPassWord[4] = 0x31;
		UserPassWord[5] = 0x31;
		UserPassWord[6] = 0x31;
		UserPassWord[7] = 0x31;
		UserPassWord[8] = 0;
		retval = ViKeyObj.ViKeyUserLogin(Index, UserPassWord);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("用户登录加密狗成功!");
		}
		else
		{
			System.out.println("用户登录加密狗失败!");
			return;
		}

		AdminPassWord[0] = 0x30;
		AdminPassWord[1] = 0x30;
		AdminPassWord[2] = 0x30;
		AdminPassWord[3] = 0x30;
		AdminPassWord[4] = 0x30;
		AdminPassWord[5] = 0x30;
		AdminPassWord[6] = 0x30;
		AdminPassWord[7] = 0x30;
		AdminPassWord[8] = 0x00;
		retval = ViKeyObj.ViKeyAdminLogin(Index, AdminPassWord);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("管理员登录加密狗成功!");
		}
		else
		{
			System.out.println("管理员登录加密狗失败!");
			return;
		}


		SoftIDString[0] = '1';
		SoftIDString[1] = '2';
		SoftIDString[2] = '3';
		SoftIDString[3] = '4';
		SoftIDString[4] = '5';
		SoftIDString[5] = '6';
		SoftIDString[6] = '7';
		SoftIDString[7] = '8';
		SoftIDString[8] = 0;

		retval = ViKeyObj.ViKeySetSoftIDString(Index, SoftIDString);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("设置加密狗软件ID成功!");
		}
		else
		{
			System.out.println("设置加密狗软件ID失败!");
			return;
		}

		
		retval = ViKeyObj.ViKeyGetSoftIDString(Index, SoftIDString);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("获取加密狗软件ID成功!");
		}
		else
		{
			System.out.println("获取加密狗软件ID失败!");
			return;
		}
	
		Addr = 0;
		Length = 10;
		for(byte m=0;m<10;m++) buffer[m] = m;	
		retval = ViKeyObj.ViKeyWriteData(Index, Addr, Length, buffer);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("向加密狗内写入数据成功");
		}
		else
		{
			System.out.println("向加密狗内写入数据失败!");
			return;
		}

		retval = ViKeyObj.ViKeyReadData(Index, Addr, Length, buffer);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("从加密狗内读取数据成功");
		}
		else
		{
			System.out.println("从加密狗内读取数据失败!");
			return;
		}

		retval = ViKeyObj.ViKeyLogoff(Index);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("关闭加密狗成功");
		}
		else
		{
			System.out.println("关闭加密狗失败!");
			return;
		}
	}

	public static void main(String[] args)
	{
		ViKeySample();
	}
}

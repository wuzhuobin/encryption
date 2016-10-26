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

		// ���Ҽ��ܹ�
		retval = ViKeyObj.ViKeyFind(dwCount);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("ϵͳ���ҵ�ViKey���ܹ�����:"+dwCount[0]);
		}
		else
		{
			System.out.println("ϵͳ��û���ҵ�ViKey���ܹ�");
			return;
		}

		Index = 0;
		//��ȡ���ܹ�Ӳ��ID
		retval = ViKeyObj.ViKeyGetHID(Index, HID);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("��ȡ���ܹ���Ӳ��ID:"+HID[0]);
		}
		else
		{
			System.out.println("��ȡ���ܹ����ʹ���");
			return;
		}


		//�û���¼���ܹ�

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
			System.out.println("�û���¼���ܹ��ɹ�!");
		}
		else
		{
			System.out.println("�û���¼���ܹ�ʧ��!");
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
			System.out.println("����Ա��¼���ܹ��ɹ�!");
		}
		else
		{
			System.out.println("����Ա��¼���ܹ�ʧ��!");
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
			System.out.println("���ü��ܹ����ID�ɹ�!");
		}
		else
		{
			System.out.println("���ü��ܹ����IDʧ��!");
			return;
		}

		
		retval = ViKeyObj.ViKeyGetSoftIDString(Index, SoftIDString);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("��ȡ���ܹ����ID�ɹ�!");
		}
		else
		{
			System.out.println("��ȡ���ܹ����IDʧ��!");
			return;
		}
	
		Addr = 0;
		Length = 10;
		for(byte m=0;m<10;m++) buffer[m] = m;	
		retval = ViKeyObj.ViKeyWriteData(Index, Addr, Length, buffer);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("����ܹ���д�����ݳɹ�");
		}
		else
		{
			System.out.println("����ܹ���д������ʧ��!");
			return;
		}

		retval = ViKeyObj.ViKeyReadData(Index, Addr, Length, buffer);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("�Ӽ��ܹ��ڶ�ȡ���ݳɹ�");
		}
		else
		{
			System.out.println("�Ӽ��ܹ��ڶ�ȡ����ʧ��!");
			return;
		}

		retval = ViKeyObj.ViKeyLogoff(Index);
		if (retval == ViKeyObj.VIKEY_SUCCESS)
		{
			System.out.println("�رռ��ܹ��ɹ�");
		}
		else
		{
			System.out.println("�رռ��ܹ�ʧ��!");
			return;
		}
	}

	public static void main(String[] args)
	{
		ViKeySample();
	}
}

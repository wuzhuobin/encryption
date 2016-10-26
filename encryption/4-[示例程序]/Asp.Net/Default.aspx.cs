using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Runtime.InteropServices;
using System.Text;


namespace test
{
    public partial class _Default : System.Web.UI.Page
    {
        public static string str2HexStr(string str)
        {
            char[] hex = new char[] {   
        '0', '1', '2', '3', '4', '5', '6', '7',  
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'  
            };
           
            StringBuilder sb = new StringBuilder("");
            char[] bs = str.ToCharArray();
            int bit;
            for (int i = 0; i < str.Length; i++)
            {
                bit = (bs[i] & 0x0f0) >> 4;
                sb.Append(hex[bit]);
                bit = bs[i] & 0x0f;
                sb.Append(hex[bit]);
            }
            return sb.ToString();
        }


        // 函数引用声明
        [DllImport("ViKey")]
        public static extern uint VikeyFind(ref uint pdwCount);

        [DllImport("ViKey")]
        public static extern uint VikeyGetHID(ushort Index, ref uint pdwHID);
        [DllImport("ViKey")]
        public static extern uint VikeyUserLogin(ushort Index, string pUserPassWord);
        
        [DllImport("ViKey")]
        public static extern uint VikeyDesEncrypt(ushort Index, ushort Length, string pText, StringBuilder pResult, ref ushort OutLength);

        protected void Page_Load(object sender, EventArgs e)
        {
            uint retcode, Count = 0, HID = 0;
            ushort OutLength= 0, Length;
            ushort j;
            string strOut="111111111111111111111111111111111111111111111111";
            StringBuilder str = new StringBuilder(255); //255 是 capacity
            //查找加密狗
            retcode = VikeyFind(ref Count);

            if (retcode != 0)
            {
                lit_is_OK.Text = "查找ViKey加密狗错误 error code:" + retcode;
                return;
            }
            else
            {
                lit_is_OK.Text = "检测到["+Count+"]个ViKey设备" ;  
            }
            for (j = 0; j < Count; j++)
            {

                //获取加密狗硬件序列号(HID)
                retcode = VikeyGetHID(j, ref HID);
                if (retcode != 0)
                {
                   
                    lit_Hid.Text = "获取硬件序列号错误 error code:" + retcode;
                    return;
                }
                lit_Hid.Text +=  "["+j+"]ViKey加密狗硬件序列号:" + HID+"<br/>";


               retcode =  VikeyUserLogin(j, "11111111");
                if (retcode != 0)
                {

                    lit_Hid.Text = "用户登陆错误 error code:" + retcode;
                    return;
                }
                lit_Hid.Text = "用户登陆成功" + "<br/>";

                Length = 8;
                retcode = VikeyDesEncrypt(j, Length, "12345678", str, ref OutLength);
                if (retcode != 0)
                {

                    lit_Hid.Text = "Des加密错误 error code:" + retcode;
                    return;
                }
                lit_Hid.Text += "[" + j + "]Des加密成功:" + (str.ToString()) + "<br/>";
            }
        }
    }
}
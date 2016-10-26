using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Runtime.InteropServices;

namespace test
{
    public partial class _Default : System.Web.UI.Page
    {

        // 函数引用声明
        [DllImport("ViKey")]
        public static extern uint VikeyFind(ref uint pdwCount);

        [DllImport("ViKey")]
        public static extern uint VikeyGetHID(ushort Index, ref uint pdwHID);

        protected void Page_Load(object sender, EventArgs e)
        {
            uint retcode, Count=0, HID = 0;
            ushort j;
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
               

            }
        }
    }
}
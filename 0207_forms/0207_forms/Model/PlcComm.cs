using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Transactions;
using XIMUTILLib;

namespace _0207_C_.Model
{
    internal class PlcComm
    {
        DeviceInterface deviceInterface = new DeviceInterface();
        internal bool blsConnected; // plc와의 연결확인.
        internal short[] toPlc = new short[80];
        internal short[] fromPlc = new short[80];

        internal PlcComm()
        {
            Console.WriteLine("hello");
        }
        internal void Connect()
        {
            deviceInterface.Connect();
            blsConnected = true;
        }
        internal void ReadWord()
        {
            byte[] byArr = new byte[256];
            deviceInterface.ReadDevice("D", 200, 2, ref byArr[0]);
            // d메모리에 200번부터 160개를 byArr에 저장 ref 는 포인터랑 똑같은 개념. arr 의 첫번째는 배열의 주소랑 똑같은거 그거.
            // D 메모리의 200Byte 번 부터 = D100 번부터 2개바이트를 읽어와서 byArr[0]의 주소값에 넣겠다라는뜻
            for (int i = 0; i < 80; i++)
            {
                fromPlc[i] = (short)((byArr[1 + (i * 2)] << 8) | (byArr[i * 2])); // ReadDevice 는 Byte단뒤로 값을 긁어오는데
                                                                                  //이걸 word단위로 붙혀준는 역할,. 80개가 될듯 fromplc배열은

            }
        }
        internal void WriteWord()
        {
            byte[] byArr = new byte[256];
            for (int i = 0; i < 80; i++)
            {
                byArr[1 + (i * 2)] = (byte)(toPlc[i] / 256);
                byArr[(i * 2)] = (byte)(toPlc[i] % 256);
                // 이거는 word를 byte 2개로 다시 쪼개는 부분
            }
            deviceInterface.WriteDevice("D", 0, 2, ref byArr[0]);
        }
    }
}

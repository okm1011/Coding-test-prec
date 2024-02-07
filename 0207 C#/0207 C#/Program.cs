using _0207_C_.Model;
using System.Collections.Specialized;

PlcComm plcComm = new PlcComm();
//연결
plcComm.Connect();
//read
plcComm.ReadWord();

//출력
Console.WriteLine(plcComm.fromPlc[0]);

//write
plcComm.toPlc = plcComm.fromPlc;
plcComm.WriteWord();


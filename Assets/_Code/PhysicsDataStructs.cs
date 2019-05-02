using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class PhysicsDataStructs : MonoBehaviour
{
    [StructLayout(LayoutKind.Sequential, Size = 12), System.Serializable]
    public struct RigidBodyData
    {
        // Vector 3 position
        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float x;
        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float y;
        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float z;
    }
}

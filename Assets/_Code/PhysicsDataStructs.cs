using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class PhysicsDataStructs : MonoBehaviour
{
    /* Physics Data Structures for RigidBody Dynamics */
    [StructLayout(LayoutKind.Sequential, Size = 20), System.Serializable]
    public struct RigidBodyData
    {
        // Vector 3 position
        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float x;
        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float y;
        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float z;

        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float angle;
        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float angularVelocity;

        [MarshalAsAttribute(UnmanagedType.R4, SizeConst = 4)]
        public float torque;
    }

    /* Physics Functions */
    [DllImport("BeybladePhysics")]   
    public static extern int Foo(int a, int b);

    [DllImport("BeybladePhysics", CallingConvention = CallingConvention.Cdecl)]
    public static extern void AddImpulse_Wrapper(Rigidbody rb, Vector3 force, float time);


    /* Monobehaviour Functions */
    void Start() { }
    void Update() { }
}

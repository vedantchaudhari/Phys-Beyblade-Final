﻿using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class BeybladeController : PhysicsDataStructs
{
    [SerializeField]
    private Rigidbody mRigidbody;
    [SerializeField]
    private Vector3 mCenterOfMass;
    [SerializeField]
    public bool isPlayerTwo;

    public void Launch()
    {
        mRigidbody.isKinematic = false;
        mRigidbody.AddTorque(new Vector3(0, 20000 * 100, 0));
        //AddImpulse_Wrapper(mRigidbody, new Vector3(1000, 0, 0), 2.5f);
 //     mRigidbody.angularVelocity
        if (!isPlayerTwo)
            mRigidbody.AddForce(Vector3.forward * 1000);
        else
            mRigidbody.AddForce(Vector3.back * 1000);
    }

    /* Monobehaviour Functions */
    void Start()
    {
        mRigidbody = GetComponent<Rigidbody>();
        mRigidbody.isKinematic = true;
        mRigidbody.centerOfMass = mCenterOfMass;

        Launch();

        Debug.Log(Foo(1, 2));
    }

    void Update()
    {
    }
}

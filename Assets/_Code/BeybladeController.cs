using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class BeybladeController : PhysicsDataStructs
{
    [SerializeField]
    private Rigidbody mRigidbody;
    [SerializeField]
    private Vector3 mCenterOfMass;

    public void Launch()
    {
        mRigidbody.isKinematic = false;
        mRigidbody.AddTorque(new Vector3(0, 10000 * 100, 0));
 //     mRigidbody.angularVelocity
        mRigidbody.AddForce(Vector3.forward * 1000);
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

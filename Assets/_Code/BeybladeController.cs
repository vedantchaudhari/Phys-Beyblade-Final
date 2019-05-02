using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

public class BeybladeController : MonoBehaviour
{
    [SerializeField]
    private Rigidbody mRigidbody;
    [SerializeField]
    private Vector3 mCenterOfMass;

    public void Launch()
    {
        mRigidbody.isKinematic = false;
        mRigidbody.AddTorque(new Vector3(0, 2000 * 100, 0));
        mRigidbody.AddForce(Vector3.forward * 1000);
    }

    /* Monobehaviour Functions */
    void Start()
    {
        mRigidbody = GetComponent<Rigidbody>();
        mRigidbody.isKinematic = true;
        mRigidbody.centerOfMass = mCenterOfMass;

        Launch();
    }

    void Update()
    {
    }
}

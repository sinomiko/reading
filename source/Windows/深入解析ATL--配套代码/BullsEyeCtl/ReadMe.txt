Enhancements:

I've made four minor enhancements to the BullsEye control.

There's a bug in ATL's OnDrawAdvanced method which causes BullsEye to draw
incorrectly in Print Preview mode when hosted on an Access form.

Access requires a control to set its dirty bit upon instantiation. Failure
to do so causes the wierdest error message "No object in this control."

The RingCount property now requests VB use its default processing for its
display name - which means you can now edit it in VB's property view rather
than having to click on the button in the view to bring up the custom
propery page.

BullsEye now registers a Property context menu item.



Corrected bugs:

November 5, 1999
Additional notes added April 11, 2000

Reported by: David Sieger
Commonly used control containers (VB and TSTCON32) do not properly
use the IPropertyPage interface. Specifically, they should call
IPropertyPage::SetObjects with a non-zero object count *followed by*
another call to SetObjects with a zero object count. VB only properly
follows this rule when the first call returns an error status. TSTCON32
seemingly never calls SetObjects with a zero reference count.

Held object references result from a SetObjects call with a non-zero
object count *without* a subsequent SetObjects call with a zero objects
count (which signals a property page to release its held object references.

The initial codebase properly handled the (erroronous) usage by VB where
it would make sequential calls to SetObjects all with a non-zero object count.
Each subsequent call to SetObjects, regardless of the object count) releases
any previously held references.

In the initial codebase, the BullsEye property page destructor released
all objects still held at that time. This was an attempt to compensate for
a container failing to make a final SetObjects call with a zero object count.

Unfortunately, the destructor doesn't run in some containers. TSTCON32, for
example, never releases the property page object until it releases all held
object references. As this never happens, when you close the TSTCON32 application
after using the BullsEye control and displaying its property page, the TSTCON32
application hides its user-interface but the process never terminates.

The modified source code adds a message handler for WM_DESTROY and releases any
held references when Windows destroys the property page window and no longer tries
to release them in the property page destructor.

With this modification, TSTCON32 now releases the property page. All objects destruct
as expected and TSTCON32 now terminates.


April 9, 1999

Reported by: Matt MoreHouse
When the Property Page detected that the RingCount was out of range in
OnChangeRingCount, it was resetting the count to the bad value instead
of the original value.


The updated source code is available on http://www.wiseowl.com/ATLInternals

    Brent

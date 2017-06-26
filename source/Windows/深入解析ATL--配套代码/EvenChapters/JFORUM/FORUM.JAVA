/**
 * This class can take a variable number of parameters on the command
 * line. Program execution begins with the main() method. The class
 * constructor is not invoked unless an object of type 'Class1'
 * created in the main() method.
 */
import atlinternals.*;

public class Forum
{
	/**
	 * The main entry point for the application. 
	 *
	 * @param args Array of parameters passed to the application
	 * via the command line.
	 */
	public static void main (String[] args)
	{
    // Demosthenes waits about the Forum for his chance to defend Phormio
    ISpeaker Demosthenes = (ISpeaker) new Demagogue ();
	
    // Apollodorus waits nervously for Demosthenes to begin
    ISpeaker Apollodorus = (ISpeaker) new Demagogue ();

    // All demagogues start as Demosthenes so initialize Apollodorus
    INamedObject no = (INamedObject) Apollodorus;
    no.setName ("Apollodorus") ;

    Apollodorus.setSlogan ("I am not a crook!");

	// Now let's have Phormio and a council member listening to the demagogues

    // Phormio of Athens enters the Forum
    IListener Phormio = (IListener) new EarPolitic ();

    no = (INamedObject) Phormio;
    no.setName ("Phormio") ;

    // A council member enters the Forum
    IListener CouncilMember = (IListener) new EarPolitic ();

    no = (INamedObject) CouncilMember;
    no.setName ("Council member");

	final int Defendent = 0;
	final int Plaintiff = 1;
	
    // Phormio waits for Demosthenes and Apollodorus to speak
    Phormio.ListenTo (Defendent, Demosthenes) ;
    Phormio.ListenTo (Plaintiff, Apollodorus) ;
    
    // The council member waits for Demosthenes and Apollodorus to speak
    CouncilMember.ListenTo (Defendent, Demosthenes) ;
    CouncilMember.ListenTo (Plaintiff, Apollodorus) ;
    
    // Demothenes begins speaking...
    Demosthenes.Speak () ;

    // Apollodorus never gets the chance to speak but if he did...
    Apollodorus.Speak () ;

    Phormio.StopListening (Defendent) ;
    Phormio.StopListening (Plaintiff) ;
    CouncilMember.StopListening (Defendent) ;
    CouncilMember.StopListening (Plaintiff) ;
	}
}

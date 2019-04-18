// Advanced Software Design - Assignment 2.
// Michael Mohan 40020843.

// Import headers for handling file output.
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class Assignment_2_With_Strategy
{  
	// Program runs the Powers method from each cass that implements the Superhero
	// interface. The time it takes for these operations to run using the Strategy
	// pattern is stored in nanoseconds. This is repeated 5 times and the time 
	// elapsed for each iteration is read into a text file.  
    public static void main(String args[]) 
    {
    	
    	String you;
    	
    	// Create array to store times.
    	long[] Times = new long[5];
    	
    	// Loop for 5 iterations.
    	for (int i = 0; i < 5; i++)
    	{
    		// Start measuring the time.
	    	long startTime = System.nanoTime();
	    	
	    	// Run the Powers methods for each class.
	    	CaptainAmerica Steve = new CaptainAmerica();
	    	Steve.Powers();
	    	SpiderMan Peter = new SpiderMan();
	    	Peter.Powers();
	    	Wolverine Logan = new Wolverine();
	    	Logan.Powers();
	    	Hulk Bruce = new Hulk();
	    	Bruce.Powers();
	    	
	    	// Calulate and store elapsed time.
	    	long elapsedTime = System.nanoTime() - startTime;
	    	Times[i] = elapsedTime;
	    	
	    	// Output the time taken in seconds and nanoseconds.
	    	double elapsedTimeSeconds = (double)elapsedTime/1000000000;
	    	System.out.println("Elapsed Time: " + elapsedTime + " nanoseconds.");
	    	System.out.println("Which is:     " + elapsedTimeSeconds + " seconds.\n\n");
	    	
	    	// Store times into a text file.
	    	try 
	    	{
				File file = new File("../../StrategyTimes.txt");
	 
				// If file doesnt exists, then create it.
				if (!file.exists()) 
					file.createNewFile();
	 
				FileWriter fw = new FileWriter(file.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);
				
				// Add times into "StrategyTimes.txt" and then close the file.
				bw.append("Elapsed Times (in nanoseconds): ");									
				for (int j = 0; j < 5; j++)
				{
					if (j == 4)
						bw.append(Times[j] + ".");
					else
						bw.append(Times[j] + ", ");
				}
				bw.close();
			} 
			catch (IOException e) 
			{
				e.printStackTrace();
			}
	    }
    }
}
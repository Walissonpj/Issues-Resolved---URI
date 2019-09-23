import java.io.*;
import java.math.*;
import java.util.*;
/**
 * IMPORTANT: 
 *      O nome da classe deve ser "Main" para que a sua solução execute
 *      Class name must be "Main" for your solution to execute
 *      El nombre de la clase debe ser "Main" para que su solución ejecutar
 */
public class Main {
	
	public static void main(String[] args) throws IOException {
		InputStreamReader ir = new InputStreamReader( System.in ) ;
		BufferedReader in = new BufferedReader(ir);
		BigInteger a ;
		boolean flag = true ;
		String s ;
		while( (s = in.readLine()) != null )
		{
			
			if(!flag )
				System.out.println("")  ;
			flag = false ;
			
			a = new BigInteger( s ) ;
			boolean ok = false, vis = false  ;
			if( a.mod( new BigInteger("400") ).equals(BigInteger.ZERO) || (a.mod( new BigInteger("4") ).equals(BigInteger.ZERO)  && !a.mod( new BigInteger("100") ).equals(BigInteger.ZERO) ) )
			{
					System.out.println("This is leap year.") ; 
					ok = true  ;

					if( a.mod( new BigInteger("15") ).equals( BigInteger.ZERO ) )
					{
						System.out.println("This is huluculu festival year.") ;
						ok = true ;
						vis = true ;
					}
					if( a.mod( new BigInteger("55") ).equals( BigInteger.ZERO ) )
					{
						System.out.println("This is bulukulu festival year.") ;
						ok = true ;
					}
			}
			if( a.mod( new BigInteger("15") ).equals( BigInteger.ZERO ) && vis == false)
			{
				System.out.println("This is huluculu festival year.") ;
				ok = true ;
			}
			if( ok == false )
				System.out.println("This is an ordinary year.") ;
		}
	}
}
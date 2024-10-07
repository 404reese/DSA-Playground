class OOPM_7A 
{ 
public static void main(String args[]) 
{ 
try 
{ 
int a,b,c; 
a=Integer.parseInt(args[0]); 
b=Integer.parseInt(args[1]); 
c=a/b; 
System.out.println(a+" / "+b+"="+c); 
} 
catch(ArithmeticException e) 
{ 
System.out.println("Division by zero error occurred"); 
System.out.println(e); 
} 
catch(ArrayIndexOutOfBoundsException e) 
{ 
System.out.println("Supply two arguments from the command line"); 
System.out.println(e); 
} 
catch(NumberFormatException e) 
{ 
System.out.println("Not valid Integers"); 
System.out.println(e); 
} 
} 
} 
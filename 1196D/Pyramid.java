import java.io.*;
import java.lang.*;
import java.util.*;

class Pyramid{

	public static void main (String[] args) throws java.lang.Exception
	{
		for(int i = 0;i < 5; i++){
			for(int k = 0;k < i + 1;k++){
				char p = 'A' + k;
		 		System.out.print(p);
			}
			System.out.println();
		}
	}
}
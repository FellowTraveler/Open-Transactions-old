//package com.wrapper.core;

// runme.java

//import otapi;
//import com.wrapper.core.jni.otapi;
import java.io.File;
import java.io.IOException;
import java.lang.reflect.Field;
import java.util.logging.Level;
import java.util.logging.Logger;


public class runme {
  
/*
 *
 * Exception in thread "main" java.lang.UnsatisfiedLinkError: C:\~\Open-Transactions\testwallet\JNI_API_Windows.dll: Can't find dependent libraries
        at java.lang.ClassLoader$NativeLibrary.load(Native Method)
        at java.lang.ClassLoader.loadLibrary0(ClassLoader.java:1803)
        at java.lang.ClassLoader.loadLibrary(ClassLoader.java:1728)
        at java.lang.Runtime.loadLibrary0(Runtime.java:823)
        at java.lang.System.loadLibrary(System.java:1028)
        at com.wrapper.core.runme.main(runme.java:26)
Java Result: 1
 */
	
	public static WalletData getWalletData() {
		
        WalletData walletData = null;
		
        if (otapi.Exists("moneychanger", "gui_wallet.dat")) {
            walletData = WalletData.ot_dynamic_cast(otapi.QueryObject(StoredObjectType.STORED_OBJ_WALLET_DATA, "moneychanger", "gui_wallet.dat"));
        } else {
            walletData = WalletData.ot_dynamic_cast(otapi.CreateObject(StoredObjectType.STORED_OBJ_WALLET_DATA));
        }
		
        return walletData;
    }
	
  public static void main(String argv[]) throws IOException {

//            String message ="Subject:The subject ends here\nMessage start";


 //           if(message.startsWith("Subject") || message.startsWith("subject"))
//                System.out.println(message.substring(0, message.indexOf("\n")));

//            addDirToRuntime("C:\\~\\OpenSSl-Win32");
//            addDirToRuntime("C:\\~\\Open-Transactions\\testwallet");
              System.loadLibrary("otapi");

        otapi.OT_API_Init("/Users/Chris/Projects/Open-Transactions/testwallet/data_folder");
	
	  otapi.OT_API_LoadWallet("wallet.xml");

	  WalletData theWalletData = getWalletData();
	  
	  
	  
	  
//	System.out.println(otapi.fact(4));
  }
  public static void addDirToRuntime(String s) throws IOException {
		try {

			Field field = ClassLoader.class.getDeclaredField("usr_paths");
			field.setAccessible(true);
			String[] paths = (String[])field.get(null);
			for (int i = 0; i < paths.length; i++) {
				if (s.equals(paths[i])) {
					return;
				}
			}
			String[] tmp = new String[paths.length+1];
			System.arraycopy(paths,0,tmp,0,paths.length);
			tmp[paths.length] = s;
			field.set(null,tmp);
			System.setProperty("java.library.path", s + File.pathSeparator + System.getProperty("java.library.path") );
		} catch (IllegalAccessException e) {
			throw new IOException("Failed to get permissions to set library path");
		} catch (NoSuchFieldException e) {
			throw new IOException("Failed to get field handle to set library path");
		}
	}

}

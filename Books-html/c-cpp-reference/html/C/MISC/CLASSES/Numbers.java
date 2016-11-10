import java.applet.*;    
import java.awt.*; 
import java.lang.*;

public class Numbers extends Applet              
{
  public void init()
  {
    // Default settings for the frame.
    
    setBackground(Color.gray);
    setForeground(Color.white);
    setFont(new Font("Courier", Font.PLAIN, 20));

    // The way we are going to place items on the Frame.

    GridBagLayout       gb = new GridBagLayout();
    GridBagConstraints cgb = new GridBagConstraints();
    setLayout(gb);

    // Create an Item.

    TextArea Text =  new TextArea(" Dec Hex Oct   Binary ASCII\n" ,10 ,30);

    String Padding  = "    ";
    String DecStr   = " ";
    String HexStr   = " ";
    String OctStr   = " ";
    String BinStr   = " ";
    String AsciiStr = " ";
    
    for (long Count=0; Count <= 255; Count++)
    {
      DecStr   = DecStr.valueOf(Count);
      DecStr   = Padd(DecStr, 4);
      HexStr   = Long.toString(Count, 16);
      HexStr   = Padd(HexStr, 4);
      OctStr   = Long.toString(Count, 8);
      OctStr   = Padd(OctStr, 4);
      BinStr   = Long.toString(Count, 2);
      BinStr   = Padd(BinStr, 9);
      AsciiStr = AsciiStr(Count);
      AsciiStr = Padd(AsciiStr, 2);

      Text.appendText( DecStr + HexStr + OctStr + BinStr + AsciiStr + "\n");
    }

    Text.setForeground(Color.black);
    Text.setBackground(Color.white);
    Text.setEditable(false);

    // Set the constraints.

    cgb.gridwidth = 100;
    gb.setConstraints(Text, cgb);

    // And place it on the Frame.

    add(Text);

  }

  // Override paint method so it draws a rectange around the Frame

  public void paint(Graphics g) 
  {
    // Get the panels dimentions.

    Rectangle r = bounds();

    // top left, length across, length down.

    g.drawRect(0, 0, r.width-1, r.height-1);
    g.drawRect(5, 5, r.width-11, r.height-11);
  }

  public String Padd(String Str, int Size)
  {
    String Padding = " 00000000000000";

    String PaddedStr = Padding.substring(0, Size-Str.length()) + Str;
    return PaddedStr; 
  }

  public String AsciiStr(long Num)
  {
    String[] Ascii = {" "," "," "," "," "," "," "," "," "," ",
    		      " "," "," "," "," "," "," "," "," "," ",
    		      " "," "," "," "," "," "," "," "," "," ",
    		      " "," "," ","!","\"","#","$","%","&","'",
    		      "(",")","*","+","'","-",".","/","0","1",
    		      "2","3","4","5","6","7","8","9",":",";",
    		      "<","=",">","?","@","A","B","C","D","E",
    		      "F","G","H","I","J","K","L","M","N","O",
    		      "P","Q","R","S","T","U","V","W","X","Y",
    		      "Z","[","\\","]","^","_","`","a","b","c",
    		      "d","e","f","g","h","i","j","k","l","m",
    		      "n","o","p","q","r","s","t","u","v","w",
    		      "x","y","z","{","|","}","~"
                      };
    String Ret = " ";

    if (Num < 127)
    {
      Ret = Ascii[(int) Num];
    }

    return Ret;
  }
}
                                        

